#include "header.h"

#include <inttypes.h>

lcd1::lcd1(uint8_t cols, uint8_t lines,uint8_t dotsize) {
  if (lines > 1) {
    _displayfunction |= LCD_2LINE;
  }
  _numlines = lines;

  setRowOffsets(0x00, 0x40, 0x00 + cols, 0x40 + cols);  

  if ((dotsize != LCD_5x8DOTS) && (lines == 1)) {
    _displayfunction |= LCD_5x10DOTS;
  }

  pinMode(_rs_pin, OUTPUT);
  if (_rw_pin != 255) { 
    pinMode(_rw_pin, OUTPUT);
  }
  pinMode(_enable_pin, OUTPUT);
  
  for (int i=0; i<((_displayfunction & LCD_8BITMODE) ? 8 : 4); ++i)
  {
    pinMode(_data_pins[i], OUTPUT);
   } 
  delayMicroseconds(50000); 

  digitalWrite(_rs_pin, LOW);
  digitalWrite(_enable_pin, LOW);
  if (_rw_pin != 255) { 
    digitalWrite(_rw_pin, LOW);
  }
  
  if (! (_displayfunction & LCD_8BITMODE)) {
    write4bits(0x03);
    delayMicroseconds(4500); 

    write4bits(0x03);
    delayMicroseconds(4500);

    write4bits(0x03); 
    delayMicroseconds(150);
    write4bits(0x02); 
  } else {
    command(LCD_FUNCTIONSET | _displayfunction);
    delayMicroseconds(4500);  

    command(LCD_FUNCTIONSET | _displayfunction);
    delayMicroseconds(150);
    command(LCD_FUNCTIONSET | _displayfunction);
  }

  command(LCD_FUNCTIONSET | _displayfunction);  
  _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;  
  display();
  clear();

  _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;

  command(LCD_ENTRYMODESET | _displaymode);

}

void lcd1::setRowOffsets(int row0, int row1, int row2, int row3)
{
  _row_offsets[0] = row0;
  _row_offsets[1] = row1;
  _row_offsets[2] = row2;
  _row_offsets[3] = row3;
}

void lcd1::clear()
{
  command(LCD_CLEARDISPLAY);  
  delayMicroseconds(2000);  
}

void lcd1::home()
{
  command(LCD_RETURNHOME);  
  delayMicroseconds(2000); 
}

void lcd1::setCursor(uint8_t col, uint8_t row)
{
  const size_t max_lines = sizeof(_row_offsets) / sizeof(*_row_offsets);
  if ( row >= max_lines ) {
    row = max_lines - 1;    
  }
  if ( row >= _numlines ) {
    row = _numlines - 1;    
  }

  command(LCD_SETDDRAMADDR | (col + _row_offsets[row]));
}

void lcd1::noDisplay() {
  _displaycontrol &= ~LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void lcd1::display() {
  _displaycontrol |= LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void lcd1::noCursor() {
  _displaycontrol &= ~LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void lcd1::cursor() {
  _displaycontrol |= LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void lcd1::noBlink() {
  _displaycontrol &= ~LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void lcd1::blink() {
  _displaycontrol |= LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void lcd1::scrollDisplayLeft(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
void lcd1::scrollDisplayRight(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right
void lcd1::leftToRight(void) {
  _displaymode |= LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left
void lcd1::rightToLeft(void) {
  _displaymode &= ~LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor
void lcd1::autoscroll(void) {
  _displaymode |= LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void lcd1::noAutoscroll(void) {
  _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void lcd1::createChar(uint8_t location, uint8_t charmap[]) {
  location &= 0x7; // we only have 8 locations 0-7
  command(LCD_SETCGRAMADDR | (location << 3));
  for (int i = 0; i < 8; i++) {
    write(charmap[i]);
  }
}

/*********** mid level commands, for sending data/cmds */

inline void lcd1::command(uint8_t value) {
  send(value, LOW);
}

inline size_t lcd1::write(uint8_t value) {
  send(value, HIGH);
  return 1; // assume sucess
}

/************ low level data pushing commands **********/

// write either command or data, with automatic 4/8-bit selection
void lcd1::send(uint8_t value, uint8_t mode) {
  digitalWrite(_rs_pin, mode);

  // if there is a RW pin indicated, set it low to Write
  if (_rw_pin != 255) {
    digitalWrite(_rw_pin, LOW);
  }

  if (_displayfunction & LCD_8BITMODE) {
    write8bits(value);
  } else {
    write4bits(value >> 4);
    write4bits(value);
  }
}

void lcd1::pulseEnable(void) {
  digitalWrite(_enable_pin, LOW);
  delayMicroseconds(1);
  digitalWrite(_enable_pin, HIGH);
  delayMicroseconds(1);    // enable pulse must be >450ns
  digitalWrite(_enable_pin, LOW);
  delayMicroseconds(100);   // commands need > 37us to settle
}

void lcd1::write4bits(uint8_t value) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(_data_pins[i], (value >> i) & 0x01);
  }

  pulseEnable();
}

void lcd1::write8bits(uint8_t value) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(_data_pins[i], (value >> i) & 0x01);
  }

  pulseEnable();
}

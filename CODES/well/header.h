#ifndef hd
#define hd
#include"Arduino.h"
#include <inttypes.h>
#include "Print.h"
#include <SD.h>
#include <SPI.h>
class he {
  public:
    void kotasizacma(char *isim);
    void kotaacma(char *isim);
    void kotasizkapatma(char *isim);
    void kotalikapatma(char *isim, int kota);

    void reset();
    void hesap(bool hesapd, int volume);

    void display_menu(uint8_t pencere, uint8_t menuoption, uint8_t sub, uint8_t cursorline);
    void displaysifre(int sifre);
    void displayfatura(int volume);
    void displaykota(int kota);
    void displayacma(char *isim);
    bool acma = false, kotasizacmanum = false;
    uint8_t kotaliacma=0;
    unsigned long acilmazamani;
    int gosterisure;
    void kayit(char *isim, int sure);
    void sonkullanimkayit(char *c, int sure);
    
  private:
  void acmakayit(char *isim);
    uint8_t lastpencere = 1;
    double adnan = 0, muzo = 0, ethem = 0, mali = 0, nur = 0, huso = 0;
    void hesap();
    void saat();
};

#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

class lcd1 : public Print {
  public:
     lcd1(uint8_t cols, uint8_t lines,uint8_t charsize = LCD_5x8DOTS);
    void clear();
    void home();

    void noDisplay();
    void display();
    void noBlink();
    void blink();
    void noCursor();
    void cursor();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    void leftToRight();
    void rightToLeft();
    void autoscroll();
    void noAutoscroll();

    void setRowOffsets(int row1, int row2, int row3, int row4);
    void createChar(uint8_t, uint8_t[]);
    void setCursor(uint8_t, uint8_t);
    virtual size_t write(uint8_t);
    void command(uint8_t);

    using Print::write;
  private:
    void send(uint8_t, uint8_t);
    void write4bits(uint8_t);
    void write8bits(uint8_t);
    void pulseEnable();

    uint8_t _rs_pin = 16; 
    uint8_t _rw_pin = 255; 
    uint8_t _enable_pin = 17; 
    uint8_t _data_pins[4] = {23, 25, 27, 29};

    uint8_t _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;;
    uint8_t _displaycontrol;
    uint8_t _displaymode;

    uint8_t _initialized;

    uint8_t _numlines;
    uint8_t _row_offsets[4];
};
#endif

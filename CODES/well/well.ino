#include <MFRC522.h>
MFRC522 rfid(10 , 9);
#include<EEPROM.h>
#include"header.h"
class he h; class lcd1 lcd(20, 4); File data1;
#define interrupt

#define PINB 48
#define PINA 19
#define PUSHB 22
#define buzzer 24
#define b6 6000

bool volumeHandler = false, sifrehandler = false, kotahandler = false;
int  lastVolume = 0, lastCount = 0, lastkota = 0, lastsifre = 0, volume = 0, sifre = 0, kota = 0, i, lastgosteri = 1;
uint8_t pencere = 1, menuoption = 1, sub = 0, cursorline = 0;
char *isim;

byte ethem[4] = {16, 233, 144, 47}; // you can increase the number of users, here ı have one.

void setup() {
  DDRA &= ~((1 << DDA2) | (1 << DDA0));
  DDRD &= ~((1 << DDD2) | (1 << DDD0));
  DDRL &= ~(1 << DDL0);
  DDRH |= (1 << DDH6);
  DDRB |= (1 << DDB0) | (1 << DDB4);
  DDRE |= (1 << DDE3) | (1 << DDE5);
  PORTD |= (1 << 2) | (1 << 0);
  PORTL |= (1 << 0);
  PORTA |= (1 << 0);
  PORTE |= (1 << 3) | (1 << 5); // relay pins (3,5)
  Serial.begin(9600); SPI.begin(); rfid.PCD_Init();
  attachInterrupt(digitalPinToInterrupt(PINA), isr, LOW);
  attachInterrupt(digitalPinToInterrupt(21), kesme, LOW);
  attachInterrupt(digitalPinToInterrupt(20), ekesme, LOW);
  if (!SD.begin(53)) {
    lcd.print("Sd kart hatasi");
    while (1);
  }
  if (EEPROM.read(200) == 123) {
    EEPROM.write(200, 0);
    h.gosterisure = EEPROM.get(150, h.gosterisure);
    isim = EEPROM.get(152, isim);
    h.sonkullanimkayit(isim, h.gosterisure);
    h.kayit(isim, h.gosterisure);
    lcd.print("kayit oldu");
    delay(500);
    lcd.clear();
  }
  if (EEPROM.read(0) != 0) {
    h.kotaliacma = EEPROM.read(0);
    EEPROM.write(0, 0);
    kota = EEPROM.get(1, kota);
    i = EEPROM.get(3, i);
    isim = EEPROM.get(5, isim);
  }
  h.display_menu(pencere, menuoption, sub, cursorline);
}
void loop() {
  if (lastkota != kota || cursorline != lastCount || lastVolume != volume || lastsifre != sifre ) {
    if (volumeHandler == true) {
      h.displayfatura(volume);
    }
    else if (sifrehandler == true) {
      h.displaysifre(sifre);
    }
    else if (kotahandler == true) {
      h.displaykota(kota);
    }
    else {
      h.display_menu(pencere, menuoption, sub, cursorline);
    }
    lastkota = kota;
    lastsifre = sifre;
    lastCount = cursorline;
    lastVolume = volume;
  }
  if ((!digitalRead(PUSHB))) {
    while (!digitalRead(PUSHB))
      delay(10);
    if (h.acma == false) {
      tone(buzzer, 4000, 50);
      if (volumeHandler == true) {
        volumeHandler = false;
        menuoption = 2;
        sub = 3;
        cursorline = 0;
        lcd.clear();
        lcd.setCursor(3, 1);
        lcd.print("Hesaplaniyor...");
        h.hesap(true, volume);
        lcd.clear();
        h.display_menu(pencere, menuoption, sub, cursorline);
      }
      else if (kotahandler == true) {
        kotahandler = false;
        if (kota >= 5) {
          detachInterrupt(digitalPinToInterrupt(PINA));
          attachInterrupt(digitalPinToInterrupt(21), kesme, LOW);
          h.kotaacma(isim);
        }
        else {
          lcd.clear();
          lcd.setCursor(1, 1);
          lcd.print("5DK'dan Az");
          lcd.setCursor(1, 2);
          lcd.print("Kullanim Suresi");
          delay(2000);
          returntomainmenu();
        }
      }
      else if (sifrehandler == true) {
        sifrehandler = false;
        if (sifre == 7) {
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print(F("Resetleniyor..."));
          h.reset();
          returntomainmenu();
        }
        else {
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print(F("Yanlis Sifre"));
          delay(2000);
          returntomainmenu();
        }
      }
      else if (menuoption == 1) {
        if (cursorline == 0) {
          sub = 1;
          menuoption = 2;
          lcd.clear();
          lcd.setCursor(3, 1);
          lcd.print("Hesaplaniyor...");
          h.hesap(false, volume);
          lcd.clear();
          h.display_menu(pencere, menuoption, sub, cursorline);
        }
        else if (cursorline == 1) {
          menuoption = 2;
          sub = 2;
          lcd.clear();
          lcd.setCursor(0, 2);
          lcd.print(F(">Geri"));
          data1 = SD.open("skul.txt");
          lcd.setCursor(0, 0);
          if (data1) {
            while (data1.available())
              lcd.write(data1.read());
          }
          data1.close();
          data1 = SD.open("skuls.txt");
          if (data1) {
            lcd.setCursor(0, 1);
            lcd.print(data1.parseInt());
            lcd.setCursor(15, 1);
            lcd.print("DK");
            data1.close();
          }
        }
        else if (cursorline == 2) {
          cursorline = 0;
          volumeHandler = true;
          h.displayfatura(volume);
        }
        else if (cursorline == 3) {
          sifrehandler = true;
          h.displaysifre(sifre);
        }
      }
      else if (menuoption == 2)
        returntomainmenu();

      else if (menuoption == 3) {
        lcd.clear();
        if (cursorline == 1) {
          kotahandler = true;
          h.displaykota(kota);
        }
        else {
          detachInterrupt(digitalPinToInterrupt(PINA));
          h.kotasizacma(isim);
        }
      }
    }
  }
  if (h.kotaliacma != 0) {
    if (h.acma == false) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Elektrikler Gitti");
      lcd.setCursor(0, 1);
      lcd.print("Bekleme Devrede");
      lcd.setCursor(0, 2);
      lcd.print("Acilmasina Kalan:");
      detachInterrupt(digitalPinToInterrupt(PINA));
      detachInterrupt(digitalPinToInterrupt(21));
      for (int bekleme = 2; bekleme > 0; bekleme--) {
        lcd.setCursor(0, 3);
        lcd.print("     ");
        lcd.setCursor(0, 3);
        lcd.print(bekleme);
        lcd.setCursor(15, 3);
        lcd.print("DK");
        delay(b6);
      }
      attachInterrupt(digitalPinToInterrupt(21), kesme, LOW);
      lcd.clear();
      h.kotaacma(isim);
    }
    else i=0;
    for (i; i < kota; i++) {
      int zaman = kota - i;
      lcd.setCursor(0, 3);
      lcd.print("     ");
      lcd.setCursor(0, 3);
      lcd.print(zaman);
      lcd.setCursor(15, 3);
      lcd.print("DK");
      delay(b6);
    }
    h.kotalikapatma(isim, kota);
    attachInterrupt(digitalPinToInterrupt(PINA), isr, LOW);
    kota = 0;
    returntomainmenu();
  }
  if (h.kotasizacmanum == true) {
    unsigned long gosterizamani = millis();
    h.gosterisure = (gosterizamani - h.acilmazamani) / b6;
    if (lastgosteri != h.gosterisure) {
      lcd.setCursor(0, 3);
      lcd.print("        ");
      lcd.setCursor(0, 3);
      lcd.print(h.gosterisure);
      lcd.setCursor(15, 3);
      lcd.print("DK");
    }
    lastgosteri = h.gosterisure;
  }
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if ( ! rfid.PICC_ReadCardSerial())
    return;
  tone(buzzer, 2000, 200);
  sifrehandler = false; kotahandler = false; volumeHandler = false;
  if (rfid.uid.uidByte[0] == ethem[0] &&
      rfid.uid.uidByte[1] == ethem[1] &&
      rfid.uid.uidByte[2] == ethem[2] &&
      rfid.uid.uidByte[3] == ethem[3] ) {
    if (menuoption == 3 && h.acma == false)
      returntomainmenu();
    if (h.acma == false) {
      menuoption = 3;
      cursorline = 1;
      isim = "Ethem";
      lcd.clear();
      h.displayacma(isim);
    }
    else {
      h.kotasizkapatma(isim);
      attachInterrupt(digitalPinToInterrupt(PINA), isr, LOW);
      returntomainmenu();
    }
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(F("Yetkisiz Kart"));
    delay(2000);
    returntomainmenu();
  }
  rfid.PICC_HaltA();
}

void returntomainmenu() {
  volume = 0; kota = 0; sifre = 0; menuoption = 1; cursorline = 0; pencere = 1; sub = 0,volumeHandler = false, sifrehandler = false, kotahandler = false;
  lcd.clear();
  h.display_menu(pencere, menuoption, sub, cursorline);
}

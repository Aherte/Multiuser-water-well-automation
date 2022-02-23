void ekesme() {
  if (h.acma == true) {
    detachInterrupt(digitalPinToInterrupt(20));
    h.acma = false;
    lcd.clear();
    if (h.kotaliacma != 0) {
      EEPROM.write(0, h.kotaliacma);
      EEPROM.put(1, kota);
      EEPROM.put(3, i);
      EEPROM.put(5, isim);
    }
    else if (h.kotasizacmanum == true) {
      EEPROM.write(200, 123);
      EEPROM.put(150, h.gosterisure);
      EEPROM.put(152, isim);
    }
  }
}

void kesme() {
    if (h.kotaliacma == 1) {
      h.kotaliacma=0;
      kota = i;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("kapaniyor...");
    }
  }
void isr ()  {
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime > 5) {
    if (digitalRead(PINB) == HIGH)
    {
      if (volumeHandler == true) {
        volume--;
      }
      if (sifrehandler == true) {
        sifre--;
      }
      if (kotahandler == true) {
          kota--;
      }
      //menu oynaması------------------------------------------
      else {
        if (sub == 3 || sub == 1) {
          if (pencere == 1) {
            if (cursorline == 3) {
              cursorline = 2;
            }
            else if (cursorline == 2) {
              cursorline = 1;
            }
            else if (cursorline == 1) {
              cursorline = 0;
            }
          }
          else if (pencere == 2) {
            if (cursorline == 0) {
              cursorline = 3;
              pencere = 1;
            }
            else if (cursorline == 2) {
              cursorline = 1;
            }
            else if (cursorline == 1) {
              cursorline = 0;
            }
          }
        }
        else if (sub == 2) {
        }
        //normal------------------------------------------------------
        else {
          if (menuoption == 3) {
            if (cursorline == 2) {
              cursorline = 1;
            }
          }
          else {
            if (cursorline == 3) {
              cursorline = 2;
            }
            else if (cursorline == 2) {
              cursorline = 1;
            }
            else if (cursorline == 1) {
              cursorline = 0;
            }
          }
        }
      }
    }
    // yukseltme---------------------------------------------
    else {
      if (kotahandler == true) {
        kota++;
      }
      if (volumeHandler == true) {
        volume = volume + 5;
      }
      if (sifrehandler == true) {
        sifre++;
      }
      //menu oynaması------------------------------------------
      else {
        if (sub == 3 || sub == 1) {
          if (pencere == 1) {
            if (cursorline == 3) {
              cursorline = 0;
              pencere = 2;
            }
            else if (cursorline == 2) {
              cursorline = 3;
            }
            else if (cursorline == 1) {
              cursorline = 2;
            }
            else if (cursorline == 0) {
              cursorline = 1;
            }
          }
          else if (pencere == 2) {
            if (cursorline == 0) {
              cursorline = 1;
            }
            else if (cursorline == 1) {
              cursorline = 2;
            }
          }
        }
        else if (sub == 2) {
        }
        //normal----------------------------------------
        else {
          if (menuoption == 3) {
            if (cursorline == 1) {
              cursorline = 2;
            }
          }
          else {
            if (cursorline == 0) {
              cursorline = 1;
            }
            else if (cursorline == 1) {
              cursorline = 2;
            }
            else if (cursorline == 2) {
              cursorline = 3;
            }
          }
        }
      }
    }
  }
  lastInterruptTime = interruptTime;
}

#include "header.h"
#ifndef ahmo
#define ahmo
class lcd1 lcdd(20, 4);
#endif
void he::displaykota(int kota) {
  lcdd.clear();
  lcdd.setCursor(0, 0);
  lcdd.print(F("Sureyi Giriniz"));
  lcdd.setCursor(0, 1);
  lcdd.print(kota);
  lcdd.setCursor(15, 1);
  lcdd.print("DK");
}
void he::displayfatura(int volume) {
  lcdd.clear();
  lcdd.setCursor(0, 0);
  lcdd.print(F("Faturayi Giriniz"));
  lcdd.setCursor(0, 1);
  lcdd.print(volume);
  lcdd.setCursor(15, 1);
  lcdd.print("TL");
}
void he::displaysifre(int sifre) {
  lcdd.clear();
  lcdd.setCursor(0, 0);
  lcdd.print(F("Sifreyi Giriniz"));
  lcdd.setCursor(0, 1);
  lcdd.print(sifre);
}
void he::display_menu(uint8_t pencere, uint8_t menuoption, uint8_t sub, uint8_t cursorline) {
  lcdd.setCursor(0, 0);
  lcdd.print(" ");
  lcdd.setCursor(0, 1);
  lcdd.print(" ");
  lcdd.setCursor(0, 2);
  lcdd.print(" ");
  lcdd.setCursor(0, 3);
  lcdd.print(" ");
  if (lastpencere != pencere)
    lcdd.clear();
  lastpencere = pencere;

  lcdd.setCursor(0, cursorline );
  lcdd.print(">");

  if (menuoption == 1) {
    lcdd.setCursor(1, 0);
    lcdd.print("Toplam Kullanim");
    lcdd.setCursor(1, 1);
    lcdd.print("Son Kullanim");
    lcdd.setCursor(1, 2);
    lcdd.print("Fatura Hesap");
    lcdd.setCursor(1, 3);
    lcdd.print("Reset(!)");
  }
  else if (menuoption == 2) {
    if (sub == 3) {
      if (pencere == 1) {
        lcdd.setCursor(1, 0);
        lcdd.print("Ethem:");
        lcdd.setCursor(7, 0);
        lcdd.print(ethem);
        lcdd.setCursor(18, 0);
        lcdd.print("TL");
        lcdd.setCursor(1, 1);
        lcdd.print("Adnan:");
        lcdd.setCursor(7, 1);
        lcdd.print(adnan);
        lcdd.setCursor(17, 1);
        lcdd.print("TL");
        lcdd.setCursor(1, 2);
        lcdd.print("Adnan Nur:");
        lcdd.setCursor(11, 2);
        lcdd.print(nur);
        lcdd.setCursor(18, 2);
        lcdd.print("TL");
        lcdd.setCursor(1, 3);
        lcdd.print("Huseyin:");
        lcdd.setCursor(9, 3);
        lcdd.print(huso);
        lcdd.setCursor(18, 3);
        lcdd.print("TL");
      }
      else {
        lcdd.setCursor(1, 0);
        lcdd.print("Mehmet Ali:");
        lcdd.setCursor(12, 0);
        lcdd.print(mali);
        lcdd.setCursor(18, 0);
        lcdd.print("TL");
        lcdd.setCursor(1, 1);
        lcdd.print("Muzaffer:");
        lcdd.setCursor(10, 1);
        lcdd.print(muzo);
        lcdd.setCursor(18, 1);
        lcdd.print("TL");
        lcdd.setCursor(1, 2);
        lcdd.print(F("Ana Menu"));
      }
    }
    else if (sub == 1) {
      if (pencere == 1) {
        lcdd.setCursor(1, 0);
        lcdd.print("Ethem:");
        lcdd.setCursor(8, 0);
        lcdd.print(ethem, 0);
        lcdd.setCursor(18, 0);
        lcdd.print("DK");
        lcdd.setCursor(1, 1);
        lcdd.print("Adnan:");
        lcdd.setCursor(8, 1);
        lcdd.print(adnan, 0);
        lcdd.setCursor(18, 1);
        lcdd.print("DK");
        lcdd.setCursor(1, 2);
        lcdd.print("Adnan Nur:");
        lcdd.setCursor(12, 2);
        lcdd.print(nur, 0);
        lcdd.setCursor(18, 2);
        lcdd.print("DK");
        lcdd.setCursor(1, 3);
        lcdd.print("Huseyin:");
        lcdd.setCursor(10, 3);
        lcdd.print(huso, 0);
        lcdd.setCursor(18, 3);
        lcdd.print("DK");
      }
      else if (pencere == 2) {
        lcdd.setCursor(1, 0);
        lcdd.print("Mehmet Ali:");
        lcdd.setCursor(13, 0);
        lcdd.print(mali, 0);
        lcdd.setCursor(18, 0);
        lcdd.print("DK");
        lcdd.setCursor(1, 1);
        lcdd.print("Muzaffer:");
        lcdd.setCursor(11, 1);
        lcdd.print(muzo, 0);
        lcdd.setCursor(18, 1);
        lcdd.print("DK");
        lcdd.setCursor(1, 2);
        lcdd.print(F("Ana Menu"));
      }
    }
  }
}
void he::displayacma(char *isim) {
  lcdd.setCursor(1, 1); lcdd.print(F("Sureli Kullanim"));
  lcdd.setCursor(1, 2); lcdd.print(F("Suresiz Kullanim"));
  lcdd.setCursor(1, 0); lcdd.print(F("Hosgeldin"));
  lcdd.setCursor(11, 0); lcdd.print(isim); lcdd.setCursor(0, 1 );
  lcdd.print(">");
}

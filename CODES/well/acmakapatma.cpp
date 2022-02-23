#include"header.h"
#ifndef ahmo3
#define ahmo3
class lcd1 lcd2(20, 4);
#endif
#define acmarolesi 3
#define kapamarolesi 5
void he::kotasizacma(char *isim) {
  if (!SD.begin(53)) {
    lcd2.print("Sd kart hatasi");
    while (1);
  }
  he::acma = true;
  he::kotasizacmanum = true;
  he::acilmazamani = millis();
  PORTE &= ~(1 << 5);
  delay(500);
  PORTE |= (1 << 5);
  delay(100);
  acmakayit(isim);
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print(F("Kuyu Calisiyor"));
  lcd2.setCursor(0, 1);
  lcd2.write(isim);
  lcd2.setCursor(0, 2);
  lcd2.print(F("Kullanim Suresi:"));
}
void he::kotaacma(char *isim) {
  if (!SD.begin(53)) {
    lcd2.print("Sd kart hatasi");
    while (1);
  }
  he::acma = true;
  he::kotaliacma = 1;
  he::acilmazamani = millis();
  PORTE &= ~(1 << 5);
  delay(500);
  PORTE |= (1 << 5);
  delay(100);
  acmakayit(isim);
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print(F("Kuyu Calisiyor"));
  lcd2.setCursor(0, 1);
  lcd2.write(isim);
  lcd2.setCursor(0, 2);
  lcd2.print(F("Kalan Sure:"));

}
void he::kotasizkapatma(char *isim) {
  he::kotasizacmanum = false;
  he::acma = false;
  PORTE &= ~(1 << 3);
  delay(500);
  PORTE |= (1 << 3);
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print(F("Kuyu Kapandi"));
  lcd2.setCursor(0, 1);
  lcd2.write(isim);
  lcd2.setCursor(0, 2);
  lcd2.print(F("Kullanim Suresi:"));
  lcd2.setCursor(0, 3);
  lcd2.print(he::gosterisure);
  lcd2.setCursor(15, 3);
  lcd2.print("DK");
  he::sonkullanimkayit(isim, he::gosterisure);
  he::kayit(isim, he::gosterisure);
  delay(2000);
  lcd2.clear();
  lcd2.setCursor(2, 1);
  lcd2.print(F("Kayit oldu"));
  delay(1000);
}
void he::kotalikapatma(char *isim, int kota) {
  detachInterrupt(digitalPinToInterrupt(21));
  he::acma = false;
  he::kotaliacma = 0;
  PORTE &= ~(1 << 3);
  delay(500);
  PORTE |= (1 << 3);
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print(F("Kuyu Kapandi"));
  lcd2.setCursor(0, 1);
  lcd2.write(isim);
  lcd2.setCursor(0, 2);
  lcd2.print(F("Kullanim Suresi:"));
  lcd2.setCursor(0, 3);
  lcd2.print(kota);
  lcd2.setCursor(15, 3);
  lcd2.print("DK");
  he::sonkullanimkayit(isim, kota);
  he::kayit(isim, kota);
  delay(2000);
  lcd2.clear();
  lcd2.setCursor(2, 1);
  lcd2.print(F("Kayit oldu"));
  delay(1000);
}

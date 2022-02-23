#include "header.h"
#ifndef ahmo1
#define ahmo1
File data2;
#endif

void he::hesap(bool hesapd,int volume) {
   ethem = 0, nur = 0, adnan = 0, mali = 0, huso = 0, muzo = 0;
  data2 = SD.open("Nur1.txt");
  if (data2) {
    while (data2.available()) 
      nur += data2.parseInt();   
    data2.close();
  }
  data2 = SD.open("Mali1.txt");
  if (data2) {
    while (data2.available()) 
      mali += data2.parseInt();    
    data2.close();
  }
  data2 = SD.open("Adnan1.txt");
  if (data2) {
    while (data2.available()) 
      adnan += data2.parseInt();   
    data2.close();
  }
  data2 = SD.open("Huso1.txt");
  if (data2) {
    while (data2.available()) 
     huso += data2.parseInt();
    data2.close();
  }
  data2 = SD.open("Ethem1.txt");
  if (data2) {
    while (data2.available()) 
      ethem += data2.parseInt();    
    data2.close();
  }
  data2 = SD.open("Muzo1.txt");
  if (data2) {
    while (data2.available()) 
      muzo += data2.parseInt();
    data2.close();
  }
  if(hesapd==true){
    int  toplam =  ethem + adnan + huso + muzo + mali + nur ;
    muzo = toplam / muzo; ethem = toplam / ethem; nur = toplam / nur; mali = toplam / mali; huso = toplam / huso; adnan = toplam / adnan;

    muzo = volume / muzo;
    adnan = volume / adnan;
    ethem = volume / ethem;
    nur = volume / nur;
    huso = volume / huso;
    mali = volume / mali;
  }
}
void he::reset() {
  SD.remove("Ethem1.txt");SD.remove("Mali1.txt");SD.remove("Muzo1.txt");SD.remove("Adnan1.txt");SD.remove("Nur1.txt");SD.remove("Huso1.txt");
  SD.remove("skul.txt");
  SD.remove("skuls.txt");
  data2 = SD.open("Ethem.txt", FILE_WRITE);
  if (data2) {
    data2.println("Yeni Donem");
    data2.println("------------------------------------");
    data2.close();
  }
    data2 = SD.open("Mali.txt", FILE_WRITE);
  if (data2) {
    data2.println("Yeni Donem");
    data2.println("------------------------------------");
    data2.close();
  }
    data2 = SD.open("Muzo.txt", FILE_WRITE);
  if (data2) {
    data2.println("Yeni Donem");
    data2.println("------------------------------------");
    data2.close();
  }
    data2 = SD.open("Adnan.txt", FILE_WRITE);
  if (data2) {
    data2.println("Yeni Donem");
    data2.println("------------------------------------");
    data2.close();
  }
    data2 = SD.open("Nur.txt", FILE_WRITE);
  if (data2) {
    data2.println("Yeni Donem");
    data2.println("------------------------------------");
    data2.close();
  }
    data2 = SD.open("Huso.txt", FILE_WRITE);
  if (data2) {
    data2.println("Yeni Donem");
    data2.println("------------------------------------");
    data2.close();
  }
  delay(2000);
}

#include"header.h"
#include <virtuabotixRTC.h>
#ifndef ahmo2
#define ahmo2
virtuabotixRTC myRTC(6, 7, 8);
File data;
#endif
void he::sonkullanimkayit(char *c, int sure) {
  SD.remove("skul.txt");
  SD.remove("skuls.txt");
  delay(50);
    data = SD.open("skul.txt", FILE_WRITE);
    if (data) {
      data.print(c);
      data.close();
    }
    data = SD.open("skuls.txt", FILE_WRITE);
    if (data) {
      data.println(sure);
      data.close();
    }
}
void he::kayit(char *isim, int sure) {
  if (isim == "Ethem") {
    data = SD.open("Ethem1.txt", FILE_WRITE);
    if (data) {
      data.println(sure);
      data.close();
    }
    data = SD.open("Ethem.txt", FILE_WRITE);
    if (data) {
      data.print("kullanim suresi:");
      data.println(sure);
      data.println("Kapatma:");
      saat();
      data.println("------------------------------------");
      data.close();
    }
  }
}
void he::acmakayit(char *isim){
  if (isim == "Ethem") {
      data = SD.open("Ethem.txt", FILE_WRITE);
    if (data) { 
      data.println("Acma:");     
      he::saat();
      data.close();
    }
  }
}
void he::saat() {
  myRTC.updateTime();
  data.print("  Tarih / Saat:  ");
  data.print(myRTC.dayofmonth);
  data.print("/");
  data.print(myRTC.month);
  data.print("/");
  data.print(myRTC.year);
  data.print(" ");
  data.print(myRTC.hours);
  data.print(":");
  data.print(myRTC.minutes);
  data.print(":");
  data.println(myRTC.seconds);
}

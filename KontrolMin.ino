#include "KontrolMin.h"

KontrolMin kontrol = KontrolMin();

void setup(){
  Serial.begin(115200);
  delay(2000);
}//SETUP

void loop(){
  ////////////////////////////////
  //Updating//
  if(Serial.available()){
    kontrol.update(Serial.read());
  }
  //Listeners//
  kontrol.addListener("fv",functionVoid); //send {fv} through serial
  kontrol.addListener("fs",functionChar); //send {fs:prueba} through serial
  kontrol.addListener("fb",functionBoolean); //send {fb:0} through serial
  kontrol.addListener("fi",functionInt); //send {fi:12} through serial
  kontrol.addListener("ff",functionFloat); //send {ff:3.1415} through serial
  ////////////////////////////////
}//LOOP

/////////////
//callbacks//
/////////////
void functionVoid(){
  Serial.println(F("Function without arguments"));
}
void functionChar(char arg[]){
  Serial.print(F("Function with argument String: "));
  Serial.println(arg);
}
void functionBoolean(bool arg){
  Serial.print(F("Function with argument boolean: "));
  Serial.println(arg);
}
void functionInt(int arg){
  Serial.print(F("Function with argument int: "));
  Serial.println(arg);
}
void functionFloat(float arg){
  Serial.print(F("Function with argument float: "));
  Serial.println(arg,5);
}

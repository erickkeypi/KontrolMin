#include <KontrolMin.h>

KontrolMin kontrol = KontrolMin();

void setup(){
  Serial.begin(9600);
}//SETUP

void loop(){
  ////////////////////////////////
  //Updating//
  if(Serial.available()>0){
    kontrol.update(Serial.read());
  }
  //Listeners//
  kontrol.addListener("fv",functionTemplate);//Delete this listener and add yours
  ////////////////////////////////

  //Add your code here

}//LOOP

/////////////
//callbacks//
/////////////
void functionTemplate(){//Delete this function and add yours
  Serial.println(F("Template"));
}

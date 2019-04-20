/*
kontrolMin library
Is part of a personal project
Can be used to control an arduino with simple strings commands
Supports value arguments sent along with the command

Written by Erick Rafael Garcia Martinez
Magneto license (π) 3000BC-3000AC. All wrigths reserved
last revision april/19/2019
*/

#include "Arduino.h"

class KontrolMin {

private:
  String data;
  char endTransmitionCharacter;
  boolean recibiendo, recibido;

public:
  KontrolMin();
  void update(char);
  String getData();
  void addListener(String,void(fc)(void));
  void addListener(String,void(fc)(String));
  void addListener(String,void(fc)(boolean));
  void addListener(String,void(fc)(int));
  void addListener(String,void(fc)(long));
  void addListener(String,void(fc)(float));
  void setEndTransmitionCharacter(char);
  void flush();
};

/*
Copyright 2019 Erick Rafael Garcia Martinez

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

last revision april/19/2019
*/

#ifndef _KONTROL_MIN_H
#define _KONTROL_MIN_H
#include "Arduino.h"

class KontrolMin {

private:
  char data[100];
  char command[20];
  char arg[80];
  bool recibiendo, recibido;
  bool compareCommand(char[],int,int);
  void extractArgs(int,int);
  int index1,index2, index3;

public:
  KontrolMin();
  void update(char);
  void addListener(char[],void(fc)(void));
  void addListener(char[],void(fc)(int));
  void addListener(char[],void(fc)(unsigned int));
  void addListener(char[],void(fc)(bool));
  void addListener(char[],void(fc)(float));
  void addListener(char[],void(fc)(String));
  void addListener(char[],void(fc)(char[]));

  char* indication(char[]);
  // String indication(String);
  // String indication(String,String);
  // String indication(String,boolean);
  // String indication(String,int);
  // String indication(String,unsigned int);
  // String indication(String,long);
  // String indication(String,unsigned long);
  // String indication(String,float);
  void flush();
};
#endif

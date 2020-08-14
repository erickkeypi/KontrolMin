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
  char indi[100];
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

  char *indication(char[]);
  char *indication(char[],char[]);
  char *indication(char[],bool);
  char *indication(char[],int);
  char *indication(char[],unsigned int);
  char *indication(char[],float);
  void flush();
};
#endif

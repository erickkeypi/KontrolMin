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
  String data;
  boolean recibiendo, recibido;

public:
  KontrolMin();
  void update(char);
  String getData();
  void addListener(String,void(fc)(void));
  void addListener(String,void(fc)(String));
  void addListener(String,void(fc)(boolean));
  void addListener(String,void(fc)(int));
  void addListener(String,void(fc)(unsigned int));
  void addListener(String,void(fc)(long));
  void addListener(String,void(fc)(unsigned long));
  void addListener(String,void(fc)(float));
  String indication(String);
  String indication(String,String);
  String indication(String,boolean);
  String indication(String,int);
  String indication(String,unsigned int);
  String indication(String,long);
  String indication(String,unsigned long);
  String indication(String,float);
  void flush();
};
#endif

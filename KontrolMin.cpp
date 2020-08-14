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

#include "KontrolMin.h"

KontrolMin::KontrolMin(){//INICIALIZADOR
  flush();
  recibiendo = false;
  recibido = false;
}

void KontrolMin::update(char s){
  static int index =0;
  if(!recibiendo){
    recibiendo=true;
    recibido=false;
    flush();
    index=0;
    index1 = index2 = index3 = -1;
  }

  if(recibiendo){
    data[index]=s;

    if(s=='{'){
      index1=index;
    }
    if(s==':'){
      index2=index;
    }
    if(s=='}'){
      index3=index;
    }

    index++;
  }

  if(s == '}' || index >=100){
    recibiendo=false;
    recibido = true;
  }
}

bool KontrolMin::compareCommand(char _etiqueta[],int _o1, int _o2){//comparacion de comando
  char *d=strchr(data,'{');//inicio del comando
  d++;
  strncpy(command,d,_o2-_o1);//copiamos el comando
  command[_o2-_o1-1]=0;
  bool res = strcmp(command,_etiqueta)==0;
  command[0]=0;
  return res;
}

void KontrolMin::extractArgs(int _o2, int _o3){
  char *d=strchr(data,':');//inicio del comando
  d++;
  strncpy(arg,d,_o3-_o2);//copiamos el comando
  arg[_o3-_o2-1]=0;
}

void KontrolMin::addListener(char _etiqueta[], void(fc)(void)){
  if(recibido){
    if(index1 != -1 && index3 != -1){
      if(compareCommand(_etiqueta,index1,index3)){
        fc();
        flush();
      }
    }
  }
}

void KontrolMin::addListener(char _etiqueta[], void(fc)(int)){
    if(recibido){
    if(index1 != -1 && index2 != -1 && index3 != -1){
      if(compareCommand(_etiqueta,index1,index2)){
        extractArgs(index2,index3);
        fc(atoi(arg));
        flush();
      }
    }
  }
}

void KontrolMin::addListener(char _etiqueta[], void(fc)(unsigned int)){
  if(recibido){
    if(index1 != -1 && index2 != -1 && index3 != -1){
      if(compareCommand(_etiqueta,index1,index2)){
        extractArgs(index2,index3);
        fc(atoi(arg));
        flush();
      }
    }
  }
}

void KontrolMin::addListener(char _etiqueta[], void(fc)(bool)){
  if(recibido){
    if(index1 != -1 && index2 != -1 && index3 != -1){
      if(compareCommand(_etiqueta,index1,index2)){
        extractArgs(index2,index3);
        fc(atoi(arg));
        flush();
      }
    }
  }
}

void KontrolMin::addListener(char _etiqueta[], void(fc)(float)){
  if(recibido){
    if(index1 != -1 && index2 != -1 && index3 != -1){
      if(compareCommand(_etiqueta,index1,index2)){
        extractArgs(index2,index3);
        fc(atof(arg));
        flush();
      }
    }
  }
}

void KontrolMin::addListener(char _etiqueta[], void(fc)(String)){
  if(recibido){
    if(index1 != -1 && index2 != -1 && index3 != -1){
      if(compareCommand(_etiqueta,index1,index2)){
        extractArgs(index2,index3);
        fc(arg);
        flush();
      }
    }
  }
}

void KontrolMin::addListener(char _etiqueta[], void(fc)(char[])){
  if(recibido){
    if(index1 != -1 && index2 != -1 && index3 != -1){
      if(compareCommand(_etiqueta,index1,index2)){
        extractArgs(index2,index3);
        fc(arg);
        flush();
      }
    }
  }
}

char *KontrolMin::indication(char _etiqueta[]){
  indi[0]=0;
  strcat(indi,"{");
  strcat(indi,_etiqueta);
  strcat(indi,"}");
  return indi;
}

char *KontrolMin::indication(char _etiqueta[], char _arg[]){
  indi[0]=0;
  strcat(indi,"{");
  strcat(indi,_etiqueta);
  strcat(indi,":");
  strcat(indi,_arg);
  strcat(indi,"}");
  return indi;
}

char *KontrolMin::indication(char _etiqueta[], bool _arg){
  char buff[3];
  indi[0]=0;
  strcat(indi,"{");
  strcat(indi,_etiqueta);
  strcat(indi,":");
  itoa(_arg,buff,10);
  strcat(indi,buff);
  strcat(indi,"}");
  return indi;
}

char *KontrolMin::indication(char _etiqueta[], int _arg){
  char buff[12];
  indi[0]=0;
  strcat(indi,"{");
  strcat(indi,_etiqueta);
  strcat(indi,":");
  itoa(_arg,buff,10);
  strcat(indi,buff);
  strcat(indi,"}");
  return indi;
}

char *KontrolMin::indication(char _etiqueta[], unsigned int _arg){
  char buff[12];
  indi[0]=0;
  strcat(indi,"{");
  strcat(indi,_etiqueta);
  strcat(indi,":");
  utoa(_arg,buff,10);
  strcat(indi,buff);
  strcat(indi,"}");
  return indi;
}

char *KontrolMin::indication(char _etiqueta[], float _arg){
  char buff[12];
  indi[0]=0;
  strcat(indi,"{");
  strcat(indi,_etiqueta);
  strcat(indi,":");
  sprintf(buff,"%f",_arg);
  strcat(indi,buff);
  strcat(indi,"}");
  return indi;
}

void KontrolMin::flush(){
  for (int i=0;i<100;i++){
    data[i]=0;
  }
  recibido = false;
}

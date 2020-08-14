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
  }

  if(recibiendo){
    data[index]=s;
    index++;
  }

  if(s == '}'){
    recibiendo=false;
    recibido = true;
    Serial.print(F("Recibido: "));
    for (int i=0;i<100;i++){
      Serial.print(data[i]);
    }
    Serial.println();
  }
}

void KontrolMin::addListener(char _etiqueta[], void(fc)(void)){
  if(recibido){
    int o1 = -1;
    int o2 = -1;
    for(int i=0;i<100;i++){
      if(data[i] == '{'){
        o1=i;
      }
      if(data[i] == '}'){
        o2=i;
      }
    }
    char *d=strchr(data,'{');
    d++;
    d[o2-o1-1]=0;
    Serial.println(d);
    while(1);
    if(o1 != -1 && o2 != -1){
      // Serial.println(data.substring(o1,o2-o1));
      // if(data.substring(o1+1,o2) == etiqueta){
      //   fc();
      //   data.remove(o1,o2-o1+1);
      // }
    }
  }
}

// void KontrolMin::addListener(String etiqueta, void(fc)(String)){
//   if(recibido){
//     int o1 = data.indexOf('{');
//     int o2 = data.indexOf(':');
//     int o3 = data.indexOf('}');
//     if(o1 != -1 && o2 != -1 && o3 != -1){
//       if(data.substring(o1+1,o2) == etiqueta){
//         String datos = data.substring(o2+1,o3);
//         data.remove(o1,o3-o1+1);
//         fc(datos);
//       }
//     }
//   }
// }
//
// void KontrolMin::addListener(String etiqueta, void(fc)(int)){
//   if(recibido){
//     int o1 = data.indexOf('{');
//     int o2 = data.indexOf(':');
//     int o3 = data.indexOf('}');
//     if(o1 != -1 && o2 != -1 && o3 != -1){
//       if(data.substring(o1+1,o2) == etiqueta){
//         int datos = data.substring(o2+1,o3).toInt();
//         data.remove(o1,o3-o1+1);
//         fc(datos);
//       }
//     }
//   }
// }
//
// void KontrolMin::addListener(String etiqueta, void(fc)(unsigned int)){
//   if(recibido){
//     int o1 = data.indexOf('{');
//     int o2 = data.indexOf(':');
//     int o3 = data.indexOf('}');
//     if(o1 != -1 && o2 != -1 && o3 != -1){
//       if(data.substring(o1+1,o2) == etiqueta){
//         int datos = data.substring(o2+1,o3).toInt();
//         data.remove(o1,o3-o1+1);
//         fc(datos);
//       }
//     }
//   }
// }
//
// void KontrolMin::addListener(String etiqueta, void(fc)(long)){
//   if(recibido){
//     int o1 = data.indexOf('{');
//     int o2 = data.indexOf(':');
//     int o3 = data.indexOf('}');
//     if(o1 != -1 && o2 != -1 && o3 != -1){
//       if(data.substring(o1+1,o2) == etiqueta){
//         long datos = data.substring(o2+1,o3).toInt();
//         data.remove(o1,o3-o1+1);
//         fc(datos);
//       }
//     }
//   }
// }
//
// void KontrolMin::addListener(String etiqueta, void(fc)(unsigned long)){
//   if(recibido){
//     int o1 = data.indexOf('{');
//     int o2 = data.indexOf(':');
//     int o3 = data.indexOf('}');
//     if(o1 != -1 && o2 != -1 && o3 != -1){
//       if(data.substring(o1+1,o2) == etiqueta){
//         long datos = data.substring(o2+1,o3).toInt();
//         data.remove(o1,o3-o1+1);
//         fc(datos);
//       }
//     }
//   }
// }
//
// void KontrolMin::addListener(String etiqueta, void(fc)(float)){
//   if(recibido){
//     int o1 = data.indexOf('{');
//     int o2 = data.indexOf(':');
//     int o3 = data.indexOf('}');
//     if(o1 != -1 && o2 != -1 && o3 != -1){
//       if(data.substring(o1+1,o2) == etiqueta){
//         float datos = data.substring(o2+1,o3).toFloat();
//         data.remove(o1,o3-o1+1);
//         fc(datos);
//       }
//     }
//   }
// }
//
// void KontrolMin::addListener(String etiqueta, void(fc)(boolean)){
//   if(recibido){
//     int o1 = data.indexOf('{');
//     int o2 = data.indexOf(':');
//     int o3 = data.indexOf('}');
//     if(o1 != -1 && o2 != -1 && o3 != -1){
//       if(data.substring(o1+1,o2) == etiqueta){
//         boolean datos = data.substring(o2+1,o3).toInt();
//         data.remove(o1,o3-o1+1);
//         fc(datos);
//       }
//     }
//   }
// }
//
// String KontrolMin::indication(String etiqueta){
//   return "{" + etiqueta + "}";
// }
//
// String KontrolMin::indication(String etiqueta,String variable){
//   return "{" + etiqueta + ":" + variable + "}";
// }
//
// String KontrolMin::indication(String etiqueta,int variable){
//   return "{" + etiqueta + ":" + variable + "}";
// }
//
// String KontrolMin::indication(String etiqueta,unsigned int variable){
//   return "{" + etiqueta + ":" + variable + "}";
// }
//
// String KontrolMin::indication(String etiqueta,long variable){
//   return "{" + etiqueta + ":" + variable + "}";
// }
//
// String KontrolMin::indication(String etiqueta,unsigned long variable){
//   return "{" + etiqueta + ":" + variable + "}";
// }
//
// String KontrolMin::indication(String etiqueta,boolean variable){
//   return "{" + etiqueta + ":" + variable + "}";
// }
//
// String KontrolMin::indication(String etiqueta,float variable){
//   return "{" + etiqueta + ":" + variable + "}";
// }
//
void KontrolMin::flush(){
  for (int i=0;i<100;i++){
    data[i]=0;
  }
  recibido = false;
}
//
// char* KontrolMin::getData(){
//   return data;
// }
//

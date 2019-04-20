#include "KontrolMin.h"

KontrolMin::KontrolMin(){
  // data.reserve(20);
  data ="";
  recibiendo = false;
  recibido = false;
  endTransmitionCharacter = '\n';
}

void KontrolMin::update(char s){
  if(!recibiendo){
    recibiendo=true;
    recibido=false;
    data ="";
  }

  if(recibiendo){
    data += s;
  }

  if(s == endTransmitionCharacter){
    recibiendo=false;
    recibido = true;
  }
}

String KontrolMin::getData(){
  return data;
}

void KontrolMin::addListener(String etiqueta, void(fc)(void)){
  if(recibido){
    int o1 = data.indexOf('{');
    int o2 = data.indexOf('}');
    if(o1 != -1 && o2 != -1){
      if(data.substring(o1+1,o2) == etiqueta){
        fc();
        data.remove(o1,o2-o1+1);
      }
    }
  }
}

void KontrolMin::addListener(String etiqueta, void(fc)(String)){
  if(recibido){
    int o1 = data.indexOf('{');
    int o2 = data.indexOf(':');
    int o3 = data.indexOf('}');
    if(o1 != -1 && o2 != -1 && o3 != -1){
      if(data.substring(o1+1,o2) == etiqueta){
        String datos = data.substring(o2+1,o3);
        data.remove(o1,o3-o1+1);
        fc(datos);
      }
    }
  }
}

void KontrolMin::addListener(String etiqueta, void(fc)(int)){
  if(recibido){
    int o1 = data.indexOf('{');
    int o2 = data.indexOf(':');
    int o3 = data.indexOf('}');
    if(o1 != -1 && o2 != -1 && o3 != -1){
      if(data.substring(o1+1,o2) == etiqueta){
        int datos = data.substring(o2+1,o3).toInt();
        data.remove(o1,o3-o1+1);
        fc(datos);
      }
    }
  }
}

void KontrolMin::addListener(String etiqueta, void(fc)(long)){
  if(recibido){
    int o1 = data.indexOf('{');
    int o2 = data.indexOf(':');
    int o3 = data.indexOf('}');
    if(o1 != -1 && o2 != -1 && o3 != -1){
      if(data.substring(o1+1,o2) == etiqueta){
        long datos = data.substring(o2+1,o3).toInt();
        data.remove(o1,o3-o1+1);
        fc(datos);
      }
    }
  }
}

void KontrolMin::addListener(String etiqueta, void(fc)(float)){
  if(recibido){
    int o1 = data.indexOf('{');
    int o2 = data.indexOf(':');
    int o3 = data.indexOf('}');
    if(o1 != -1 && o2 != -1 && o3 != -1){
      if(data.substring(o1+1,o2) == etiqueta){
        float datos = data.substring(o2+1,o3).toFloat();
        data.remove(o1,o3-o1+1);
        fc(datos);
      }
    }
  }
}

void KontrolMin::addListener(String etiqueta, void(fc)(boolean)){
  if(recibido){
    int o1 = data.indexOf('{');
    int o2 = data.indexOf(':');
    int o3 = data.indexOf('}');
    if(o1 != -1 && o2 != -1 && o3 != -1){
      if(data.substring(o1+1,o2) == etiqueta){
        boolean datos = data.substring(o2+1,o3).toInt();
        data.remove(o1,o3-o1+1);
        fc(datos);
      }
    }
  }
}

void KontrolMin::setEndTransmitionCharacter(char l){
  endTransmitionCharacter = l;
}

void KontrolMin::flush(){
  data="";
  recibido = false;
}

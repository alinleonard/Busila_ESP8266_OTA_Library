/*
  Busila_OTA.h - Library for esp8266 OTA
  Created by Alin Busila, February 24, 2018
*/
#ifndef BusilaOTA_h
#define BusilaOTA_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class Busila_OTA
{
  public:
    Busila_OTA(int pin);
    void begin(const char* host);
    void handle();
  private:
    int _pin;
};

#endif

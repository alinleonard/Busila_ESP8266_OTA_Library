/*
  Busila_OTA.cpp - Library for esp8266 OTA
  Created by Alin Busila, February 24, 2018
*/

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "Busila_OTA.h"

#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

Busila_OTA::Busila_OTA(int pin)
{
  _pin = pin;
}

void Busila_OTA::begin(const char* host)
{
  MDNS.begin(host);

  httpUpdater.setup(&httpServer);
  httpServer.begin();

  MDNS.addService("http", "tcp", 80);
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);
}

void Busila_OTA::handle()
{
  httpServer.handleClient();
}

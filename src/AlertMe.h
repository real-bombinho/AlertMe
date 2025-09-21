/*
	AlertMe.h - Library for sending emails and SMS from the ESP8266!
	Created by Connor Nishijima, October 14th 2017.
	Released under the GPLv3 license.
*/

#ifndef alertme_h
#define alertme_h

#include <FS.h>                   //this needs to be first, or it all crashes and burns...
#include "Arduino.h"
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>          //https://github.com/bblanchon/ArduinoJson

static const char ErrorSendingMessage[]   PROGMEM = "Sending message error";
static const char ErrorSMTPQuit[]         PROGMEM = "SMTP QUIT error";
static const char ErrorNotConnected[]     PROGMEM = "Could not connect to mail server";
static const char ErrorConnection[]       PROGMEM = "Connection Error";
static const char ErrorIdentification[]   PROGMEM = "Identification error";
static const char ErrorAuthentification[] PROGMEM = "SMTP AUTH error";
static const char ErrorSMTPData[]         PROGMEM = "SMTP DATA error";
static const char ErrorNotSent[]          PROGMEM = "Sending message error";
static const char ErrorSMTPTimeout[]      PROGMEM = "SMTP Response TIMEOUT!";

class AlertMe{
	public:
		AlertMe();
		void connect(bool debug_wifi = false);
		const char* send(String subject, String message, String dest);
		const char* get_error();
		void debug(bool enabled);
		void config();
		void reset(bool format = false);
	private:
		void conn_network(bool retry = false);
};

#endif

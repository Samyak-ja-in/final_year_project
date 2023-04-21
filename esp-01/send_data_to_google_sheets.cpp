/*
 * BasicHTTPSClient.ino
 * Created on: 20.08.2018
 * This code has been modified to upload data to google sheets.
 * Software used: Arduino IDE
 * Haedware used: ESP_01 wifi module
 */

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

const uint8_t fingerprint[20] = { 0x5B, 0x0D, 0xB2, 0x44, 0x6B, 0xF9, 0x6C, 0x29, 0xA2, 0xEC, 0xE9, 0x13, 0xEE, 0x79, 0xFF, 0xC4, 0x25, 0xE9, 0x2C, 0x8D };

ESP8266WiFiMulti WiFiMulti;

void setup() {

  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  
  /*This SSID and PASSWORD are needed to be modified according to the network*/
  WiFiMulti.addAP("Radinet 2.4GH", "sonalkunj@123");
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);

    client->setFingerprint(fingerprint);
    // Or, if you happy to ignore the SSL certificate, then use the following line instead:
    // client->setInsecure();

    HTTPClient https;

    Serial.print("[HTTPS] begin...\n");
    if (https.begin(*client, "https://script.google.com/macros/s/AKfycbxYKy3VymRtRWi3pDplayFI6sHATCZvNjY0lbXcWrfOKPynLXIvAqqNh4_9tRzm0R_u2A/exec?tag=adc_A0&value=2009")) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }

  Serial.println("Wait 10s before next round...");
  delay(10000);
}


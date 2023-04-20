/*************************************************************
  This code is modified by Tushar Gupta to control humanoid robot.
  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
// #define BLYNK_TEMPLATE_ID           "TMPL4YDhDmWO"
// #define BLYNK_TEMPLATE_NAME         "Quickstart Template"

// #define BLYNK_AUTH_TOKEN            "6RcPTylByNcVNLxP6h-KMgW_N1BL-Cgl"
// #define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_TEMPLATE_ID "TMPL3cfhP1HIO"
#define BLYNK_TEMPLATE_NAME "Humanoid Robot"
#define BLYNK_AUTH_TOKEN "96H2QjCyznJ9MXyg9rZrXX3l4ESdYvfT"
// #define BLYNK_TEMPLATE_ID "TMPL3cfhP1HIO"
// #define BLYNK_TEMPLATE_NAME "Humanoid Robot"
// #define BLYNK_AUTH_TOKEN "6RcPTylByNcVNLxP6h-KMgW_N1BL-Cgl"
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define GPIO_2 2

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Tenda_FD1A70";
char pass[] = "";

BlynkTimer timer;

// Attach virtual serial terminal to Virtual Pin V10
WidgetTerminal terminal(V10);

// You can send commands from Terminal to your hardware. Just use
// the same Virtual Pin as your Terminal Widget
BLYNK_WRITE(V0)
{
  String value = param.asStr();
  terminal.println(value);
  Serial.println(value);
  // Ensure everything is sent
  terminal.flush();
}

BLYNK_WRITE(V1)
{
  // Set incoming value from pin V1 to a variable
  int value = param.asInt();
  
  // Update state
  Serial.println(value);
  Blynk.virtualWrite(V1, value);
  //digitalWrite(GPIO_2, 0 ^ value);
}

BLYNK_WRITE(V2)
{
  // Set incoming value from pin V2 to a variable
  int value = param.asInt();
  
  // Update state
  Serial.println(value);
  Blynk.virtualWrite(V2, value);
  //digitalWrite(GPIO_2, 0 ^ value);
}

BLYNK_WRITE(V3)
{
  // Set incoming value from pin V3 to a variable
  int value = param.asInt();
  
  // Update state
  Serial.println(value);
  Blynk.virtualWrite(V3, value);
  //digitalWrite(GPIO_2,0 ^ value);
}

BLYNK_WRITE(V4)
{
  // Set incoming value from pin V4 to a variable
  int value = param.asInt();
  
  // Update state
  Serial.println(value);
  Blynk.virtualWrite(V4, value);
  //digitalWrite(GPIO_2,0 ^ value);
}

BLYNK_WRITE(V5)
{
  // Set incoming value from pin V5 to a variable
  int value = param.asInt();
  
  // Update state
  Serial.println(value);
  Blynk.virtualWrite(V5, value);
  //digitalWrite(GPIO_2,0 ^ value);
}

BLYNK_WRITE(V6)
{
  // Set incoming value from pin V6 to a variable
  int value = param.asInt();
  
  // Update state
  Serial.println(value);
  Blynk.virtualWrite(V6, value);
  //digitalWrite(GPIO_2,0 ^ value);
}

BLYNK_WRITE(V7)
{
  // Set incoming value from pin V7 to a variable
  int value = param.asInt();
  
  // Update state
  Serial.println(value);
  Blynk.virtualWrite(V7, value);
  //digitalWrite(GPIO_2, 0 ^ value);
}

BLYNK_WRITE(V8)
{
  // Set incoming value from pin V8 to a variable
  int value = param.asInt();
  
  // Update state
  Serial.println(value);
  Blynk.virtualWrite(V8, value);
  //digitalWrite(GPIO_2, 0 ^ value);
}

BLYNK_WRITE(V9)
{
  // Set incoming value from pin V9 to a variable
  int value = param.asInt();

  // Update state
  Serial.println(value);
  Blynk.virtualWrite(V9, value);
  //digitalWrite(GPIO_2, 0 ^ value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
  //pinMode(2, OUTPUT);
}

void loop()
{
  Blynk.run();
  timer.run();
  //Serial.println(robot_cmd);
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

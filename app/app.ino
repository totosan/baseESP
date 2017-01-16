#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <SPI.h>

#include <ESP8266WiFi.h>

static int LED = LED_BUILTIN;
static char* ssid="";
static char* pass="";
void setup()
{
    pinMode(LED,OUTPUT);
}

void loop()
{
}

void initSerial()
{
    // Start serial and initialize stdout
    Serial.begin(115200);
    Serial.setDebugOutput(true);
}

void initWifi()
{

    // check for the presence of the shield :
    if (WiFi.status() == WL_NO_SHIELD)
    {
        Serial.println("WiFi shield not present");
        // don't continue:
        while (true)
            ;
    }

    // attempt to connect to Wifi network:
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);

connect:
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    if (WiFi.status() != WL_CONNECTED)
    {                               // FIX FOR USING 2.3.0 CORE (only .begin if not connected)
        WiFi.begin(ssid, pass); // connect to the network
    }
    int count=0;
    for (count = 0; count < 20; count++)
    {
        delay(500);
        toggleLED();
        int wifi_stat = WiFi.status();
        Serial.print(count);
        Serial.print(" WifiStat: ");
        Serial.println(wifi_stat);
        if (wifi_stat == WL_CONNECTED)
        {
            break;
        }
    }

    Serial.println("");

    if (count < 20)
    {
        Serial.println("WiFi connected");
    }
    else
    {
        Serial.println("Client !!!NOT!!! connected");
        goto connect;
    }

    Serial.println("Connected to wifi");
    digitalWrite(LED,LOW);
}

void toggleLED(){
    digitalWrite(LED, !digitalRead(LED));
}

void initTime()
{

    time_t epochTime;

    configTime(0, 0, "pool.ntp.org", "time.nist.gov");

    while (true)
    {
        epochTime = time(NULL);

        if (epochTime == 0)
        {
            Serial.println("Fetching NTP epoch time failed! Waiting 2 seconds to retry.");
            delay(2000);
        }
        else
        {
            Serial.print("Fetched NTP epoch time is: ");
            Serial.println(epochTime);
            break;
        }
    }
}

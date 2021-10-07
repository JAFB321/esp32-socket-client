#include <WiFi.h>

 // Wifi 
const char* ssid = "WIFI SSID"; // Wifi ssid
const char* pass = "WIFI PASSWORD";   // Wifi password

// TCP Sockets
const IPAddress serverIP(192,168,1,50); // TCP Server IP
uint16_t serverPort = 4000;             // Port

WiFiClient client; 

void setup()
{
	Serial.begin(9600);

    WiFi.begin(ssid, pass);
    
    Serial.println("Connecting Wifi...");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("1.- Connected");
    Serial.println(WiFi.localIP());
    Serial.println();

    Serial.println("2.- Connecting tcp socket...");
    while (!client.connected())
    {
        client.connect(serverIP, serverPort);
        delay(1000);
    }
    Serial.println("TCP socket connected");
}

void loop()
{
    if(client.connected()){
        const int pinTouch = touchRead(4);

        if(pinTouch < 40 || pinTouch > 90){
            Serial.println("Trying to send message...");
            client.print("Pin touch has been touched!");
            delay(1000);
        }
    }
}

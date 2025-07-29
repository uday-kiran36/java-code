// #include <Wire.h>

// #define lightPin 13

// #include "FirebaseESP32.h"
// #define FIREBASE_HOST "homeautomation-6a112-default-rtdb.firebaseio.com" //Do not include https:// in FIREBASE_HOST
// #define FIREBASE_AUTH "HFW07VWYmLz3eNQwK2YwENqgocOhdmlRAS18kNmU"
// #define WIFI_SSID "Redmi"
// #define WIFI_PASSWORD "chitty18"
// //Define Firebase Data object
// FirebaseData firebaseData;

// int delayTime = 2000;

// void setup() {
//   // put your setup code here, to run once:
//   pinMode(lightPin,OUTPUT);
//   pinMode(2,OUTPUT);
//   Serial.begin(115200);


//  //Connecting to Wi-Fi network
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.print("Connecting to Wi-Fi");
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     digitalWrite(2,!digitalRead(2));
//     Serial.print(".");
//     delay(300);
//   }
//   Serial.println();
//   Serial.print("Connected with IP: ");
//   Serial.println(WiFi.localIP());
//   Serial.println();
//   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
//   Firebase.reconnectWiFi(true);

//   //display.init();
//  //display.setFont(ArialMT_Plain_16);
   
// }

// void loop() {
//   // put your main code here, to run repeatedly:

// String lightCmdFull;
// String lightCmd;
// int finalCmd;

// //display.clear();
// Firebase.getString(firebaseData,"IOTLAB/Light_Control/Light_Cmd",lightCmdFull);
// lightCmd = lightCmdFull.substring(2,lightCmdFull.length()-2);
// finalCmd = lightCmd.toInt();

// if(finalCmd == 1)
// {
//   digitalWrite(lightPin,HIGH);
//   digitalWrite(2,HIGH);
//   Serial.println("Light ON");
//  // display.drawString(20,0,"LIGHT ON");
// }
// else
// {
//   digitalWrite(lightPin,LOW);
//   digitalWrite(2,LOW);
//   Serial.println("Light OFF");
//   //display.drawString(20,0,"LIGHT OFF");
  
// }


// //display.display();  
// delay(delayTime);
// }
#include <Wire.h>
#include <WiFi.h>
#include "FirebaseESP32.h"

#define lightPin 13
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "chitty18"

// Firebase configuration
FirebaseData firebaseData;
FirebaseConfig firebaseConfig;

int delayTime = 2000;

void setup() {
  // Set up pins
  pinMode(lightPin, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(115200);

  // Connecting to Wi-Fi network
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(2, !digitalRead(2));
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  // Initialize Firebase
  firebaseConfig.host = FIREBASE_HOST;
  firebaseConfig.auth = FIREBASE_AUTH;
  Firebase.begin(&firebaseConfig, &firebaseData);
  Firebase.reconnectWiFi(true);
}

void loop() {
  String lightCmdFull;
  String lightCmd;
  int finalCmd;

  Firebase.getString(firebaseData, "IOTLAB/Light_Control/Light_Cmd", lightCmdFull);
  lightCmd = lightCmdFull.substring(2, lightCmdFull.length() - 2);
  finalCmd = lightCmd.toInt();

  if (finalCmd == 1) {
    digitalWrite(lightPin, HIGH);
    digitalWrite(2, HIGH);
    Serial.println("Light ON");
  } else {
    digitalWrite(lightPin, LOW);
    digitalWrite(2, LOW);
    Serial.println("Light OFF");
  }

  delay(delayTime);
}

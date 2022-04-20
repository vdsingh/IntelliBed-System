#include "Firebase_Arduino_WiFi101.h"



char ssid[] = "UMASS-DEVICES";
char pass[] = "GoUMass!";
char url[] = "https://intelli--bed-default-rtdb.firebaseio.com/";
char api[] = "AIzaSyBqmtDdXcCLp4ODEgtkelMj7QWEixxSVOY";

//2. Declare the Firebase Data object in global scope

FirebaseData fbdo;
void setup() {
  Serial.begin(9600);
  Firebase.begin(url, api, ssid, pass);
  Firebase.reconnectWiFi(true);
  setFbFloat(23232, 1111111111111111.1111);
}
void setFbFloat(float data, float timestamp) {
  String child = "/test/";
  char timeString[20];
  dtostrf(timestamp,20,6,timeString);
  if (Firebase.setFloat(fbdo, child+timeString, 123.456789)) {

    //Success, then read the payload value return from server
    //This confirmed that your data was set to database as float number

    if (fbdo.dataType() == "float")
      Serial.println(fbdo.floatData());

  } else {
    //Failed, then print out the error detail
    Serial.println(fbdo.errorReason());
  }
}

void loop(){
  
}


#include <Config.h>
#include <Firebase.h>
#include <Firebase_Arduino_WiFi101.h>
#include <Firebase_TCP_Client.h>
#include <WCS.h>

#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
char url[] = "https://intelli--bed-default-rtdb.firebaseio.com/";
char api[] = "AIzaSyBqmtDdXcCLp4ODEgtkelMj7QWEixxSVOY";
int status = WL_IDLE_STATUS;     // the Wifi radio's status

//2. Declare the Firebase Data object in global scope

FirebaseData fbdo;
Firebase.begin(url, api, ssid, pass);
Firebase.reconnectWiFi(true);

void setup(){
  
}


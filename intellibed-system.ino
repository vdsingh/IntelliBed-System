#include <Config.h>
#include <Firebase.h>
#include <Firebase_Arduino_WiFi101.h>
#include <Firebase_TCP_Client.h>
#include <WCS.h>

#include <arduino_secrets.h>

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
char url[] = "https://intelli--bed-default-rtdb.firebaseio.com/";
char api[] = "AIzaSyBqmtDdXcCLp4ODEgtkelMj7QWEixxSVOY";
int status = WL_IDLE_STATUS;     // the Wifi radio's status

//2. Declare the Firebase Data object in global scope

FirebaseData fbdo;
Firebase.begin(url, api, ssid, pass);
Firebase.reconnectWiFi(true);

void setFbFloat(float data, float timestamp) {
  if (Firebase.setFloat(fbdo, "/test/".concat(timestamp), 123.456789)) {

    //Success, then read the payload value return from server
    //This confirmed that your data was set to database as float number

    if (fbdo.dataType() == "float")
      Serial.println(fbdo.floatData());

  } else {
    //Failed, then print out the error detail
    Serial.println(fbdo.errorReason());
  }
}

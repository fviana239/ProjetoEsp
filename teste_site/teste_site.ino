#include <Arduino_JSON.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "********"; // Nome da rede no roteador
const char* password = "********";  // Senha do wifi
 
void setup () {
  
 pinMode(0, OUTPUT);
 pinMode(2, OUTPUT);
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");
 
  }
  delay(500);
    
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://helloesp.cf/novo.php");  //Specify request destination
    int httpCode = http.GET();                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
       String payload = http.getString();   //Get the request response payload
      
  //difinindo o tamanho do buffer para o objeto json
      const size_t bufferSize = JSON_OBJECT_SIZE(1);
     
      //realizando o parse do json para um JsonObject
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject & root = jsonBuffer.parseObject(http.getString());

      int entrada1 = 1;
    

const char * temp1 = root["status"];
const char * temp2 = root["outros"];
  
Serial.println(payload);             //Print the response payload
Serial.println("dado a");  
Serial.println(atoi(temp1));
entrada1 = atoi(temp1);  

  if (entrada1 == 1){
    digitalWrite(0, LOW);
    digitalWrite(2, LOW);
    
    delay (100);
  }else{
    digitalWrite(0, HIGH);
    digitalWrite(2, HIGH);
    
    
    delay (100);
  }
 
    }
 
    http.end();   //Close connection
 
  }
 
  delay(5000);    //Send a request every 5 seconds
}

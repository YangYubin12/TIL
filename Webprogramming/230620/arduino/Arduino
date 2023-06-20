#include <WiFi.h>
#include "DHT.h"
#define DHTPIN 17 //현재 온습도 센서가 연결된 핀
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

//서버의 주소(ipconfig)
//컴퓨터가 bssm_free에 접속되어있을 것
//상황에 따라 서버 주소 바뀔 수 있음
const char * host = "10.150.151.11";
const int Port = 80;

const char* ssid = "bssm_free";
const char* password = "bssm_free";

WiFiClient client;

void setup() {
  Serial.begin(115200); //결과를 PC에서
  dht.begin();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  /////////////////////////////////////
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //1회 서버에 request
  //1.클라이언트가 서버에 접속
  if (!client.connect(host, Port)) {
    Serial.println("connection failed");
    return;
  }
  Serial.println("서버와 연결되었습니다!");
  //2.클라이언트가 서버에 request를 전송
  
  int data_num = 100;
  float data_temp = dht.readTemperature();
  float data_humi = dht.readHumidity();

  // 서버로 보내는 request
  // bssm2_3/upload.php?temp=12.34&humi=56.78
  String url = "/bssm2_3/test/upload.php?data_temp="+String(data_temp)+"&data_humi="+String(data_humi); //중요!! temp, humi 수정해야함
  //String url = "/bssm2_3/now.php";
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: "+ host +"\r\n" +
               "Connection: close\r\n\r\n");
  //3.서버가 클라이언트에게 response 전송
  unsigned long t = millis(); //생존시간
  while(1){
    if(client.available()) break;
    if(millis() - t > 10000) break;
  }
  //응답이 왔거나 시간안에 응답이 안 왔을 경우
  Serial.println("응답이 도착했습니다");
  while(client.available()){
    
    Serial.write(client.read());
  }
  //4.연결 해제
  Serial.println("연결이 해제되었습니다!");
  delay(1000);
}

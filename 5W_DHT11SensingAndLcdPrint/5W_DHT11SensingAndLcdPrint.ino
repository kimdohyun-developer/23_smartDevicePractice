#include <DHT.h>
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int a=0;
int b=0;
unsigned long timeVal=0; //이전 시간




void setup() {
  Serial.begin(9600);//시리얼 프린트 시작
   dht.begin();

   //lcd 구현부
  lcd.init(); //초기화
  lcd.backlight();
}

void loop() {


//delay없이 초세기-> a를 기준으로 b도 움직일 수 있음.
 if(millis()-timeVal>=1000){

   a++; 

   float  t = dht.readTemperature(); //온도값을 대입
   float  h = dht.readHumidity();   //습도값을 대입
   Serial.print("Temperture: ");
   Serial.println(t);
   Serial.print(" C ");
   Serial.print("Humidity: ");
   Serial.print(h);
   Serial.println(" %");

   timeVal=millis();

   if(a%2==0){ //a를 기준으로 2초마다 b 1 증가 
    b++;
   }

   if(a==16){
    a=0;
  }

  if(b==16){
    b=0;
  }

  lcdPrint(a,b,t,h); //매개변수로 각자 움직일 초, 온도, 습도를 받음.
  
  }


  
}

//메소드로 한번에 관리.
void lcdPrint(int a, int b, float t, float h){

  //온도
   lcd.setCursor(a,0);
  lcd.print(" ");
  lcd.setCursor(1+a,0);
  lcd.print("Temp: ");
  lcd.setCursor(6+a,0);
  lcd.print(t);

  //습도
     lcd.setCursor(b,1);
  lcd.print(" ");
  lcd.setCursor(1+b,1);
  lcd.print("Hum: ");
  lcd.setCursor(5+b,1);
  lcd.print(h);
  lcd.setCursor(10+b,1);
  lcd.print("%");
  

}


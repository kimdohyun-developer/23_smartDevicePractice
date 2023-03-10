//2주차 실습 - 내장 LED 점멸

int LED_BUILTIN = 2;

void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(1000);                     
  digitalWrite(LED_BUILTIN, LOW);   
  delay(1000);                      
}

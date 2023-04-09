


int val =0;


void setup() {
  Serial.begin(9600);
  
  pinMode(12,OUTPUT);
 
}

void loop() {

  val = analogRead(13); // 가변저항으로부터 아날로그 신호를 받을 변수를 선언해준다.
  Serial.println(val); 
  val = map(val, 0, 1023, 0, 255); // val의 최댓값을 1023에서 255로 매핑해준다. 
   analogWrite(12, val); // 보드에서 아날로그로 쓸수있는 11,10,9,6,5,3번핀(물결표시)중에서 하나를 선택하면 된다.
    

  
   
}

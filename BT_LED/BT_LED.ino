#include "BluetoothSerial.h"

const char *pin = "1234"; 

String device_name = "ESP32-BT-Slave";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

int LED = 23; //LED를 제어할 PIN



void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
 
  #ifdef USE_PIN
    SerialBT.setPin(pin);
    Serial.println("Using PIN");
  #endif

  pinMode(LED,OUTPUT);
}

void loop() {

  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  
  if (SerialBT.available()) {
    
    char txt = SerialBT.read();
    if(txt == 'o'){
    digitalWirte(LED,HIGH);
    //o를 입력하면 LED를 킴


       
    } 
    else if(txt=='x'){
    digitalWirte(LED,LOW);
    //x를 입력하면  LED를 끔

    }

    
  }

  
  delay(20);
  
}

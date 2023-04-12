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

#include <DHT.h>

#define DHTPIN 13

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);






void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
 
  #ifdef USE_PIN
    SerialBT.setPin(pin);
    Serial.println("Using PIN");
  #endif

  dht.begin();
}

void loop() {

  

    float  t = dht.readTemperature(); //온도값을 대입

    float  h = dht.readHumidity();   //습도값을 대입

    
    

  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  
  
  if (SerialBT.available()) {
    
    char txt = SerialBT.read();
    if(txt == 't'){
       SerialBT.print("Temperture: ");

       SerialBT.print(t);

       SerialBT.print(" C ");
       SerialBT.println("");

       
    } 
    else if(txt=='h'){
    SerialBT.print("Humidity: ");

    SerialBT.print(h);

    SerialBT.print(" %");
    SerialBT.println("");
    
    }

    
  }
  
  delay(20);
}

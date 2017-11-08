#include <Wire.h>
#include <SHT25.h>

SHT25 sht25;

void setup() {
  
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Get Interface Shield Serial Number");
  Serial.println("==================================");


  if(!sht25.begin()){    
    for(;;){
      Serial.println(F("ERROR"));
      delay(1000);
    }
  }  
}

void loop() {
  uint8_t serial_number[8] = {0};
  sht25.getSerialNumber(serial_number);

  uint32_t sum = 0;
  for(uint8_t ii = 0; ii < 8; ii++){
    sum += serial_number[ii];
  }

  
  if(sum == 0){
    Serial.println(F("ERROR"));        
  }
  else {
    char serial[32] = "";
    sprintf(serial, "egg%02x%02x%02x%02x%02x%02x%02x%02x",
    serial_number[0],
    serial_number[1],
    serial_number[2],
    serial_number[3],
    serial_number[4],
    serial_number[5],
    serial_number[6],
    serial_number[7]); 
    Serial.print(F("Serial Number: "));   
    Serial.println(serial);
  }

  delay(1000);
}

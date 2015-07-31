#include <Wire.h>
#include <Intel_Edison_BT_SPP.h>

Intel_Edison_BT_SPP spp = Intel_Edison_BT_SPP();

void setup() {  
//    Serial.begin(115200);
        pinMode(7, OUTPUT);
        pinMode(11, OUTPUT);
        pinMode(13, OUTPUT);
    Serial.begin(9600);
     Serial.println("Intel Edison BT SPP test!");
    spp.open();
}
void leftLed(){  
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(7, LOW);
  delay(100);
}

void rightLed(){  
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}

void breakLed(){  
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
}


void processSpp(char ch){  
//    Serial.print(ch);
    switch(ch){
      case 'W':
        Serial.println("Straight");
        break;

      case 'A':
        Serial.println("LEFT");
        leftLed();
        break;

      case 'S':
        Serial.println("STOP");
        breakLed();
        break;

      case 'D':
        Serial.println("RIGHT");
        rightLed();
        break;        
    }
}

void loop() {  
    ssize_t size = spp.read();
    if (size != -1) {
                const char* buf = spp.getBuf();
                for(int i=0;i<size;i++){
                  processSpp(buf[i]);
                }
//        Serial.println(spp.getBuf());
    } else {
        // Well, some error here 
        delay(500);
    }
}

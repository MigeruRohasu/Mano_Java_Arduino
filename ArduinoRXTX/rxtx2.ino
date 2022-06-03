#include <Servo.h>
String dato;


Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
int pinservo1 = 2;
int pinservo2 = 3;
int pinservo3 = 4;
int pinservo4 = 5;
int pinservo5 = 6;

int on =0;
int off = 180;

void setup() {
  servo1.attach(pinservo1, 610, 2550);
  servo2.attach(pinservo2, 670, 2540);
  servo3.attach(pinservo3, 660, 2600);
  servo4.attach(pinservo4, 660, 2600);
  servo5.attach(pinservo5, 660, 2600);
  pinMode(pinservo1, OUTPUT);
  pinMode(pinservo2, OUTPUT);
  pinMode(pinservo3, OUTPUT);
  pinMode(pinservo4, OUTPUT);
  pinMode(pinservo5, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  digitalWrite(10,HIGH);
      servo1.write(off);
      servo2.write(off);
      servo3.write(off);
      servo4.write(off);
      servo5.write(off);
      delay(1000);
      digitalWrite(10,LOW);
      servo1.write(on);
      servo2.write(on);
      servo3.write(on);
      servo4.write(on);
      servo5.write(on);
      delay(1000);
      servo1.write(off);
      servo2.write(off);
      servo3.write(off);
      servo4.write(off);
      servo5.write(off);
      delay(1000);
}

void loop() {
  if (Serial.available() > 0) {    
    dato = Serial.readString();
    dato.trim();
    if(dato == "indiceON"){
      digitalWrite(10,HIGH);
      servo1.write(on);
    }else if(dato == "indiceOFF"){
      digitalWrite(10,LOW);
      servo1.write(off);  
    }else if(dato == "corazonON"){
      digitalWrite(10,HIGH);
      servo2.write(on);
    }else if(dato == "corazonOFF"){
      digitalWrite(10,LOW);
      servo2.write(off);  
    }else if(dato == "anularON"){
      digitalWrite(10,HIGH);
      servo3.write(on);
    }else if(dato == "anularOFF"){
      digitalWrite(10,LOW);
      servo3.write(off);  
    }else if(dato == "meniqueON"){
      digitalWrite(10,HIGH);
      servo4.write(on);
    }else if(dato == "meniqueOFF"){
      digitalWrite(10,LOW);
      servo4.write(off);  
    }else if(dato == "gordoON"){
      digitalWrite(10,HIGH);
      servo5.write(on);
      delay(800);
      servo1.write(off);
      servo2.write(off);
      servo3.write(off);
      servo4.write(off);
      servo5.write(off);
    }else if(dato == "gordoOFF"){
      digitalWrite(10,LOW);
      servo5.write(off);  
    }else if(dato == "cerrar"){
      digitalWrite(10,LOW);
      servo1.write(off);
      servo2.write(off);
      servo3.write(off);
      servo4.write(off);
      servo5.write(off);  
    }else if(dato == "abrir"){
      digitalWrite(10,HIGH);
      servo1.write(on);
      servo2.write(on);
      servo3.write(on);
      servo4.write(on);
      servo5.write(on);  
    }
    delay(800);
    digitalWrite(10,LOW);
    delay(800);
   }
}

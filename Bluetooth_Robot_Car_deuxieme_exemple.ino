char cmd; // The Bluetooth Command
//The L298N Control Pins
const int rightMotorForward = 5;
const int rightMotorBackward = 6;
const int leftMotorForward = 7;
const int leftMotorBackward = 8;
 
void setup() {
  pinMode(leftMotorForward,OUTPUT);   //left motor forward
  pinMode(leftMotorBackward,OUTPUT);   //left motor reverse
  pinMode(rightMotorForward,OUTPUT);   //right motor forward
  pinMode(rightMotorBackward,OUTPUT);   //right motor reverse
  Serial.begin(9600);
}

void stopMotors() {
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorBackward,LOW);
}
 
void loop() {
  if(Serial.available()){
    cmd = Serial.read();
    
    if(cmd == 'F'){           //move forward
      digitalWrite(leftMotorForward,HIGH);
      digitalWrite(leftMotorBackward,LOW);
      digitalWrite(rightMotorForward,HIGH);
      digitalWrite(rightMotorBackward,LOW);
    }
     
    else if(cmd == 'B'){      //move reverse
      digitalWrite(leftMotorForward,LOW);
      digitalWrite(leftMotorBackward,HIGH);
      digitalWrite(rightMotorForward,LOW);
      digitalWrite(rightMotorBackward,HIGH);
    }
     
    else if(cmd == 'L'){      //turn Left
      digitalWrite(leftMotorForward,LOW);
      digitalWrite(leftMotorBackward,LOW);
      digitalWrite(rightMotorForward,HIGH);
      digitalWrite(rightMotorBackward,LOW);
    }
     
    else if(cmd == 'R'){      //turn Right
      digitalWrite(leftMotorForward,HIGH);
      digitalWrite(leftMotorBackward,LOW);
      digitalWrite(rightMotorForward,LOW);
      digitalWrite(rightMotorBackward,LOW);
    }
    
    else if(cmd == 'S'){      //stop - nouvelle commande
      stopMotors();
    }
  }
  else {
    // Pas de données disponibles = arrêt automatique
    stopMotors();

  }
}
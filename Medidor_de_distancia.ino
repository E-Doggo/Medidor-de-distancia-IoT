  #define echo 27
  #define trigger 25
  int cm = 0;

  int pins[6] = {15, 2, 0, 4, 16, 17};
  

  void setup() {
    for (int i = 0; i < 6; i++)
    {
      pinMode(pins[i], OUTPUT);
    }
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
  }

  long readUltrasonicDistance(int triggerPin, int echoPin)
  {
    
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    return pulseIn(echoPin, HIGH);
  }

  void measureDistance(int cm)
  {
    if (cm > 0 && cm <= 20)
    {
        digitalWrite(pins[0], HIGH);
        delay(200); 
        digitalWrite(pins[0], LOW);
    }
    else if (cm > 20 && cm <= 40)
    {
        digitalWrite(pins[1], HIGH);
        delay(200); 
        digitalWrite(pins[1], LOW);
    }
  
    else if  (cm > 40 && cm <= 60)
    {
        digitalWrite(pins[2], HIGH);
        delay(200); 
        digitalWrite(pins[2], LOW);
    }
    
    else if  (cm > 60 && cm <= 80)
    {
        digitalWrite(pins[3], HIGH);
        delay(200); 
        digitalWrite(pins[3], LOW);
    }
    
    else if  (cm > 80 && cm <= 100)
    {
        digitalWrite(pins[4], HIGH);
        delay(200); 
        digitalWrite(pins[4], LOW);
    }
    
    else if  (cm > 100)
    {
        digitalWrite(pins[5], HIGH);
        delay(200);
        digitalWrite(pins[5], LOW);
    }
  }

  void loop() {
    cm = 0.01723 * readUltrasonicDistance(trigger,echo);
    measureDistance(cm);
    Serial.println(" cm");
    Serial.print(cm);
}

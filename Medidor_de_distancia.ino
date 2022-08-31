  #define echo 27
  #define trigger 25
  int cm = 0;

  int ports[6] = {15, 2, 0, 4, 16, 17}; //Puertos del MCU
  

  void setup() {
    for (int i = 0; i < 6; i++)
    {
      pinMode(ports[i], OUTPUT);
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
    return pulseIn(echoPin, HIGH); //Se devolvera el tiempo entre el envio y la recepcion
  }

  void measureDistance(int cm)
  {
    if (cm > 0 && cm <= 20)
    {
        digitalWrite(ports[0], HIGH);
        delay(200); 
        digitalWrite(ports[0], LOW);
    }
    else if (cm > 20 && cm <= 40)
    {
        digitalWrite(ports[1], HIGH);
        delay(200); 
        digitalWrite(ports[1], LOW);
    }
  
    else if  (cm > 40 && cm <= 60)
    {
        digitalWrite(ports[2], HIGH);
        delay(200); 
        digitalWrite(ports[2], LOW);
    }
    
    else if  (cm > 60 && cm <= 80)
    {
        digitalWrite(ports[3], HIGH);
        delay(200); 
        digitalWrite(ports[3], LOW);
    }
    
    else if  (cm > 80 && cm <= 100)
    {
        digitalWrite(ports[4], HIGH);
        delay(200); 
        digitalWrite(ports[4], LOW);
    }
    
    else if  (cm > 100)
    {
        digitalWrite(ports[5], HIGH);
        delay(200);
        digitalWrite(ports[5], LOW);
    }
  }

  void loop() {
    cm = 0.01723 * readUltrasonicDistance(trigger,echo); //se calculara la distancia multiplicando la velocidad en la que el sonido recorre un centimetro por el tiempo de rebote obtenido.
    measureDistance(cm);
    Serial.println(" cm");
    Serial.print(cm);
}

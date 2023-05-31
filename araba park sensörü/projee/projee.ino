#define echoPin 8
#define trigPin 9

long gecenSure;
long mesafe;
int redLed=2;
int blueLed=3;
int greenLed=4;
int hasasiyet;

void setup() {
Serial.begin(9600);

pinMode(echoPin , INPUT  );
pinMode(trigPin, OUTPUT);
pinMode(greenLed,OUTPUT);
pinMode(blueLed,OUTPUT);
pinMode(redLed,OUTPUT);
}

void loop() {
 hasasiyet = analogRead(A0);
 digitalWrite(trigPin,LOW);
      delayMicroseconds(5);
 digitalWrite(trigPin,HIGH);
       delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 
 gecenSure = pulseIn(echoPin, HIGH);

 mesafe = gecenSure/29.1/2;

 Serial.print("MESAFE: ");
 Serial.print(mesafe);
 Serial.println("CM");
 Serial.print("HASASİYET: ");
 Serial.println(hasasiyet);

 if (mesafe!=1001 && mesafe>=20 )
    digitalWrite(greenLed,1);
 else 
    digitalWrite(greenLed,0); 

 if(mesafe>10 && mesafe<20)
     digitalWrite(blueLed,1);
 else 
    digitalWrite(blueLed,0);

  if(mesafe>0 && mesafe<=10)
     digitalWrite(redLed,1);
     else 
    digitalWrite(redLed,0);
  
   
    

 delay(hasasiyet);

}


#include"DHT.h"
#define DHTTYPE DHT11
#define dht_dpin 0

DHT dht(dht_dpin,DHTTYPE);

//init global vars
// digital pin 2 has a pushbutton attached to it. Give it a name:
uint8_t irSensor = D5;
uint8_t LED = D4;
uint8_t MOTOR = D1;


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  pinMode(irSensor, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  delay(1);
}

// the loop routine runs over and over again forever:
void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int x = IR();
  // read the input pin:
  
  // print out the state of the button:
  Serial.println("IrState = ");
  Serial.print(x);
  Serial.println("Temp = ");
  Serial.print(t);
  Serial.println(" ");
  if(t>30){
      digitalWrite(MOTOR,x);
  }
  //digitalWrite(MOTOR,!(irState));
  delay(800);        // delay in between reads for stability
}

int IR(){
  
  int irState = digitalRead(irSensor);
  // print out the state of the button:
  Serial.println(irState);
  digitalWrite(LED, !(irState));
  return !(irState);
  
}

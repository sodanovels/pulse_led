int ledPin = 5;

int x = 0;
int delayVal = 25;
String action = "pulser";
bool runStatus = false;
float sinVal;
int ledVal;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (action == "pulser"){
    pulser();
  }
  else {
   strober();
  }
}
void setDelay( int param) {
  delayVal = param;
}
void turnOn(){
  runStatus = true;
  analogWrite(ledPin, 255);
}

void turnOff() {
  runStatus = false;
  analogWrite(ledPin, 0);
}

void pulser() {
 // Serial.println("pulsing");
    x++;
  if (x==180){
    x=0;
  }
  // convert degrees to radians then obtain sin value
  sinVal = (sin(x*(3.1412/180)));
  ledVal = int(sinVal*255);
  analogWrite(ledPin, ledVal);
  
}


void strober() {
  Serial.println("strobing");
 // analogWrite(ledPin, 1);
  pulser();
  delay(delayVal);
}

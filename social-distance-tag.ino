//init pin for ultrasonic sensor
const int trigPin = 2; //D2 pin on maker nano
const int echoPin = 3 ; //D3 pin on maker nano

//init duration 
long duration;
long now = millis();
long lastMeasure= 0;

//init distance in seconds
int distance= 0;

//init for buzzer pin
#define BUZZER 8 //built-in buzzer in maker nano
#define NOTE_E4 330
#define NOTE_G4 392
#define NOTE_B4 494
#define NOTE_D5 587

//init for led pin
#define Led4 4
#define Led5 5
#define Led6 6
#define Led7 7
#define Led8 8
#define Led9 9
#define Led10 10
#define Led11 11
#define Led12 12
int delayMs;

void setup() {
  Serial.begin(115200);
  //set pinmode for led
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);
  pinMode(Led8, OUTPUT);
  pinMode(Led9, OUTPUT);
  pinMode(Led10, OUTPUT);
  pinMode(Led11, OUTPUT);
  pinMode(Led12, OUTPUT);
   
  //Set pimode for ultrasonic sensor
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.println("Start measure distance in centimeter.");
}

void loop() {
  checkDistance();

  //Print out to view in serial monitor  
  Serial.print("Distance: ");
  Serial.println(distance);
 
  //Check distance to turn on the led 
  // 5cm
  if(distance < 10){
    tenCM();
    noteD5();
  }
  else if(distance < 20){
    twentyCM();
    noteD5();
  }
   else if(distance < 30){
    thirtyCM();
    noteB4();
  }
   else if(distance < 40){
    fourtyCM();
    noteB4();
  }
  else if(distance < 50){
    fiftyCM();
    noteG4();
  }
  else if(distance < 60){
    sixtyCM();
    noteE4();
  }
  else if(distance < 70){
    seventyCM();
    noteE4();
  }
  else if(distance < 90){
    ninetyCM();
    noteE4();
  }

  else{
    digitalWrite(Led4, LOW);
    digitalWrite(Led5, LOW);
    digitalWrite(Led6, LOW);
    digitalWrite(Led7, LOW);
    digitalWrite(Led8, LOW);
    digitalWrite(Led9, LOW);
    digitalWrite(Led10, LOW);
    digitalWrite(Led11, LOW);
    digitalWrite(Led12, LOW);
    Serial.println("Out of distance");
  }
  delay(delayMs);
}



void checkDistance(){
  //ultrasonic sensor measure distance
  now = millis();
  if(now - lastMeasure > 1000){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.034/2;
    }
}

void noteD5(){
  tone(BUZZER, NOTE_D5,50);
  delay(50);
  delayMs =30;
}

void noteB4(){
  tone(BUZZER, NOTE_B4,50);
  delay(50);
  delayMs = 70;
}

void noteG4(){
  tone(BUZZER, NOTE_G4,50);
  delay(50);
  delayMs = 110;
}

void noteE4(){
  tone(BUZZER, NOTE_E4,70);
  delay(50);
  delayMs = 150;
}

void ninetyCM(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led10, LOW);
  digitalWrite(Led11, LOW);
  digitalWrite(Led12, HIGH);
}
void seventyCM(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(Led9, LOW);
  digitalWrite(Led10, LOW);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led12, HIGH);
}
void sixtyCM(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(Led9, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led12, HIGH);
}

void fiftyCM(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led9, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led12, HIGH);
}
void fourtyCM(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led9, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led12, HIGH);
}

void thirtyCM(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led9, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led12, HIGH);
}

void twentyCM(){
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led6, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led9, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led12, HIGH);
}

void tenCM(){
  digitalWrite(Led4, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led6, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(Led9, HIGH);
  digitalWrite(Led10, HIGH);
  digitalWrite(Led11, HIGH);
  digitalWrite(Led12, HIGH);
}

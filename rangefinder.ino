#define sonar_read 2
#define sonar_write 3
#define beeper 4
short duration;
short distance;

void setup() {
  //establishes input/output ports
  pinMode(sonar_write, OUTPUT);
  pinMode(sonar_read, INPUT);
  pinMode(beeper, OUTPUT);

  //initialization with 9600 baud rate
  Serial.begin(9600);
}
void loop() {
  //clears any high voltage in sonar trig
  digitalWrite(sonar_write, LOW);
  delayMicroseconds(2);

  //shoots sound wave
  digitalWrite(sonar_write, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonar_write, LOW);

  //distance = speed * time. distance in this context is double because forward and back
  duration = pulseIn(sonar_read, HIGH);
  distance = (duration * 0.034 / 2);

  //reporting
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm ");
  delay(1000); //spit rate
}

void beep(short freq, short ms){
  tone(4, freq, ms);
}

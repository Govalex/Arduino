//dirt cheap wireless RX by http://tthheessiiss.wordpress.com
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13,OUTPUT);

  // Clear Timer on Compare Match (CTC) Mode
  bitWrite(TCCR1A, WGM10, 0);
  bitWrite(TCCR1A, WGM11, 0);
  bitWrite(TCCR1B, WGM12, 1);
  bitWrite(TCCR1B, WGM13, 0);

  // Toggle OC1A and OC1B on Compare Match.
  bitWrite(TCCR1A, COM1A0, 1);
  bitWrite(TCCR1A, COM1A1, 0);
  bitWrite(TCCR1A, COM1B0, 1);
  bitWrite(TCCR1A, COM1B1, 0);

  // No prescaling
  bitWrite(TCCR1B, CS10, 1);
  bitWrite(TCCR1B, CS11, 0);
  bitWrite(TCCR1B, CS12, 0);

  OCR1A = 210;
  OCR1B = 210;
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  // if incoming serial
  if (Serial.available()) {
    readSerial();
    digitalWrite(13, HIGH);
  } 
  else {
    digitalWrite(13, LOW);
  }
  delay(10);
}

void readSerial() {
  char val = Serial.read();
  Serial.print(val);
}


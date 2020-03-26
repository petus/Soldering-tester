/*
 * SOLDERING TESTER v0.1
 * 
 * made by chiptron.cz
 * 3/2020
 * 
 * Probe GND of Nucleo board to Vcc of tested board
 * Probe inputs (A0, A1,...) to pin (e.g. GPIO) of tested board
 * 
 * Push the user button for the soldering test
 * If the LED is blinking, some analog channel is badly soldered, otherwise it is ok
 * 
 */


#define A0 PA0
#define A1 PA1
#define A2 PA4 
#define A3 PB0 
#define A4 PC1 
#define A5 PC0 
#define A6 PC2 
#define A7 PC3

#define UB PC13 // user button
#define SL PA5  // status LED

#define ADCformula (1000 * (3.3 / 1023.0))

float anaVal = 0;

void setup() {

  Serial.begin(115200);

  pinMode(UB, INPUT); // user button
  pinMode(SL, OUTPUT);  //status LED

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  
  digitalWrite(SL, LOW);
}

void loop() {

  bool error = false;
  digitalWrite(SL, HIGH);
  
  if(!(digitalRead(UB)))
  {
    digitalWrite(SL, LOW);
    delay(100);
    digitalWrite(SL, HIGH);
    Serial.println("Start of testing");

    for(uint8_t i=0; i <= 7; i++)
    {
      anaVal = 0;
      switch (i)
      {
        case 0:
          anaVal = analogRead(A0) * ADCformula;
          break;

        case 1:
          anaVal = analogRead(A1) * ADCformula;
          break;

        case 2:
          anaVal = analogRead(A2) * ADCformula;
          break;

        case 3:
          anaVal = analogRead(A3) * ADCformula;
          break;

        case 4:
          anaVal = analogRead(A4) * ADCformula;
          break;

        case 5:
          anaVal = analogRead(A5) * ADCformula;
          break;

        case 6:
          anaVal = analogRead(A6) * ADCformula;
          break;

        case 7:
          anaVal = analogRead(A7) * ADCformula;
          break;

        default:
          break;
      }

      if((anaVal >= 200) && (anaVal <= 800))
      {
        Serial.print("OK: channel ");
        Serial.print(i);
        Serial.print("; ");
        Serial.print(anaVal);
        Serial.println(" mV");
      }
      else 
      {
        Serial.print("Badly soldered: channel ");
        Serial.print(i);
        Serial.print("; ");
        Serial.print(anaVal);
        Serial.println(" mV");
        error = true;
      }
    }
  }

  if(error)
  {
    for(uint8_t j=0; j<=10; j++)
    {
      digitalWrite(SL, LOW);
      delay(100);
      digitalWrite(SL, HIGH);
      delay(100);
    }
  }
  delay(500);
}

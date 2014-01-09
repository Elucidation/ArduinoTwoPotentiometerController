/*
Reads in potentiometer analog values (range 0 to 1023) from pins A & B.
Converts values to 0-100 range, and displays them on Serial.
*/
#define pinA A1
#define pinB A0

#define LOOP_DELAY_MS 2

void setup() {
  // Initialize serial communications at 9600 bps
  Serial.begin(9600); 
}

void loop() {
  // Read and print the results to the serial monitor.
  Serial.print("A = ");
  Serial.print(map(analogRead(pinA), 0, 1023, 0, 100));
  Serial.print("\t B = ");
  Serial.println(map(analogRead(pinB), 0, 1023, 0, 100));

  // Time to wait for the analog-to-digital converter to settle
  // after the last reading.
  delay(LOOP_DELAY_MS);
}

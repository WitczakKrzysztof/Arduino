void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read data from the PC
  if (Serial.available()) {
    char data = Serial.read();
    // Do something with the received data
    // For example, you can print it to the Serial Monitor
    Serial.print("Received: ");
    Serial.println(data);
  }

  // Send data to the PC
  // For example, you can send a message every second
  delay(1000);
  Serial.println("Hello from Arduino!");
}
#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2     // Digital pin connected to the DHT11 data pin
#define DHTTYPE DHT11 // DHT 11

#define LCD_SC  8     // LCD Screen Chip Select pin
#define LCD_DC  9     // LCD Data/Command pin
#define LCD_DIN 11    // LCD Data In pin
#define LCD_CLK 12    // LCD Clock pin
#define LCD_RST 13    // LCD Reset pin

#define SWITCH_PIN 7  // Digital pin connected to the switch

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(LCD_SC, LCD_DC, LCD_DIN, LCD_CLK, LCD_RST);

void setup() {
  dht.begin();
  lcd.begin(84, 48);
}

void loop() {
  // Read temperature and humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if readings are valid
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.print("Failed to read");
    return;
  }

  // Read the switch state
  int switchState = digitalRead(SWITCH_PIN);

  // Display information on the LCD
  lcd.clear();
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%  ");
  lcd.setCursor(0, 1);
  lcd.print("Temperature: ");
  lcd.print(t);
  lcd.print("C");

  // If the switch is pressed, display additional information
  if (switchState == HIGH) {
    lcd.setCursor(0, 2);
    lcd.print("Switch Pressed!");
  }
}

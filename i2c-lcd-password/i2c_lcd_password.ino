#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <SoftwareSerial.h>

//4X3 KEYPAD
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // SET 3 IF USING 4X3  Columns

// Configure the software serial pins
SoftwareSerial sim800l(10, 11); // RX, TX

//4X3 KEYPAD
// char keys[ROWS][COLS] = {
//   {'1','2','3'},
//   {'4','5','6'},
//   {'7','8','9'},
//   {'*','0','#'}
// };

// byte rowPins[ROWS] = {2, 3, 4, 5}; // Connect to the row pinouts of the keypad
// byte colPins[COLS] = {6, 7, 8}; // Connect to the column pinouts of the keypad

//4X4 KEYPAD
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};  // Connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9};  // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the address if needed

String inputString = ""; // To store entered text
String comparisonString = "12345";

const String correctPassword = "1234"; // Define correct password
const String callPassword = "444"; // Define correct password
const int buzzerPin = 9; // Pin for the buzzer

const int analogPin = A1; // Analog pin to read
unsigned long lastAnalogReadTime = 0;
const unsigned long analogReadInterval = 200; // Interval for reading analog value (milliseconds)

void setup() {
  Wire.begin();  // Start I2C as master;
  lcd.begin(16, 2); // Adjust the dimensions if your LCD is different
  Serial.begin(9600); // Adjust baud rate if needed

  // Turn on the backlight (adjust if needed)
  lcd.backlight();

  // Set buzzer pin as output
  pinMode(buzzerPin, OUTPUT);

  // Initial LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("     Hello!     ");
  lcd.setCursor(0, 1);
  lcd.print("Enter password");
}



void loop() {
  int analogValue;
  unsigned long currentMillis = millis();

  // Read analog value at specified interval
  if (currentMillis - lastAnalogReadTime >= analogReadInterval) {
    analogValue = analogRead(analogPin);
    Serial.print("Analog Value: ");
    Serial.println(analogValue);
    lastAnalogReadTime = currentMillis;
  }
  
  char key = keypad.getKey();

  if (key != NO_KEY && key != '#' && key != '*') {
    inputString += key;
   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter password");
    lcd.setCursor(0, 1);
    lcd.print(inputString);
  //lcd.print("*");   //Displays asterics instead of real digits, use (key) for real digits.
    
  } else if (key == '#') {
    if (inputString == comparisonString) {
      lcd.clear();
      lcd.print("Success!");
      delay(1000);
      lcd.clear();
      lcd.print("Enter code:");
    } else {
      lcd.clear();
      lcd.print("Error!");
      delay(1000);
      lcd.clear();
      lcd.print("Enter code:");
    }
    inputString = "";
  }
  else if (key == '*') {
      // Clear the last entered character if '*' is pressed
      if (inputString.length() > 0) {
        inputString.remove(inputString.length() - 1);
        // Display updated entered text on LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter password");
        lcd.setCursor(0, 1);
        lcd.print(inputString);
      }
    }
}
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4;  //define the number of rows and columns in the keypad
const byte COLS = 3;

char keys[ROWS][COLS] = {  //define the keypad matrix
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte rowPins[ROWS] = { 2, 3, 4, 5 };  //define the row and column pins
byte colPins[COLS] = { 6, 7, 8 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

String inputString = "";
String comparisonString = "12345";

void setup() {
  lcd.begin(16, 2);
  lcd.print("Enter code:");

  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY && key != '*') {
    inputString += key;
    lcd.setCursor(inputString.length(), 1);
    lcd.print("*");   //Displays asterics instead of real digits, use (key) for real digits.
    
  } else if (key == '*') {
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
}

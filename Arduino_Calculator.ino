#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the I2C address for your LCD

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("BVM FOREVER");
  delay(5000);
  lcd.clear();
  lcd.print("MEGHAN_23EC427");
  delay(5000);
  lcd.clear();
  lcd.print("ANSHUL_23EC47");
  delay(5000);
  lcd.clear();


}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Enter expression:");
  
  while (!Serial.available()) {
    // Wait for input
  }
  
  String input = Serial.readStringUntil('\n');
  
  lcd.setCursor(0, 1);
  lcd.print("Result: ");
  lcd.print(calculate(input));
  delay(2000);
  lcd.clear();
}

float calculate(String expression) {
  int operand1, operand2;
  char operation;

  sscanf(expression.c_str(), "%d %c %d", &operand1, &operation, &operand2);

  switch (operation) {
    case '+':
      return operand1 + operand2;
    case '-':
      return operand1 - operand2;
    case '*':
      return operand1 * operand2;
    case '/':
      if (operand2 != 0) {
        return (float)operand1 / operand2;
      } else {
        lcd.clear();
        lcd.print("Error: Division by 0");
        delay(2000);
        lcd.clear();
        return 0;
      }
    default:
      lcd.clear();
      lcd.print("Error: Invalid operation");
      delay(2000);
      lcd.clear();
      return 0;
  }
}

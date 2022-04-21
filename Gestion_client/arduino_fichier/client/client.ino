#include <Keypad.h>

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
char data;


//Keypad
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};


String ch;

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );




void setup() {
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();

  Serial.begin(9600);
  lcd.print("CLIENT");
  Serial.println("Robojax 4x4 keypad");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {

    data = Serial.read();

    if (data == '1')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CLIENT AJOUTER");
      Serial.write('1');
      delay(500);



    }
  
    else if (data == '0')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.println("erreur");
      lcd.setCursor(0,1);
      lcd.println("ID EXISTE");
      Serial.write('0');
      delay(500);
      // Serial.print(data);
    }

  }
  char key = keypad.getKey();
    // just print the pressed key

   if (key){
    ch+=key; 
    Serial.print(key);

   }



}

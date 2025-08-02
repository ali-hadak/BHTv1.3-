#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>

#define upButton D3
#define okButton D4
#define downButton D5

int networkCount = WiFi.scanNetworks();
int networkCount2 = WiFi.scanNetworks();

byte unselectedBox[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};

byte selectedBox[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

LiquidCrystal_I2C lcd(0x27, 16,2);
void setup() {
  lcd.begin();

  pinMode(upButton, INPUT_PULLUP);
  pinMode(okButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);

  lcd.createChar(0, unselectedBox);
  lcd.createChar(1, selectedBox);
}

void Desktop() {
  int okButton_d = digitalRead(okButton);
  int upButton_d = digitalRead(upButton);
  int downButton_d = digitalRead(downButton);

  if (downButton_d == 1) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.write(0);
    lcd.print("fake_network");

    lcd.setCursor(0, 1);
    lcd.write(1);
    lcd.print("app_manager");

    delay(1500);

    int okButton_d = digitalRead(okButton);
    int upButton_d = digitalRead(upButton);
    int downButton_d = digitalRead(downButton);

    if (okButton_d == 1) {
      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.write(1);
      lcd.print("wifi_scanner");

      lcd.setCursor(0, 1);
      lcd.write(0);
      lcd.print("settings");

      int okButton_d = digitalRead(okButton);
      int upButton_d = digitalRead(upButton);
      int downButton_d = digitalRead(downButton);

      if (okButton_d == 1) {
        lcd.setCursor(0, 3);
        lcd.print("Scanning..");

        lcd.setCursor(0, 1);
        lcd.write(1);
        lcd.setCursor(1, 1);
        lcd.write(1);
        delay(1000);

        lcd.setCursor(2, 1);
        lcd.write(1);
        lcd.setCursor(3, 1);
        lcd.write(1);
        delay(500);

        lcd.setCursor(4, 1);
        lcd.write(1);
        lcd.setCursor(5, 1);
        lcd.write(1);
        lcd.setCursor(6, 1);
        lcd.write(1);
        lcd.setCursor(7, 1);
        lcd.write(1);
        delay(200);

        lcd.setCursor(8, 1);
        lcd.write(1);
        lcd.setCursor(9, 1);
        lcd.write(1);
        lcd.setCursor(10, 1);
        lcd.write(1);
        lcd.setCursor(11, 1);
        lcd.write(1);
        delay(500);

        lcd.setCursor(12, 1);
        lcd.write(1);
        lcd.setCursor(13, 1);
        lcd.write(1);
        lcd.setCursor(14, 1);
        lcd.write(1);
        delay(2000);

        lcd.setCursor(15, 1);
        lcd.write(1);
        delay(1000);

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("2 WiFi finded!");
        delay(1500);

        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("1: ");
        lcd.print(networkCount);

        lcd.setCursor(0,1);
        lcd.print("2: ");
        lcd.print(networkCount2);

        delay(2500);

        if (downButton_d == 1) {
          int okButton_d = digitalRead(okButton);
          int upButton_d = digitalRead(upButton);
          int downButton_d = digitalRead(downButton);

          if (okButton_d == 1) {
            lcd.clear();
            
            lcd.setCursor(0, 0);
            lcd.print("BHt v1.3 YLicane"); 

            lcd.setCursor(0, 0);
            lcd.print("RayOS v1.0"); 

            delay(5000);
          }
        }
      }
    }
  }

  okButton_d = digitalRead(okButton);
  upButton_d = digitalRead(upButton);
  downButton_d = digitalRead(downButton);

  if (okButton_d == 1) {
    delay(1500);
    
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("create:fake wifi");

    lcd.setCursor(0, 1);
    lcd.print(".");
    delay(1000);

    lcd.setCursor(0, 1);
    lcd.print("..");
    delay(1000);

    lcd.setCursor(0, 1);
    lcd.print("...");
    delay(1000);

    const char* fake_ssid = "FreeWiFi_5G";

    WiFi.mode(WIFI_AP);
    WiFi.softAP(fake_ssid);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("fake wifi was");

    lcd.setCursor(0, 1);
    lcd.print("Created!");

    delay(2000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("ssid:");

    lcd.setCursor(0, 1);
    lcd.print(fake_ssid);
    
  }

  delay(5000);
  lcd.clear();
}

void boot() {
  lcd.setCursor(0,0);
  lcd.print("Checking Licance");
  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print(".");
  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print("..");
  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print("...");
  delay(1000);

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("RayOS is being prepared.");
  delay(1000);
  
  lcd.clear();
  delay(1000);

  lcd.setCursor(5, 0);
  lcd.print("RayOS");

  lcd.setCursor(0, 1);
  lcd.write(1);
  lcd.setCursor(1, 1);
  lcd.write(1);
  delay(1000);

  lcd.setCursor(2, 1);
  lcd.write(1);
  lcd.setCursor(3, 1);
  lcd.write(1);
  delay(500);

  lcd.setCursor(4, 1);
  lcd.write(1);
  lcd.setCursor(5, 1);
  lcd.write(1);
  lcd.setCursor(6, 1);
  lcd.write(1);
  lcd.setCursor(7, 1);
  lcd.write(1);
  delay(200);

  lcd.setCursor(8, 1);
  lcd.write(1);
  lcd.setCursor(9, 1);
  lcd.write(1);
  lcd.setCursor(10, 1);
  lcd.write(1);
  lcd.setCursor(11, 1);
  lcd.write(1);
  delay(500);

  lcd.setCursor(12, 1);
  lcd.write(1);
  lcd.setCursor(13, 1);
  lcd.write(1);
  lcd.setCursor(14, 1);
  lcd.write(1);
  delay(2000);

  lcd.setCursor(15, 1);
  lcd.write(1);
  delay(1000);

  lcd.clear();
}

void loop() {
  boot();
  Desktop();
  
}

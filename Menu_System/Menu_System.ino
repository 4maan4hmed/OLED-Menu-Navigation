#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define MAX_VISIBLE_ITEMS 4 // Number of menu items visible at a time

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int buttonUpPin = 15;
const int buttonDownPin = 16;
const int buttonSelectPin = 17;
const int buttonBackPin = 18;
const int ledPin = 12; // GPIO pin for the LED

float kp = 60.0;
float ki = 0.0;
float kd = 10.0;
int ledBrightness = 128; // 0-255

float battery = 99;

enum MenuState { MAIN_MENU, BOT_MODE_MENU, LF_MENU, MS_MENU, SETTINGS_MENU, PID_MENU, BRIGHTNESS_MENU };
MenuState currentMenu = MAIN_MENU;

int menuIndex = 0;
int topMenuIndex = 0; // Index of the top visible menu item

const String mainMenuItems[] PROGMEM = {"Bot Mode", "Hardware Check", "Battery Status", "Restart", "Calibration"};
const String botModeMenuItems[] PROGMEM = {"Line Follower Mode", "Maze Solver Mode"};
const String lfMenuItems[] PROGMEM = {"Start", "Check all values", "Settings"};
const String msMenuItems[] PROGMEM = {"Start", "Check all values", "Settings"};
const String settingsMenuItems[] PROGMEM = {"PID Values", "Initial Speed", "Delay Before Start", "Max Speed", "LED Brightness"};
const String pidMenuItems[] PROGMEM = {"Adjust kp", "Adjust ki", "Adjust kd"};

const int mainMenuSize = sizeof(mainMenuItems) / sizeof(mainMenuItems[0]);
const int botModeMenuSize = sizeof(botModeMenuItems) / sizeof(botModeMenuItems[0]);
const int lfMenuSize = sizeof(lfMenuItems) / sizeof(lfMenuItems[0]);
const int msMenuSize = sizeof(msMenuItems) / sizeof(msMenuItems[0]);
const int settingsMenuSize = sizeof(settingsMenuItems) / sizeof(settingsMenuItems[0]);
const int pidMenuSize = sizeof(pidMenuItems) / sizeof(pidMenuItems[0]);

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();

  pinMode(buttonUpPin, INPUT_PULLUP);
  pinMode(buttonDownPin, INPUT_PULLUP);
  pinMode(buttonSelectPin, INPUT_PULLUP);
  pinMode(buttonBackPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  analogWrite(ledPin, ledBrightness); // Set initial brightness

  displayMenu();
}

void loop() {
  if (digitalRead(buttonUpPin) == LOW) {
    menuIndex = (menuIndex - 1 + getCurrentMenuSize()) % getCurrentMenuSize();
    if (menuIndex < topMenuIndex) {
      topMenuIndex = menuIndex;
    }
    displayMenu();
    delay(200);
  }

  if (digitalRead(buttonDownPin) == LOW) {
    menuIndex = (menuIndex + 1) % getCurrentMenuSize();
    if (menuIndex >= topMenuIndex + MAX_VISIBLE_ITEMS) {
      topMenuIndex = menuIndex - MAX_VISIBLE_ITEMS + 1;
    }
    displayMenu();
    delay(200);
  }

  if (digitalRead(buttonSelectPin) == LOW) {
    selectMenuItem();
    delay(200);
  }

  if (digitalRead(buttonBackPin) == LOW) {
    navigateBack();
    delay(200);
  }
}

int getCurrentMenuSize() {
  switch (currentMenu) {
    case MAIN_MENU: return mainMenuSize;
    case BOT_MODE_MENU: return botModeMenuSize;
    case LF_MENU: return lfMenuSize;
    case MS_MENU: return msMenuSize;
    case SETTINGS_MENU: return settingsMenuSize;
    case PID_MENU: return pidMenuSize;
    case BRIGHTNESS_MENU: return 1;
  }
  return 0;
}

void displayMenu() {
  Serial.println(currentMenu);//To know the state of the
  display.clearDisplay();
  display.setTextSize(1.5);
  display.setTextColor(WHITE);

  const String* menuItems;
  int menuSize = getCurrentMenuSize();

  switch (currentMenu) {
    case MAIN_MENU: menuItems = mainMenuItems; break;
    case BOT_MODE_MENU: menuItems = botModeMenuItems; break;
    case LF_MENU: menuItems = lfMenuItems; break;
    case MS_MENU: menuItems = msMenuItems; break;
    case SETTINGS_MENU: menuItems = settingsMenuItems; break;
    case PID_MENU: menuItems = pidMenuItems; break;
    case BRIGHTNESS_MENU:
      displayBrightnessMenu();
      return;
  }

  int endIndex = min(topMenuIndex + MAX_VISIBLE_ITEMS, menuSize);
  for (int i = topMenuIndex; i < endIndex; i++) {
    display.setTextColor(i == menuIndex ? BLACK : WHITE, i == menuIndex ? WHITE : BLACK);
    display.setCursor(0, (i - topMenuIndex) * 15);
    display.println(menuItems[i]);
  }
  display.display();
}

void selectMenuItem() {
  switch (currentMenu) {
    case MAIN_MENU:
      handleMainMenuItem();
      break;
    case BOT_MODE_MENU:
      handleBotModeMenuItem();
      break;
    case LF_MENU:
      handleLFMenuItem();
      break;
    case MS_MENU:
      handleMSMenuItem();
      break;
    case SETTINGS_MENU:
      handleSettingsMenuItem();
      break;
    case PID_MENU:
      adjustPidValue(pidMenuItems[menuIndex]);
      break;
    case BRIGHTNESS_MENU:
      // Nothing to select, just adjusting brightness
      break;
  }
}

void handleMainMenuItem() {
  if (mainMenuItems[menuIndex] == "Bot Mode") {
    currentMenu = BOT_MODE_MENU;
    menuIndex = 0;
    topMenuIndex = 0;
    displayMenu();
  } else if (mainMenuItems[menuIndex] == "Hardware Check") {

  } else if (mainMenuItems[menuIndex] == "Battery Status") {

  } else if (mainMenuItems[menuIndex] == "Restart") {
    
  } else if (mainMenuItems[menuIndex] == "Calibration") {
    
  }
}

void handleLFMenuItem() {
  if (lfMenuItems[menuIndex] == "Check all values") {
    displayValues();
  } else if (lfMenuItems[menuIndex] == "Settings") {
    currentMenu = SETTINGS_MENU;
    menuIndex = 0;
    topMenuIndex = 0;
    displayMenu();
  }
}

void handleMSMenuItem() {
  if (msMenuItems[menuIndex] == "Check all values") {
    displayValues();
  } else if (msMenuItems[menuIndex] == "Settings") {
    currentMenu = SETTINGS_MENU;
    menuIndex = 0;
    topMenuIndex = 0;
    displayMenu();
  }
}

void handleBotModeMenuItem() {
  if (botModeMenuItems[menuIndex] == "Line Follower Mode") {
    currentMenu = LF_MENU;
    menuIndex = 0;
    topMenuIndex = 0;
    displayMenu();
  } else if (botModeMenuItems[menuIndex] == "Maze Solver Mode") {
    currentMenu = MS_MENU;
    menuIndex = 0;
    topMenuIndex = 0;
    displayMenu();
  }
}

void handleSettingsMenuItem() {
  if (settingsMenuItems[menuIndex] == "PID Values") {
    currentMenu = PID_MENU;
    menuIndex = 0;
    topMenuIndex = 0;
    displayMenu();
  } else if (settingsMenuItems[menuIndex] == "LED Brightness") {
    currentMenu = BRIGHTNESS_MENU;
    displayBrightnessMenu();
  }
}

void displayValues() {
  display.clearDisplay();
  display.setTextSize(1.2);
  display.setTextColor(WHITE);
  display.setCursor(0, 12);
  display.print("kp: "); display.println(kp);
  display.setCursor(0, 22);
  display.print("ki: "); display.println(ki);
  display.setCursor(0, 32);
  display.print("kd: "); display.println(kd);
  display.display();
}

void adjustPidValue(String pidItem) {
  float* pidValue;

  if (pidItem == "Adjust kp") pidValue = &kp;
  else if (pidItem == "Adjust ki") pidValue = &ki;
  else if (pidItem == "Adjust kd") pidValue = &kd;
  else return;

  displayPidValue(*pidValue);

  while (true) {
    if (digitalRead(buttonUpPin) == LOW) {
      *pidValue += 0.5;
      displayPidValue(*pidValue);
      delay(200);
    }

    if (digitalRead(buttonDownPin) == LOW) {
      *pidValue -= 0.5;
      displayPidValue(*pidValue);
      delay(200);
    }

    if (digitalRead(buttonBackPin) == LOW) {
      displayMenu();
      break;
    }
  }
}

void displayPidValue(float pidValue) {
  display.clearDisplay();
  display.setTextSize(1.2);
  display.setTextColor(WHITE);
  display.setCursor(0, 12);
  display.print("Value: ");
  display.println(pidValue);
  display.display();
}

void displayBrightnessMenu() {
  display.clearDisplay();
  display.setTextSize(1.2);
  display.setTextColor(WHITE);
  display.setCursor(0, 12);
  display.print("Brightness: ");
  display.println(ledBrightness);
  display.display();

  while (true) {
    if (digitalRead(buttonUpPin) == LOW) {
      ledBrightness = max(0, ledBrightness -5);
      analogWrite(ledPin, ledBrightness);
      displayBrightnessMenu();
      delay(200);
    }

    if (digitalRead(buttonDownPin) == LOW) {
      ledBrightness = min(255, ledBrightness + 5);
      analogWrite(ledPin, ledBrightness);
      displayBrightnessMenu();
      delay(200);
    }

    if (digitalRead(buttonBackPin) == LOW) {
      currentMenu = SETTINGS_MENU;
      menuIndex = 0;
      topMenuIndex = 0;
      displayMenu();
      break;
    }
  }
}

void navigateBack() {
  if (currentMenu == SETTINGS_MENU || mainMenuItems[menuIndex] == "Check all values") {
    currentMenu = MAIN_MENU;
  } else if (currentMenu == PID_MENU) {
    currentMenu = SETTINGS_MENU;
  } else if (currentMenu == BRIGHTNESS_MENU) {
    currentMenu = SETTINGS_MENU;
  } 
    else if(currentMenu == 1 ){
      currentMenu=MAIN_MENU;
    }
    else if(currentMenu == 2 ){
      currentMenu=BOT_MODE_MENU;
    }
    else if(currentMenu == 3 ){
      currentMenu=BOT_MODE_MENU;
    }
   else {
    return;
  }
  menuIndex = 0;
  topMenuIndex = 0;
  displayMenu();
}

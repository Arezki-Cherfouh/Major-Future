#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define NEXT_BTN 12
#define PREV_BTN 14
#define CONFIRM_BTN 13
#define BUZZER_PIN 25  // New Buzzer Pin

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* majors[] = {"Arts", "Business", "Engineering", "Computer Science", "AI"};
int currentMajor = 0;
int numMajors = 5;

// Helper function for sound
void playTone(int frequency, int duration) {
  tone(BUZZER_PIN, frequency, duration);
  delay(duration);
  noTone(BUZZER_PIN);
}

void setup() {
  pinMode(NEXT_BTN, INPUT_PULLUP);
  pinMode(PREV_BTN, INPUT_PULLUP);
  pinMode(CONFIRM_BTN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;);
  }
  showMenu();
}

void loop() {
  if (digitalRead(NEXT_BTN) == LOW) {
    currentMajor = (currentMajor + 1) % numMajors;
    playTone(1000, 50); // Short high beep
    showMenu();
    delay(200); 
  }
  
  if (digitalRead(PREV_BTN) == LOW) {
    currentMajor = (currentMajor - 1 + numMajors) % numMajors;
    playTone(800, 50); // Slightly lower beep
    showMenu();
    delay(200);
  }

  if (digitalRead(CONFIRM_BTN) == LOW) {
    playTone(1500, 100); // Selection chirp
    runPrediction();
    showMenu(); 
  }
}

void showMenu() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Select Major:");
  display.drawFastHLine(0, 12, 128, SSD1306_WHITE);
  
  display.setCursor(0, 30);
  display.setTextSize(2);
  display.println(majors[currentMajor]);
  display.display();
}

void runPrediction() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.print("Predicting future");
  display.display();

  for(int i=0; i<3; i++) {
    delay(500);
    playTone(2000, 30); // Thinking "ticks"
    display.print(".");
    display.display();
  }

  delay(500);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print("You will be great");
  display.display();

  if (currentMajor >= 2) {
    // The "Sad" Sound Effect
    playTone(1000, 200); 
    delay(1500);
    
    display.print("ly depressed");
    display.display();
    
    // Sad Trombone style sound
    playTone(300, 500); 
    playTone(200, 800);
    
    delay(3500); 
  } else {
    // Happy Sound for Arts/Business
    playTone(1500, 100);
    playTone(2000, 300);
    delay(3000); 
  }
}






// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64

// // Button Pins for ESP32
// #define NEXT_BTN 12
// #define PREV_BTN 14
// #define CONFIRM_BTN 13

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// const char* majors[] = {"Arts", "Business", "Engineering", "Computer Science", "AI"};
// int currentMajor = 0;
// int numMajors = 5;

// void setup() {
//   // Setup buttons with internal pullups
//   pinMode(NEXT_BTN, INPUT_PULLUP);
//   pinMode(PREV_BTN, INPUT_PULLUP);
//   pinMode(CONFIRM_BTN, INPUT_PULLUP);
  
//   // Initialize I2C Display (ESP32 uses 21/22 by default)
//   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
//     for(;;); 
//   }
  
//   showMenu();
// }

// void loop() {
//   // Navigation: Next
//   if (digitalRead(NEXT_BTN) == LOW) {
//     currentMajor = (currentMajor + 1) % numMajors;
//     showMenu();
//     delay(200); // Debounce delay
//   }
  
//   // Navigation: Previous
//   if (digitalRead(PREV_BTN) == LOW) {
//     currentMajor = (currentMajor - 1 + numMajors) % numMajors;
//     showMenu();
//     delay(200); 
//   }

//   // Selection: Confirm
//   if (digitalRead(CONFIRM_BTN) == LOW) {
//     runPrediction();
//     showMenu(); // Return to selection screen after prediction
//   }
// }

// void showMenu() {
//   display.clearDisplay();
//   display.setTextSize(1);
//   display.setTextColor(SSD1306_WHITE);
//   display.setCursor(0, 0);
//   display.println("Select Major:");
//   display.drawFastHLine(0, 12, 128, SSD1306_WHITE);
  
//   display.setCursor(0, 30);
//   display.setTextSize(2);
//   display.println(majors[currentMajor]);
//   display.display();
// }

// void runPrediction() {
//   display.clearDisplay();
//   display.setTextSize(1);
//   display.setCursor(0, 20);
//   display.print("Predicting future");
//   display.display();
  
//   // Animation loop
//   for(int i=0; i<3; i++) {
//     delay(500);
//     display.print(".");
//     display.display();
//   }
  
//   delay(500);
//   display.clearDisplay();
//   display.setTextSize(2);
//   display.setCursor(0, 10);
//   // display.println("You will");
//   // display.println("be great");
//   display.print("You will be great");
//   display.display();

//   // The Joke Logic
//   // 2=Engineering, 3=CS, 4=AI
//   if (currentMajor >= 2) { 
//     delay(1500); 
//     // display.setCursor(0, 45);
//     // display.println("ly depressed");
//     display.print("ly depressed");
//     display.display();
//     delay(3500); // Give time to read the punchline
//   } else {
//     delay(3000); // Stay on "You will be great"
//   }
// }
/*
 * The Sentinel: Context-Aware Desk Lamp
 * Controls a light based on ambient light and presence.
 * Uses non-blocking fade for smooth transitions.
 */

// Pins
const int ldrPin = A0;
const int irSensorPin = 2;
const int lightPin = 9;

// Settings - CALIBRATE THESE FOR YOUR ENVIRONMENT
const int darkThreshold = 700; // LDR value below which it's "dark" (LDR gets higher in darkness)
const unsigned long fadeDuration = 1500; // Time in ms for full fade in/out

// State Tracking
bool isDark = false;
bool isPersonPresent = false;
int targetBrightness = 0; // What brightness we are fading to (0-255)
int currentBrightness = 0; // Current PWM value of the light

// Non-blocking fade control
unsigned long previousFadeMillis = 0;
const int fadeInterval = 20; // Update every 20ms for smoothness

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(lightPin, OUTPUT);
  
  // For debugging and calibration - Open Serial Monitor and see the LDR values!
  Serial.begin(9600);
  Serial.println("The Sentinel Desk Lamp - Initialized");
  Serial.println("LDR Value | Person Present | Current Brightness");
}

void loop() {
  // 1. Read Sensors
  int ldrValue = analogRead(ldrPin);
  // HW-477 is ACTIVE-LOW: reads LOW when obstacle detected
  isPersonPresent = (digitalRead(irSensorPin) == LOW);
  isDark = (ldrValue > darkThreshold); 

  // 2. Determine what the target should be based on conditions
  if (isDark && isPersonPresent) {
    targetBrightness = 255; // Fade ON
  } else {
    targetBrightness = 0;   // Fade OFF
  }

  // 3. Handle the non-blocking fade towards the target
  unsigned long currentMillis = millis();
  if (currentMillis - previousFadeMillis >= fadeInterval) {
    previousFadeMillis = currentMillis;

    if (currentBrightness != targetBrightness) {
      // Move current brightness one step closer to target
      currentBrightness += (currentBrightness < targetBrightness) ? 1 : -1;
      analogWrite(lightPin, currentBrightness);
    }
  }

  // 4. (Optional) Serial Print for Debugging and Calibration
  Serial.print(ldrValue);
  Serial.print("        | ");
  Serial.print(isPersonPresent ? "YES          " : "NO           ");
  Serial.print(" | ");
  Serial.println(currentBrightness);
  
  // A small delay to stabilize readings, not necessary for fade
  delay(50);
}
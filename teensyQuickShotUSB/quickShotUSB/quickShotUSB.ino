//QuickShot QS-1130F
//MSX mode (2 button)
//pins used 0-5 (pull-up mode)
//0: up (J1)
//1: down (J2)
//2: left (J3)
//3: right (J4)
//4: button1 (J6)
//5: button2 (J7)
//J8: will be GND shotrted with joystick activity
//J5: +5V (from board's Vin)
//J9: GND (from boards GND)

#define PIN_D0 0
#define PIN_D1 1
#define PIN_D2 2
#define PIN_D3 3
#define PIN_D4 4
#define PIN_D5 5
#define LED_PIN 6

//joystick status
int jB1 = 0;
int jB2 = 0;
int jHat = -1;
int jX = 1;
int jY = 1;

bool ledPin = false;

int jHatLookup[3][3] = {{315,   0,  45},
                        {270,  -1,  90},
                        {225, 180, 135}};

IntervalTimer myTimer;

void handleJoystick() {
  Joystick.button(1, jB1);
  Joystick.button(2, jB2); 
  Joystick.hat(jHat);
  Joystick.send_now();

  if(ledPin)
  {
    digitalWrite(LED_PIN, HIGH);
    ledPin = false;
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    ledPin = true;
  }
}

void setup() {
  //setup pins
  pinMode(PIN_D0, INPUT_PULLUP);//up
  pinMode(PIN_D1, INPUT_PULLUP);//down
  pinMode(PIN_D2, INPUT_PULLUP);//left
  pinMode(PIN_D3, INPUT_PULLUP);//right
  pinMode(PIN_D4, INPUT_PULLUP);//button1
  pinMode(PIN_D5, INPUT_PULLUP);//button2

  pinMode(LED_PIN, OUTPUT);

  //joystcik manuel send mode
  Joystick.useManualSend(true);

  //setup timer
  myTimer.begin(handleJoystick, 20000);//50Hz refresh rate
}

void loop() {
  // put your main code here, to run repeatedly:
  jX = 1;
  jY = 1;
  jB1 = 0;
  jB2 = 0;
  if (!digitalRead(PIN_D0))
    jY = 0;  
  if (!digitalRead(PIN_D1))
    jY = 2;
  if (!digitalRead(PIN_D2))
    jX = 0;
  if (!digitalRead(PIN_D3))
    jX = 2;
  jHat = jHatLookup [jX][jY];
  if (!digitalRead(PIN_D4))
    jB1 = 1;
  if (!digitalRead(PIN_D5))
    jB2 = 1;   
}

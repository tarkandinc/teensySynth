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

#define PIN_UP    0
#define PIN_DOWN  1
#define PIN_LEFT  2
#define PIN_RIGHT 3
#define PIN_FIRE1 4
#define PIN_FIRE2 5
#define PIN_STAT  13

#define USB_MANUAL_SEND
#define STATUS_BLINK

//joystick status
int jB1 = 0;
int jB2 = 0;
int jHat = -1;
int jX = 1;
int jY = 1;

#ifdef STATUS_BLINK
bool ledPin = false;
#endif

int jHatLookup[3][3] = {{315,   0,  45},
                        {270,  -1,  90},
                        {225, 180, 135}};

IntervalTimer myTimer;

void handleJoystick() {
  Joystick.button(1, jB1);
  Joystick.button(2, jB2); 
  Joystick.hat(jHat);
#ifdef USB_MANUAL_SEND
  Joystick.send_now();
#endif

#ifdef STATUS_BLINK
  if(ledPin)
  {
    digitalWrite(PIN_STAT, HIGH);
    ledPin = false;
  }
  else
  {
    digitalWrite(PIN_STAT, LOW);
    ledPin = true;
  }
}
#endif

void setup() {
  //setup pins
  pinMode(PIN_UP,    INPUT_PULLUP);//up
  pinMode(PIN_DOWN,  INPUT_PULLUP);//down
  pinMode(PIN_LEFT,  INPUT_PULLUP);//left
  pinMode(PIN_RIGHT, INPUT_PULLUP);//right
  pinMode(PIN_FIRE1, INPUT_PULLUP);//button1
  pinMode(PIN_FIRE2, INPUT_PULLUP);//button2

#ifdef STATUS_BLINK
  pinMode(PIN_STAT, OUTPUT);
#endif

  //joystcik manuel send mode
#ifdef USB_MANUAL_SEND
  Joystick.useManualSend(true);
#endif

  //setup timer
  myTimer.begin(handleJoystick, 20000);//50Hz refresh rate
}

void loop() {
  // put your main code here, to run repeatedly:
  //default center
  jX = 1;
  jY = 1;
  //default off
  jB1 = 0;
  jB2 = 0;
  //read pins
  if (!digitalRead(PIN_UP))
    jY = 0;  
  if (!digitalRead(PIN_DOWN))
    jY = 2;
  if (!digitalRead(PIN_LEFT))
    jX = 0;
  if (!digitalRead(PIN_RIGHT))
    jX = 2;
  jHat = jHatLookup [jX][jY];
  if (!digitalRead(PIN_FIRE1))
    jB1 = 1;
  if (!digitalRead(PIN_FIRE2))
    jB2 = 1;   
}

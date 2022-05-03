//QuickShot QS-1130F
//MSX mode (2 button)
//pins used 0-5 (pull-up mode)
//inputs are low active
//0: up (J1)
//1: down (J2)
//2: left (J3)
//3: right (J4)
//4: button1 (J6)
//5: button2 (J7)
//J8: Common (GND)
//J5: +5V (from board's Vin)
//J9: GND (from boards GND)

//DB-9 MSX MODE PINOUT
// UP  DN   LE  RH  5V
//   F1  F2   CM  0V

#define PIN_UP    0
#define PIN_DOWN  1
#define PIN_LEFT  2
#define PIN_RIGHT 3
#define PIN_FIRE1 4
#define PIN_FIRE2 5
#define PIN_STAT  13

#define HZ_50 20000

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

//dpad 0 is up
int jHatLookup[3][3] = {{315,   0,  45},
                        {270,  -1,  90},
                        {225, 180, 135}};

IntervalTimer myTimer;

void handleJoystick()
{
  //read pins
  jY = digitalRead(PIN_UP);//if up jY=0, not jY=1
  jY = 2 - digitalRead(PIN_DOWN);//if down jY=2, not jY=1
  jX = digitalRead(PIN_LEFT);//if left jX=0, not jX=1
  jX = 2 - digitalRead(PIN_RIGHT);//if right jX=2, not jX=1
  jHat = jHatLookup [jX][jY];
  jB1 = 1 - digitalRead(PIN_FIRE1);
  jB2 = 1 - digitalRead(PIN_FIRE2);
  
  //usb josytick data
  Joystick.button(1, jB1);
  Joystick.button(2, jB2); 
  Joystick.hat(jHat);
#ifdef USB_MANUAL_SEND
  Joystick.send_now();
#endif

#ifdef STATUS_BLINK
  if(ledPin=!ledPin)
    digitalWrite(PIN_STAT, HIGH);
  else
    digitalWrite(PIN_STAT, LOW);
}
#endif

void setup()
{
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

  //joystcik manual send mode
#ifdef USB_MANUAL_SEND
  Joystick.useManualSend(true);
#endif

  //setup timer
  myTimer.begin(handleJoystick, HZ_50);//50Hz refresh rate
}

void loop()
{
  // put your main code here, to run repeatedly:  
}

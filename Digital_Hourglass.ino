const int switchPin = 8;                //Switch wired to pin 8. Setting up value for variable switchPin that will come into play later
unsigned long previousTime = 0;         //Initialize other variables
int switchState = 0;
int previousState = 0;

int led = 2;                            //LED wired to pin 2
long interval = 2000;                   //interval = 2000 milliseconds

void setup() {
  // setup code here, to run once:
  
  for (int x = 2; x<8; x++){            //for loop pins 2 through 7
    pinMode(x, OUTPUT);                 //set pinMode to output
  }

  pinMode(switchPin, INPUT);            //pinMode of pin 8 set to input
}

void loop() {
  // main code here, to run repeatedly:

  unsigned long currentTime = millis();                 //time since start of program is recorded

  if ((currentTime - previousTime) > interval) {        //if current time - previous time > the 2000 millisecond interval
    previousTime = currentTime;                         //set previousTime = currentTime
    digitalWrite(led, HIGH);                            //turn on led coming from pin 2
    led++;                                              //set led = pin 3

  }

  switchState = digitalRead(switchPin);                 //read input from pin 8

  if (switchState != previousState) {                   //if input from pin 8 does not equal previous state (= 0)
    for (int x = 2; x < 8; x++) {                       //loop through 2 through 7
      digitalWrite(x, LOW);                             //turn output low for each turning off led's
    }
    led = 2;                                            //reset led = 2 resetting led loop
    previousTime = currentTime;                         //set previousTime = currentTime resetting timer
  }
  
  previousState = switchState;                          //reset switchState = 0
  
}

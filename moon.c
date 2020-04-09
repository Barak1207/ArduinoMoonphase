//It takes our Moon about 29.53 days to complete one cycle of phases (from new Moon to new Moon)
//29.53 days is 708.72 hours
//2048 steps is for a full rotation of the disk, moon to moon is half a rotation.
//=> (2048/2) / 708.72 = 1.44485... steps in an hour
//=> 3600/1.44485.. = 2491.593... so we'll do a step every 2491.6 seconds.
#define STEPS_IN_ROTATION 2048
#define STEP_EVERY_N_SECONDS 2491
#define BASE_DELAY 100 //milliseconds
//#define BASE_DELAYS_IN_A_SECOND 1000 / BASE_DELAY

#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

#define BUTTON_PIN A6 //Yes it's analog, no you can't ask why

#define NUMBER_LEDS 7
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6
#define LED_6 7
#define LED_7 8

#define CLOCKWISE false
#define COUNTER_CLOCKWISE true

int led_pin_array[NUMBER_LEDS] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7};

int step_number = 0;
int delay_counter = 0;
int seconds = 0;

void setup()
{
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);

  randomSeed(analogRead(0));
}

void loop() 
{
  //Adjust position of moon by button
  if (analogRead(BUTTON_PIN) == 1023)
  {
    int i;
    for (i=0;i<1024/128; i++)
    {
      oneStep(CLOCKWISE);
      delay(5);
    }
  }
  


  if (delay_counter == 1000)//A second has passed
  {
    delay_counter = 0;
    seconds++;
  }
  //Step every 2491.6 seconds
  if (seconds == STEP_EVERY_N_SECONDS && delay_counter == 600)
  {
    seconds = 0;
    oneStep(CLOCKWISE);
  }
  doLEDs();
  delay_counter += BASE_DELAY;  
  delay(BASE_DELAY);
}

void doLEDs()
{
  int i; 
  for(i=0; i < NUMBER_LEDS; i++)
  {
    //random(N)==0 determines chance for LED to be on
    digitalWrite(led_pin_array[i], random(150)==0);
  }
}



void oneStep(bool direction)
{//"Written By Nikodem Bartnik - nikodembartnik.pl"
  if(direction)
  {
    switch(step_number)
    {
      case 0:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        break;
    }
  }
  else
  {
    switch(step_number)
    {
      case 0:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
    }
  }
    step_number++;
    if(step_number == 4)
    {
      step_number = 0;
    }
}


// set up for moisture
float humidPercentage = humidPercentage;


//set up for RGB LED Light
int redpin = 11; // select the pin for the red LED
int bluepin = 10; // select the pin for the blue LED
int greenpin = 9 ;// select the pin for the green LED
int val;

void setup() {
  // set up for moisture
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps

  //set up for RGB LED Light
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
  
}

void loop() {
  //Set up for moisture
  int val;
  val = analogRead(0); //connect sensor to Analog 0
  humidPercentage = (float(val)/1023)*100;
  Serial.print(humidPercentage); //print the value to serial port
  Serial.print("%");
  Serial.print("\n");
  delay(1000);

  //set up for RGB LED Light
  if (humidPercentage >= 70)
  {
    analogWrite (11, 0);
    analogWrite (10, 255);
    analogWrite (9, 0);
  }
  else if (humidPercentage <= 20)
  {
    analogWrite (11, 255);
    analogWrite (10, 0);
    analogWrite (9, 0);
  }
  else
  {
    analogWrite (11, 0);
    analogWrite (10, 0);
    analogWrite (9, 255);
  }
}


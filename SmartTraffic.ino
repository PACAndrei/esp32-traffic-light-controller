#define gLED      25
#define yLED      26
#define rLED      27
#define ForceG     4
#define LDR_pin   34

const int dark_Threshold = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(gLED, OUTPUT);
  pinMode(yLED, OUTPUT);
  pinMode(rLED, OUTPUT);
  pinMode(ForceG, INPUT_PULLUP);
  pinMode(LDR_pin, INPUT);

  Serial.begin(115200);
}

void traffic_light()
{
  
  digitalWrite(rLED,HIGH);
  delay(1500);
  digitalWrite(rLED,LOW);

  digitalWrite(gLED,HIGH);
  delay(1000);
  digitalWrite(gLED,LOW);

  digitalWrite(yLED,HIGH);
  delay(500);
  digitalWrite(yLED,LOW);

}

void forced_green()
{
    digitalWrite(rLED, LOW);
    digitalWrite(yLED, LOW);
    digitalWrite(gLED, HIGH);
    delay(2000);
    digitalWrite(gLED, LOW);
}

void energy_save()
{
  digitalWrite(rLED, LOW);
  digitalWrite(gLED, LOW);
  while(analogRead(LDR_pin) < dark_Threshold)
  {
    digitalWrite(yLED, HIGH);
    delay(500);
    digitalWrite(yLED, LOW);
    delay(500);
  }
}

void logic()
{
  int ldrValue = analogRead(LDR_pin);

  if (ldrValue < dark_Threshold) 
  {
    energy_save();
  }

  if (digitalRead(ForceG) == LOW) 
  {
    forced_green();
  } 
  else 
  {
    traffic_light();
  }
}

void loop() {
  /* 
  //Debugging
  int light = analogRead(LDR_pin); 
  Serial.println(light);
  delay(500);
  */
  logic();
  
}

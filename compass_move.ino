
#include <Wire.h>
#include <LSM303.h>

LSM303 compass;

char report[80];
char text;
int counter =0;
unsigned long startTime = 0;

#define m11 11    // موتور راست
#define m12 12
#define m21 9    // موتور چپ
#define m22 10


void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
}

void left()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   delay(100);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}

void right()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   delay(100);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}

void setup() {
  Serial.begin(9600); // تنظیم نرخ ارتباط سریال
  pinMode(m11, OUTPUT); // تنظیم به عنوان خروجی
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>){-32767, -32767, -32767};
  compass.m_max = (LSM303::vector<int16_t>){+32767, +32767, +32767};
} 

void loop() {
  
  compass.read();

  float heading1 = compass.heading();
  String buf = String(heading1, 2);
  Serial.println(sizeof(buf));

  delay(200);
   
  text = Serial.read(); 

  if(text !='1' && text !='2' && text !='3' && text !='4')
  { 
   if (millis() - startTime > 1000){
    Stop();
    }
  }

  
  if (text=='1')
  {
    
    forward();
    startTime = millis(); 
  }

   else if (text=='4')
  {
    startTime = millis();
    backward();
  }

   else if (text=='2')
  {
    startTime = millis();
    right();
  }

   else if (text=='3')
  {
    startTime = millis();
    left();
  }

  
}

String text; 

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
} 

void loop() {
  while (Serial.available())
  { 
  delay(10); 
  char c = Serial.read(); 
  text += c; 
  }  
  if (text.length() > 0)
  {
    Serial.println(text); 
    
       if(text == "1")
       {
         forward();
         
        }  
      else if(text == "4")
      {
        backward();
      }
      else if(text == "2")
      {
        right();
      }
      else if(text == "3")
      {
        left();
      }
      else{
        Stop();
        }

text="";
}
}

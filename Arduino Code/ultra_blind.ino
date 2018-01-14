const int echo = 11, Trig = 12;
const int echo1 = 9, Trig1 = 10;

void setup() {
Serial.begin(38400);
pinMode(Trig1, OUTPUT);
pinMode(echo1, INPUT);
pinMode(Trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(13, OUTPUT);
pinMode(8, OUTPUT);
}
void loop()
{
long left,right;
left=ping_me(Trig1,echo1);
right=ping_me(Trig,echo);
int a=0,b=1,c=2,d=3;
if(left<50 && right<50)
{
//Serial.write(d);
digitalWrite(13,HIGH);
digitalWrite(8,HIGH);
}
else if(left<50)
{
//Serial.write(b);
digitalWrite(13,HIGH);
}
else if(right<50)
{
//Serial.write(c);
digitalWrite(8,HIGH);
}
else
{
//Serial.write(a);
digitalWrite(8,LOW);
digitalWrite(13,LOW);
}
//Serial.print("left  ");
//Serial.print(left);
//Serial.print("  right");
//Serial.println(right);
}

long ping_me(int T,int e)
{
long duration, inches, cm;
digitalWrite(T, LOW);
delayMicroseconds(2);
digitalWrite(T, HIGH);
delayMicroseconds(10);
digitalWrite(T, LOW);
duration = pulseIn(e, HIGH);
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
//Serial.print(inches);
//Serial.print("in, ");
//Serial.print(cm);
//Serial.print("cm");
//Serial.println();
delay(100);
return cm;
}
long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}

  
  
  
enum pin
{
  p2 = 2,
  p3,
  p4,
  p5,
  p6,
  p7,
  p8,
  p9,
  p10,
  p11,
  p12,
  p13
};


void setup()
{
  for( int i = 2; i <= 13; i++ )
  {
    pinMode( i, OUTPUT );
    digitalWrite(i, LOW);
  }
}

void loop()
{
  delay(500);
  digitalWrite( p3, !digitalRead( p3 ));

}

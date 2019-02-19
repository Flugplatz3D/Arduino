void setup()
{
Serial.begin(9600);
}

void loop()
{
Serial.print( millis() );
Serial.println("");
delay( 1000 );
}



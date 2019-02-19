int dirFA = 12;
int dirRA = 8;
int dirB = 13;  // not used in this example
int speedA = 10;
int speedB = 11; // not used in this example

void setup()
{
	pinMode (dirFA, OUTPUT);
	pinMode (dirRA, OUTPUT);
	pinMode (dirB, OUTPUT);
	pinMode (speedA, OUTPUT);
	pinMode (speedB, OUTPUT);
}

void loop()
{
	digitalWrite (dirRA, HIGH);
	// move the motor A to one direction increasing speed
	digitalWrite (dirFA, LOW);
	for (int j = 0; j < 255; j += 10)
	{
		analogWrite (speedA, j);
		delay (100);
	}

	delay(2000); // keep the motor rolling for one second

	// move the motor A to one direction decreasing speed
	digitalWrite (dirFA, LOW);
	for (int j = 255; j >= 0; j -= 10)
	{
		analogWrite (speedA, j);
		delay (100);
	}

	// stop the motor
	digitalWrite(speedA, LOW);

	delay(2000); // keep the motor stopped for one second

	digitalWrite (dirFA, HIGH);
	// move the motor A to one direction increasing speed
	digitalWrite (dirRA, LOW);
	for (int j = 0; j < 255; j += 10)
	{
		analogWrite (speedA, j);
		delay (100);
	}

	delay(2000); // keep the motor rolling for one second

	// move the motor A to one direction decreasing speed
	digitalWrite (dirRA, LOW);
	for (int j = 255; j >= 0; j -= 10)
	{
		analogWrite (speedA, j);
		delay (100);
	}

	// stop the motor
	digitalWrite(speedA, LOW);

	delay(2000); // keep the motor stopped for one second
}

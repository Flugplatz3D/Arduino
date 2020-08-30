long start       = 0;
int  max_seconds = 30;
long i           = 2; // Start at 2
long found       = 0; // Number of primes we've found

void setup() {
  Serial.begin(115200);

  while (!Serial) { }

  Serial.println("");
  Serial.print("Running prime benchmark for ");
  Serial.print(max_seconds);
  Serial.println(" seconds...");

  start = millis();
}

void loop() {
  int prime = is_prime(i); // Check if the number we're on is prime

  if (prime == 1) {
    found++;

    if (found % 2000 == 0) {
      Serial.print(".");
    }

    if (found % 50000 == 0) {
      Serial.print("\n");
    }
  }

  int running_seconds = (millis() - start) / 1000;

  if (max_seconds > 0 && (running_seconds >= max_seconds)) {
    Serial.print("\nFound ");
    Serial.print(found);
    Serial.print(" primes in ");
    Serial.print(max_seconds);
    Serial.println(" seconds");
    delay(10000);

    i     = 2;
    found = 0;
    start = millis();
  }

  i++;
}

int is_prime(long num) {
  // Only have to check for divisible for the sqrt(number)
  int upper = sqrt(num);

  // Check if the number is evenly divisible (start at 2 going up)
  for (long cnum = 2; cnum <= upper; cnum++) {
    long mod = num % cnum; // Remainder

    if (mod == 0) {
      return 0;
    } // If the remainer is 0 it's evenly divisible
  }

  return 1; // If you get this far it's prime
}

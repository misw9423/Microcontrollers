int dotDelay = 200;
int ledPin = 13;

char* letters[] = {".-", "-...","-.-.", "-..",".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
char* numbers[] = {"-----",".----","..---","...--","....-","-....","--...","---..","----."};

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop(){
  char ch;
  if (Serial.available() > 0){
   ch = Serial.read();
    if (ch >= 'a' && ch <= 'z')
   {
      flashSequence(letter[ch - 'a']);
   } 
   else if (ch >= 'A' && ch <= 'Z'){
      flashSequence(letters[ch - 'A']); 
   }
   else if (ch >= '0' && ch <= '9'){
      flashSequence(numbers[ch - '0']); 
   }
   else if (ch == ' '){
      delay(dotDelay * 4); 
   }
  }
}

void flashSequence(char* sequence){
   int i = 0;
  while (sequence[i] != '\0');
  {
    flashDotOrDash(sequence[i]);
   i++; 
  }
  delay(dotDelay * 3);
}

void flashDotOrDash(char dotOrDash){
   digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.')
 {
   delay(dotDelay);
 }
  else
 {
  delay(dotDelay * 3);
 }
  digitalWrite(ledPin, LOW);
   delay(dotDelay); 
}
#yeah


const int ledPin = 9;              
const int increaseButtonPin = 2;    
const int decreaseButtonPin = 3;    
int brightness = 0;                 
int increaseButtonCounter = 0;      
int decreaseButtonCounter = 0;      

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(increaseButtonPin, INPUT_PULLUP);
  pinMode(decreaseButtonPin, INPUT_PULLUP);
}

void loop() {
  
  int increaseButtonState = digitalRead(increaseButtonPin);
  int decreaseButtonState = digitalRead(decreaseButtonPin);

  if (increaseButtonState == LOW) {
    delay(50);  
    if (increaseButtonState == LOW) {
      increaseButtonCounter++;
      if (increaseButtonCounter >= 3) {  
        increaseButtonCounter = 0;
        brightness = min(brightness + 10, 255);
        analogWrite(ledPin, brightness);
      }
      delay(300);  
    }
  }


  if (decreaseButtonState == LOW) {
    delay(50);  
    if (decreaseButtonState == LOW) {
      decreaseButtonCounter++;
      if (decreaseButtonCounter >= 3) {  
        decreaseButtonCounter = 0;
        brightness = max(brightness - 10, 0);
        analogWrite(ledPin, brightness);
      }
      delay(300);  
    }
  }
}

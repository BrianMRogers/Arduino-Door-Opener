
int analogPinA0 = A0;
int micInput;

//Demo button temporarily substituting for the microphone input. This code establishes what pin they're connected to on the arduino.
int mainButton = 4;

//Demo Light for code ensurance. This code establishes the pin number thats connected to the LED, just like the 'mainButton' int
int whiteTestLed = 11;

//Servo Pin
int servoPin = 9;
#include <Servo.h>
Servo name_servo;

//Int values for duration of on/off times
int holdingDuration;
int nonHoldingDuration;



//keyWord is the string that collects all short (S) and long (L) inputs
String keyWord;

//translation is the string that recieves and hold the interpretations of the morse. This value should match the password
String translation;

//passWord is the collection of values that I want to be entered in morse
String passWord = "YOUR PASSCODE HERE";


void setup() 
  {
    //Start Serial and establish button connection and light output
    Serial.begin(9600);
    pinMode(whiteTestLed, OUTPUT);
    name_servo.attach(9);
    name_servo.write(0);
    
  }



void loop() 
  {
  
    //If the device reads a low power, then the button is pressed which then leads into the following commands
  micInput = analogRead(analogPinA0);
    
  if(micInput > 600)
    {
    
      digitalWrite(whiteTestLed, HIGH);
      Serial.println("On");
      
//Here lies holdingDuration

      for(int i = 0; i < 8; i++)
     {
        micInput += analogRead(analogPinA0);
        Serial.println(micInput);
        delay(150);
     }

      //if statement decides whether to add a long press or short press to the sequence based on how long the 'holdingDuration' value was held for
      if(micInput > 2300)
      {
        //Add long press string to the code entrance string/sequence
        keyWord += "L";
      }
      else if(micInput < 2300)
      {
        //Add short press string to the code entrance string/sequence
        keyWord += "S"; 
      }
      
      
      micInput = 0;
      //holdingDuration = 0;
      //Create off time here for making spaces in the final string
      
      //This allows me to monitor the serial log
      Serial.println(keyWord);
      delay(200);
      
      while(analogRead(analogPinA0) < 600)
      {
        //Serial.println(nonHoldingDuration);
        nonHoldingDuration ++;
        delay(100);

        //This code decides whether the button hasn't been held for long enough to create a space in the final string
        if(nonHoldingDuration > 40)
          {
          //Add space string to the code entrance string/sequence
            keyWord += " ";
            translate(keyWord);
            nonHoldingDuration = 0;
            break;
          }
          else if(analogRead(analogPinA0) > 600)
          {
            nonHoldingDuration = 0;
            break;
          }
        
      }
      
    }


  
  //If the device reads a HIGH power, then the button is not pressed. THIS SECTION IS SET

  
  if(analogRead(analogPinA0 < 600))
    {
      digitalWrite(whiteTestLed, LOW);
      Serial.println(nonHoldingDuration);
      delay(100);
      nonHoldingDuration ++;
      if(nonHoldingDuration > 19)
      {
        if(translation.equals(passWord))
        {
          Serial.println("CORRECT PASSWORD");
          //Activate servo here **The numbers should be changed so it only moves the arm enough to press the button and release from beneath the phone.**
          name_servo.write(180);
          Serial.println("OPEN");
          delay(5000);
          name_servo.write(0);
          Serial.println("CLOSED");
        }
        
        keyWord = "";
        translation = "";
        nonHoldingDuration = 0;
        Serial.println("ENTRY CLEARED");
      }
      
    }  
  }

// MORSE CHARACTER LIST

void translate(String methodKey)
  {
    keyWord = methodKey;

    //LETTER A
    if(methodKey.equals("SL "))
    {
      translation += "A";  
      Serial.println(translation);
    }
    
    //LETTER B
    if(methodKey.equals("LSSS "))
    {
      translation += "B";  
      Serial.println(translation);
    }
    
    //LETTER C
    if(methodKey.equals("LSLS "))
    {
      translation += "C";  
      Serial.println(translation);
    }

    //LETTER D
    if(methodKey.equals("LSS "))
    {
      translation += "D";  
      Serial.println(translation);
    }

    //LETTER E
    if(methodKey.equals("S "))
    {
      translation += "E";  
      Serial.println(translation);
    }

    //LETTER F
    if(methodKey.equals("SSLS "))
    {
      translation += "F";  
      Serial.println(translation);
    }
    //LETTER G
    if(methodKey.equals("LLS "))
    {
      translation += "G";  
      Serial.println(translation);
    }
    //LETTER H
    if(methodKey.equals("SSSS "))
    {
      translation += "H";  
      Serial.println(translation);
    }
    //LETTER I
    if(methodKey.equals("SS "))
    {
      translation += "I";  
      Serial.println(translation);
    }
    //LETTER J
    if(methodKey.equals("SLLL "))
    {
      translation += "F";  
      Serial.println(translation);
    }
    //LETTER K
    if(methodKey.equals("LSL "))
    {
      translation += "K";  
      Serial.println(translation);
    }
    //LETTER L
    if(methodKey.equals("SLSS "))
    {
      translation += "L";  
      Serial.println(translation);
    }
    //LETTER M
    if(methodKey.equals("LS "))
    {
      translation += "M";  
      Serial.println(translation);
    }
    //LETTER N
    if(methodKey.equals("LL "))
    {
      translation += "N";  
      Serial.println(translation);
    }
    //LETTER O
    if(methodKey.equals("LLL "))
    {
      translation += "O";  
      Serial.println(translation);
    }
    //LETTER P
    if(methodKey.equals("SLLS "))
    {
      translation += "P";  
      Serial.println(translation);
    }
    //LETTER Q
    if(methodKey.equals("LLSL "))
    {
      translation += "Q";  
      Serial.println(translation);
    }
    //LETTER R
    if(methodKey.equals("SLS "))
    {
      translation += "R";  
      Serial.println(translation);
    }
    //LETTER S
    if(methodKey.equals("SSS "))
    {
      translation += "S";  
      Serial.println(translation);
    }
    //LETTER T
    if(methodKey.equals("L "))
    {
      translation += "T";  
      Serial.println(translation);
    }
    //LETTER U
    if(methodKey.equals("SSL "))
    {
      translation += "U";  
      Serial.println(translation);
    }
    //LETTER V
    if(methodKey.equals("SSSL "))
    {
      translation += "V";  
      Serial.println(translation);
    }
    //LETTER W
    if(methodKey.equals("SLL "))
    {
      translation += "W";  
      Serial.println(translation);
    }
    //LETTER X
    if(methodKey.equals("LSSL "))
    {
      translation += "X";  
      Serial.println(translation);
    }
    //LETTER Y
    if(methodKey.equals("LSLL "))
    {
      translation += "Y";  
      Serial.println(translation);
    }
    //LETTER Z
    if(methodKey.equals("LLSS "))
    {
      translation += "Z";  
      Serial.println(translation);
    }
    keyWord = "";
    //translation = "";
  }

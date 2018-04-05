//Chose the option pin
#define optionPin  12

//Encoder
#define dotPeriod 200 /*dot is 1 unit*/
#define dashPeriod dotPeriod*3 /*dash is 3 unit*/
#define relaxTime dotPeriod*2
#define letterSpace dotPeriod*3 /*space between letters is 3 units*/
#define wordSpace dotPeriod*7 /*space between words is 7 units*/

#define buzz 1000
#define tonePin 3




void dit()
{
  tone(tonePin, buzz);
  /*tone(pin, frequency)
   * use output pin(DIGITAL) - 3 as the input to buzzer.
  */
  delay(dotPeriod);
  /*delay(ms)
   * ms: the number of milliseconds to pause (unsigned long)
   */
  noTone(tonePin);
  /*noTone(pin)
   *pin: the pin on which to stop generating the tone
   */
  delay(relaxTime);
    /*delay(ms)
   * ms: the number of milliseconds to pause (unsigned long)
   */
}

void dah()
{
  tone(tonePin, buzz);
  delay(dashPeriod);
  noTone(tonePin);
  delay(relaxTime);
}

void di()
{
  dit();
}

void playLetter(char x)
{
  switch (x) {

    case 'A':
      di(); dah(); return;
    case 'B':
      dah(); di(); di(); dit(); return;
    case 'C':
      dah(); di(); dah(); dit(); return;
    case 'D':
      dah(); di(); di(); return;
    case 'E':
      di(); return;
    case 'F':
      di(); di(); dah(); dit(); return;
    case 'G':
      dah(); dah(); dit(); return;
    case 'H':
      di(); di(); di(); dit(); return;
    case 'I':
      di(); dit(); return;
    case 'J':
      di(); dah(); dah(); dah(); return;
    case 'K':
      dah(); di(); dah(); return;
    case 'L':
      di(); dah(); di(); dit(); return;
    case 'M':
      dah(); dah();
    case 'N':
      dah(); dit(); return;
    case 'O':
      dah(); dah(); dah(); return;
    case 'P':
      di(); dah(); dah(); dit(); return;
    case 'Q':
      dah(); dah(); di(); dah(); return;
    case 'R':
      di(); dah(); dit(); return;
    case 'S':
      di(); di(); di(); return;
    case 'T':
      dah(); return;
    case 'U':
      di(); di(); dah(); return;
    case 'V':
      di(); di(); di(); dah(); return;
    case 'W':
      di(); dah(); dah(); return;
    case 'X':
      dah(); di(); di(); dah(); return;
    case 'Y':
      dah(); di(); dah(); dah(); return;
    case 'Z':
      dah(); dah(); di(); dit(); return;
    case ' ':
      delay(wordSpace);
    case '.':                                        //period
      di(); dah(); di(); dah(); di(); dah(); return;
    case '/':                                       //word separator
      dah(); di(); di(); dah(); di(); return;
    case '-':                                        //hiphen
      dah(); di(); di(); di(); di(); dah(); return;
    case '?':                                       //question mark
      di(); dah(); di(); di(); dah(); di();  return;
    case ',':                                     //comma
      dah(); dah(); di(); di(); dah(); dah(); return;
    case '1':
      di(); dah(); dah(); dah(); dah(); return;
    case '2':
      di(); di(); dah(); dah(); dah(); return;
    case '3':
      di(); di(); di(); dah(); dah(); return;
    case '4':
      di(); di(); di(); di(); dah(); return;
    case '5':
      di(); di(); di(); di(); di(); return;
    case '6':
      dah(); di(); di(); di(); di(); return;
    case '7':
      dah(); dah(); di(); di(); di(); return;
    case '8':
      dah(); dah(); dah(); di(); di(); return;
    case '9':
      dah(); dah(); dah(); dah(); di(); return;
    case '0':
      dah(); dah(); dah(); dah(); dah(); return;
  }
}

int Index = 0, endofstring;//removed the i:not needed
char Input[255];

//Decoder
unsigned long signal_len, t1, t2;//t1 = time1, t2 = time2
int inputPin = 2;   //pin 2:input pin 
int ledPin = 7;     //pin 7: output pin for LED

String code = "";

void setup()
{
  
    Serial.begin(9600);
    pinMode(optionPin,OUTPUT);//pin  12
    
    pinMode(tonePin, OUTPUT); /*Set pin 3 as the output pin.(For Encoder)*/
    
    pinMode(inputPin, INPUT_PULLUP);
    /*There are 20K pullup resistors built into the Atmega chip that can be accessed from software. These built-in pullup 
     * resistors are accessed by setting the pinMode() as INPUT_PULLUP. This effectively inverts the behavior of the INPUT 
     * mode, where HIGH means the sensor is off, and LOW means the sensor is on.
     * When connecting a sensor to a pin configured with INPUT_PULLUP, the other end should be connected to ground. 
     */
    pinMode(ledPin, OUTPUT);
}

void loop()
{
  /*
   * If you do not set the pinMode() to OUTPUT, and connect an LED to a pin, when calling digitalWrite(HIGH), the LED 
   * may appear dim. Without explicitly setting pinMode(), digitalWrite() will have enabled the internal pull-up 
   * resistor, which acts like a large current-limiting resistor.
   */

   Serial.println("HIGH(Button Pressed)  : MorseCode Encoder , LOW(Button Un-Pressed) : MorseCode Decoder.");
   
   if(digitalRead(optionPin) == HIGH)//encoder
   {
          Serial.println("MorseCode Encoder:");
          
              while (!Serial.available()); //The control stays in this loop untill it receives an input.
              while (Serial.available())
              {
                Input[Index] = Serial.read(); //Serial.read() Reads incoming serial data.
                //Serial.println(Input[Index]);
                if (Input[Index] >= 97 && Input[Index] <= 122)
                {
                  Input[Index] = char(int(Input[Index]) - 32);
                  //If the user inputs small letters(e.g: 'a','b','c' etc.) If the small letter's ASCII value gets 
                  //subtracted by 32 we get the ASCII value of the Capital Letter of that same Alphabet(e.g: 'a' ascii value = 97 subtract 32 
                  //and we get 65 which is the ascii value of 'A' 
                }
                Index++;
              }
              //Serial.println();
              endofstring = Index;
              for (Index = 0; Index < endofstring; Index++)
              {
                Serial.print(Input[Index]);//prints the input letter. we got from the user
                playLetter(Input[Index]);
                delay(letterSpace);
                Serial.println();  //Serial.println(val) :Prints data to the serial port as human-readable ASCII text 
              }
              Index = 0;
   }
   if(digitalRead(optionPin) == LOW)//decoder
   {
      Serial.println("MorseCode Decoder:");
                NextDotDash:
                while (digitalRead(inputPin) == HIGH) {}//Reads the value from a specified digital pin, either HIGH or LOW.                
                t1 = millis();//time at button press
                digitalWrite(ledPin, HIGH);//LED on while button pressed              
                while (digitalRead(inputPin) == LOW) {}
                t2 = millis();//time at button release
                digitalWrite(ledPin, LOW);//LED off on button release
                signal_len = t2 - t1; //time for which button is pressed 
                if (signal_len > 50) //to account for switch debouncing
                {
                    code = code + readio(); //function to read dot or dash
                }
               
                while ((millis() - t2) < 500)//if time between button press greater than 0.5sec, skip loop and go to next alphabet
                {
                    if (digitalRead(inputPin) == LOW)//input pin inactive
                    {
                        goto NextDotDash;
                    }
                }
                convertor();//function to decipher code into alphabet and number
   }

}

char readio()
{
    if (signal_len < 600 && signal_len > 50)
    {
        return '.';     //if button press less than 0.6sec, it is a dot
    }
    else if (signal_len > 600)
    {
        return '-';     //if button press more than 0.6sec, it is a dash
    }
}

void convertor()
{
    static String letters[] =
    {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-",".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--..", "E"
    };
    static String numbers[] =
    {
        "-----", ".----", "..---", "...--", "....-", ".....",
        "-....","--...", "---..", "----.", "E"
    };
    int i = 0;
    if (code == ".-.-.-")
    {
        Serial.print(".");//full stop
    } 
    else if (code == "-..-.")
    {
        Serial.print("/");
    }
    else if (code == "-....-")
    {
        Serial.print("-");
    }
    else if (code == ".-..-.")
    {
        Serial.print("?");
    }
    else if (code == "--..--")
    {
        Serial.print(",");
    } 
    else if (code == "-......")
    {
        Serial.print(" "); //for white space
    }
    else if (code == "......-")
    {
        Serial.println(" "); //for white space
    }   
    else
    {
        while (letters[i] != "E")     //loop for comparing input code with letters array
        {
            if (letters[i] == code)
            {
                Serial.println(char('A' + i));
                break;
            }
            if (numbers[i] == code)
            {
                Serial.println(char('0' + i));
                break;
            }

            i++;
        }
        if (letters[i] == "E"||numbers[i] == "E")
        {
            Serial.println("<Wrong input>");
        }
    }
    code = "";
}


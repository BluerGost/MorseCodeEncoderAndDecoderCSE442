# Morse Code Encoder And Decoder CSE-442 (Microcontroller)

## Description

This project is able to toggle between encoding and decoding of mode using a switch. This project in encoding mode will be able to take regular text message from the keybord as input and convert it into morse code and give output via a buzzer. On the other hand, in decoding mode it will be able to take morse code via a push button and convert that message in regular text message and show it on the monitor.

## Authors

* [**Kevin Stephen Biswas**](https://github.com/BluerGost/) *Role*: Programmer,and Circuit Design.<br>
* **S.M Saiful Islam** 
* **MD. Sadman Hossain** 
* **Nazmul Hasan** 

## Directory Details

* **KevinDecoderPlusEncoder.ino** : It is the file which contains the auduino Sketch for the Morse Code encoder and decoder. Note this two will not work at the same time.

  * If Pin 12 is High(+5V) -> it will operate in encoding mode.
  * If pin 12 is Low(0V) -> it will operate in decoding mode.

* **~/Circuit Diagram** : This Folder contains the circuit diagram image of this project. This diagram was created using "Fritzing" tools. The file with the ".fzz" extention is the file actual circuit diagram editing file which can be opened with "Fritzing" software

## Tools Used

* [Fritzing](http://fritzing.org/) For Designing Circuit
* [Arduino IDE](https://www.arduino.cc/en/main/software)

## Circuit Components Used

  1. An Arduino
  2. A tactile push button
  3. An RGB LED Light
  4. A Breadboard
  5. A buzzer
  6. Some jumper cables
  7. A laptop

## Acknowledgments

[MorseCode Encoder](https://github.com/ahashans/MorseCodeEncoder)
[MorseCode Decoder](http://www.instructables.com/id/Morse-Code-Decoder/)

## Helpful Website Links

[International MorseCode](https://morsecode.scphillips.com/morse2.html)
[Learn Morse Code](http://www.learnmorsecode.com/)



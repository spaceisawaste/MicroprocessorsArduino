#include <LiquidCrystal.h>
/**
 * Code for the arduino keyboard project. The keyboard can play 16 different tones. There are 4 buttons that each play a unique tone when pressed.
 * A potentiometer allows the user to select another 'set' of notes to play. An LCD displays the current active set and the note being played.
 * @author Conor
 */

LiquidCrystal lcd(12,11,5,4,3,2); //tell arduino where the lcd pins are
/*
 * These are the four discrete note sets. I chose the notes C3-D5, with no sharps or flats.
 */
int notes1[]={131,147,165,175};
int notes2[]={196,220,247,262};
int notes3[]={294,330,349,392};
int notes4[]={440,494,523,587};

/**
 * This begins our serial monitor for troubleshooting and initializes the lcd
 */
void setup() 
{
	Serial.begin(9600);
	lcd.begin(16,2);
	lcd.print("Turn knob for new notes!");
}
/**
 * Runs the main code
 */
void loop() 
{
	int keyVal=analogRead(0);
	playTone(keyVal);
}

/**
 * This method takes an integer value, in this case the voltage measured by a button being pressed and converts it into two outputs: sound and an image on the lcd
 * Calls the helper function setLCD
 * @param keypress the voltage value from pushing a button
 */
public void playTone(int keyPress)
{
	//Just establishing all the values the function will need to work
	int noteList[]={notes1[],notes2[],notes3[],notes4[]};	//originally this was a global variable, but nothing else uses it so i moved it here
	int mappedPos=map(analogRead(1),0,1023,1,4);
	int noteSet[]=noteList[mappedPos];
	String nameSet[]=setLCD(mappedPos);

	lcd.cursor(0,1); //move cursor to next line to print the current note
	if(keyPress==1023)
	{
		tone(8,noteSet[0]);
		lcd.print(nameSet[0]);
	}
	else if(keyPress>=990 && keyPress<=1010) //leave some leeway for errant voltages
	{
		tone(8,noteSet[1]);
		lcd.print(nameSet[1]);
	}
	else if(keyPress>=505 && keyPress<=515)
	{
		tone(8,noteSet[2]);
		lcd.print(nameSet[2]);
	}
	else if(keyPress>=5 && keyPress<=10)
	{
		tone(8,noteSet[3]);
		lcd.print(nameSet[3]);
	}
	else
	{
		noTone(8);
	}
}

/**
 * Pass the pot's mapped value and sets name list of notes based on it. Also displays those note names on LCD
 * @param potVal mapped value of the potentiometer, we assume betweeen 1 and 4
 * @return the array of strings containing the set of notes for that pot position
 */
public String[] setLCD(int potVal)
{
	String nameSet[]={"A","B","C","D"}; //dummy values to be overwritten
	lcd.cursor(0,0);
	switch potVal
	{
	case 1
	{
		lcd.print("C D E F");
		return nameSet[]={"C","D","E","F"};
	}
	case 2
	{
		lcd.print("G A B C");
		return nameSet[]={"G","A","B","C"};
	}
	case 3
	{
		lcd.print("D E F G");
		return nameSet[]={"D","E","F","G"};
	}
	case 4
	{
		lcd.print("A B C D");
		return nameSet[]={"A","B","C","D"};
	}
	}
}

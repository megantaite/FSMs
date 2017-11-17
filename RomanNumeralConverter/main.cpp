//Name: Megan Taite
//Date: Sept. 27, 2017
//Class: CSCI371
//Assignment: Program 1: FSM Roman Numeral Converter
//Description: Converts Roman Numerals to decimal numbers that contain
//characters of no greater value than the Roman Numeral "C"

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){

	//create a state table that tells us where to go from our current
	//state depending on the input received
	int stateTable[18][5] = {{1, 6, 8, 12, 15},{2, 4, 5, -1, -1},
			{3,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1},{7,-1,-1,-1,-1},{2,-1,-1,-1,-1},
			{1,6,9,11,14},{1,6,10,-1,-1},{1,6,-1,-1,-1},
			{1,6,-1,-1,-1},{1,6,13,-1,-1},{1,6,9,-1,-1},
			{1,6,-1,-1,-1},{1,6,8,12,16},{1,6,8,12,17},
			{1,6,8,12,-1}};
	//create an action table that tells us how much to add to our current
	//number depending on the input received and our current state
	int actionTable[18][5] = {{1, 5, 10, 50, 100},{1, 3, 8, -1, -1},
			{1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1},{1,-1,-1,-1,-1},{1,-1,-1,-1,-1},
			{1,5,10,30,80},{1,5,10,-1,-1},{1,5,-1,-1,-1},
			{1,5,-1,-1,-1},{1,5,10,-1,-1},{1,5,10,-1,-1},
			{1,5,-1,-1,-1},{1,5,10,50,100},{1,5,10,50,100},
			{1,5,10,50,-1}};

	//create variables to help keep track during the process
	int currState, prevState, sum, inputRN;
	currState = prevState = sum = 0;
	string strInput;
	bool validInput = true;

	//while there are still strings being entered
	while(cin >> strInput){
		//make sure variables are set to 0
		//to properly process each new string
		sum = 0;
		currState = 0;
		prevState = 0;

		//make the string all upper case for ease of use later
		transform(strInput.begin(), strInput.end(),strInput.begin(), ::toupper);

		//prepare variables to help us iterate through the string
		int strCount = 0;
		int strLength = strInput.length();

		//While not at end of string
		while(strCount < strLength) {
			//assume input is valid until proven otherwise
			validInput = true;
			//get current character
			char c = strInput[strCount];
			//Figure out index of input depending on what
			//Roman Numeral was input
			if(c == 'I'){
				inputRN = 0;
			}
			else if(c == 'V'){
				inputRN = 1;
			}
			else if(c == 'X'){
				inputRN = 2;
			}
			else if(c == 'L'){
				inputRN = 3;
			}
			else if(c == 'C'){
				inputRN = 4;
			}
			else{
				validInput = false;
				break;
			}

			//Get new current state while maintaining
			//previous state so we know what to add later
			prevState = currState;
			currState = stateTable[currState][inputRN];

			//if current state is -1, then input was invalid
			//do not continue processing the string
			if(currState == -1){
				validInput = false;
				break;
			}

			//Add to our sum depending on where we were and what was input
			sum = sum + actionTable[prevState][inputRN];
			//prepare to get next character of string
			strCount++;

		}

		//if the input was valid, output sum
		if(validInput){
			cout << strInput << " = " << sum << endl;
		}
		//else output an error message
		else{
			cout << strInput << " = error, not a Roman Number" << endl;
		}

	}

	return 0;
}

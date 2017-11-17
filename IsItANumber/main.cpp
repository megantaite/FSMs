// Megan Taite
// CSCI371: Program 2
// October 10, 2017
// Please Note: I intentionally did not upper case
//		the input string because "e" has a different
//		meaning than "E" and should not be accepted
//		no matter the user's intention


#include <iostream>
using namespace std;

int main(){

	//create a state table that tells us where to go from our current
	//state depending on the input received
	int stateTable[14][14] = {{1,1,1,1,1,1,1,1,1,1,2,3,5,-1},{1,1,1,1,1,1,1,1,1,1,-1,-1,6,4},
			{1,1,1,1,1,1,1,1,1,1,-1,-1,5,-1},{1,1,1,1,1,1,1,1,1,1,-1,-1,5,-1},{11,11,11,11,11,11,11,11,11,11,9,8,10,-1},
			{7,7,7,7,7,7,7,7,7,7,-1,-1,-1,-1},{7,7,7,7,7,7,7,7,7,7,-1,-1,-1,4},{7,7,7,7,7,7,7,7,7,7,-1,-1,-1,4},
			{11,11,11,11,11,11,11,11,11,11,-1,-1,10,-1},{11,11,11,11,11,11,11,11,11,11,-1,-1,10,-1},
			{13,13,13,13,13,13,13,13,13,13,-1,-1,-1,-1},{11,11,11,11,11,11,11,11,11,11,-1,-1,12,-1},
			{13,13,13,13,13,13,13,13,13,13,-1,-1,-1,-1},{13,13,13,13,13,13,13,13,13,13,-1,-1,-1,-1}};
	//create an action table that tells us whether or not the string is
	//is in an accept state at its current location
	string actionTable[14][14] = {{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","yes","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","yes","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"},
			{"yes","yes","yes","yes","yes","yes","yes","yes","yes","yes","no","no","no","no"}};

		//create variables to help keep track during the process
		int currState, prevState, inputChar;
		currState = prevState = 0;
		string strInput;
		string outputString = "no";

		//while there are still strings being entered
		while(cin >> strInput){
			//make sure variables are set to 0
			//to properly process each new string
			currState = 0;
			prevState = 0;

			//prepare variables to help us iterate through the string
			int strCount = 0;
			int strLength = strInput.length();

			//While not at end of string
			while(strCount < strLength) {

				//get current character
				char c = strInput[strCount];
				//Figure out index of input depending on what
				//symbol was input
				if(c == '0'){
					inputChar = 0;
				}
				else if(c == '1'){
					inputChar = 1;
				}
				else if(c == '2'){
					inputChar = 2;
				}
				else if(c == '3'){
					inputChar = 3;
				}
				else if(c == '4'){
					inputChar = 4;
				}
				else if(c == '5'){
					inputChar = 5;
				}
				else if(c == '6'){
					inputChar = 6;
				}
				else if(c == '7'){
					inputChar = 7;
				}
				else if(c == '8'){
					inputChar = 8;
				}
				else if(c == '9'){
					inputChar = 9;
				}
				else if(c == '+'){
					inputChar = 10;
				}
				else if(c == '-'){
					inputChar = 11;
				}
				else if(c == '.'){
					inputChar = 12;
				}
				else if(c == 'E'){
					inputChar = 13;
				}
				else{
					outputString = "no";
					break;
				}

				//Get new current state while maintaining
				//previous state so later we can determine
				//if we entered accept state or not
				prevState = currState;
				currState = stateTable[currState][inputChar];

				//if current state is -1, then input was invalid
				//do not continue processing the string
				if(currState == -1){
					outputString = "no";
					break;
				}

				//change our string to yes if we are in accept state currently
				//or to no if we are not in an accept state currently
				outputString = actionTable[prevState][inputChar];
				//prepare to get next character of string
				strCount++;

			}

			//output result
			cout << strInput << " " << outputString << endl;
		}

	return 0;
}

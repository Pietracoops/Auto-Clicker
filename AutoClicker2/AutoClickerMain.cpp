#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "ClickFunctions.h"
#include <sstream>
#include <stdlib.h> 
#include <cmath>
using namespace std;


//Comparing Function Declarations
void RubricInputCompare();
string RemoveSpaces(string Entry);
void checkIfDefault(int RubricRow, int InputRow);
void FindInputInDatabaseArray(int InputRow);
void StoreInClickArray(string code, string ClickDur, string Xcord, string Ycord, string Menu);
string* SplitTrigger(string line);
string FindSection(string code);
bool is_number(const string& s);
double FindValue(string code);
void TypeOutNumber(double Value);
string* FindingMenuCoords(string Menu);

//Filling Array Function Declaration
void ReadRubricFile();
void ReadDatabaseFile();
string* getData(string line);
void ReadInputFile(string CaseFile);
double ConvertToNum(string Entry);
string Trim(string Entry);
void CheckDatabaseArray(int RubricRow);

//GLOBAL ARRAYS
string SectionArray[200];
double ClickArray[300][4];
int ClickArrayRow = 0;
string InputArray[100][2];
string RubricArray[100][3];
string DatabaseArray[200][50];
int trace = 0;//trace


int main()
{

	cout << "BOT START" << endl;
	
	
	//Constants
	int LoopCounter = 0; //Counting loop iterations in phase shifting process
	int TemporaryHighestID = -1;
	string CaseFile;

	int CalculatorX;
	int CalculatorY;
	int CalculatorTime;
	//Handles
	RECT RASTORect;
	RECT CalculatorRect;
	HWND hRASTO;
	HWND hCalculator;
	
	//Click Class
	Click Rasto;
	Click Calculator;


	cout << "Enter Test Case Name: " << endl;
	cin >> CaseFile;


	cout << "Initializing... Please Wait." << endl;




//*****************************************************************************
//FILLING DATABASES
//*****************************************************************************
	ReadRubricFile();//completed
	ReadDatabaseFile();//completed
	ReadInputFile(CaseFile);//completed
//*****************************************************************************
//FILLING DATABASES
//*****************************************************************************




//*****************************************************************************
//FINDING RUBRIC ARRAY INSIDE INPUT ARRAY
//*****************************************************************************
	RubricInputCompare();
//*****************************************************************************
//FINDING RUBRIC ARRAY INSIDE INPUT ARRAY
//*****************************************************************************


//*****************************************************************************
//RASTO
//*****************************************************************************
	cout << "Make Rasto the active screen and release the mouse." << endl;
	for (int i = 0; i < 4; i++)
	{
		cout <<"Clicking commencing in... " << 3 - i << endl;
		Sleep(1000);
	}


//Getting Rasto Window Handle
hRASTO = FindWindow(NULL, "RASTO [Untitled.tow]*");

//Getting Window size
GetWindowRect(hRASTO, &RASTORect);


//Applying Initial RASTO Phase Shift
for (int i = 0; i < 200; i++)
{
	if (SectionArray[i].compare("") == 0)
	{
		break;
	}


	if (SectionArray[i].compare("RASTO") == 0)
	{
		ClickArray[i][1] = ClickArray[i][1] + RASTORect.left;
		ClickArray[i][2] = ClickArray[i][2] + RASTORect.top;

		Rasto.LeftClick(ClickArray[i][1], ClickArray[i][2]);//clicking
		Sleep(ClickArray[i][0]);
	}

	if (SectionArray[i].compare("Calculator") == 0)
	{
		ClickArray[i][1] = ClickArray[i][1] + RASTORect.left;
		ClickArray[i][2] = ClickArray[i][2] + RASTORect.top;

		Rasto.LeftClick(ClickArray[i][1], ClickArray[i][2]);//clicking
		Sleep(ClickArray[i][0]);
	}


}



//*****************************************************************************
//RASTO
//*****************************************************************************


//Then Click Calculator




//*****************************************************************************
//CALCULATOR
//*****************************************************************************
	Sleep(2000);
	//Getting Calculator Handle
	hCalculator = FindWindow(NULL, "Calculator");


	//Getting Calculator Window Size
	GetWindowRect(hCalculator, &CalculatorRect);


	//Initializing Button Locations in Calculator
	for (int i = 0; i < 200; i++)
	{
		if (SectionArray[i].compare("") == 0)
		{
			break;
		}

		if (SectionArray[i].compare("RASTO") != 0 && SectionArray[i].compare("Calculator") != 0)
		{
			ClickArray[i][1] = ClickArray[i][1] + CalculatorRect.left;
			ClickArray[i][2] = ClickArray[i][2] + CalculatorRect.top;

			if (ClickArray[i][3] == 0)
			{
				Calculator.LeftClick(ClickArray[i][1], ClickArray[i][2]);//clicking
				Sleep(ClickArray[i][0]);
			}
			else
			{
				Calculator.LeftDoubleClick(ClickArray[i][1], ClickArray[i][2]);//clicking
				TypeOutNumber(ClickArray[i][3]);
				Sleep(ClickArray[i][0]);
			}

		}
	}

//*****************************************************************************
//CALCULATOR
//*****************************************************************************



	////COORDINATE LOCATOR
	while (true)
	{
	GetWindowRect(hRASTO, &RASTORect);
	cout << "Get cursor Position" << endl;
	Sleep(2000);

	cout << RASTORect.left << " Rasto top Left corner X" << endl;
	cout << RASTORect.top << " Rasto top Left corner Y" << endl;

	if (MOUSEEVENTF_LEFTDOWN)
	{
	POINT p;
	GetCursorPos(&p);
	cout << "Cursor Position: X: "<< p.x << "  Y: " << p.y << endl;
	}
	}

cout << "Autoclicking Complete." << endl;

}


void TypeOutNumber(double Value)
{
	string value;
	value = std::to_string(Value);
	int DecimalFound = 0;
	int stopvalue = 0;
	string tempstring;

	


	//check if it should be a decimal number
	tempstring = std::to_string(Value);
	std::size_t period = tempstring.find(".");

	if (period != std::string::npos)
	{
		if (tempstring[period + 1] == '0')
		{
			if (tempstring[period + 2] == '0')
			{
				stopvalue = period;
			}

		}
		else
		{
			stopvalue = period + 3;
		}


	}


		for (int i = 0; i < stopvalue; i++)
		{
			if (DecimalFound == 1)
			{
				DecimalFound++;
			}
			if (DecimalFound == 3)//allowing only 2 decimal places after decimal
			{
				break;
			}


			if (value[i] == '.')
			{
				keybd_event(VkKeyScan('.'), 0xB4, 0, 0);
				keybd_event(VkKeyScan('.'), 0xB4, KEYEVENTF_KEYUP, 0);
				DecimalFound = 1;
			}


			if (value[i] == '1')
			{
				keybd_event(VkKeyScan('1'), 0x82, 0, 0);
				keybd_event(VkKeyScan('1'), 0x82, KEYEVENTF_KEYUP, 0);
			}

			if (value[i] == '2')
			{
				keybd_event(VkKeyScan('2'), 0x83, 0, 0);
				keybd_event(VkKeyScan('2'), 0x83, KEYEVENTF_KEYUP, 0);
			}

			if (value[i] == '3')
			{
				keybd_event(VkKeyScan('3'), 0x84, 0, 0);
				keybd_event(VkKeyScan('3'), 0x84, KEYEVENTF_KEYUP, 0);
			}

			if (value[i] == '4')
			{
				keybd_event(VkKeyScan('4'), 0x85, 0, 0);
				keybd_event(VkKeyScan('4'), 0x85, KEYEVENTF_KEYUP, 0);
			}

			if (value[i] == '5')
			{
				keybd_event(VkKeyScan('5'), 0x86, 0, 0);
				keybd_event(VkKeyScan('5'), 0x86, KEYEVENTF_KEYUP, 0);
			}

			if (value[i] == '6')
			{
				keybd_event(VkKeyScan('6'), 0x87, 0, 0);
				keybd_event(VkKeyScan('6'), 0x87, KEYEVENTF_KEYUP, 0);
			}


			if (value[i] == '7')
			{
				keybd_event(VkKeyScan('7'), 0x88, 0, 0);
				keybd_event(VkKeyScan('7'), 0x88, KEYEVENTF_KEYUP, 0);
			}

			if (value[i] == '8')
			{
				keybd_event(VkKeyScan('8'), 0x89, 0, 0);
				keybd_event(VkKeyScan('8'), 0x89, KEYEVENTF_KEYUP, 0);
			}

			if (value[i] == '9')
			{
				keybd_event(VkKeyScan('9'), 0x8A, 0, 0);
				keybd_event(VkKeyScan('9'), 0x8A, KEYEVENTF_KEYUP, 0);
			}

			if (value[i] == '0')
			{
				if (DecimalFound == 1)
				{
					break;
				}

				keybd_event(VkKeyScan('0'), 0x8B, 0, 0);
				keybd_event(VkKeyScan('0'), 0x8B, KEYEVENTF_KEYUP, 0);
			}
		}



}



void ReadRubricFile()
{
	//std::ifstream file("C:/Users/B0585031/Desktop/text.txt");
	std::ifstream file("rubric.nl");
	string component;
	string section;
	string value;
	string line;
	int ArrayRow = 0;

	while (!file.eof())
	{
		if (file.is_open())
		{
			

			while (getline(file, line))
			{
				std::size_t comment = line.find("*");
				std::size_t found = line.find("%");
				std::size_t thirdfound = line.find("=");

				//ignoring comments
				if (comment != std::string::npos)
				{
					goto EndOfLoop;
				}
				//section
				if (found != std::string::npos)
				{
					section = line.substr(found + 1);

				}
				else
				{
					//finding component
					if (thirdfound != std::string::npos)
					{
						component = line.substr(0, thirdfound);
						value = line.substr(thirdfound + 1);

						RubricArray[ArrayRow][0] = section;
						RubricArray[ArrayRow][1] = component;
						RubricArray[ArrayRow][2] = value;

						//Go to next row
						ArrayRow = ArrayRow + 1;

						if (trace == 1)
						{
							std::cout << "Section is " << section << '\n';
							cout << component << " is the component" << endl;
							cout << value << " is the value" << endl;
						}


					}
				}

			EndOfLoop:;
			}

		}
		else
		{
			cout << "Unable to open file" << endl;
			break;
		}

	}



}
void ReadDatabaseFile()
{
	//std::ifstream file("C:/Users/B0585031/Desktop/text.txt");
	std::ifstream file("Database.nl");
	string code;
	string value;
	string visibility;
	string clickduration;
	string xcord;
	string ycord;
	string trigger;

	string* data;
	string line;

	int Row = 0;
	while (!file.eof())
	{
		if (file.is_open())
		{


			while (getline(file, line))
			{
				
				std::size_t comment = line.find("*");

				if (comment != std::string::npos)
				{
					goto EndOfLoop;
				}

				std::size_t found = line.find("|");
			

				if (found != std::string::npos)
				{

					data = getData(line);
					
					for (int i = 0; i < 50; i++)
					{
						DatabaseArray[Row][i] = data[i];

					}

					delete[] data;
					Row++;
				}
				
			EndOfLoop:;
			}

		}
		else
		{
			cout << "Unable to open file" << endl;
			break;
		}

	}

}
string* getData(string line) {
	string* data = new string[50];
	string code;
	string value;
	string clickdur;
	string xcord;
	string ycord;
	string menu;
	string trigger;

	int triggercounter = 6;
	
	//limitting input entries
	for (int i = 0; i < 50; i++)
	{
		std::size_t found = line.find("|");
		
		
		//finding code
		if (found != std::string::npos && i == 0)
		{
			code = line.substr(0, found);
			code = RemoveSpaces(code);
			data[0] = code;
			line = line.substr(found+1);
			if (trace == 1)
			cout << code <<  endl;
		}

		if (found != std::string::npos && i == 1)
		{
			value = line.substr(0, found);
			value = RemoveSpaces(value);
			data[1] = value;
			line = line.substr(found + 1);
			if (trace == 1)
			cout << value << endl;
			
		}


		if (found != std::string::npos && i == 2)
		{
			clickdur = line.substr(0, found);
			clickdur = RemoveSpaces(clickdur);
			data[2] = clickdur;
			line = line.substr(found + 1);
			if (trace == 1)
			cout << clickdur << endl;

		}

		if (found != std::string::npos && i == 3)
		{
			xcord = line.substr(0, found);
			xcord = RemoveSpaces(xcord);
			data[3] = xcord;
			line = line.substr(found + 1);
			if (trace == 1)
			cout << xcord << endl;

		}

		if (found != std::string::npos && i == 4)
		{
			ycord = line.substr(0,found);
			ycord = RemoveSpaces(ycord);
			data[4] = ycord;
			line = line.substr(found + 1);
			if (trace == 1)
			cout << ycord << endl;
		}

		if (found != std::string::npos && i == 5)
		{
			menu = line.substr(0, found);
			menu = RemoveSpaces(menu);
			data[5] = menu;
			line = line.substr(found + 1);
			if (trace == 1)
				cout << ycord << endl;
		}

		if (found != std::string::npos && i >= 6)
		{
			trigger = line.substr(0,found);
			trigger = RemoveSpaces(trigger);
			data[triggercounter] = trigger;
			line = line.substr(found + 1);
			triggercounter++;
			if (trace == 1)
			cout << trigger << endl;
		}


	}


	return data;
}

void ReadInputFile(string CaseFile)
{
	//std::ifstream file("C:/Users/B0585031/Desktop/text.txt");
	std::ifstream file(CaseFile);
	std::ostringstream temp;
	string component;
	string value;
	string line;
	double returnvalue = 0;
	int ArrayRow = 0;
	while (!file.eof())
	{
		if (file.is_open())
		{


			while (getline(file, line))
			{
				std::size_t comment = line.find("!");
				

				//Removing comments
				if (comment != std::string::npos)
				{
					line = line.substr(0, comment);
				}
				
				
					std::size_t thirdfound = line.find("=");

					//finding component
					if (thirdfound != std::string::npos)
					{
						component = line.substr(0, thirdfound);
						value = line.substr(thirdfound + 1);

						InputArray[ArrayRow][0] = component;
						
						returnvalue = ConvertToNum(value);
						if (returnvalue != -999999)
						{
							//converting return value into string so that it can be stored in same array
							value  = std::to_string(returnvalue);
							//temp << returnvalue;
							//value = temp.str();
							//convert return value to string to store back in
							InputArray[ArrayRow][1] = value;
							if (trace == 1)
							cout << value << " Double to String, and stored in InputArray " << endl;
						}
						else
						{


							//trim it first to remove the '' then store in array
							value = Trim(value);
							InputArray[ArrayRow][1] = value;
							if (trace == 1)
							cout << value << " Trimmed and stored in InputArray " << endl;

						}


						//Go to next row
						ArrayRow = ArrayRow + 1;

						if (trace == 1)
						{
							cout << component << " is the component" << endl;
							cout << value << " is the value" << endl;
						}


					}
				

			}

		}
		else
		{
			cout << "Unable to open file" << endl;
			break;
		}

	}
}
double ConvertToNum(string Entry)
{
	string NewStringValue;
	string NewStringExponent;

	double Value = -999999;
	double Exponent = 0;
	double FinalValue = -999999;

	std::size_t found = Entry.find("E");
	if (found != std::string::npos)
	{
		NewStringValue = Entry.substr(0, found);
		Value = stod(NewStringValue.c_str());
		if (trace == 1)
		cout << "Real Value is " << Value << endl;

		NewStringExponent = Entry.substr(found + 2);
		Exponent = stod(NewStringExponent.c_str());
		if (trace == 1)
		cout << "Exponent Value is " << Exponent << endl;

		FinalValue = Value * pow(10, Exponent);
		if (trace == 1)
		cout << "Final Value is " << FinalValue << endl;
	}
	
	else
	{
		FinalValue = -999999;
	}

	return FinalValue;
}
string Trim(string Entry)
{
	
	string FinalString;
	int StringLength;


	for (int i = 0; i < 2; i++)//Removing Quotes
	{
		
		std::size_t found = Entry.find("'");

		if (found != std::string::npos)
		{
			if (i == 0)
			{
				//getting rid of first quote
				Entry = Entry.substr(found + 1);
				if (trace == 1)
				cout << "Removed First Quote " << Entry << endl;
			}
			else
			{
				Entry = Entry.substr(0, found);
				if (trace == 1)
				cout << "Removed second Quote " << Entry << endl;
			}
		}

		std::size_t foundspace = Entry.find(" ");
		if (foundspace != std::string::npos)
		{

			if (foundspace == 0)
			{
				Entry = Entry.substr(foundspace + 1);
			}
			if (foundspace > 0)
			{
				Entry = Entry.substr(0, foundspace);

			}


		}

	}

	return Entry;
}


void RubricInputCompare()
{
	int FoundTrigger = 0;
	string input;
	string rubric;
	//RubricArray[100][3];
	//InputArray[100][2];

	for(int i = 0; i < 100; i++)//Rubric Array
	{
		for (int j = 0; j < 100; j++)//Input Array
		{
			//should put this section in its own function - If I have time
			//Removing Spaces within the inputs so that comparisons can be made
			string input = InputArray[j][0];
			string rubric = RubricArray[i][1];
			input = RemoveSpaces(input);
			rubric = RemoveSpaces(rubric);
			RubricArray[i][1] = rubric;
			InputArray[j][0] = input;

			//Exit Condition -> when reached the end of rubric
			if (rubric.compare("") == 0)
			{
				goto END;
			}

			std::size_t found = input.find(rubric);//finding rubric inside input
			if (found != std::string::npos)//comparing codes
			{
				FoundTrigger = 1;
				if (trace == 1)
				cout << "Similarity Found: " << RubricArray[i][1] << " " << InputArray[j][0] << endl;
				//Check if default
				checkIfDefault(i, j);//Database search will be done in here
				break;
			}
		}

		if (FoundTrigger == 0)
		{
			if (trace == 1)
			{
			cout << "Similarity Not Found: " << RubricArray[i][1] << endl;
			cout << "Checking in Database Array for Guidlines "<< endl;
			}

			CheckDatabaseArray(i);
		}
		FoundTrigger = 0;
	}

END:;
}

void CheckDatabaseArray(int RubricRow)
{
	string DatabaseCode;
	string RubricCode = RubricArray[RubricRow][1];
	for (int i = 0; i < 200; i++)
	{
		
		DatabaseCode = RemoveSpaces(DatabaseArray[i][0]);
		std::size_t found = DatabaseCode.find(RubricCode);//Finding RubricCode inside DatabaseCode

		if (DatabaseCode.compare("") == 0)
		{
			if (trace == 1)
			cout << "A Rubric input is missing a forced entry or input declaration missing from input file: " << RubricCode << endl;
			break;
		}
		
		if (found != std::string::npos)
		{
			std::size_t founddollar = DatabaseCode.find("$");
			if (founddollar != std::string::npos)
			{
				if (trace == 1)
				cout << "Found a forced Value - Adding to ClickArray" << endl;
				
				StoreInClickArray(DatabaseArray[i][0], DatabaseArray[i][2], DatabaseArray[i][3], DatabaseArray[i][4], DatabaseArray[i][5]);
				break;
			}
			else
			{
		   cout << "A Database Entry was found for the missing input value, but it is not forced. Entry Skipped: " << RubricCode << endl;
		   break;
			}

		}

	}




}

void checkIfDefault(int RubricRow, int InputRow)
{
	
	double tempValue;
	string RubricValue = RubricArray[RubricRow][2];
	string InputValue = InputArray[InputRow][1];

	if (trace == 1)
	cout << "Checking if " << RubricArray[RubricRow][1] << " is default" << endl;

	//removing spaces so we can compare
	RubricArray[RubricRow][2] = RemoveSpaces(RubricValue);
	InputArray[InputRow][1] = RemoveSpaces(InputValue);

	//value  = std::to_string(returnvalue);
	//stod(NewStringValue.c_str());



	//Checking to see if value is 9E20 - if it is, convert it for compare
	std::size_t foundE = RubricValue.find("E");
	if (foundE != std::string::npos)
	{
		tempValue = ConvertToNum(RubricValue);
		RubricValue = std::to_string(tempValue);
	}


	//Checking if value was converted from double - if so, then need to do the same to
	//rubric so we can compare values.
	std::size_t foundperiod = InputValue.find(".");
	if (foundperiod != std::string::npos)
	{
		//need to convert to double so that we can properly compare
		tempValue = stod(RubricValue.c_str());
		RubricValue = std::to_string(tempValue);
		RubricArray[RubricRow][2] = RubricValue;
	}
	
	if (RubricArray[RubricRow][2] == InputArray[InputRow][1])
	{
		//we are done here - move onto next input - no clicks required
		if (trace == 1)
		cout << RubricArray[RubricRow][1] << " is at default" << endl;
	}
	else
	{
		//if is not at default, we need to change it to what its supposed to be - by clicking
		FindInputInDatabaseArray(InputRow);
		if (trace == 1)
		cout << RubricArray[RubricRow][1] << " is not at default" << endl;
	}

}

void FindInputInDatabaseArray(int InputRow)
{
	string InputCode = InputArray[InputRow][0];
	string InputValue = InputArray[InputRow][1];
	string DatabaseCode;
	string DatabaseValue;
	string TriggerCode;
	string TriggerValue;
	string* data;
	std::string TempArray[20][50];
	std::string TempArray2[20][50];
	std::string TriggerArray[50][2];
	int foundcounter = 0;
	int foundcounter2 = 0;

		for (int i = 0; i < 200; i++)//finding Database rows with same code
		{
			////should put this section in its own function - If I have time
			////Removing Spaces within the inputs so that comparisons can be made
			//string input = InputArray[j][0];
			//string rubric = RubricArray[i][1];
			//input = RemoveSpaces(input);
			//rubric = RemoveSpaces(rubric);
			//RubricArray[i][1] = rubric;
			//InputArray[j][0] = input;

			DatabaseCode = DatabaseArray[i][0];

			//Exit Condition -> when reached the end of rubric
			if (DatabaseCode.compare("") == 0)
			{
				break;
			}

			std::size_t found = DatabaseCode.find(InputCode);
			
			if (found != std::string::npos)//comparing codes
			{
				//storing Database info into temp array
				for (int j = 0; j < 50; j++)
				{
					TempArray[foundcounter][j] = DatabaseArray[i][j];
				}
				foundcounter++;
			}
		}

		if (foundcounter != 0)//if a database entry was found
		{

			for (int k = 0; k < foundcounter; k++)//finding which database entry matches based on Value
			{
				DatabaseValue = TempArray[k][1];
				if (is_number(DatabaseValue))
				{
					DatabaseValue = std::to_string(stod(DatabaseValue));
				}
				std::size_t found = DatabaseValue.find(InputValue);

				if (found != std::string::npos || DatabaseValue.compare("Value") == 0)//if Database value = to the value in input or "Value"-> store it
				{
					if (trace == 1)
					cout << "Narrowing down to second temparray" << endl;

					for (int j = 0; j < 50; j++)
					{
						if (TempArray[k][j].compare("") == 0)
						{
							break;
						}
						TempArray2[foundcounter2][j] = TempArray[k][j];
					}
					foundcounter2++;
				}

				if (DatabaseValue.compare("") == 0)
				{
					break;
				}
			}



			for (int z = 0; z < 100; z++)//Splitting Triggers
			{
				foundcounter = 0;

				for (int j = 6; j < 50; j++)
				{

					if (TempArray2[z][j].compare("Void") == 0)
					{
						TriggerArray[foundcounter][0] = "Void";
						break;
					}
					else{
						data = SplitTrigger(TempArray2[z][j]);
					}

					if (data[0].compare("") == 0)
					{

						break;
					}

					TriggerArray[foundcounter][0] = data[0];
					TriggerArray[foundcounter][1] = data[1];
					foundcounter++;
					delete[] data;


				}
				//cycle through inputs to check Triggers
				for (int i = 0; i < 100; i++)//input array rows
				{

					for (int j = 0; j < 50; j++)//TriggerArray rows
					{
						TriggerCode = RemoveSpaces(TriggerArray[j][0]);
						InputCode = RemoveSpaces(InputArray[i][0]);
						
						
						if (TriggerArray[j][0].compare("") == 0)//reach end of trigger array break;
						{
							break;
						}
						if (InputCode.compare(TriggerCode) == 0 || TriggerArray[j][0].compare("Void") == 0)//Codes are the same
						{
							if (TriggerArray[j][0].compare("Void") == 0)
							{
								if (trace == 1)
								cout << "stored" << endl;
								
								StoreInClickArray(TempArray2[z][0], TempArray2[z][2], TempArray2[z][3], TempArray2[z][4], TempArray2[z][5]);
								goto skipTriggerCheck;
							}

							//TriggerValue = RemoveSpaces(TriggerArray[j][1]);t
							TriggerValue = std::to_string(stod(TriggerArray[j][1]));
							InputValue = RemoveSpaces(InputArray[i][1]);
							if (InputValue.compare(TriggerValue)==0)//Values the Same
							{
								if (trace == 1)
								cout << "stored" << endl;
								
								StoreInClickArray(TempArray2[z][0], TempArray2[z][2], TempArray2[z][3], TempArray2[z][4], TempArray2[z][5]);
								goto skipTriggerCheck;
							}
						
						}

					}//Trigger array rows for-loop


					if (InputArray[i][0].compare("") == 0)//reach end of input array break;
					{
					
						break;
					}

				}
			

				//reinitializing array
				for (int i = 0; i < 50; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						TriggerArray[i][j].clear();
					}

				}

			
			}


		}
		else
		{
			if (trace == 1)
			cout << "Entry not found in Database - Entry Skipped" << endl;
		}


		//store into click array

	skipTriggerCheck:;
		//reset Array
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				TempArray[i][j].clear(); 
			}

		}

}


string* SplitTrigger(string line) {
	string* data = new string[2];
	string code;
	string value;

	int triggercounter = 6;

	//limitting input entries

		std::size_t found = line.find("=");


		//finding code
		if (found != std::string::npos)
		{
			code = line.substr(0, found);
			code = RemoveSpaces(code);
			data[0] = code;
			//line = line.substr(found + 1);
			if (trace == 1)
			cout << code << endl;

			value = line.substr(found+1);
			value = RemoveSpaces(value);
			data[1] = value;
			//line = line.substr(found + 1);
			if (trace == 1)
		    cout << value << endl;
		}

	return data;
}

bool is_number(const string& s){
	for (int i = 0; i < s.length(); i++)//for each char in string,
		if (!(s[i] >= '0' && s[i] <= '9' || s[i] == '.' || s[i] == ' ')) return false;
	//if s[i] is between '0' and '9' of if it's a whitespace (there may be some before and after
	// the number) it's ok. otherwise it isn't a number.

	return true;
}



void StoreInClickArray(string code,string ClickDur,string Xcord,string Ycord,string Menu)
{
	string Code;
	double ClickDuration;
	double XCoordinate;
	double YCoordinate;

	double MenuClickDuration;
	double MenuXCoordinate;
	double MenuYCoordinate;
	double value = -999999;
	string section;
	string* coords;

	value = FindValue(code);//if the value is a type input, this will fetch the value as type double

	

	if (Menu.compare("Void") != 0)//if not void -> find Menu Click in database
	{
		coords = FindingMenuCoords(Menu);

		MenuClickDuration = stod(coords[0].c_str());
		MenuXCoordinate = stod(coords[1].c_str());
		MenuYCoordinate = stod(coords[2].c_str());

		ClickArray[ClickArrayRow][0] = MenuClickDuration;
		ClickArray[ClickArrayRow][1] = MenuXCoordinate;
		ClickArray[ClickArrayRow][2] = MenuYCoordinate;

		section = FindSection(code);
		SectionArray[ClickArrayRow] = section;//this is the section for the menu (same as regular input)
		ClickArrayRow++;

		delete[] coords;
	}

	if (Menu.compare("Void") == 0)
	{
		std::size_t found = code.find("$");
		if (found != std::string::npos)
		{
			section = code.substr(found + 1);
		}
		else
		{
			section = FindSection(code);
		}

	}

	

	//convert to doubles
	ClickDuration = stod(ClickDur.c_str());
	XCoordinate = stod(Xcord.c_str());
	YCoordinate = stod(Ycord.c_str());



	//Storing in Array
	//Convert the values to doubles
	ClickArray[ClickArrayRow][0] = ClickDuration;
	ClickArray[ClickArrayRow][1] = XCoordinate;
	ClickArray[ClickArrayRow][2] = YCoordinate;
	
	if (value != -999999)
	{
	ClickArray[ClickArrayRow][3] = value;
	}

	SectionArray[ClickArrayRow] = section;//section for input



	ClickArrayRow++;
	
}

double FindValue(string code)//checking database array to see if value = "Value" - if yes then return value
{
	string DatabaseCode;
	string DatabaseValue;
	string InputCode;
	string ReturnValue;
	double ReturnValueDouble;
	for (int i = 0; i < 200; i++)
	{

		DatabaseCode = RemoveSpaces(DatabaseArray[i][0]);

		if (DatabaseCode.compare(code) == 0)
		{
			DatabaseValue = RemoveSpaces(DatabaseArray[i][1]);

			if (DatabaseValue.compare("Value") == 0)//if the value in database = "Value"
			{

				for (int j = 0; j < 100; j++)//Search input database for actual user specified value
				{
					InputCode = RemoveSpaces(InputArray[j][0]);

					if (InputCode.compare(code) == 0)
					{
						ReturnValue = InputArray[j][1];
					}
				}
			}
		}
	}

	if (is_number(ReturnValue) && ReturnValue.compare("") != 0)
	{
		ReturnValueDouble = stod(ReturnValue);
	}
	else
	{
		ReturnValueDouble = -999999;
	}


	return ReturnValueDouble;
}

string FindSection(string code)
{
	string RubricCode;
	string section;

	for (int i = 0; i < 100; i++)
	{

		code = RemoveSpaces(code);
		RubricCode = RemoveSpaces(RubricArray[i][1]);

		if (RubricCode.compare("") == 0)//exit condition
		{
			break;
		}

		if (RubricCode.compare(code) == 0)
		{
			section = RubricArray[i][0];
		}
	}



	return section;
}



string RemoveSpaces(string Entry)
{

	while (true)
	{
		std::size_t spaces = Entry.find(" ");

		if (spaces != std::string::npos)
		{
			if (spaces == 0)//spaces at beginning
			{
				Entry = Entry.substr(spaces + 1);
			}

			if (spaces > 0)//spaces not at beggining
			{
				Entry = Entry.substr(0, spaces);
			}
		}
		else
		{
			break;
		}

	}
	return Entry;
}

string* FindingMenuCoords(string Menu)
{
	string InputCode;
	string InputValue;
	string DatabaseCode;
	string DatabaseValue;
	string TriggerCode;
	string TriggerValue;
	string* data;
	std::string TempArray[20][50];
	std::string TriggerArray[50][2];
	int foundcounter = 0;
	string* coords = new string[4];


	for (int i = 0; i < 200; i++)//finding Database rows with same code
	{
		////should put this section in its own function - If I have time
		////Removing Spaces within the inputs so that comparisons can be made
		//string input = InputArray[j][0];
		//string rubric = RubricArray[i][1];
		//input = RemoveSpaces(input);
		//rubric = RemoveSpaces(rubric);
		//RubricArray[i][1] = rubric;
		//InputArray[j][0] = input;

		DatabaseCode = DatabaseArray[i][0];

		//Exit Condition -> when reached the end of rubric
		if (DatabaseCode.compare("") == 0)
		{
			break;
		}

		std::size_t found = DatabaseCode.find(Menu);

		if (found != std::string::npos)//comparing codes
		{
			//storing Database info into temp array
			for (int j = 0; j < 50; j++)
			{
				if (DatabaseArray[i][j].compare("") == 0)
				{
					break;
				}
				TempArray[foundcounter][j] = DatabaseArray[i][j];
			}
			foundcounter++;
		}
	}

	if (foundcounter != 0)//if a database entry was found
	{


		for (int z = 0; z < 100; z++)//Splitting Triggers
		{
			foundcounter = 0;

			for (int j = 6; j < 50; j++)
			{

				if (TempArray[z][j].compare("Void") == 0)
				{
					TriggerArray[foundcounter][0] = "Void";
					break;
				}
				else{
					data = SplitTrigger(TempArray[z][j]);
				}

				if (data[0].compare("") == 0)
				{

					break;
				}

				TriggerArray[foundcounter][0] = data[0];
				TriggerArray[foundcounter][1] = data[1];
				foundcounter++;
				delete[] data;


			}
			//cycle through inputs to check Triggers
			for (int i = 0; i < 100; i++)//input array rows
			{

				for (int j = 0; j < 50; j++)//TriggerArray rows
				{
					TriggerCode = RemoveSpaces(TriggerArray[j][0]);
					InputCode = RemoveSpaces(InputArray[i][0]);


					if (TriggerArray[j][0].compare("") == 0)//reach end of trigger array break;
					{
						break;
					}
					if (InputCode.compare(TriggerCode) == 0 || TriggerArray[j][0].compare("Void") == 0)//Codes are the same
					{
						if (TriggerArray[j][0].compare("Void") == 0)
						{
							if (trace == 1)
							cout << "stored" << endl;
							
							coords[0] = TempArray[z][2];
							coords[1] = TempArray[z][3];
							coords[2] = TempArray[z][4];
							goto skipTriggerCheck;
						}

						//TriggerValue = RemoveSpaces(TriggerArray[j][1]);t
						TriggerValue = std::to_string(stod(TriggerArray[j][1]));
						InputValue = RemoveSpaces(InputArray[i][1]);
						if (InputValue.compare(TriggerValue) == 0)//Values the Same
						{
							if (trace == 1)
							cout << "stored" << endl;
							
							coords[0] = TempArray[z][2];
							coords[1] = TempArray[z][3];
							coords[2] = TempArray[z][4];
							goto skipTriggerCheck;
						}

					}

				}//Trigger array rows for-loop


				if (InputArray[i][0].compare("") == 0)//reach end of input array break;
				{

					break;
				}

			}


			//reinitializing array
			for (int i = 0; i < 50; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					TriggerArray[i][j].clear();
				}

			}


		}


	}
	else
	{
		if (trace == 1)
		cout << "Menu not found in Database - No Menu Recorded" << endl;
	}


	//store into click array

skipTriggerCheck:;
	//reset Array
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			TempArray[i][j].clear();
		}

	}

	return coords;

}
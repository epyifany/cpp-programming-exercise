// program.cpp
// challenge02
// Yifan Yu
// yyu3
// Aug 31, 2018

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;


int process_string(string str);
void process_output(int answer, vector<string> first, vector<string> second, vector<string> third);


int main(int argc, char *argv[]) {
	string str;
	vector<string> first, second, third;

	//1. Collect Input
	while(getline(cin, str)){

		//2. process string: stack of numbers, pop first two to operate
		int answer = process_string(str);

		//3.Process output
		process_output(answer, first, second, third);
	}
	return 0;
}



void process_output(int answer, vector<string> first, vector<string> second, vector<string> third)
{
	string astr;
	astr = to_string(answer);
	for(int i = 0; i < astr.size(); i++){
		switch(astr[i]){
			//print out in the old fashion way
			case '-':
				first.push_back("   ");
				second.push_back(" _ ");
				third.push_back("   ");
				break;
			case '1':
				first.push_back("   ");
				second.push_back("  |");
				third.push_back("  |");
				break;
			case '2':
				first.push_back(" _ ");
				second.push_back(" _|");
				third.push_back("|_ ");
				break;
			case '3':
				first.push_back(" _ ");
				second.push_back(" _|");
				third.push_back(" _|");
				break;
			case '4':
				first.push_back("   ");
				second.push_back("|_|");
				third.push_back("  |");
				break;
			case '5':
				first.push_back(" _ ");
				second.push_back("|_ ");
				third.push_back(" _|");
				break;
			case '6':
				first.push_back(" _ ");
				second.push_back("|_ ");
				third.push_back("|_|");
				break;
			case '7':
				first.push_back(" _ ");
				second.push_back("  |");
				third.push_back("  |");
				break;
			case '8':
				first.push_back(" _ ");
				second.push_back("|_|");
				third.push_back("|_|");
				break;
			case '9':
				first.push_back(" _ ");
				second.push_back("|_|");
				third.push_back(" _|");
				break;
			case '0':
				first.push_back(" _ ");
				second.push_back("| |");
				third.push_back("|_|");
				break;
		}
	}

	for(int i = 0; i < first.size(); i++){
	 cout << first[i];
 	}
	cout << endl;
	for(int i = 0; i < second.size(); i++){
	 cout << second[i];
	}
	cout << endl;
	for(int i = 0; i < third.size(); i++){
	 cout << third[i];
	}
	cout << endl;
	first.clear();
	second.clear();
	third.clear();
}



int process_string(string str)
{
	int num; int num2;
	stack<int> numbers;
	char s[str.length() + 1];

	strcpy(s, str.c_str());

	char * pch;
	pch = strtok (s, " ,.\t");

	if (pch != NULL)
	{ //process first number
		numbers.push(atoi (pch));
		pch = strtok (NULL, " ,.\t");
	}

	while (pch != NULL)
	{ //Process other numbers
		if (atoi (pch) != 0 || pch[0] == 0){
			numbers.push(atoi (pch));
			pch = strtok (NULL, " ,.\t");
		}
		//Process operations
		else {
			num2 = numbers.top();
			numbers.pop();
			num = numbers.top();
			numbers.pop();

			switch(pch[0]){
				case '+':
					num = num + num2;
					pch = strtok (NULL, " ,.\t");
					numbers.push(num);
					continue;
					break;

				case '-':
					num = num - num2;
					pch = strtok (NULL, " ,.\t");
					numbers.push(num);
					continue;
					break;

				case '*':
					num = num * num2;
					pch = strtok (NULL, " ,.\t");
					numbers.push(num);
					continue;
					break;

				case '/':
					num = num / num2;
					pch = strtok (NULL, " ,.\t");
					numbers.push(num);
					continue;
					break;

				case '^':
					num = pow(num, num2);
					pch = strtok (NULL, " ,.\t");
					numbers.push(num);
					continue;
					break;

				default:
					pch = strtok (NULL, " ,.\t");
			}
		}
	}


	return numbers.top();
}

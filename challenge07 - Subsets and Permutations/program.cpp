// program.cpp
// challenge07
// Yifan Yu
// yyu3
// Sept 17, 2018

#include <iostream>
#include <vector>

using namespace std;

bool are_permutation(int num1, int num2);

void generate_solutions(int quotient){
  bool no_solution = true;
  int num2;

  //3. go through options (start with lowest possible to highest possible)
  for(int num1 = 1234; num1 < 50000; num1++){
    num2 = num1 * quotient;
    if (num2 > 98765)
      break;

    else if (are_permutation(num1, num2)){ //using a program function
      //4. print possibilities
      if (num1 < 10000){
        cout << num2 << " / 0" << num1 << " = " << quotient << endl;
      }
      else{
        cout << num2 << " / " << num1 << " = " << quotient << endl;
      }

      no_solution = false;
    }
  }

  if (no_solution){
    cout << "There are no solutions for " << quotient << "." << endl;
  }
}

int main(int argc, char *argv[]) {
  int i;
  int input_count = 0;

	//1. Collect Input
  while(cin >> i){
    if (i <= 0){
      return 0;
    }
    if(input_count != 0) {cout << endl;}

    // 2. check int;
    if (i > 98765 / 1234 || i < 2) //provide i with lower and upper limits
    {
      cout << "There are no solutions for " << i << "." << endl;
    }
    else{
      generate_solutions(i);
    }
    input_count++;
  }

	return 0;
}


//function that checks for two 5 digit numbers are permutation of 10 digits
bool are_permutation(int num1, int num2){

  int arr[10]= { 0 };

  arr[(num1 / 10000) % 10]++; //histogram increment for each digit
  arr[(num1 / 1000)  % 10]++;
  arr[(num1 / 100)   % 10]++;
  arr[(num1 / 10)    % 10]++;
  arr[(num1 / 1)     % 10]++;

  arr[(num2 / 10000) % 10]++;
  arr[(num2 / 1000)  % 10]++;
  arr[(num2 / 100)   % 10]++;
  arr[(num2 / 10)    % 10]++;
  arr[(num2 / 1)     % 10]++;

  for(int i = 0; i <= 9; i++){
    if(arr[i] > 1)
      return false;
  }
  return true;
}

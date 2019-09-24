// program.cpp
// challenge21
// Yifan Yu
// yyu3
// November 23, 2018

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;


void reversePrintVector(vector<int> vec);
vector<int> returnSum(vector<int> a, vector<int> b);

//2. Generate big ints
void calcBigInts(vector<vector<int>> &bigInts){

  vector<int> first = {2}, second = {5}, third = {3, 1}, fourth;
  bigInts.push_back(first);
  bigInts.push_back(second);
  bigInts.push_back(third);

  for(int i = 3; i < 1000; i++){
    fourth = returnSum(third, third);
    fourth = returnSum(fourth, second);
    fourth = returnSum(fourth, first);

    first = second;
    second = third;
    third = fourth;
    bigInts.push_back(fourth);
  }

}

int main(int argc, char *argv[]) {

  //1. input and initialization
  int num;
  vector<vector<int>> bigInts;
  calcBigInts(bigInts);
  while(cin >> num){

    //3. Output
    reversePrintVector(bigInts[num - 1]);
  }

  return EXIT_SUCCESS;
}

void reversePrintVector(vector<int> vec){
  for(int i = vec.size() - 1; i >= 0; i--)
    cout << vec[i];
  cout << endl;
}

vector<int> returnSum(vector<int> a, vector<int> b){

  vector<int> sum;

  int length, carry_digit = 0;
  length = (a.size() <= b.size()) ? b.size() : a.size();

  for(int i = 0; i <= length; i++){
    int a_num, b_num;

    a_num = (i >= a.size()) ? 0 : a[i];
    b_num = (i >= b.size()) ? 0 : b[i];

    int digit_sums = a_num + b_num + carry_digit;
    if(i != length || digit_sums != 0)
      sum.push_back(digit_sums % 10);
    carry_digit = (digit_sums > 9) ? 1 : 0;

 }
  return sum;
}

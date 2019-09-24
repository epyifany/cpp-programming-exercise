// program.cpp
// challenge09
// Yifan Yu
// yyu3
// Sept 24, 2018

#include <iostream>

using namespace std;



int main(int argc, char *argv[]) {

  //1. initialization & input
  int oneCount, twoCount, threeCount, fourCount;

  while(cin >> oneCount >> twoCount >> threeCount >> fourCount){

    //2. count how many blocks there are
    int extraCount = fourCount * 4 + threeCount * 3 + twoCount * 2 + oneCount;

    //3. Calculate how many rows there  are
    int rowCount = (extraCount % 4 != 0) ? extraCount / 4 + 1 : extraCount / 4;

    //4. output
    cout << rowCount << endl;
  }

  return 0;

}

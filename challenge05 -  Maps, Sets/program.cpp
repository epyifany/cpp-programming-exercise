// program.cpp
// challenge05
// Yifan Yu
// yyu3
// Sept 11, 2018

#include <iostream>
#include <unordered_map>

using namespace std;

int calcCycleLength (long int i, unordered_map<long long int, long int>& mymap){

  long int count = 1;
  int initial = i;


  while(i != 1) {

    if (mymap.find(i) != mymap.end() ) //check for pairs in the map
    {
      count = count + mymap[i] - 1;
      break;
    }
    else if(i % 2) { //if odd

      i = 3 * i + 1;
    }
    else {

      i = i / 2;
    }
    count++;
  }
  mymap[initial] = count;
  return count;
}

int main(int argc, char *argv[]) {

  int a, b;
  unordered_map<long long int, long int> mymap;

  while(cin >> a){
    cin >> b;
    int maxInt = a;
    long int maxCyc = 0;

    if(a < b){
      for (int i = a; i <= b; i++){
        if(calcCycleLength(i, mymap) > maxCyc){
          maxCyc = mymap[i];
          maxInt = i;

        }
      }
    }
    else{
      for (int i = b; i <= a; i++){
        if(calcCycleLength(i, mymap) > maxCyc){
          maxCyc = mymap[i];
          maxInt = i;

        }
      }
    }
    
    cout << a << " " << b << " " << maxInt << " " << maxCyc << endl;

  }

	return 0;
}

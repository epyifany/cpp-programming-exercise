// program.cpp
// challenge06
// Yifan Yu
// yyu3
// Sept 13, 2018

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>


using namespace std;

void split_string(string str, vector<string> &strVector);

//2. Calculate Sequence for a given index
int calcSeq(int index, vector<string> strVector){
  int seq = 0;
  set<string> items;

  while(index < strVector.size() && !(items.count(strVector[index]))){
    items.insert(strVector[index]);
    seq++;
    index++;
  }
  return seq;
}



//3. finding the index with the largest sequence
int longestIndex(vector<string> strVector){

  int maxIndex = 0;

  for(int i = 1; i < strVector.size(); i++){
    if(calcSeq(maxIndex, strVector) < calcSeq(i, strVector)){
      maxIndex = i;
    }

  }
  return maxIndex;
}



int main(int argc, char *argv[]) {

  string str;
  //1. process Input
  while(getline(cin, str)){

    vector<string> strVector;

    split_string(str, strVector);


    //4. outputting
    int maxIndex = longestIndex(strVector);
    int maxSeq = calcSeq(maxIndex, strVector);
    cout << maxSeq << ": ";
    for (int i = maxIndex; i < maxIndex + maxSeq - 1; i++)
      cout << strVector[i] << ", ";

    cout << strVector[maxIndex + maxSeq - 1] << endl;

  }
  return 0;

}





//This function split a string seperated by   ,.\t and push them to a vector
void split_string(string str, vector<string> &strVector){


  char cstr[str.length() + 1]; //declaring a c string with sentinel
  strcpy(cstr, str.c_str()); //copying the string into a c cstring

  char *pch;
	pch = strtok(cstr, " ,.\t");
  while(pch != NULL)
	{
		string convert_string = pch;
    strVector.push_back(convert_string);
		pch = strtok(NULL, " ,.\t");
	}

}

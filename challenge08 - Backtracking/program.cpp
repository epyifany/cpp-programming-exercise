// program.cpp
// challenge08
// Yifan Yu
// yyu3
// Sept 21, 2018

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

void split_string(string str, vector<string> &strVector);


//3. process operation: inserting answers on a set
void process_op(int num, set<int> &myset){
  if (myset.empty()){
    myset.insert(num);
  }

  else {
    set<int> newset;
    for (auto elem : myset){
      newset.insert(elem + num);
      newset.insert(elem - num);
      newset.insert(elem * num);
    }
    myset = newset;
  }

}


int main(int argc, char *argv[]) {

  string str;
  //1. process Input
  while(getline(cin, str)){

    vector<string> strVector;
    split_string(str, strVector);
    bool is_illuminati = false;

    set<int> myset;

    //2. Generating permutations
    sort(strVector.begin(), strVector.end());
    do {

      for(int i = 0; i < strVector.size(); i++){
        process_op(stoi(strVector[i]), myset);
      }

      for(auto elem : myset){
        // cout << elem << endl;
        if (elem == 13) {is_illuminati = true; }
      }
      myset.clear();

      if(is_illuminati) {break; }

    } while (next_permutation(strVector.begin(), strVector.end()));


    //4. processing outputs
    if(is_illuminati){
      cout << "Illuminati!" << endl;
    }
    else{
      cout << "Nothing to see" << endl;
    }

  }
	return 0;
}


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

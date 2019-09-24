// program.cpp
// challenge10
// Yifan Yu
// yyu3
// Sept 24, 2018

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

void split_string(string str, vector<string> &strVector);

//3. check and update if each pos of the array can be reached by jumping
void process_jump(vector<string> &strVector, vector<bool> &boolVector){

  for(int i = 0; i < strVector.size() - 1; i++){
    if(boolVector[i]){
      for(int j = 0; j < stoi(strVector[i]); j++){
        boolVector[1 + j + i] = true;
      }
    }
  }
}


int main(int argc, char* argv[]){

  string str;
  //1. Process Input
  while(getline(cin, str)){

    vector<string> strVector;
    split_string(str, strVector);

    //2. Declaring a bool vector of bool indicating if positions can be reached
    vector<bool> boolVector;
    boolVector.push_back(true); //first one has to be reached
    for(int i = 1; i < strVector.size(); i++) {boolVector.push_back(false);}


    process_jump(strVector, boolVector);

    //4. Outpus
    if(boolVector[strVector.size() - 1]) { // if you can reach the last pos
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }

  }

  return EXIT_SUCCESS;
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

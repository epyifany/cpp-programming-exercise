// program.cpp
// challenge13
// Yifan Yu
// yyu3
// October 17, 2018

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>


using namespace std;

void split_string(string str, vector<int> &intVector);


void find_subtree_root_r(vector<int> intVector, int height, vector<vector<int>> &map){

  //basecases
  if (intVector.size() == 1){
    map[height].push_back(intVector[0]);
    return;
  }
  if (intVector.size() == 0){
    return;
  }

  int half_size = intVector.size() / 2;
  cout << "map add " << intVector[intVector.size() / 2] << " at level " << height << endl;
  map[height].push_back(intVector[intVector.size() / 2]);

  // int half_size = intVector.size() / 2;
  vector<int> split_lo(intVector.begin(), intVector.begin() + half_size);
  // split_lo.pop_back();
  for (auto a: split_lo)
    cout << a;
  cout << endl;

  vector<int> split_hi(intVector.begin() + half_size, intVector.end());
  split_hi.erase(split_hi.begin());

  for (auto a: split_hi)
    cout << a;
  cout << endl;

  find_subtree_root_r(split_lo, height + 1, map);
  find_subtree_root_r(split_hi, height + 1, map);
}

int main(int argc, char *argv[]) {

  string str;
  //1. process Input
  while(getline(cin, str)){

    vector<int> intVector;
    split_string(str, intVector);

    vector<int> emptyVec;
    vector<vector<int>> map;
    int heights = int(log2(intVector.size())) + 1;
    cout << heights << endl;

    for(int i = 0; i < heights; i++){
      map.push_back(emptyVec);
    }

    find_subtree_root_r(intVector, 0, map);



    for (auto level: map){
      for (auto node: level){
        cout << node;
      }
      cout << "return" << endl;
    }

    // func(intVector, 0);

  }
  return 0;

}





//This function split a string seperated by   ,.\t and push them to a vector
void split_string(string str, vector<int> &intVector){


  char cstr[str.length() + 1]; //declaring a c string with sentinel
  strcpy(cstr, str.c_str()); //copying the string into a c cstring

  char *pch;
	pch = strtok(cstr, " ,.\t");
  while(pch != NULL)
	{
		string convert_string = pch;
    intVector.push_back(stoi(convert_string));
		pch = strtok(NULL, " ,.\t");
	}

}

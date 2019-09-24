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

//2. Divide and Conquer
void find_subtree_root_r(vector<int> intVector, int height, vector<vector<int>> &tree){

  //basecases
  if (intVector.size() == 1){
    tree[height].push_back(intVector[0]);
    return;
  }
  if (intVector.size() == 0){
    return;
  }
  //Conquer
  int half_size = intVector.size() / 2;
  tree[height].push_back(intVector[intVector.size() / 2]); //adding value to tree
  //Divide
  vector<int> split_lo(intVector.begin(), intVector.begin() + half_size);
  vector<int> split_hi(intVector.begin() + half_size, intVector.end());
  split_hi.erase(split_hi.begin());
  find_subtree_root_r(split_lo, height + 1, tree);
  find_subtree_root_r(split_hi, height + 1, tree);
}

int main(int argc, char *argv[]) {

  string str;
  //1. process Input
  while(getline(cin, str)){

    vector<int> intVector, emptyVec;
    vector<vector<int>> tree;
    split_string(str, intVector);
    int heights = int(log2(intVector.size())) + 1; //calculating the min height
    for(int i = 0; i < heights; i++){
      tree.push_back(emptyVec); //tree contains the nodes at each level
    }

    find_subtree_root_r(intVector, 0, tree); //start finding the root at level 0

    //3. Process output
    for (auto level: tree){
      for(int i = 0; i < level.size(); i++){
        if (i != level.size() - 1)
          cout << level[i] << " ";
        else
          cout << level[i];
      }
      cout << endl;
    }
  }
  return EXIT_SUCCESS;
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

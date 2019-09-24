// program.cpp
// challenge12
// Yifan Yu
// yyu3
// Oct 4, 2018

#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <algorithm>

using namespace std;

int getYum(vector<tuple<int, int>>);
void update_yummiest(vector<tuple<int, int>> candies_packed, vector<tuple<int, int>> &candies_yum);
bool can_add_to_pack(vector<tuple<int, int>> candies_packed, int add_weight, int weight);



//3. recursivly function that runs through combination
void func_r(vector<tuple<int, int>> candies_left, vector<tuple<int, int>> candies_packed, vector<tuple<int, int>> &candies_yum, int weight){
  while(!candies_left.empty()){
    //as long as there are candies in the left array,
    //if able to add, compare, erase what was just being added.
    if(can_add_to_pack(candies_packed, get<0>(candies_left[0]), weight)){
      candies_packed.push_back(candies_left[0]);
      candies_left.erase(candies_left.begin());
      update_yummiest(candies_packed, candies_yum);
      func_r(candies_left, candies_packed, candies_yum, weight); //recursive call
      candies_packed.erase(candies_packed.end());
    }
    else{
      //if not able to add,
      candies_left.clear();
      candies_packed.erase(candies_packed.end());
    }
  }
}


int main(int argc, char *argv[]) {

  //1. Input / Initialization
  int weight, count, temp1, temp2;
  while(cin >> weight >> count){

    if(weight == 0 && count == 0) {return 0; } //Exit if no more counts

    vector<tuple<int, int>> candies;
    vector<tuple<int, int>> pack;
    vector<tuple<int, int>> yummiest;
    for(int i = 0; i < count; i++){
      cin >> temp1 >> temp2;
      candies.push_back(make_tuple(temp1, temp2));
    }

    //2. Sort and go through all combination, not permutation in order to find
    // the yummiest combination that can fit in the pack
    sort(candies.begin(), candies.end());
    func_r(candies, pack, yummiest, weight);

    // 4. Output
    cout << getYum(yummiest) << endl;
    for (int i = 0; i < yummiest.size(); i++){
      cout << get<0>(yummiest[i]) << " " << get<1>(yummiest[i]) << endl;
    }

  }
  return 0;
}




int getYum(vector<tuple<int, int>> candies){
  int yum = 0;
  for (int i = 0; i < candies.size(); i++){
    yum = yum + get<1>(candies[i]);
  }
  return yum;
}

void update_yummiest(vector<tuple<int, int>> candies_packed, vector<tuple<int, int>> &candies_yum){
  if(getYum(candies_packed) > getYum(candies_yum)){
    candies_yum = candies_packed;
  }
}

bool can_add_to_pack(vector<tuple<int, int>> candies_packed, int add_weight, int weight){
  int total_weight_in_pack = 0;
  for (int i = 0; i < candies_packed.size(); i++){
    total_weight_in_pack +=  get<0>(candies_packed[i]);
  }
  total_weight_in_pack += add_weight;

  if(total_weight_in_pack <= weight){
    return true;
  }
  else{
    return false;
  }
}

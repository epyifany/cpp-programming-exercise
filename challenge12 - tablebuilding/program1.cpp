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

  cout <<  "pack weight calculation: " << total_weight_in_pack << endl;

  total_weight_in_pack += add_weight;
  if(total_weight_in_pack <= weight){
    cout << "pack add: " << add_weight << endl;
    return true;
  }
  else{
    cout << "pack could not add: " << add_weight << endl;
    return false;
  }
}

void func(vector<tuple<int, int>> candies_left, vector<tuple<int, int>> candies_packed, int weight){
  cout << "current what is in the pack : ";
  for (int i = 0; i < candies_packed.size(); i++){
    cout << get<0>(candies_packed[i]) << " " << get<1>(candies_packed[i]) << " ";
  }
  cout << endl;

  while(!candies_left.empty()){
    //as long as there are candies in the left array,
    //if able to add, compare, erase what was just being added.
    if(can_add_to_pack(candies_packed, get<0>(candies_left[0]), weight)){
      candies_packed.push_back(candies_left[0]);
      candies_left.erase(candies_left.begin());
      func(candies_left, candies_packed, weight);
      candies_packed.erase(candies_packed.end());
    }
    else{
      //if not able to add,
      candies_left.clear();
      candies_packed.erase(candies_packed.end());
    }
  }

  // candies_packed.erase(candies_left.end());
}





int main(int argc, char *argv[]) {

  //1. Input

  int weight, count, temp1, temp2, yum;
  cin >> weight >> count;

  vector<tuple<int, int>> candies;
  vector<tuple<int, int>> pack;

  for(int i = 0; i < count; i++){
    cin >> temp1 >> temp2;

    candies.push_back(make_tuple(temp1, temp2));
  }
  sort(candies.begin(), candies.end());

  for (int i = 0; i < count; i++)
  { cout << get<0>(candies[i]) << " " << get<1>(candies[i]) << " "<< "\n"; }

  func(candies, pack, weight);

  return 0;

}

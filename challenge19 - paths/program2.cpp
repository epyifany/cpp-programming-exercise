// program.cpp
// challenge19
// Yifan Yu
// yyu3
// Nov 14, 2018

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;

bool map[256][256];
void split_string(string str, vector<int> &intVector);

vector<int> cycleVec_r(int current, int N, vector<int> visited){

  visited.push_back(current);
  cout << "Current: " << current << endl;
  for(auto num : visited){
    cout << num << " ";
  } cout << endl;

  //successful case: if visited all and can go back to 1
  if(visited.size() == N && map[0][visited.back() - 1]){
    visited.push_back(1);
    return visited;
  }

  //failed case: if visited all and can go back to 1
  if(visited.size() == N && !map[0][visited.back() - 1]){
    visited.clear();
    return visited;
  }

  vector<int> returnVec;
  for(int i = 1; i <= N; i++){
    vector<int>::iterator it = find(visited.begin(), visited.end(), i);
    if(it == visited.end() && map[i - 1][current - 1]){
      returnVec = cycleVec_r(i, N, visited);
      if(!returnVec.empty()) {return returnVec; }
    }
  }

  //dead case
  returnVec.clear();
  return returnVec;
}


int main(int argc, char *argv[]) {
  cout.flush();
  int N, temp1, temp2;
  string str;


  while(cin >> N){
    // bool map[N][N];
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        map[i][j] = 0;
      }
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        cout << map[i][j] << " ";
      }
      cout << endl;
    }
    char c = (cin >> ws).peek();
    cout << "peek is "<< c << endl;
    while(c != '%'){
      cin >> temp1 >> temp2;
      cout << temp1 << temp2 << endl;
      map[temp1 - 1][temp2 - 1] = true;
      map[temp2 - 1][temp1 - 1] = true;
      c = (cin >> ws).peek();
      cout << "peek is "<< c << endl;
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        cout << map[i][j] << " ";
      }
      cout << endl;
    }

    vector<int> emptyVec;
    vector<int> vectorInt = cycleVec_r(1, N, emptyVec);

    //4. Output
    for(auto num : vectorInt){
      cout << num << " ";
    }
    cout << endl;

    cin >> str; //extract % from input
  }
  return 0;

}

// Yifan Yu
// program.cpp

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

//2. Design binary search functions for given target
int binary_search_index(vector<int> &v, int target) {
    auto it = lower_bound(v.begin(), v.end(), target);
    return (it != v.end() && *it == target ? it - v.begin() : v.size());
}

int main(int argc, char *argv[]) {

    //1. Read and Store Inputs
    vector<int> v, targets;
    int ROWS = 0, COLS = 0, entry, targetNums, target;


    while(cin >> ROWS >> COLS){
      int size = ROWS * COLS; // calculate the total entries of the matrix

      if (size == 0) {
        cerr << "Error Message: EXIT NORMAL BUT MATRIX SIZE ZERO" << endl;
        return 0;
      }

      for (int i = 0; i < size; i++){ //pushing a matrix into a vector
        cin >> entry;
        v.push_back(entry);
      }

      cin >> targetNums;        //pushing all targets into a vector
      for (int i = 0; i < targetNums; i++){
        cin >> target;
        targets.push_back(target);
      }




      //3. Output
      for (int i = 0; i < targetNums; i++){
        //case 1 no match
        if (!binary_search(v.begin(), v.end(), targets[i])){
          cout << targets[i] << " is not in the grid" << endl;
        }
        else{ //case 2 match and calculate its col and row based on index
          cout << targets[i] << " is at row=" << binary_search_index(v, targets[i]) / COLS;
          cout << ", col=" << binary_search_index(v, targets[i]) % COLS << endl;
        }
      }

      v.clear();
      targets.clear();
    }

    return 0;
}

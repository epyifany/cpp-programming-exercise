// program.cpp
// challenge11
// Yifan Yu
// yyu3
// Oct 3, 2018

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void minSteps(int x, int y, vector<vector<int>> &table, vector<vector<int>> &table2) {


  if (x == 0 && y == 0){
    table2[0][0] = table[0][0];
  }
  else if(y - 1 < 0){
    table2[y][x] = table[y][x] + table2[y][x - 1]; //first column
  }
  else if(x - 1 < 0){
    table2[y][x] = table[y][x] + table2[y - 1][x]; //first column
  }
  else{
    if(table2[y][x - 1] <= table2[y - 1][x] &&
      table2[y][x - 1] <= table2[y - 1][x - 1])
      {table2[y][x] = table[y][x] + table2[y][x - 1];}
    else if(table2[y - 1][x] <= table2[y][x - 1] &&
      table2[y - 1][x] <= table2[y - 1][x - 1])
      {table2[y][x] = table[y][x] + table2[y - 1][x];}
    else
      {table2[y][x] = table[y][x] + table2[y - 1][x - 1];}
  }
}



int main(int argc, char *argv[]) {

  //1. Input / table building

  int size, temp;

  cin >> size;
  vector<vector<int>> table;
  vector<int>row;
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      cin >> temp;
      row.push_back(temp);
    }
    table.push_back(row);
    row.clear();
  }

  //2. table processing / route remembering

  vector<vector<int>> table2;
  vector<int>row2;
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      row2.push_back(0);
    }
    table2.push_back(row2);
    row2.clear();
  }



  for(int i = 0; i < 2 * size - 1; i++) {
    if(i < size){
      for (int x = 0; x <= i; x++) {
        cout << "x = " << x << " y = " << i - x << endl;
        minSteps(x, i - x, table, table2);
      }
    }
    else {
      for (int y = size - 1; i - y < size; y--){
        cout << "x = " << i - y << " y = " << y << endl;
        minSteps(i - y, y, table, table2);
      }
    }
  }

  //3. output

  //test output table
  cout << "table1" << endl;
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++){
      cout << table[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\ntable2" << endl;
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++){
      cout << table2[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;

}

// program.cpp
// challenge11
// Yifan Yu
// yyu3
// Oct 4, 2018

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//3. design a function that given a coordinate, select a shortest path and update both tables
void minSteps(int x, int y, vector<vector<int>> &table, vector<vector<string>> &table2) {

  if (x == 0 && y == 0){ //if the coordinate is the origin
    table2[0][0].append(to_string(table[0][0]));
  }
  else if(y - 1 < 0){ //if the coordinate has no path above it
    table2[y][x] = table2[y][x - 1] + " " + to_string(table[y][x]);
    table[y][x] = table[y][x] + table[y][x - 1]; //first column
  }
  else if(x - 1 < 0){ //if the coordinate has no path left of it
    table2[y][x] = table2[y - 1][x] + " " + to_string(table[y][x]);
    table[y][x] = table[y][x] + table[y - 1][x]; //first column
  }
  else{ //if the coordinate has path from both top left, top and left
    if(table[y][x - 1] <= table[y - 1][x] &&
    table[y][x - 1] <= table[y - 1][x - 1])
    {
      table2[y][x] = table2[y][x - 1] + " " + to_string(table[y][x]);
      table[y][x] = table[y][x] + table[y][x - 1];
    }
    else if(table[y - 1][x] <= table[y][x - 1] &&
    table[y - 1][x] <= table[y - 1][x - 1])
    {
      table2[y][x] = table2[y - 1][x] + " " + to_string(table[y][x]);
      table[y][x] = table[y][x] + table[y - 1][x];
    }
    else
    {
      table2[y][x] = table2[y - 1][x - 1] + " " + to_string(table[y][x]);
      table[y][x] = table[y][x] + table[y - 1][x - 1];
    }
  }
}



int main(int argc, char *argv[]) {

  //1. Input / table building
  int size, temp;
  while(cin >> size)
  {
    if (size <= 0)
    { return 0; }

    //first table updates the shortest travel dis at given coordinate
    vector<vector<int>> table;
    vector<int>row;
    for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
        cin >> temp; // reads the N x N map into the table
        row.push_back(temp);
      }
      table.push_back(row);
      row.clear();
    }

    //the second table keeps track of the shortest route
    vector<vector<string>> table2;
    vector<string>row2;
    for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
        row2.push_back("");
      }
      table2.push_back(row2);
      row2.clear();
    }

    //2. table processing / route remembering
    for(int i = 0; i < 2 * size - 1; i++) {
      if(i < size){
        for (int x = 0; x <= i; x++) {
          minSteps(x, i - x, table, table2);
        }
      }
      else {
        for (int y = size - 1; i - y < size; y--){
          minSteps(i - y, y, table, table2);
        }
      }
    }

    //4. output
    cout << table[size - 1][size - 1] << endl;
    cout << table2[size - 1][size - 1] << endl;

  }
  return 0;

}

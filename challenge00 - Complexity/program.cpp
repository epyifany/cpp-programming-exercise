// program.cpp
// challenge00
// Yifan Yu
// yyu3
// Aug 23, 2018

#include <iostream>
#include <vector>
using namespace std;

bool isTidy (int x);


// Main Execution

int main(int argc, char *argv[])
{
  int deckCount = 1;
  int deckNum;
  int deckInput;

  vector<int> deck;

  cin >> deckNum;

  //store deck size in a vector
  while (deckCount <= deckNum)
  {

    cin >> deckInput;
    deck.push_back(deckInput);
    deckCount++;
  }
  for (int i = 0; i < deck.size(); i++){

    int tidyCount = deck[i];
    
    //if a number is not tidy, goto a small number
    while(!isTidy(tidyCount))
      tidyCount--;

    //output
    cout << "Deck #" << int(i+1) << ": "<< tidyCount<<endl;
  }


  return 0;
}

bool isTidy (int x){
  bool xTidy = false;

  //check if tidy. compare a first letter to a second letter
  if (x / 1000 <= (x % 1000)/100 && (x % 1000)/100 <= (x % 100)/10 && (x % 100)/10 <= x % 10)
    xTidy = true;

  return xTidy;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

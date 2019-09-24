//Yifan Yu
//Challenge 01
//yyu3
//Aug 29, 2018

#include <iostream>
#include <string>

// Ask questions to resolve ambiguity.
// What are the data types?  What assumptions?
//
//
// Design an algorithm.
// What is the complexity? What trade-offs?
//
//
// Write pseudocode first.
// Goal is to eventually translate into "real" code.
//
//
// Write code at a moderate pace.
// Use data structures, keep it readable.
//
//
// Test your code and fix any mistakes.
// Consider extreme cases, user error, general case

using namespace std;

const size_t NLETTERS =26;

int letters_used(string &s1, string &s2){

  int times_used = 0;
  bool letters_used_up = true;
  // 2. Computer histograms
  int h1[NLETTERS] = {0};
  int h2[NLETTERS] = {0};

  for (auto c : s1) { h1[tolower(c) - 'a']++; }
  for (auto c : s2) { h2[tolower(c) - 'a']++; }


	// 3. deduce s2 histogram in s1
  while(true){
		
		 
    for (size_t i = 0; i < NLETTERS; i++){
      h1[i] = h1[i] - h2[i];//deduction for every letter
    }


    for (size_t i = 0; i < NLETTERS; i++){
      if (h1[i] < 0)
        return times_used; //no more letters therefore does not contain word
    }
    times_used++;

  }

  return times_used;
}

int main(int argc, char *argv[]){

  //1. Read input
  string s1, s2;

  while (cin >> s1 >> s2){

    // 4. Output result
    cout << letters_used(s1, s2) << endl;


  }
}

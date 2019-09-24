// Yifan Yu
// yyu3
// Sept 6, 2018

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

bool process_string(string gold, string blue){
	//2. Pushing numbers from a line into a vector
	char goldc[gold.length() + 1];
	char bluec[blue.length() + 1];

	strcpy(goldc, gold.c_str());
	strcpy(bluec, blue.c_str());
	
	vector<int> goldnum;
	vector<int> bluenum;

	char *pch;
	pch = strtok(goldc, " ,.\t");
	while(pch != NULL)
	{
		goldnum.push_back(atoi(pch));
		pch = strtok(NULL, " ,.\t");
	}

 	char *pch2;	
  pch2 = strtok(bluec, " ,.\t");
  while(pch2 != NULL)
  {
    bluenum.push_back(atoi(pch2));
    pch2 = strtok(NULL, " ,.\t");
  }

	//3. Sorting the vectors
  sort(goldnum.begin(), goldnum.end());
	sort(bluenum.begin(), bluenum.end());

	//4. Comparing the height of each girl
	
	for(int i = 0; i < bluenum.size(); i++){
	
		if(bluenum[i] <= goldnum[i])
			return false;
	}	


	
	return true;
}


int main(int argc, char *argv[]) {
	string gold, blue;

	//1. Collect Input
	while(getline(cin, gold)){
		
		getline(cin, blue);
		

		//5. Process Output
		if(process_string(gold, blue)){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
		

	}
	return 0;
}


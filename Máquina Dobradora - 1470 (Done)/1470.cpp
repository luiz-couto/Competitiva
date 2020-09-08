#include <bits/stdc++.h>

using namespace std;

void turnTheTapeRecursiv(vector<int> currentTape, vector<int> finalTape, int end, int start, bool *isPossible) {
  int currentSize = end - start + 1;
  int finalSize = finalTape.size() - 1;
  if (currentSize >= finalSize && (*isPossible) == false) {
    if (currentSize == finalSize) {
      
      auto itStart = 1;
      auto itEnd = currentTape.size() - 1;
      bool checkEqualStart = true;
      bool checkEqualEnd = true;
      
      for (int i=start; i<=end; i++) {
        if ( currentTape[itStart] != finalTape[itStart]) {
          checkEqualStart = false;
        }

        if (currentTape[itEnd] != finalTape[itStart]) {
          checkEqualEnd = false;
        }

        itStart++;
        itEnd--;

      }

      // for (int i : currentTape) {
      //   cout << i << " ";
      // }
      // cout << endl;

      // for (int j : finalTape) {
      //   cout << j << " ";
      // }
      // cout << endl;

      if (checkEqualStart || checkEqualEnd) {
        *isPossible = true;
      }

    } else {

      int aux, minSize, maxSize;
      aux = currentSize;

      if (finalSize <= aux/2) {
        minSize = aux/2;
      } else {
        minSize = aux - finalSize;
      }

      maxSize = abs(end - minSize);
      minSize = minSize + start;

      for(int j=start+1; j<=minSize; j++){
        for(int i=start; i<j; i++) {
          currentTape[j+(j-i)-1] = currentTape[j+(j-i)-1] + currentTape[i];
        }
        
        turnTheTapeRecursiv(currentTape, finalTape, end, j, isPossible);
        
        for(int i=start; i<j; i++) {
          currentTape[j+(j-i)-1] = currentTape[j+(j-i)-1] - currentTape[i]; 
        }
        
      }
      for(int j=end-1; j>=maxSize; j--){
        for(int i=end; i>j; i--) {
          currentTape[j-(i-j)+1] = currentTape[j-(i-j)+1] + currentTape[i]; 
        }

        turnTheTapeRecursiv(currentTape, finalTape, j, start, isPossible);
        
        for(int i=end; i>j; i--) {
          currentTape[j-(i-j)+1] = currentTape[j-(i-j)+1] - currentTape[i]; 
        }
          
      }

    }
  }
}



int main() {

  int inputSize;

  while (cin >> inputSize) {

    vector<int> initialTape;
    initialTape.push_back(0);

    for (int i=0; i<inputSize; i++) {
      int value;
      cin >> value;
      initialTape.push_back(value);
    }

    int finalSize;
    cin >> finalSize;
    vector<int> finalTape;
    finalTape.push_back(0);

    for (int i=0; i<finalSize; i++) {
      int value;
      cin >> value;
      finalTape.push_back(value);
    }

    bool isPossible = false;

    if (finalSize == 1) {
      int sum = 0;
      for (int i=1; i<initialTape.size(); i++) {
        sum = sum + initialTape[i];
      }

      if (sum == finalTape[1]) {
        isPossible = true;
      }
    } else {
      turnTheTapeRecursiv(initialTape, finalTape, inputSize, 1, &isPossible);
    }

    if (isPossible) {
      cout << "S" << endl;
    } else {
      cout << "N" << endl;
    }


  }

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int auxToCut(vector<int> vecLen, int pos) {
  int sum = 0;
  for (int i=pos+1; i<vecLen.size(); i++) {
    sum = sum + vecLen[i];
  }
  return sum + vecLen[pos];
}

void cutString(string str, int parts) {
  vector<int> vecLen (parts, 1);
  vecLen[0] = str.length() - (parts - 1);

  int numberOfIter = 0;
  while (1) {
    //cout << vecLen[0] << " " << vecLen[1] << " " << vecLen[2] << " " << vecLen[3]  << endl;
    numberOfIter++;
    
    
    vector<int> vecSub(parts, -1);
    bool needsCheck = true;
    for (int i=vecLen.size() - 1; i>= 0; i--) {
      string numberInString = str.substr(str.length() - auxToCut(vecLen, i), vecLen[i]);
      int numberInInt = stoi(numberInString);
      
      if (numberInString.length() > 1 && numberInString[0] == 0) {
        needsCheck = false;
        break;
      }
      if (i != vecLen.size() - 1 && numberInInt > 1000) {
        needsCheck = false;
        break;
      }
      if (i != vecLen.size() - 1 && numberInInt > vecSub[vecLen.size() - 1]) {
        needsCheck = false;
        break;
      }
      vecSub[i] = numberInInt;
    }

    if (needsCheck) {
      int sum = 0;
      for (int i=0; i<vecSub.size() - 1; i++) {
        sum = sum + vecSub[i];
      }
      if (sum == vecSub[vecSub.size() - 1]) {
        for (int i=0; i<vecSub.size(); i++) {
          cout << vecSub[i] << " ";
        }
        cout << endl;
      }
    }

    bool breakItAll = false;
    int sumOfRight = 0;

    for(int i=vecLen.size() - 1; i>= 1; i--) {
      if (i == vecLen.size() - 1 && vecLen[i] == str.length() - i) {
        breakItAll = true;
        break;
      }

      if (vecLen[i] + vecLen[i - 1] == str.length() - sumOfRight - i + 1) {
        if (vecLen[i - 1] == str.length() -  (sumOfRight + vecLen[i]) - (i-1)) {
          vecLen[i] = vecLen[i] + 1;
          for(int j=i-1; j>=0; j--) {
            
            if (j == 0) {
              vecLen[j] = (str.length() - sumOfRight) - (vecLen[i]) - (i - 1);
            } else {
              vecLen[j] = 1;
            }
          }
          break;
        } else {
          vecLen[i] = vecLen[i] + 1;
          vecLen[i - 1] = vecLen[i - 1] - 1;
          break;
        }

      }

      sumOfRight = sumOfRight + vecLen[i];

    }

    if (breakItAll) {
      break;
    }

  }
    
    
    //cout << vecSub[0] << " " << vecSub[1] << " " << vecSub[2] << " " << vecSub[3]  << endl;
}
int main() {
  cutString("14121238", 4);
  return 0;
}
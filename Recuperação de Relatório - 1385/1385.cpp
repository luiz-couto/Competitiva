#include <bits/stdc++.h>

using namespace std;


struct bro {
  string name;
  string number;
  bro(string name, string number) {
    this->name = name;
    this->number = number;
  }
};

vector<bro> myMainVec;

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
  vector<int> finals;

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
  //cutString("9519851936", 3);
  
  int c;
  cin >> c;

  for (int i=0; i<c; i++) {
    string input;
    cin >> input;

    int numberOfProducts = (input.length() - 6) / 2;
    
    string totalStr;
    for (int j=0; j<4; j++) {
      string broStr;
      cin >> broStr;

      if (broStr[0] == 'T' && broStr[1] == 'P') {
        totalStr = broStr;
        break;
      }

      string name;
      string number;
      for (int k=0; k<broStr.length(); k++) {
        if (isdigit(broStr[k])) {
          name = broStr.substr(0,k);
          number = broStr.substr(k, broStr.length() - name.length());
          break;
        }
      }

      myMainVec.push_back(bro(name, number));
      cutString(number, numberOfProducts + 1);

    }

    string totalNumber = totalStr.substr(2, totalStr.length() - 2);
    myMainVec.push_back(bro("TP", totalNumber));
    cutString(totalNumber, numberOfProducts + 1);

    // Printando resposta
    for(int l=1; l<=numberOfProducts; l++) {
      cout << "P" << l << " ";
    }
    cout << "Totals" << endl;



    
  }
  
  return 0;
}
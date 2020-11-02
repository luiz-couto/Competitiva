#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define repWithEqual(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] + 1 << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}


const int NMAX = 1000000;

int patternFind[NMAX];
int countOccur = 0;

void computeLPSArray(char* pat, int M, int* lps) {
  int len = 0; 
  lps[0] = 0;

  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    }
    else {
      if (len != 0) { 
        len = lps[len - 1];
      }
      else {
        lps[i] = 0; 
        i++; 
      }
    }
  } 
}


void KMP(char* pattern, char* txt) {
  int m = strlen(pattern);
  int n = strlen(txt);

  int lps[m];

  computeLPSArray(pattern, m, lps);

  int i = 0;
  int j = 0;

  while (i < n) {
    if (pattern[j] == txt[i]) {
      j++;
      i++;
    }

    if (j == m) {
      patternFind[countOccur] = i - j;
      countOccur++;
      j = lps[j - 1];
    }

    else if (i < n && pattern[j] != txt[i]) { 
      if (j != 0) j = lps[j - 1]; 
      else i = i + 1; 
    }
  }
}



int main() {
  
  int cases;
  cin >> cases;

  rep(nc, 0, cases) {
    string txt;
    int n;

    cin >> txt;
    cin >> n;
    
    rep(nn, 0, n) {
      string pat;
      cin >> pat;

      char* txtAsChar = &txt[0];
      char* patAsChar = &pat[0];

      countOccur = 0;
      KMP(patAsChar, txtAsChar);
      
      if (countOccur == 0) {
        cout << "n" << endl;
        continue;
      }
      cout << "y" << endl;
    }

  }

  return 0;
}
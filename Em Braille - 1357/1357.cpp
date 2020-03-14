#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    char type;
    cin >> type;

    if(type == 'S') {

        vector<pair<char,char> > lineOne;
        vector<pair<char,char> > lineTwo;
        vector<pair<char,char> > lineThree;

        string number;
        cin >> number;

        for (int i=0; i< number.length(); i++){
            char d = number[i];
            pair<char, char> pf;
            pair<char, char> ps;
            pair<char, char> pt;

            if (d == '1') {
                pf.first = '*';
                pf.second = '.';
                lineOne.push_back(pf);

                ps.first = '.';
                ps.second = '.';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);

            }
            if (d == '2') {
                pf.first = '*';
                pf.second = '.';
                lineOne.push_back(pf);

                ps.first = '*';
                ps.second = '.';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);
            }
            if (d == '3') {
                pf.first = '*';
                pf.second = '*';
                lineOne.push_back(pf);

                ps.first = '.';
                ps.second = '.';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);
            }
            if (d == '4') {
                pf.first = '*';
                pf.second = '*';
                lineOne.push_back(pf);

                ps.first = '.';
                ps.second = '*';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);
            }
            if (d == '5') {
                pf.first = '*';
                pf.second = '.';
                lineOne.push_back(pf);

                ps.first = '.';
                ps.second = '*';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);
            }
            if (d == '6') {
                pf.first = '*';
                pf.second = '*';
                lineOne.push_back(pf);

                ps.first = '*';
                ps.second = '.';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);
            }
            if (d == '7') {
                pf.first = '*';
                pf.second = '*';
                lineOne.push_back(pf);

                ps.first = '*';
                ps.second = '*';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);
            }
            if (d == '8') {
                pf.first = '*';
                pf.second = '.';
                lineOne.push_back(pf);

                ps.first = '*';
                ps.second = '*';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);
            }
            if (d == '9') {
                pf.first = '.';
                pf.second = '*';
                lineOne.push_back(pf);

                ps.first = '*';
                ps.second = '.';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);
            }
            if (d == '0') {
                pf.first = '.';
                pf.second = '*';
                lineOne.push_back(pf);

                ps.first = '*';
                ps.second = '*';
                lineTwo.push_back(ps);

                pt.first = '.';
                pt.second = '.';
                lineThree.push_back(pt);
            }

        }

        for(auto par:lineOne) {
            cout << par.first << par.second << " ";
        }
        cout << endl;
        
        for(auto par:lineTwo) {
            cout << par.first << par.second << " ";
        }
        cout << endl;
        
        for(auto par:lineThree) {
            cout << par.first << par.second << " ";
        }
        cout << endl;







    }

}
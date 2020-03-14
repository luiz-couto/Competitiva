#include <bits/stdc++.h>

using namespace std;

int main() {

    while(1) {

    int n;
    cin >> n;

    if (n == 0) {
        break;
    }

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
    if (type == 'B') {
        vector<pair<char,char> > lineOne;
        vector<pair<char,char> > lineTwo;
        vector<pair<char,char> > lineThree;

        string first;

        for (int i=0; i<n; i++) {
            string bla;
            cin >> bla;
            first = first + bla;
        }
        for (int i=0; i<first.length(); i=i+2) {
            pair<char, char> p;
            p.first = first[i];
            p.second = first[i+1];
            lineOne.push_back(p);
        }

        string second;

        for (int i=0; i<n; i++) {
            string bla;
            cin >> bla;
            second = second + bla;
        }
        for (int i=0; i<second.length(); i=i+2) {
            pair<char, char> p;
            p.first = second[i];
            p.second = second[i+1];
            lineTwo.push_back(p);
        }

        string third;
        
        for (int i=0; i<n; i++) {
            string bla;
            cin >> bla;
            third = third + bla;
        }
        for (int i=0; i<third.length(); i=i+2) {
            pair<char, char> p;
            p.first = third[i];
            p.second = third[i+1];
            lineThree.push_back(p);
        }

        for (int i=0; i<lineOne.size(); i++) {
            if (lineOne[i].first == '*' && lineOne[i].second == '.' && lineTwo[i].first == '.' && lineTwo[i].second == '.' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '1';

            if (lineOne[i].first == '*' && lineOne[i].second == '.' && lineTwo[i].first == '*' && lineTwo[i].second == '.' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '2';
            
            if (lineOne[i].first == '*' && lineOne[i].second == '*' && lineTwo[i].first == '.' && lineTwo[i].second == '.' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '3';
            
            if (lineOne[i].first == '*' && lineOne[i].second == '*' && lineTwo[i].first == '.' && lineTwo[i].second == '*' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '4';
            
            if (lineOne[i].first == '*' && lineOne[i].second == '.' && lineTwo[i].first == '.' && lineTwo[i].second == '*' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '5';

            if (lineOne[i].first == '*' && lineOne[i].second == '*' && lineTwo[i].first == '*' && lineTwo[i].second == '.' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '6';
            
            if (lineOne[i].first == '*' && lineOne[i].second == '*' && lineTwo[i].first == '*' && lineTwo[i].second == '*' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '7';

            if (lineOne[i].first == '*' && lineOne[i].second == '.' && lineTwo[i].first == '*' && lineTwo[i].second == '*' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '8';
            
            if (lineOne[i].first == '.' && lineOne[i].second == '*' && lineTwo[i].first == '*' && lineTwo[i].second == '.' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '9';

            if (lineOne[i].first == '.' && lineOne[i].second == '*' && lineTwo[i].first == '*' && lineTwo[i].second == '*' && lineThree[i].first == '.' && lineThree[i].second == '.')
                cout << '0';
        }

        cout << endl;

    }
    }

}
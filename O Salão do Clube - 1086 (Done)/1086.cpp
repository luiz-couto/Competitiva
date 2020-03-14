#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v) {
    for(int i:v) {
        cout << i << ", ";
    }

    cout << endl;
}

int calcula(vector<int> v, int largura, int horizontal, int vertical) {

    vector<int>::iterator realBegin = v.begin();
    int vectorSize = v.size();

    if((vertical*100)%(largura) != 0){
        return -1;
    }
    
    sort(v.rbegin(), v.rend());
    vector<int>::iterator i;
    
    for(i=realBegin; i != v.end(); i++) {
        if((*i) > horizontal) {
            (*i) = -1;
            realBegin++;
            vectorSize--;
        }
    }

    if(vectorSize == 0) {
        return -1;
    }


    i = realBegin;

    int numTabuasUsadas = 0;

    for(int j=0; j<(vertical*100)/(largura); j++) {
        //cout << "FOR: " << vertical << endl;
        //sort(v.rbegin(), v.rend());
        if ((*i) == horizontal) {
            
            (*i) = -1;
            realBegin++;
            vectorSize--;

            numTabuasUsadas++;
            if(vectorSize == 0){
                if(j == ((vertical*100)/(largura)) - 1) {
                    return numTabuasUsadas;
                } else {
                    return -1;
                }
            }

            i = realBegin;
        
        } else {
            
            if((vectorSize == 1)) {
                return -1;
            }

            if((vectorSize == 2)) {
                vector<int>::iterator b = realBegin;
                vector<int>::iterator e = realBegin++;

                if ((*b) + (*e) == horizontal && j == ((vertical*100)/(largura)) - 1) {
                    
                    numTabuasUsadas++;
                    numTabuasUsadas++;
                    return numTabuasUsadas;

                } else {
                    return -1;
                }
            }

            if ((*i) + (*i) < horizontal) {
                return -1;
            }


            vector<int>::iterator begin = realBegin+1;
            vector<int>::iterator end = v.end()-1;

            bool gotIt = false;
            
            while (((end - realBegin) - (begin - realBegin)) + 1 > 2)
            {
                vector<int>::iterator middle = begin + ((((end - realBegin) - (begin - realBegin)) +1) / 2);

                if ((*i) + (*middle) == horizontal) {
                    numTabuasUsadas++;
                    numTabuasUsadas++;
                    
                    (*i) = -1;
                    realBegin++;
                    vectorSize--;

                    v.erase(middle--);
                    vectorSize--;

                    i = realBegin;
                    gotIt = true;
                    break;
                }
                if ((*i) + (*middle) < horizontal) {
                    end = middle;
                    if ((((end - realBegin) - (begin - realBegin)) +1) == 2){
                        break;
                    }
                }
                if ((*i) + (*middle) > horizontal) {
                    begin = middle;
                    if ((((end - realBegin) - (begin - realBegin)) +1) == 2){
                        break;
                    }
                }

            }
           
            if(!gotIt) {
                if ((*i) + (*begin) == horizontal) {
                    numTabuasUsadas++;
                    numTabuasUsadas++;
                    
                    
                    (*i) = -1;
                    realBegin++;
                    vectorSize--;
                    
                    
                    v.erase(begin--);
                    vectorSize--;

                    i = realBegin;
                }
                else if ((*i) + (*end) == horizontal) {
                    numTabuasUsadas++;
                    numTabuasUsadas++;
                    
                    (*i) = -1;
                    realBegin++;
                    vectorSize--;

                    v.erase(end - 2);
                    vectorSize--;

                    i = realBegin;
                } else {
                    
                    (*i) = -1;
                    realBegin++;
                    vectorSize--;
                    
                    j--;
                    i = realBegin;
                    //return -1;
                }
            }




        }
    }

    return numTabuasUsadas;

}

int main() {

while(1) {
    int n,m;
    scanf("%d", &n);
    scanf(" %d%*c", &m);

    if (n==0 && m==0){
        break;
    }

    int largura;
    scanf("%d%*c", &largura);

    int num;
    scanf("%d%*c", &num);

    vector<int> tabuas;

    for(int i=0; i<num; i++) {
        int t;
        scanf(" %d", &t);
        tabuas.push_back(t);
    }

    // cout << n << " " << m << " " << largura << endl;
    // print(tabuas);
    int bla = calcula(tabuas,largura,m,n);
    int ble = calcula(tabuas,largura,n,m);

    if (ble == -1 && bla == -1) {
        cout << "impossivel" << endl;
    } else {
        if(ble == -1) {
            ble=10000;
        }

        if(bla == -1) {
            bla=10000;
        }

        if(ble <= bla) {
            cout << ble << endl;
        } else {
            cout << bla << endl;
        }
    }

}

    return 0;
}
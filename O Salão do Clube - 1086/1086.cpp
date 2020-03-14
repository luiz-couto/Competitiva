#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v) {
    for(int i:v) {
        cout << i << ", ";
    }

    cout << endl;
}

int calcula(vector<int> v, int largura, int horizontal, int vertical) {
    if((vertical*100)%(largura) != 0){
        return -1;
    }
    vector<int>::iterator i;
    for(i=v.begin(); i != v.end(); i++) {
        if((*i) > horizontal) {
           v.erase(i--);
        }
    }
    if(v.size() == 0) {
        return -1;
    }

    sort(v.rbegin(), v.rend());

    i = v.begin();

    int numTabuasUsadas = 0;

    for(int j=0; j<(vertical*100)/(largura); j++) {
        //cout << "FOR: " << vertical << endl;
        //sort(v.rbegin(), v.rend());
        if ((*i) == horizontal) {
            v.erase(i--);
            numTabuasUsadas++;
            if(v.size() == 0){
                if(j == ((vertical*100)/(largura)) - 1) {
                    return numTabuasUsadas;
                } else {
                    return -1;
                }
            }
            i = v.begin();
        } else {
            if((v.size() == 1)) {
                return -1;
            }
            if((*i) + (*i) < horizontal) {
                return -1;
            }
            int encontrei = 0;
            vector<int>::iterator k = v.begin();
            k++;
            for(k; k!=v.end(); k++) {
                vector<int>::iterator s = v.end()-1;
                if ((*i)+(*k) == horizontal) {
                    v.erase(k--);
                    v.erase(i--);
                    numTabuasUsadas++;
                    numTabuasUsadas++;
                    if(v.size() == 0){
                        if(j == ((vertical*100)/(largura)) - 1) {
                            return numTabuasUsadas;
                        } else {
                            return -1;
                        }
                    }
                    i = v.begin();
                    encontrei = 1;
                    break;
                }
                if ((*i)+(*s) == horizontal) {
                    v.erase(s--);
                    v.erase(i--);
                    numTabuasUsadas++;
                    numTabuasUsadas++;
                    if(v.size() == 0){
                        if(j == ((vertical*100)/(largura)) - 1) {
                            return numTabuasUsadas;
                        } else {
                            return -1;
                        }
                    }
                    i = v.begin();
                    encontrei = 1;
                    break;
                }
                s--;
            }
            if (encontrei == 0)  {
                v.erase(i--);
                if(v.size() == 0){
                if(j == ((vertical*100)/(largura)) - 1) {
                    return numTabuasUsadas;
                } else {
                    return -1;
                }
            }
                i = v.begin();
                j--;
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

    if (ble && bla == -1) {
        cout << "impossivel" << endl;
    } else {
        if(ble == -1) {
            ble=100;
        }

        if(bla == -1) {
            bla=100;
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
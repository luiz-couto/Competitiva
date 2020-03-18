#include <bits/stdc++.h>

using namespace std;

vector<int> entrada;
vector<int> saida;

vector<int> turnTheTape(int pos1, int pos2, vector<int> v) {
    // verfifcar se tem um num par de elementos entre eles

    if (pos2 <= pos1) {
        return vector<int>();
    }

    int entreEles = pos2-pos1-1;

    if ((entreEles)%2 != 0) {
        return vector<int>();
    }

    vector<int>::iterator begin = v.begin() + pos1;
    vector<int>::iterator end = v.begin() + pos2;

    vector<int> resultado;

    begin = begin + entreEles/2;
    end = end - entreEles/2;

    // cout << *begin << endl;
    // cout << *end << endl;

    // cout << v.end() - end << endl;
    // cout << begin - v.begin() + 1 << endl;

    int frt = 1;
    while(1) { 

        if (v.end() - end < begin - v.begin() + 1 && resultado.size() != 0 ) {
            resultado.insert(resultado.end()-frt, (*begin) + (*end));
            frt++;
        } else {
            resultado.push_back((*begin) + (*end));
        }
        

        if (begin == v.begin() || end == v.end()-1) {
            begin--;
            end++;
            break;
        }

        begin--;
        end++;
    }

    while (end != v.end()) {
        resultado.push_back(*end);
        end++;
    }

    while(1) {
        if (begin == v.begin()-1) {
            break;
        }
        resultado.insert(resultado.begin(), (*begin));
        begin--;
    }

    return resultado;


}



int main() {

    int n,m;

    cin >> n;

    for (int i=0; i<n; i++) {
        int number;
        cin >> number;
        entrada.push_back(number);
    }

    cin >> m;

    for(int i=0; i<m; i++) {
        int numbers;
        cin >> numbers;
        saida.push_back(numbers);
    }

    for(auto i:entrada) {
        cout << i << " - ";
    }
    cout << endl;

    vector<int> test = turnTheTape(1,6,entrada);

    for(auto i:test) {
        cout << i << " - ";
    }
    cout << endl;

    return 0;
}
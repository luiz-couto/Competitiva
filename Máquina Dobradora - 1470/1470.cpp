#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > entrada;
vector<int> saida;

void sum_up_recursive(vector<pair<int,int> > numbers, int target, vector<pair<int,int> > partial, vector<vector<pair<int, int> > > &all)
{
    int s = 0;
    for(auto x:partial){
        s += x.first;
    } 

    if (s == target){
        all.push_back(partial);
    }

    if (s >= target)
        return;

    for (int i = 0; i < numbers.size(); i++)
    {
        vector<pair<int,int> > remaining = vector<pair<int,int> >();
        pair<int, int> n = numbers[i];
        for (int j = i + 1; j < numbers.size(); j++){
            remaining.push_back(numbers[j]);
        }

        vector<pair<int,int> > partial_rec = vector<pair<int,int> >(partial);
        partial_rec.push_back(n);
        sum_up_recursive(remaining, target, partial_rec, all);
    }
}

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
        pair<int, int> p;
        p.first = number;
        p.second = i;
        entrada.push_back(p);
    }

    cin >> m;

    for(int i=0; i<m; i++) {
        int numbers;
        cin >> numbers;
        saida.push_back(numbers);
    }

    for(auto i:entrada) {
        cout << i.first << " - ";
    }
    cout << endl;
    
    vector<vector<pair<int, int> > > all;

    sum_up_recursive(entrada, 10, vector<pair<int,int> >(), all);

    sort(all.begin(), all.end(), [](const vector<pair<int,int> > & a, const vector<pair<int,int> > & b){ return a.size() < b.size(); });
  
    for(auto y:all) {
        for(auto q:y) {
            cout << q.second << " - ";
        }
        cout << endl;
    }

    //cout << contains_sum(b,e,50,3);
    //vector<int> test = turnTheTape(1,6,entrada);

    // for(auto i:test) {
    //     cout << i << " - ";
    // }
    // cout << endl;

    // for (int i=0; i<saida.size(); i++) {
    //  //soma de 1 num
    // }

    return 0;
}
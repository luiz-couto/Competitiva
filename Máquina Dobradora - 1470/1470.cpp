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

vector<pair<int, int> > turnTheTape(int pos1, int pos2, vector<pair<int, int> > v) {
    // verfifcar se tem um num par de elementos entre eles

    if (pos2 <= pos1) {
        return vector<pair<int, int> >();
    }

    int entreEles = pos2-pos1-1;

    if ((entreEles)%2 != 0) {
        return vector<pair<int, int> >();
    }

    vector<pair<int, int> >::iterator begin = v.begin() + pos1;
    vector<pair<int, int> >::iterator end = v.begin() + pos2;

    vector<pair<int, int> > resultado;

    begin = begin + entreEles/2;
    end = end - entreEles/2;

    int frt = 1;

    while(1) { 

        if (v.end() - end < begin - v.begin() + 1 && resultado.size() != 0 ) {
            pair<int, int> p = make_pair((*begin).first + (*end).first, 0);
            resultado.insert(resultado.end()-frt,p);
            frt++;
        } else {
            pair<int, int> p = make_pair((*begin).first + (*end).first, 0);
            resultado.push_back(p);
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
        pair<int, int> pr = make_pair((*end).first, 0);
        resultado.push_back(pr);
        end++;
    }

    while(1) {
        if (begin == v.begin()-1) {
            break;
        }
        pair<int, int> pr = make_pair((*begin).first, 0);
        resultado.insert(resultado.begin(),pr);
        begin--;
    }

    int posi = 0;
    
    for(int i=0; i<resultado.size(); i++) {
        resultado[i] = make_pair(resultado[i].first, posi);
        posi++;
    }

    return resultado;


}

bool recursiv(int position, vector<pair<int,int> > entrada, vector<int> saida) {
    if (position == saida.size()) {
        return true;
    }

    int sum = saida[position];
    vector<vector<pair<int, int> > > all;
    
    sum_up_recursive(entrada, sum, vector<pair<int,int> >(), all);

    std::sort(all.begin(), all.end(), [](const vector<pair<int,int> > & a, const vector<pair<int,int> > & b){ return a.size() < b.size(); });

    for(auto vp:all) {
        if (vp.size() == 1) {
            if(vp[0].second == position){
                std::cout << vp[0].first << " ----> " << saida.size() << endl;
                if (recursiv(position + 1, entrada, saida)){
                    return true;
                }
            } else if (vp[0].first == 7) {
                cout << "ENTROU Q" << endl;
                reverse(entrada.begin(), entrada.end());
                if (recursiv(position + 1, entrada, saida)){
                    return true;
                }
            }

        }
        bool getIt = false;
        for(int i=0; i<1; i++) {
            vector<pair<int, int> > t = turnTheTape(vp[i].second, vp[i+1].second, entrada);
            for (auto k:t) {
                cout << k.first << " -> ";
            }
            cout << endl;
            if (t.size() != 0) {

                if(vp[i].first + vp[i].second != sum) {
                    if (recursiv(position, t, saida)){
                        return true;
                    }
                } else {
                    if (recursiv(position+1, t, saida)) {
                        return true;
                    }
                }

                
            }
        }
    }

    return false;

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

    cout << recursiv(0,entrada, saida) << endl;

    return 0;
}
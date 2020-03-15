#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;

    cin >> n >> m;

    vector<vector<int> > tabuleiro;

    int corInicial = true;
    int casNum = 1;
    
    for (int i=0; i<n; i++) {

        int corCasa = corInicial;

        for (int j=1; j<=m; j++) {
            if(corCasa == true) {
                vector<int> casa;
                if (m%2 != 0) { //m ímpar
                    int pulo = m/2;
                    int ultimo = (m*n)/2 + 1;
                    int above = casNum + pulo;
                    int below = casNum - pulo;
                    
                    if (j%m == 1) { //borda esquerda

                        if (below > 0) {
                            casa.push_back(0);
                            casa.push_back(below);
                        } else {
                            casa.push_back(0);
                            casa.push_back(0);
                        }
                        
                        
                        if (above < ultimo){
                            casa.push_back(0);
                            casa.push_back(above + 1);
                        } else {
                            casa.push_back(0);
                            casa.push_back(0);
                        }
                        
                    }
                    else if (j%m == 0) { //borda direita

                        if (below > 1) {
                            casa.push_back(below - 1);
                            casa.push_back(0);
                        } else {
                            casa.push_back(0);
                            casa.push_back(0);
                        }
                        
                        if (above < ultimo){
                            casa.push_back(above);
                            casa.push_back(0);
                        } else {
                            casa.push_back(0);
                            casa.push_back(0);
                        }


                    } else { //meio
                        
                        if (below > 0) {
                            casa.push_back(below - 1);
                            casa.push_back(below);
                        } else {
                            casa.push_back(0);
                            casa.push_back(0);
                        }
                        
                        if (above < ultimo) {
                            casa.push_back(above);
                            casa.push_back(above + 1);
                        } else {
                            casa.push_back(0);
                            casa.push_back(0);
                        }
                        
                    }
                }

                if (m%2 == 0) { // m par
                    int ultimo = (m*n)/2;
                    int pulo;
                    if (corInicial) {
                        pulo = m/2;
                    } else {
                        pulo = (m/2) + 1;
                    }
                    int above = casNum + pulo;
                    int below = casNum - pulo;

                    if (j%m == 1) { // borda esquerda
                        
                        if (below > 0) {
                           casa.push_back(0);
                           casa.push_back(below);
                        } else {
                            casa.push_back(0);
                            casa.push_back(0);
                        }
                        
                        if (above < ultimo) {
                            casa.push_back(0);
                            casa.push_back(above);
                        } else {
                            casa.push_back(0);
                            casa.push_back(0);
                        }
                       
                    }
                    else if (j%m == 0) { // borda direita

                        
                        if (below > 0) {
                            casa.push_back(below + 1);
                            casa.push_back(0);
                        } else {
                            casa.push_back(0);
                            casa.push_back(0);
                        }
                        
                        
                        if(corInicial) {
                            if (above <= ultimo) {
                                casa.push_back(above - 1);
                                casa.push_back(0);
                            } else {
                                casa.push_back(0);
                                casa.push_back(0);
                            }
                        } else {
                            if (above <= ultimo + 1) {
                                casa.push_back(above -1);
                                casa.push_back(0);
                            } else {
                                casa.push_back(0);
                                casa.push_back(0);
                            }
                        }

                    } else { // meio
                        
                        if (corInicial) {
                            if (below > 0) {
                                casa.push_back(below - 1);
                                casa.push_back(below);
                            } else {
                                casa.push_back(0);
                                casa.push_back(0);
                            }
                        } else {
                            if (below >= 0) {
                                casa.push_back(below + 1);
                                casa.push_back(below + 2);
                            } else {
                                casa.push_back(0);
                                casa.push_back(0);
                            }
                        }
                        
                        if(corInicial) {
                            if (above <= ultimo) {
                                casa.push_back(above - 1);
                                casa.push_back(above);
                            } else {
                                casa.push_back(0);
                                casa.push_back(0);
                            }
                        } else {
                            if (above <= ultimo) {
                                casa.push_back(above - 1);
                                casa.push_back(above);
                            } else {
                                casa.push_back(0);
                                casa.push_back(0);
                            }
                        }
                        
                        
                    }
                    

                } 

                tabuleiro.push_back(casa);
                casNum++;
            }
            corCasa = !corCasa;
        }

        corInicial = !corInicial;

    }

    for(int i=0; i<tabuleiro.size(); i++) {
        cout << i+1 << ": ";
        for (auto j:tabuleiro[i]) {
            cout << j << " - ";
        }
        cout << endl;
    }






    return 0;
}
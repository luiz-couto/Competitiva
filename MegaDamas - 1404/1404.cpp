#include <bits/stdc++.h>

using namespace std;


int greateer = 0;
int numberIterations = 0;

void recursiv(int casa, vector<int> ve, int pecasComidas, vector<vector<int> > tabuleiro, int quemChamou) {

    //cout << "casa: "<< casa << endl;

    for (int i=0; i<tabuleiro[casa-1].size(); i++) {
        numberIterations++;
        if (numberIterations > 100000) {
            break;
        }
        if (ve[tabuleiro[casa-1][i]] == 2 && tabuleiro[casa-1][i] != -5) {
            //cout << "olhando para:" << tabuleiro[casa-1][i] << endl;
            if(ve[tabuleiro[tabuleiro[casa-1][i] - 1][i]] == 0) {
                if (tabuleiro[tabuleiro[casa-1][i] - 1][i] != -5 && tabuleiro[tabuleiro[casa-1][i] - 1][i] != quemChamou) {
                    //vector<int> novo = ve;
                    ve[tabuleiro[casa-1][i]] = 0;
                    int g = pecasComidas + 1;
                    recursiv(tabuleiro[tabuleiro[casa-1][i] - 1][i], ve, g, tabuleiro, casa);
                    ve[tabuleiro[casa-1][i]] = 2;
                    //cout << "Voltei da:" << casa << endl;
                }
            }
        }
    }

    if (pecasComidas > greateer) {
        greateer = pecasComidas;
    }

    //cout << casa << ": " << pecasComidas << endl;

}



int main() {

    int n,m;

    while (1) {

    vector<vector<int> > tabuleiro;
    vector<int> v;
    greateer = 0;
    numberIterations = 0;

    cin >> n;
    cin >> m;

    if (n == 0) {
        break;
    }

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
                            casa.push_back(-5);
                            casa.push_back(below);
                        } else {
                            casa.push_back(-5);
                            casa.push_back(-5);
                        }
                        
                        
                        if (above < ultimo){
                            casa.push_back(-5);
                            casa.push_back(above + 1);
                        } else {
                            casa.push_back(-5);
                            casa.push_back(-5);
                        }
                        
                    }
                    else if (j%m == 0) { //borda direita

                        if (below > 1) {
                            casa.push_back(below - 1);
                            casa.push_back(-5);
                        } else {
                            casa.push_back(-5);
                            casa.push_back(-5);
                        }
                        
                        if (above < ultimo){
                            casa.push_back(above);
                            casa.push_back(-5);
                        } else {
                            casa.push_back(-5);
                            casa.push_back(-5);
                        }


                    } else { //meio
                        
                        if (below > 0) {
                            casa.push_back(below - 1);
                            casa.push_back(below);
                        } else {
                            casa.push_back(-5);
                            casa.push_back(-5);
                        }
                        
                        if (above < ultimo) {
                            casa.push_back(above);
                            casa.push_back(above + 1);
                        } else {
                            casa.push_back(-5);
                            casa.push_back(-5);
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
                           casa.push_back(-5);
                           casa.push_back(below);
                        } else {
                            casa.push_back(-5);
                            casa.push_back(-5);
                        }
                        
                        if (above < ultimo) {
                            casa.push_back(-5);
                            casa.push_back(above);
                        } else {
                            casa.push_back(-5);
                            casa.push_back(-5);
                        }
                       
                    }
                    else if (j%m == 0) { // borda direita

                        
                        if (below > 0) {
                            casa.push_back(below + 1);
                            casa.push_back(-5);
                        } else {
                            casa.push_back(-5);
                            casa.push_back(-5);
                        }
                        
                        
                        if(corInicial) {
                            if (above <= ultimo) {
                                casa.push_back(above - 1);
                                casa.push_back(-5);
                            } else {
                                casa.push_back(-5);
                                casa.push_back(-5);
                            }
                        } else {
                            if (above <= ultimo + 1) {
                                casa.push_back(above -1);
                                casa.push_back(-5);
                            } else {
                                casa.push_back(-5);
                                casa.push_back(-5);
                            }
                        }

                    } else { // meio
                        
                        if (corInicial) {
                            if (below > 0) {
                                casa.push_back(below - 1);
                                casa.push_back(below);
                            } else {
                                casa.push_back(-5);
                                casa.push_back(-5);
                            }
                        } else {
                            if (below >= 0) {
                                casa.push_back(below + 1);
                                casa.push_back(below + 2);
                            } else {
                                casa.push_back(-5);
                                casa.push_back(-5);
                            }
                        }
                        
                        if(corInicial) {
                            if (above <= ultimo) {
                                casa.push_back(above - 1);
                                casa.push_back(above);
                            } else {
                                casa.push_back(-5);
                                casa.push_back(-5);
                            }
                        } else {
                            if (above <= ultimo) {
                                casa.push_back(above - 1);
                                casa.push_back(above);
                            } else {
                                casa.push_back(-5);
                                casa.push_back(-5);
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
    
    v.push_back(-1);

    for (int i=0; i<tabuleiro.size(); i++) {
        int pec;
        cin >> pec;
        v.push_back(pec);
    }

    for (int i=1; i<=v.size(); i++) {
        if (v[i] == 1) {
            v[i] = 0;
            recursiv(i,v,0,tabuleiro, -5);
            v[i] = 1;
        }
    }

    //cout << "Iterations:" << numberIterations << endl;
    cout << greateer << endl;
    
    }
    return 0;
}
#pragma once

#include <vector>
#include <string>
#include <map>

using namespace std;

class AFN {
public:
    int quantidade_estados;
    int quantidade_simbolos_terminais;
    vector<char> simbolos_terminais;
    int quantidade_estados_iniciais;
    int quantidade_estados_aceitacao;
    vector<int> estados_aceitacao;
    int quantidade_transicoes;
    vector<vector<pair<char, int>>> transicoes;

    void ler_do_stdin();
    bool aceita_cadeia(string cadeia);

private:
    bool aceita_cadeia(string cadeia, int estado_atual, map<pair<int, string>, bool> percorrido);
};
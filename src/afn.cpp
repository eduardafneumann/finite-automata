#include "afn.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

void AFN::ler_do_stdin()
{
    cin >> quantidade_estados >> quantidade_simbolos_terminais;
    for (int i = 0; i < quantidade_simbolos_terminais; i++)
    {
        char simbolo;
        cin >> simbolo;
        simbolos_terminais.push_back(simbolo);
    }

    cin >> quantidade_estados_iniciais >> quantidade_estados_aceitacao;
    for (int i = 0; i < quantidade_estados_aceitacao; i++)
    {
        int estado;
        cin >> estado;
        estados_aceitacao.push_back(estado);
    }

    cin >> quantidade_transicoes;
    transicoes.assign(quantidade_transicoes, vector<pair<char, int>>());
    for (int i = 0; i < quantidade_transicoes; i++)
    {
        char simbolo;
        int origem, destino;
        cin >> origem >> simbolo >> destino;
        transicoes[origem].push_back(pair<char, int>(simbolo, destino));
    }
}

bool AFN::aceita_cadeia(string cadeia, int estado_atual, map<pair<int, string>, bool> percorrido)
{
    // cout << "estado " << estado_atual << " com cadeia " << cadeia << endl;
    if (percorrido.count(pair<int, string>(estado_atual, cadeia)) > 0 &&
        percorrido[pair<int, string>(estado_atual, cadeia)] == true)
    {
        return false;
    }

    if (cadeia.size() == 0 &&
        count(this->estados_aceitacao.begin(), this->estados_aceitacao.end(), estado_atual) > 0)
    { // Processou toda a cadeia e está em estado de aceitação
        return true;
    }

    // Marca que já passou por esse estado com essa cadeia, para evitar ciclos
    percorrido[pair<int, string>(estado_atual, cadeia)] = true;

    // Dispara a recursão para todas as transições possíveis
    bool aceita = false;
    for (auto transicao : this->transicoes[estado_atual])
    {
        // Se o símbolo da transição é o próximo da cadeia, tira o próximo símbolo da cadeia
        if (transicao.first == cadeia[0])
        {
            aceita |= aceita_cadeia(cadeia.substr(1, cadeia.size() - 1), transicao.second, percorrido);
        }
        // Se o símbolo da transição é lambda, não altera a cadeia
        else if (transicao.first == '-')
        {
            aceita |= aceita_cadeia(cadeia, transicao.second, percorrido);
        }
    }

    return aceita;
}

bool AFN::aceita_cadeia(string cadeia)
{
    map<pair<int, string>, bool> percorrido;

    // Verifica se é possível começando de qualquer um dos estados iniciais
    bool aceita = false;
    for (int estado_inicial = 0; estado_inicial < this->quantidade_estados_iniciais; estado_inicial++)
    {
        aceita |= this->aceita_cadeia(cadeia, estado_inicial, percorrido);
    }
    return aceita;
}
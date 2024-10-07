#include <iostream>
#include <vector>
#include <string>
#include "afn.hpp"

using namespace std;

int main()
{
    AFN automata;
    automata.ler_do_stdin();

    int quantidade_cadeias;
    cin >> quantidade_cadeias;
    for (int i = 0; i < quantidade_cadeias; i++)
    {
        string cadeia_atual;
        cin >> cadeia_atual;
        if (automata.aceita_cadeia(cadeia_atual))
        {
            cout << "aceita" << endl;
        }
        else
        {
            cout << "rejeita" << endl;
        }
    }

    return 0;
}
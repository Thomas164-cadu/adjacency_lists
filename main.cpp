/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome: Carlos Eduardo Thomas e André Luis Sanson Bonfante
 * Matricula: 2021101006 e 2021101018
 */

#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>

using namespace std;

void print_exception(const exception &e, int level = 0) {
    cerr << "exception: " << string(level, ' ') << e.what() << "\n";
    try {
        rethrow_if_nested(e);
    } catch(const std::exception& nested_exception) {
        print_exception(nested_exception, (level + 2));
    }
}

int main() {
    try {

        int v, o;
        cin >> v >> o;

        Grafo g(v);

        while (o) {
            char c;
            cin >> c;

            if (c == 'I') {
                int x, y;
                cin >> x >> y;
                Aresta a(x, y);
                g.insere_aresta(a);
            } else if (c == 'R') {
                int x, y;
                cin >> x >> y;
                Aresta a(x, y);
                g.remove_aresta(a);
            } else if (c == 'E') {
                cout << g.num_arestas() << "\n";
            } else if (c == 'Q') {
                int n;
                cin >> n;
                vector<int> nums = vector<int>();
                for (int i = 0; i < n; i++) {
                    int x;
                    cin >> x;
                    nums.push_back(x);
                }
                if (g.eh_clique(nums)) {
                    cout << "SIM\n";
                } else {
                    cout << "NAO\n";
                }
            } else if (c == 'C') {
                int x, y, w, z;
                cin >> x >> y >> w >> z;
                Aresta a(w, z);
                if (g.existe_caminho_restrito(x, y, a, vector<int>(v))) {
                    cout << "SIM\n";
                } else {
                    cout << "NAO\n";
                }
            } else if (c == 'G') {
                g.imprime_graus();
            }

            o--;
        }
    } catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}

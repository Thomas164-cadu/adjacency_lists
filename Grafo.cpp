/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome: Carlos Eduardo Thomas e André Luis Sanson Bonfante
 * Matricula: 2021101006 e 2021101018
 */

#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    lista_adj_.resize(num_vertices_);
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        const string error = "Nao foi possivel inserir a aresta:" + e.to_string();
        throw_with_nested(runtime_error(error));
    }

    if (e.v1 == e.v2) {
        return;
    }

    bool jaPossuiVertice = false;
    for (int v : lista_adj_[e.v1]) {
        if (v == e.v2) {
            jaPossuiVertice = true;
            break;
        }
    }
    
    if (!jaPossuiVertice) {
        lista_adj_[e.v1].push_back(e.v2);
        num_arestas_++;
    }

    jaPossuiVertice = false;
    for (int v : lista_adj_[e.v2]) {
        if (v == e.v1) {
            jaPossuiVertice = true;
            break;
        }
    }

    if (!jaPossuiVertice) {
        lista_adj_[e.v2].push_back(e.v1);
    }
}

void Grafo::remove_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        const string error = "Nao foi possivel inserir a aresta:" + e.to_string();
        throw_with_nested(runtime_error(error));
    }

    if (e.v1 == e.v2) {
        return;
    }

    for (int v : lista_adj_[e.v1]) {
        if (v == e.v2) {
            lista_adj_[e.v1].remove(e.v2);
            lista_adj_[e.v2].remove(e.v1);
            num_arestas_--;
            break;
        }
    }
}

void Grafo::valida_vertice(int v) {
    if (v < 0 || v >= num_vertices_) {
        throw out_of_range("Indice do vertice eh invalido: " + to_string(v));
    }
}

void Grafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}

bool Grafo::eh_clique(vector<int> vertices) { 
    for (int i = 0; i < (int) vertices.size(); i++) {
        for (int j = 0; j < (int) vertices.size(); j++) {
            if (vertices[j] == vertices[i]) {
                continue;
            }

            bool possuiAresta = false;
            for (int v : lista_adj_[vertices[i]]) {
                if (v == vertices[j]) {
                    possuiAresta = true;
                    break;
                }
            }

            if (!possuiAresta) {
                return false;
            }
        }
    }

    return true;
}

bool Grafo::existe_caminho_restrito(int v, int w, Aresta e, vector<int> marcado) {
    if (v == w) {
        return true;
    }
    marcado[v] = 1;
    for (int u = 0; u < num_vertices_; u++) {
        if (sao_vizinhos(v, u) && marcado[u] == 0) {
            bool ehArestaRestrita = (v == e.v1 && u == e.v2) || (v == e.v2 && u == e.v1);
            if (ehArestaRestrita) {
                continue;
            }

            if (existe_caminho_restrito(u, w, e, marcado)) {
                return true;
            }
        }
    }
    return false;
}

bool Grafo::sao_vizinhos(int v1, int v2) {
    for (int v : lista_adj_[v1]) {
        if (v == v2) {
            return true;
        }
    }
    return false;
}

void Grafo::imprime_graus() {
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ": " << lista_adj_[i].size() << "\n";
    }
}

void Grafo::imprime() {
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ": ";
        for (int v : lista_adj_[i]) {
            cout << v << " -> ";
        }
        cout << "\n";
    }
}

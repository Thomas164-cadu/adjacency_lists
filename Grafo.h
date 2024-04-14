/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome: Carlos Eduardo Thomas e André Luis Sanson Bonfante
 * Matricula: 2021101006 e 2021101018
 */

#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>

class Grafo {

public:
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    bool eh_clique(std::vector<int> vertices);
    bool existe_caminho_restrito(int v1, int v2, Aresta e, std::vector<int> marcado);
    void imprime_graus();
    void imprime();

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>> lista_adj_;

    void valida_vertice(int v);
    void valida_aresta(Aresta e);
    bool sao_vizinhos(int v1, int v2);
};

#endif
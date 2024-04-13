/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome: Carlos Eduardo Thomas e André Luis Bonfante
 * Matricula: 2021101006 e ....
 */

#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"

class Grafo {
public:
    Grafo(int num_vertices);
    // ~Grafo(); // Se necessario
    int num_arestas();
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    // Metodo eh_clique
    // Metodo existe_caminho_restrito
    void imprime_graus();
private:
    int num_vertices_;
    int num_arestas_;
    // Representacao do grafo como listas de adjacencia
};

#endif /* GRAFO_H */

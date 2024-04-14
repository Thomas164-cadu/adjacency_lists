/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome: Carlos Eduardo Thomas e André Luis Sanson Bonfante
 * Matricula: 2021101006 e 2021101018
 */
#include "Aresta.h"
#include <string>

Aresta::Aresta(int v1, int v2) : v1(v1), v2(v2) {
}

std::string Aresta::to_string() {
    return std::to_string(v1) + " " + std::to_string(v2);
}

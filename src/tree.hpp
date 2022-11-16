#ifndef TREE_H
#define TREE_H

#include "recorrencia.hpp"
#include <stdbool.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record
{
    string key;
    float value;
    string codigo;
};

struct Tree
{
    Record reg;
    Tree *esq, *dir,*pai;
};

void ordena(vector<Tree*>&floresta);
void juntaArvore(vector<Tree*>&floresta);

#endif
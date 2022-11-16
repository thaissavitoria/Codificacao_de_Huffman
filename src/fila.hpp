#ifndef FILA_HPP
#define FILA_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "tree.hpp"

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
	Tree *p;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};


void FFVazia(Fila *f);
bool isVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void widthPath(Tree *t);
void fazCod(Tree** t); //gera os códigos
string procuraCod(Tree** t,string palavra); ///procura código
void preencheCod(vector<string>&codigosf,Tree**t,vector<string>&arq); //preenche o vector códigos de acordo com a sequencia de palavras do arquivo

#endif
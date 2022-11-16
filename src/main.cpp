#include "tree.hpp"
#include "fila.hpp"

int main()
{
  vector<Tree*>floresta;
  Tree *aux;

  vector<string>arq;
  vector<string>codigosf;
  
  map<string,float>Hash;

  Token t;
  t.readFile(); 
  t.preencheStpW();
  t.removeStpW(arq);
  t.mapWords(Hash);


  /// Inserindo arvores na floresta
  for (auto item: Hash ){
    aux= new Tree;
    aux->reg.key=item.first;
    aux->reg.value=item.second;
    aux->dir=NULL;
    aux->esq=NULL;
    floresta.push_back(aux);
  }

  juntaArvore(floresta); ////transforma todas as arvores em uma so

  fazCod(&floresta[0]); /// codifica as folhas

  preencheCod(codigosf,&floresta[0],arq); ///preenche os codigos na ordem do arquivo

  /////................Escrevendo no arquivo..................
  FILE *arq_bin;

  arq_bin=fopen("arq_bina.bin","wb");

  fwrite(&codigosf,sizeof(string),codigosf.size(),arq_bin);

  return 0;
}
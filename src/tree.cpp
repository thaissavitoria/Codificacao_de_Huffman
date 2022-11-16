#include "tree.hpp"

void ordena(vector<Tree *> &floresta)
{
    Tree *aux;
    for (int i = 0; i < floresta.size(); i++)
    {
        for(int j=i;j<floresta.size();j++)
        {
            if(floresta[j]->reg.value>floresta[i]->reg.value)
            {
                aux=floresta[j];
                floresta[j]=floresta[i];
                floresta[i]=aux;
            }
        }
    }
}

void juntaArvore(vector<Tree *> &floresta)
{
    Tree *aux_esq,*aux_dir,*paizao;

    while(floresta.size()!=1)
    {
        aux_esq=floresta[floresta.size()-1];
        aux_dir=floresta[floresta.size()-2];

        floresta.pop_back();
        floresta.pop_back();

        paizao=new Tree;
        paizao->esq=aux_esq;
        paizao->dir=aux_dir;
        paizao->reg.value=aux_dir->reg.value+aux_esq->reg.value;
        aux_dir->pai=paizao;
        aux_esq->pai=paizao;
        floresta.push_back(paizao);
        ordena(floresta);      
    }
    floresta[0]->pai=NULL;
}

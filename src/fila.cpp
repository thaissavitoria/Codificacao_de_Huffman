#include "fila.hpp"

void FFVazia(Fila *f)
{
    f->first = (Block *)malloc(sizeof(Block));
    f->last = f->first;
    f->first->prox = NULL;
}

bool isVazia(Fila *f)
{
    return f->first == f->last;
}

void Enfileira(Fila *f, Item d)
{
    f->last->prox = (Block *)malloc(sizeof(Block));
    f->last = f->last->prox;
    f->last->data = d;
    f->last->prox = NULL;
}

void Desenfileira(Fila *f, Item *d)
{
    Block *aux;

    if (f->first == f->last)
    {
        printf("FILA VAZIA!\n");
        return;
    }

    aux = f->first->prox;
    f->first->prox = aux->prox;

    if (f->first->prox == NULL)
        f->last = f->first;

    *d = aux->data;
    free(aux);
}

void widthPath(Tree *t)
{
    Fila q;
    Item no, filho;

    FFVazia(&q);
    no.p = t;
    Enfileira(&q, no);

    while (!isVazia(&q))
    {

        Desenfileira(&q, &no);
        cout << no.p->reg.codigo << endl;

        if (no.p->esq != NULL)
        {
            filho.p = no.p->esq;
            Enfileira(&q, filho);
            // printf(" Entrei esquerda! ");
        }

        if (no.p->dir != NULL)
        {
            filho.p = no.p->dir;
            Enfileira(&q, filho);
            // printf(" Entrei direita! ");
        }
    }
}

void fazCod(Tree **t)
{
    Fila q;
    Item no, filho;
    string cod;

    FFVazia(&q);
    no.p = *t;
    Enfileira(&q, no);

    while (!isVazia(&q))
    {

        Desenfileira(&q, &no);

        if (no.p->esq != NULL)
        {
            no.p->esq->reg.codigo = no.p->esq->pai->reg.codigo + "0";
            filho.p = no.p->esq;
            Enfileira(&q, filho);
            // printf(" Entrei esquerda! ");
        }

        if (no.p->dir != NULL)
        {
            no.p->dir->reg.codigo = no.p->dir->pai->reg.codigo + "1";
            filho.p = no.p->dir;
            Enfileira(&q, filho);
            // printf(" Entrei direita! ");
        }
    }
}

string procuraCod(Tree** t,string palavra)
{
        Fila q;
    Item no, filho;
    string cod;

    FFVazia(&q);
    no.p = *t;
    Enfileira(&q, no);

    while (!isVazia(&q))
    {

        Desenfileira(&q, &no);
        if(no.p->reg.key==palavra)
        {
            return no.p->reg.codigo;
        }

        if (no.p->esq != NULL)
        {
            filho.p = no.p->esq;
            Enfileira(&q, filho);
            // printf(" Entrei esquerda! ");
        }

        if (no.p->dir != NULL)
        {
            filho.p = no.p->dir;
            Enfileira(&q, filho);
            // printf(" Entrei direita! ");
        }
    }
    return "a";
}

void preencheCod(vector<string>&codigosf,Tree**t,vector<string>&arq)
{
    for(auto i:arq)
    {
        codigosf.push_back(procuraCod(t,i));
    }
}

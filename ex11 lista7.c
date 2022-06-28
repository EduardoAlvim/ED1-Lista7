#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int topo;
    int dados[5];
};

void copiar(struct stack pilha, struct stack *copia){
    struct stack aux;
    for(int i=0;i<5;i++){
        empilha(desempilha(&pilha),&aux);
    }
    for(int i=0;i<5;i++){
        empilha(desempilha(&aux),&*copia);
    }
    for(int i=0;i<5;i++){
        printf("\n %d",copia->dados[i]);
    }
}

void empilha (int x, struct stack *pilha)
{
    if (pilha->topo == 9)
    {
        /* pilha cheia*/printf("%s", "stack overflow");
    }
    else
    {
        pilha->topo = pilha->topo +1;
        pilha->dados[pilha->topo]=x;
    }
}
int desempilha(struct stack *pilha)
{
    int x;
    if (pilha->topo == -1)
    {
        /* pilha vazia*/printf("%s", "stack underflow");
        return(-1);
    }
    else
    {
        x= pilha->dados[pilha->topo];
        pilha->topo = pilha->topo - 1;
        return x;
    }
}

void main()
{
    struct stack pilha;
    pilha.topo=-1;
    struct stack copia;
    copia.topo=-1;
    int valor;
    for(int i=0;i<5;i++){
        printf("\nDigite um valor: ");
        scanf("%d",&valor);
        empilha(valor,&pilha);
    }
    copiar(pilha,&copia);
    for(int i=0;i<5;i++){
        printf("\n%d",copia.dados[i]);
    }
}


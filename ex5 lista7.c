#include <stdio.h>
#include <stdlib.h>

/*Dado  uma  pilha  que  armazene números,  escreva  uma  função para  ordenar  os valores desta pilha em ordem crescente. */

struct stack
{
    int topo;
    char dados[10];
};

int ordena(struct stack *pilha, struct stack *ordenada)
{
    struct stack aux;
    aux.topo=-1;
    empilha(desempilha(&*pilha),&aux);
    int x;
    x=desempilha(&*pilha);
    while(pilha->topo != -1)
    {
        if(x<aux->dados[aux->topo])
        {
            empilha(x,&aux);
            x=desempilha(&*pilha);
        }
        else
        {
            empilha(x,&*ordenada);
        }
    }
    if(ordenada->topo==9)
    {
        return 0;
    }
    else
    {
        while(pilha->topo != 9)
        {
            int x;
            x=desempilha(&aux);
            if(x<ordenada->dados[ordenada->topo])
            {
                empilha(desempilha(&*ordenada),&*pilha);
                empilha(x,&*ordenada);
            }
            else
            {
                empilha(x,&*ordenada);
            }
            while(pilha->topo != -1)
            {
                int x;
                x=desempilha(&*pilha);
                if(x<ordenada->dados[ordenada->topo])
                {
                    empilha(desempilha(&*ordenada),&aux);
                    empilha(x,&*ordenada);
                }
                else
                {
                    empilha(x,&*ordenada);
                }
            }
        }
        return 0;
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
    struct stack ordenada;
    pilha.topo=-1;
    ordenada.topo=-1;
    int valor;
    for(int i=0; i<10; i++)
    {
        printf("\nDigite um numero: ");
        scanf("%d",&valor);
        empilha(valor,&pilha);
    }
    ordena(&pilha,&ordenada);
    for(int i=0; i<10; i++)
    {
        printf("\n%d",ordenada.dados[i]);
    }
}

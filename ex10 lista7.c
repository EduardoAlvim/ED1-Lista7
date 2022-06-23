#include <stdio.h>
#include <stdlib.h>

/*- Escreva um algoritmo que leia no m�ximo 100 valores inteiros. O valor 0 (zero)
finaliza a entrada de dados. Para cada valor lido, determinar se ele � um n�mero par
ou impar. Se o n�mero for par, ent�o inclu�-lo na FILA PAR; caso contr�rio, inclu�-lo
na FILA �MPAR. Ap�s o t�rmino da entrada de dados, retirar um elemento de cada
fila alternadamente (iniciando-se pela FILA �MPAR) at� que ambas as filas ficarem
vazias. Se o elemento retirado de uma das filas for um valor positivo, ent�o inclu�-lo em uma PILHA;
caso contr�rio, remover um elemento da PILHA. Finalmente,
escrever o conte�do da pilha.*/

typedef struct
{
    int item[100];
    int inicio,fim;
} Fila;

struct stack
{
    int topo;
    int dados[200];
};

void empilha (int x, struct stack *pilha)
{
    if (pilha->topo == 199)
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

void Inicia(Fila *F)
{
    F->inicio=F->fim=0;
}

int Insere(Fila *F,int X)
{
    if(F->fim==100)
        return 0;
    else
    {
        F->item[F->fim]=X;
        F->fim=F->fim+1;
        return 1;
    }
}

int Remove(Fila *F,int *X)
{
    if(F->inicio==F->fim)
        return 0;
    else
    {
        *X=F->item[F->inicio];
        F->inicio=F->inicio+1;
        return 1;
    }
}

void main()
{
    Fila fimpar;
    Fila fpar;
    Inicia(&fimpar);
    Inicia(&fpar);
    struct stack pilha;
    pilha.topo=-1;
    int valor, cont=0,conti=0,contp=0;
    while(valor!=0 && cont<=100)
    {
        printf("\nDigite um numero diferente de 0, zero para de ler: ");
        scanf("%d",&valor);
        if(valor %2 == 0){
            Insere(&fpar,valor);
            contp++;
        }
        else{
            Insere(&fimpar,valor);
            conti++;
        }
        cont++;
    }

    for(int i=0;i<conti+contp;i++){
        if(i % 2 == 0){
            Remove(&fimpar,&valor);
            if(valor>0){
                empilha(valor,&pilha);
            }
            else{
                desempilha(&pilha);
            }
        }
        else{
            Remove(&fpar,&valor);
            if(valor>0){
                empilha(valor,&pilha);
            }
            else{
                desempilha(&pilha);
            }
        }
    }
}

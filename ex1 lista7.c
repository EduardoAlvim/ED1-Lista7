#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Escreva um algoritmo que solicite ao usuário uma sequência de caracteres e
realize as seguintes operações, utilizando as estruturas de dados pilha e fila:
a) Imprimir o texto na ordem inversa;
b) Verificar se o texto é um palíndromo, ou seja, se a string é escrita da mesma
maneira de frente para trás e de trás para frente. Ignore espaços e pontos.*/


typedef struct
{
    char item[100];
    int inicio,fim;
} Fila;

struct stack
{
    int topo;
    char dados[100];
};

//-----------------Fila----------------------------

void Inicia(Fila *F)
{
    F->inicio=F->fim=0;
}

int Insere(Fila *F,char X)
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

int Remove(Fila *F,char *X)
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

//-----------------Pilha-----------------------------

void empilha (char x, struct stack *pilha)
{
    if (pilha->topo == 99)
    {
        /* pilha cheia*/printf("%s", "stack overflow");
    }
    else
    {
        pilha->topo = pilha->topo +1;
        pilha->dados[pilha->topo]=x;
    }
}
char desempilha(struct stack *pilha)
{
    char x;
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
    Fila fila;
    Inicia(&fila);
    struct stack pilha;
    pilha.topo=-1;
    char palavra[100],invertida[100];
    int tam, i;
    printf("\nDigite a frase: ");
    gets(palavra);
    fflush(stdin);
    tam=strlen(palavra);
    for(i=0; i<tam; i++)
    {
        empilha(palavra[i],&pilha);
        Insere(&fila,palavra[i]);
    }
    for(i=0;i<tam;i++){
        invertida[i]=desempilha(&pilha);
    }
    invertida[i]='\0';
    for(i=0; i<tam; i++)
    {
        empilha(palavra[i],&pilha);
    }

    printf("\nFrase normal: %s\nFrase invertida: %s",palavra,invertida);
    int cont=0;
    for(i=0; i<tam; i++)
    {
        char in, f;
        Remove(&fila,&in);
        f=desempilha(&pilha);
        if(in != f)
        {
            cont++;
        }
    }
    if(cont > 0){
        printf("\nA palavra nao e um palindromo");
    }
    else{
        printf("\nA palavra e um palindromo");
    }
}

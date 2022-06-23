#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Escreva um algoritmo que solicite ao usuário uma sequência de caracteres e
realize as seguintes operações, utilizando as estruturas de dados pilha e fila:
a) Imprimir o texto na ordem inversa;
b) Verificar se o texto é um palíndromo, ou seja, se a string é escrita da mesma
maneira de frente para trás e de trás para frente. Ignore espaços e pontos.*/

struct stack
{
    int topo;
    int dados[100];
};

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
    struct stack pilha;
    pilha.topo=-1;
    char palavra[100],invertida[100];
    printf("\nDigite a frase: ");
    gets(palavra);
    fflush(stdin);
    for(int i=0; i<strlen(palavra); i++)
    {
        empilha(palavra[i],&pilha);
    }
    for(int i=0; i<strlen(palavra); i++)
    {
        invertida[i]=desempilha(&pilha);
    }
    printf("\nFrase normal: %s\nFrase invertida: %s",palavra,invertida);

    if(strcmp(palavra,invertida)==0)
    {
        printf("\nA frase e um palindromo");
    }
    else
    {
        printf("\nA frase nao e um palindromo");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Escreva um algoritmo que use uma pilha para inverter a ordem das letras de
cada palavra de uma string, preservando a ordem das palavras. Por exemplo, para a
string ESTE EXERCICIO E MUITO FACIL o resultado deve ser ETSE
OICICREXE E OTIUM LICAF
*/

struct stack
{
    int topo;
    char dados[100];
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
    char palavra[100],str2[100];
    int cont=0;
    printf("\nDigite a frase: ");
    gets(palavra);
    fflush(stdin);
    for(int i=0; i<strlen(palavra); i++)
    {
        if(palavra[i] !=' ' && palavra[i] != '\0')
        {
            empilha(palavra[i],&pilha);
            cont++;
        }
        else
        {
            if(palavra[i]==' ')
            {
                empilha(palavra[i],&pilha);
                cont++;
            }
            for(int j=strlen(str2); j<cont; j++)
            {
                str2[j]=desempilha(&pilha);
            }
        }
    }
    printf("\nFrase normal: %s\nFrase invertida: %s",palavra,str2);
}

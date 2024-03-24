#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 21
#define TOT_I 15

typedef struct{
    char nome[LEN];
    float qu;
}Ingrediente;

int main(int argc, char* argv[])
{
    char ricetta[LEN], ingrediente[LEN], richiesta[LEN];
    Ingrediente ingr[TOT_I];
    int trovato=0, i=0, ingrtot=0, possibile=1;
    float q;
    FILE *fin;
    FILE *frigo;

    if(argc!=3)
        return -1;

    fin=fopen(argv[1], "r");
    frigo=fopen(argv[2], "r");
    if(fin==NULL||frigo==NULL)
        return -2;

    printf("quale ricetta vuoi? ");
    scanf("%s", richiesta);

    while(fscanf(fin, "%s%s%f", ricetta, ingrediente, &q)==3)
    {
        if(strcmp(ricetta, richiesta)==0)
        {
            strcpy(ingr[i].nome, ingrediente);
            ingr[i].qu=q;
            trovato=1;
            i++;
        }
    }
    ingrtot=i;
    fclose(fin);

    if(!trovato)
    {
        printf("ricetta non trovata\n");
        return 0;
    }
    else
    {
        printf("ingredienti: \n");

        for(i=0;i<ingrtot;i++)
        {
            while(fscanf(frigo, "%s%f", ingrediente, &q)==2)
            {
                int disponibile=0;
                if(strcmp(ingrediente, ingr[i].nome)==0)
                {

                    if(q>=ingr[i].qu)
                        printf("-%s: OK\n", ingrediente);
                    else
                    {
                        printf("-%s: NO\nrichiesto: %.1f, disponibile %.1f\n", ingrediente, ingr[i].qu, q);
                        possibile=0;
                    }

                {

                }
                }

            }
        }
    }

    fclose(frigo);
    if(possibile)
        printf("ricetta '%s' possibile\n", richiesta);
    else
        printf("ricetta '%s' impossibile\n", richiesta);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main() {
    Fila f; inicializarFila(&f);
    int estoque;
    printf("Estoque inicial: ");
    scanf("%d",&estoque);
    char cmd[20];
    while(1){
        printf("\nCmd> ");
        if(scanf("%19s",cmd)!=1) break;
        if(strcmp(cmd,"ADD")==0){
            Cliente c; scanf("%23s %d",c.id,&c.qtd);
            enfileirar(&f,c);
        } else if(strcmp(cmd,"START")==0){
            while(!filaVazia(&f)&&estoque>0){
                Cliente c; desenfileirar(&f,&c);
                if(c.qtd<=estoque){
                    printf("Cliente %s atendido com %d\n",c.id,c.qtd);
                    estoque-=c.qtd;
                } else {
                    printf("Cliente %s pediu %d, restam %d. Aceita? (S/N): ",c.id,c.qtd,estoque);
                    char r; scanf(" %c",&r);
                    if(r=='S'||r=='s'){printf("Venda parcial de %d\n",estoque);estoque=0;}
                    else printf("Nao atendido.\n");
                }
            }
            if(estoque==0) printf("Ingressos esgotados!\n");
        } else if(strcmp(cmd,"REL")==0){
            printf("Estoque restante: %d\n",estoque);
        } else if(strcmp(cmd,"EXIT")==0){
            limparFila(&f); break;
        } else printf("Comando invalido\n");
    }
    return 0;
}

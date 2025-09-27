
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){
    Pilha p; initPilha(&p);
    char cmd[20];
    while(1){
        printf("CMD> ");
        if(scanf("%19s",cmd)!=1) break;
        if(strcmp(cmd,"CALL")==0){
            char f[48]; int sp;
            scanf("%47s %d",f,&sp);
            push(&p,f,sp);
        } else if(strcmp(cmd,"RET")==0){
            Frame fr;
            if(pop(&p,&fr)) printf("Retorno de %s\n",fr.func);
            else printf("Pilha vazia.\n");
        } else if(strcmp(cmd,"PEEK")==0){
            Frame fr;
            if(peek(&p,&fr)) printf("Topo: %s %d\n",fr.func,fr.sp);
            else printf("Pilha vazia.\n");
        } else if(strcmp(cmd,"TRACE")==0){
            Frame *cur=p.topo; int nivel=0;
            while(cur){printf("%d: %s %d\n",nivel,cur->func,cur->sp);cur=cur->baixo;nivel++;}
        } else if(strcmp(cmd,"EXIT")==0){
            limparPilha(&p); break;
        } else printf("Invalido\n");
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(Fila *f){f->ini=f->fim=NULL;}

void enfileirar(Fila *f, Cliente c){
    Cliente *n=malloc(sizeof(Cliente));
    if(!n) return;
    *n=c; n->prox=NULL;
    if(!f->ini) f->ini=f->fim=n;
    else {f->fim->prox=n;f->fim=n;}
}

bool desenfileirar(Fila *f, Cliente *out){
    if(!f->ini) return false;
    Cliente *tmp=f->ini; *out=*tmp;
    f->ini=tmp->prox; if(!f->ini) f->fim=NULL;
    free(tmp); return true;
}

bool filaVazia(Fila *f){return f->ini==NULL;}

void limparFila(Fila *f){
    Cliente tmp; while(desenfileirar(f,&tmp));
}

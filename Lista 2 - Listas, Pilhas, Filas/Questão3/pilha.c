
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void initPilha(Pilha* p){p->topo=NULL;}

bool push(Pilha* p,const char* f,int sp){
    Frame* n=malloc(sizeof(Frame));
    if(!n) return false;
    strcpy(n->func,f); n->sp=sp;
    n->baixo=p->topo; p->topo=n; return true;
}

bool pop(Pilha* p,Frame* out){
    if(!p->topo) return false;
    Frame* tmp=p->topo; *out=*tmp;
    p->topo=tmp->baixo; free(tmp); return true;
}

bool peek(Pilha* p,Frame* out){
    if(!p->topo) return false;
    *out=*p->topo; return true;
}

bool vaziaPilha(Pilha* p){return p->topo==NULL;}

void limparPilha(Pilha* p){
    Frame tmp; while(pop(p,&tmp));
}

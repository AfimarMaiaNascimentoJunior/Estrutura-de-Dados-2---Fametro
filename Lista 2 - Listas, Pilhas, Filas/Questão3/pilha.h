
#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct Frame{
    char func[48];
    int sp;
    struct Frame *baixo;
} Frame;

typedef struct{
    Frame *topo;
} Pilha;

void initPilha(Pilha*);
bool push(Pilha*,const char*,int);
bool pop(Pilha*,Frame*);
bool peek(Pilha*,Frame*);
bool vaziaPilha(Pilha*);
void limparPilha(Pilha*);

#endif

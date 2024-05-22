#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#define MAX 200


typedef int tp_item;

typedef struct
{
    tp_item item[MAX];
    int ini,fim;
    // int tam;
}tp_fila;

void inicializa_Fila(tp_fila *f){

    f->ini = f->fim = MAX -1;

}

int filaVazia(tp_fila *f){

    if (f->ini == f->fim)
    {
        return 1;
    } return 0;
    
}

int proximo(int pos){

    if (pos == MAX -1)// checa se a posição é a mesma da ultima posição da fila.
    {
        return 0;
    } return ++pos;
    
}

int filaCheia(tp_fila *f){

    if (proximo(f->fim) == f->ini)
    {
        return 1;
    } return 0;
    
}


int insereFila(tp_fila *f, tp_item e){

    if (filaCheia(f))
    {
        return 0;//Não foi possivel adiconar a fila.
    }
    
    f->fim = proximo(f->fim);
    f->item[f->fim] = e;
// f->tam++;
    return 1;
}

int removeFila(tp_fila *f, tp_item *e){
    if (filaVazia(f))
    {
        return 0;// Não foi possivel remover da fila.
    }
    f->ini = proximo(f->ini);
    *e = f->item[f->ini];
    // f-> tam--;
    return 1;
}

void imprimeFila(tp_fila f ){

    tp_item e;
    while (!filaVazia(&f))
    {
        removeFila(&f, &e);
        printf("\n%d", e);
    }
    
}

//duas opções de codigo do tamanho_fila
int tamanho_Fila(tp_fila *f){
    if(filaVazia(f)) return 0;
    if(f->ini < f->fim) return f->fim - f->ini;
    return MAX - 1 - f->ini + f->fim + 1;
}

int tamanho_Fila1(tp_fila f){
    int cont = 0;
    tp_item e;
    while (!filaVazia(&f))
    {
        removeFila(&f,&e);
        cont++; 
    }
    return cont;
}






#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Código escrito por el equipo 9*/
typedef struct _nodo nodo;
typedef struct _lista lista;

struct _nodo{
    int info;
    nodo* sig;
};

struct _lista{
    nodo* head;
    nodo* tail;
    int num;
};

nodo* crear_nodo(int info){
    nodo *t = (nodo*)malloc(sizeof(nodo));
    t->sig = NULL;
    t->info = info;
    return t;
}

lista* crear_lista(){
    lista* l = (lista*) malloc(sizeof(lista));
    l->head=NULL;
    l->tail=NULL;
    l->num=0;
    return l;
}

bool insertar_fin(lista *l, int info){
    nodo* nuevo = crear_nodo(info);
    if(l->head == NULL && l->tail == NULL){
        l->head=nuevo;
        l->tail = nuevo;
        l->num++;
        return true;
    }else{
        l->tail->sig = nuevo;
        l->tail = nuevo;
        l->num++;
        return true;
    }
    return false;
}

void eliminar_inicio(lista *l){
    if(l->head == NULL && l->tail == NULL){
         return;
    }
    nodo *temp = l->head;
    l->head = l->head->sig;
    temp->sig= NULL;
    free(temp);
    temp=NULL;
    l->num--;
}

bool es_vacia(lista *l){
    if(l->head == NULL && l->tail == NULL){
         return true;
    }return false;
}

void imprimir_lista(lista *l){
    printf("Lista:\n");
    for(nodo* t = l->head;t != NULL; t = t->sig){
        printf("|%d| ->\t", t->info);
    }
    printf("\n\n");
}

void imprimir_direcciones(lista *l){
    printf("Direcciones de memoria:\n");
    for(nodo* t = l->head;t != NULL; t = t->sig){
        printf("%p\n", t);
    }
    printf("\n\n");
}

void eliminar_lista(lista *l){
    printf("La memoria será liberada\n");
    if(!es_vacia(l)){
        nodo* t =l->head;
        while(l->head!=NULL){
            eliminar_inicio(l);
            t =l->head;
        }
    }    
    free(l);
    l=NULL;
    return;
}

int main(){
    lista* l1=crear_lista();
    insertar_fin(l1, 1);
    insertar_fin(l1, 2);
    insertar_fin(l1, 3);
    insertar_fin(l1, 4);
    insertar_fin(l1, 5);
    insertar_fin(l1, 6);

    imprimir_lista(l1);

    imprimir_direcciones(l1);
    eliminar_lista(l1);

    system("pause");
    return 0;
}
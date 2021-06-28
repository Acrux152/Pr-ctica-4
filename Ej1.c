#include <stdio.h>
#include <stdlib.h>

/*Código escrito por el equipo 9*/
int main(){
    int *array=NULL, *array2=NULL, num, cont;
    printf("Cuantos elementos tiene el arreglo?\n");
    scanf("%d", &num);
    array=(int *)realloc(array, num*sizeof(int));
    if (array != NULL){
        for(cont=0; cont<num; cont++){
            printf("Ingresa el valor en %d\n", cont+1);
            scanf("%d", array+cont);
        }

        printf("Vector reservado: \n[");
        for(cont=0; cont<num; cont++){
            printf("Valor:%d dir:%p\n", *(array+cont), array+cont);
        }


        printf("\t]\n");
    }
    num *=2;
    
    array2=(int*)realloc(array, num*sizeof(int));
    if (array != NULL){
        for(; cont<num; cont++){
            printf("Ingresa el valor en %d\n", cont+1);
            scanf("%d", array+cont);
        }

    printf("Vector reservado: \n[");
        for(cont=0; cont<num; cont++){
            printf("Valor:%d dir:%p\n", *(array+cont), array+cont);
        }
        printf("\t]\n");
        printf("La memoria sera liberada\n");
        free(array);
    }

    system("pause");
    return 0;
}

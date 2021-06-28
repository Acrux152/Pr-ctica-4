#include <stdio.h>
#include <stdlib.h>

/*Código escrito por el equipo 9*/
int main(){
    int *array=NULL, *array2, num, cont;
    printf("Cuantos elementos tiene los arreglos?\n");
    scanf("%d", &num);
    array=(int *)malloc(num*sizeof(int));
    array2=(int*)calloc(num, sizeof(int));
    if (array != NULL){
        printf("Vector reservado: \n[");
        for(cont=0; cont<num; cont++){
            printf("Valor:%d dir:%p\n", *(array+cont), array+cont);
        }
        printf("\t]\n");
        printf("La memoria sera liberada\n");
        free(array);
    }

    if (array2 != NULL){
        printf("Vector reservado: \n[");
        for(cont=0; cont<num; cont++){
            printf("Valor:%d dir:%p\n", *(array2+cont), array2+cont);
        }
        printf("\t]\n");
        printf("La memoria sera liberada\n");
        free(array2);
    }

    system("pause");
    return 0;
}
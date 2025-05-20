#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main(){
    FILE *f = fopen("ages.txt","r");

    if(f != NULL){
        printf("Fajl beolvasva!\n");
    }
    else{
        printf("Fajl-t nem sikerült beolvasni!\n");
    }

    int *t = malloc(sizeof(int));
    int k = 0;
    int meret = 1;
    int feltoltot_meret = 0;
    int tmp = 0;
    while(fscanf(f,"%d",&tmp) == 1){
        if(meret == feltoltot_meret){
            meret = meret * 2;
            t = realloc(t, meret*sizeof(int));
        }
        

        t[k] = tmp;
        k++;
        feltoltot_meret++;
    }

    t = realloc(t, feltoltot_meret*sizeof(int));

    int count = 0;
    for(int i = 0; i < feltoltot_meret; i++){
        int ev = 2025 - t[i];
        if(ev <= 1981){
            count++;
        }
    }

    printf("A millenniuminal idosebbek szama: %d\n", count);


    free(t);
    fclose(f);
    return 0;
}
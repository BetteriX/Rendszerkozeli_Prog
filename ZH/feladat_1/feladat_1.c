#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* const argv[]){
    srand(time(NULL));

    double rf = (double) rand()/((unsigned)RAND_MAX + 1);

    double zold_esely = 0.0526;
    double esely = (double)18/38;

    if (argc == 2 && strcmp(argv[1], "-h") == 0){
        printf("zold: 5.26\n");
        printf("piros: %f\n", esely*100);
        printf("fekete: %f\n", esely*100);
        exit(0);
    }

    if(rf < zold_esely){
        printf("zold\n");
    }
    else if(rf > zold_esely && rf < esely){
        printf("piros\n");
    }
    else{
        printf("fekete\n");
    }

    return 0;
}

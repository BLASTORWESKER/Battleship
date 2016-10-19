#include <stdio.h>
#include <stdlib.h>
#define MAP_HEIGHT 10
#define MAP_WIDTH 10
#define NB_PLAYER 2
#define ID_CORVETTE 1
#define ID_DESTROYER 2
#define ID_CROISER 3
#define ID_PORTE_AVION 4

int doRand(int startVal, int endVal){

    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}
void Corvette_IA_1(){
    int map[MAP_HEIGHT][MAP_WIDTH][NB_PLAYER]={0};
    int x=0;
    int y=0;
    x = doRand(0,MAP_HEIGHT);
    y = doRand(0,MAP_WIDTH);
    map[x][y][1] = ID_CORVETTE;






}

void printMap(int map[MAP_HEIGHT][MAP_WIDTH][NB_PLAYER],int player){
    int i=0;
    int j=0;
    for(i=0;i<MAP_HEIGHT;i++){
        for(j=0;j<MAP_WIDTH;j++){
            printf("%d ",map[i][j][player]);
        }
        br();
    }
}

void PvP(){




}

void PvIA(){




}

void IAvIA(){
    Corvette_IA_1();




}
void br(){ // Retour à la ligne
    printf("\n");
}

int main()
{
    int mode_de_jeu = 0;
    int height=0;
    int width=0;
    int map[MAP_HEIGHT][MAP_WIDTH][NB_PLAYER]={0};



    printf("BATAILLE NAVALE\n\n");
    printf("1 - PvP\n2 - PvIA\n3 - IAvIA\n");
    br();
    scanf("%d",&mode_de_jeu);
    fflush(stdin);

    while (mode_de_jeu < 1 || mode_de_jeu > 3){
        printf("Saisie incorecte \n");
        scanf("%d",&mode_de_jeu);
    }
    br();
    printMap(map,0);

    switch(mode_de_jeu){
        case 1:
            PvP();
            break;
        case 2:
            PvIA();
            break;
        case 3:
            IAvIA();
            break;
    }




    return 0;
}

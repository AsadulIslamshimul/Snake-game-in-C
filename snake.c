#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

    int i,j, width=30, height=30;
    int x,y,fruit_x,fruit_y,game_over=0,score;
    int count_tail=0;
    int flag=0;
    int tail_x[100];
    int tail_y[100];


    // For making snake and fruit position

    void setup(){

x=width/2;
y=height/2;
level_1:
fruit_x=rand()%20;
    if(fruit_x==0){
    goto level_1;
}
level_2:
fruit_y=rand()%20;
    if(fruit_y==0){
    goto level_2;

}
}
        // for making box

void draw(){
    system("cls"); // for clear previous box


for(i=0;i<width;i++){
    for(j=0;j<height;j++){
        if(i==0||j==0||i==width-1||j==(height-1)){
            printf("*");
        }
        else{
                if(i==x && j==y){
                    printf("O");                     // print snake
                }
                else if(i==fruit_x && j==fruit_y){
                    printf("F");                     //print fruit
                }
                else{
                    int k,m=0; //i,j pair
                        for(k=0;k<count_tail;k++){

                                // print length of snake

                            if(i==tail_x[k] && j==tail_y[k]){
                                printf("o");
                                m=1;
                            }
                        }
                        if(m==0){

                        printf(" ");
                                }
            }
        }
    }
    printf("\n");
}
    printf("SCORE=%d",score);
}

        // for input the keys


void input(){
if(kbhit()){
    switch(getch()){
    case 'a': flag=1;
    break;
    case 's': flag=2;
    break;
    case 'w': flag=3;
    break;
    case 'z': flag=4;
    break;
    case 'v': game_over=1;
    break;


    }
}
}
        // for making logic or moving snake



        void make_logic(){

                    // For snake bigger
            int i;
            int prev_2x,prev_2y;

            int prev_x=tail_x[0];
            int prev_y=tail_y[0];

            tail_x[0]=x;
            tail_y[0]=y;


           for(i=1;i<count_tail;i++){
                prev_2x=tail_x[i];
                prev_2y=tail_y[i];
                tail_x[i]=prev_x;
                tail_y[i]=prev_y;
                prev_x=prev_2x;
                prev_y=prev_2y;

           }

            // moving snake

        switch(flag){
        case 1: y--;
        break;
        case 2: y++;
        break;
        case 3: x--;
        break;
        case 4: x++;
        break;
        default :
            break;
        }
         // For game over
        if(x<0||x>width||y<0||y>height){
            game_over=1;
        }
        for(i=0;i<count_tail;i++){
            if(x==tail_x[i] && y==tail_y[i]){
                game_over=1;
            }
        }
            // For changing fruit position

         if(x ==fruit_x && y==fruit_y){
            level_3:
        fruit_x=rand()%20;
        if(fruit_x==0){
        goto level_3;
        }
        level_4:
        fruit_y=rand()%20;
        if(fruit_y==0){
        goto level_4;
        }
            score=score+10;
            count_tail++;

}
        }
int main(){

    int i,j,p;
    char ch;

     printf("       >>~Welcome to SNAKE GAME~<<   \n\n");
     printf("  What level you want to play?\n");
     printf("  Easy press:1. Medium press:2. Hard press:3.\n");
     printf("  Inter your level:");
   scanf("%d",&p);

    if(p==1){


setup();
while(game_over!=1){
draw();
input();
make_logic();

        // For control speed

for(i=0;i<1000;i++){
    for(j=0;j<10000;j++){

    }
}
for(i=0;i<1000;i++){
    for(j=0;j<100000;j++){

    }
}


}
printf("\n");
    }
    else if(p==2){
       setup();
while(game_over!=1){
draw();
input();
make_logic();

        // For control speed

for(i=0;i<1000;i++){
    for(j=0;j<1000;j++){

    }
}
for(i=0;i<1000;i++){
    for(j=0;j<1000;j++){

    }
}


}
printf("\n");
    }

 else if(p==3){
    setup();
while(game_over!=1){
draw();
input();
make_logic();
}
printf("\n");
 }
 else{
    printf("  You have press wrong key\n");
    printf("  GAME OVER\n\n");
    printf("  **THANK YOU**");
 }
return 0;
}

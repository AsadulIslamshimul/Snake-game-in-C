#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>



    int i,j, length=20, height=40;
    int x,y, food_x,food_y,game_over=0,score;
    int count_move=0;
    int tdx=0;
    int move_x[100];
    int move_y[100];


    // For making snake and fruit position

    void config(){

    x=length/2;
    y=height/2;
    level_1:
    food_x=rand()%20;
    if(food_x==0){
    goto level_1;
}
    level_2:
    food_y=rand()%20;
    if(food_y==0){
    goto level_2;

}
}
        // for making box

    void print(){
    system("cls"); // for clear previous box


    for(i=0;i<length;i++){
    for(j=0;j<height;j++){
        if(i==0||j==0||i==length-1||j==(height-1)){
            printf("%c",219);
        }
        else{
                if(i==x && j==y){
                    printf("%c",153);                     // print snake
                }
                else if(i==food_x && j==food_y){
                    printf("%c",254);                     //print fruit
                }
                else{
                    int k,m=0; //i,j pair
                        for(k=0;k<count_move;k++){

                                // print length of snake

                if(i==move_x[k] && j==move_y[k]){
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


    void input_key(){
        char a;
        int UP=72;
        int DOWN=80;
        int LEFT=75;
        int RIGHT=77;

    if(kbhit()){

        a=getch();

    if(a==LEFT||a=='a'){
        tdx=1;
    }
    else if (a==RIGHT||a=='s'){
        tdx=2;
    }
    else if (a==UP||a=='w'){
        tdx=3;
    }
    else if(a==DOWN||a=='z'){
        tdx=4;
    }
}
}
            // Print "SNAKE" on the screen



   void print_screen(){


    int i,j,k,l,n,m;
    for(i=0;i<1;i++){
        // For 1st row

    for(j=0;j<45;j++){
        if(j==3||j==4||j==10||j==18||j==24||j==31||j==33||j==37||j==38||j==39){
            printf("%c",254);
        }
        else{
            printf(" ");
        }
    }
    printf("\n");

            //for 2nd row

    for(k=0;k<45;k++){
        if(k==2||k==5||k==9||k==11||k==17||k==23||k==25||k==31||k==32||k==37){
            printf("%c",254);
        }
        else {
            printf(" ");
        }
    }
    printf("\n");

        // For 3rd row

    for(l=0;l<45;l++){
        if(l==4||l==8||l==12||l==16||l==22||l==23||l==24||l==25||l==26||l==31||l==37||l==38||l==39){
            printf("%c",254);
        }
        else {
            printf(" ");
        }
    }
    printf("\n");

           // for 4th row

    for(m=0;m<45;m++){
        if(m==2||m==5||m==7||m==13||m==15||m==21||m==27||m==31||m==32||m==37){
            printf("%c",254);
        }
        else {
            printf(" ");
        }
    }
    printf("\n");

            // for 5th row

    for(n=0;n<45;n++){
        if(n==4||n==6||n==14||n==20||n==28||n==31||n==34||n==37||n==38||n==39){
            printf("%c",254);
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
}


     printf("                                        GAME BY SHIMUL.\n");

     printf("       >>~Welcome to SNAKE GAME~<<   \n\n");
     printf("RULES: \n");
     printf(">>> If you touch the head on boundary the game will end.\n");
     printf(">>> If you touch the head to snake body the game will end.\n");
     printf(">>> For move snake  use the Array keys.\n");
     printf(">>> You also can move Left press 'A'  Right 'S'  Up 'W' Down 'Z'.\n\n");

   }

        // for making logic or moving snake



        void make_logic(){

                    // For snake bigger
            int i;
            int prev_2x,prev_2y;

            int prev_x=move_x[0];
            int prev_y=move_y[0];

            move_x[0]=x;
            move_y[0]=y;


           for(i=1;i<count_move;i++){
                prev_2x=move_x[i];
                prev_2y=move_y[i];
                move_x[i]=prev_x;
                move_y[i]=prev_y;
                prev_x=prev_2x;
                prev_y=prev_2y;

           }

            // moving snake

        switch(tdx){
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

        if(x<0||x>length||y<0||y>height){
            game_over=1;
            printf("%c",7);
            printf("\n\n");
            printf("   >>~ GAME OVER ~<<\n");
            printf(" THANK YOU FOR PLAYING \n");
        }
        for(i=0;i<count_move;i++){
            if(x==move_x[i] && y==move_y[i]){
                game_over=1;
                printf("%c",7);
                printf("\n\n");
                printf("   >>~ GAME OVER ~<<\n");
                printf(" THANK YOU FOR PLAYING \n");
            }
        }
            // For changing fruit position

         if(x ==food_x && y==food_y){
            level_3:
        food_x=rand()%20;
        if(food_x==0){
        goto level_3;
        }
        level_4:
        food_y=rand()%20;
        if(food_y==0){
        goto level_4;
        }
            score=score+10;
            count_move++;

}
        }

int main(){

    int i,j;
    char ch,p;
     print_screen();

     printf("  What level you want to play?\n\n");
     printf("  Easy press:E. Medium press:M. Hard press:H.\n\n");
     printf("  Inter your level:");
     scanf("%c",&p);

    if(p=='e'||p=='E'){

    config();
    while(game_over!=1){
    print();
    input_key();
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
    else if(p=='m'||p=='M'){
       config();
while(game_over!=1){
print();
input_key();
make_logic();

        // For control speed

for(i=0;i<1000;i++){
    for(j=0;j<10000;j++){

    }
}
for(i=0;i<1000;i++){
    for(j=0;j<10000;j++){

    }
}
}
printf("\n");
    }

 else if(p=='h'||p=='H'){

    config();
while(game_over!=1){
print();
input_key();
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


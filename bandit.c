#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int money = 5000;
int price = 300;
int coeff = 100;
int x1 = 0, x2 = 0, x3 = 0;

void val(){
    x1 = rand() % 8;
    x2 = rand () % 8;
    x3 = rand () % 8;
}

void output(){
    printf ("Money  = %d\n", money);   
    printf (" %d  %d  %d\n" , x1, x2, x3);
    sleep(1);
}

int check(){
    int win = 0;
    if (x1 <= 4){
        if ((x1 == x2) && (x2 == x3)) 
		win = (x1 +1)* coeff;
    }	
   if((x1 == 6) && (x2 == 6) && (x3 == 6)){
	return -1;
	}
    if (x1 == 5 || x1 == 7){
        if((x1 == 7) && (x2 == 7) && (x3 == 7)) 
		return 1000;
	else
        	win = (x1 + 1)* coeff;
    }
    return win;
}



void play(){
    while ((money - price) >= 0) {
        val();
    	output();
		money = money - price + check();
		printf("Your win = %d\n",check());
        if (check() == 1000) {
            printf("You won!\n");            
            exit(0);
        }
        if(check() == -1){
            printf("You lose!\n");          
            exit(0);
        }  
    }
    printf("You have no enough money\n Game over!!!");          
    exit(0);

}

int main(){
    printf("You have %d credits\n", money);
    srand(time(NULL));
    play();
    return 0;
}
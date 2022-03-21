#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    // roll dice
    // Sum of the spots on 2 upward faces is calculated
    // 7 or 11 on 1st throw -> win
    // 2 , 3 , 12 on the 1st throw -> lose
    // 4 , 5 , 6 , 8 , 9 , 10 becomes player point
    // Player must roll his point before rolling 7 to win

    srand(time(NULL));

    int a , b , counter = 0 , point = 0;

    while(true){
        a = 1 + rand() % 6;
        b = 1 + rand() % 6;

        counter++;

        int c = a + b;

        if(((c == 7) || (c == 11)) && (counter == 1)){
            printf("First throw = %d\nSecond throw = %d\nPoint = %d\n Sum = %d\n-------------\n " , a , b , point , c);
            printf("You Win");
            break;
        }
        else if(((c == 2) || (c == 3) || (c == 12)) && (counter == 1)){
            printf("First throw = %d\nSecond throw = %d\nPoint = %d\n Sum = %d\n-------------\n " , a , b , point , c);
            printf("You LOSE");
            break;
        }
        else if(point == c){
            printf("First throw = %d\nSecond throw = %d\nPoint = %d\n Sum = %d\n-------------\n " , a , b , point , c);
            printf("You Win");
            break;
        }
        else if((c == 7) && (counter != 1)){
            printf("First throw = %d\nSecond throw = %d\nPoint = %d\n Sum = %d\n-------------\n " , a , b , point , c);
            printf("You Lose");
            break;
        }
        else{
            printf("First throw = %d\nSecond throw = %d\nPoint = %d\n Sum = %d\n-------------\n " , a , b , point , c);
        }


        point = c;


    }
    return 0;
}

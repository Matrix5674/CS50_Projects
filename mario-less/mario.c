#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;
    int n = 0;
    do{
    x = get_int("How tall do you want the pyramid to be? ");
    } while (x>8 || x<1);

    for (int k = x; x>0; x--){ //Loops size times
        for (int i = x-1; i>0; i--){ //Loops size-1 times
            printf(" "); //creates the starting line of spaces
            }
            for (int j = 0; j<n+1; j++){
                printf("#");

            }
            n = n+1;
            printf("\n");
    }

}

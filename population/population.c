#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize;
    int endSize;
    int a = 0;
    do {
            // TODO: Prompt for start size
    startSize = get_int("How many llama's do we start off with?");

    }while (startSize<9);
    do{


    // TODO: Prompt for end size
    endSize = get_int("How many llama's should we have at the end?");
    }
    while (startSize>endSize);

    // TODO: Calculate number of years until we reach threshold
    while (startSize < endSize){
        startSize = startSize + (startSize/3) - (startSize/4);

        a++;

    }
    // TODO: Print number of years
    printf("Years: %i/n", a);
}

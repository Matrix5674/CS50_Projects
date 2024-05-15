#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    int x = 0;

    int n;
    string input = get_string("Enter a word: ");


    for (int i = 0; input[i] != '\0'; i++){
         int k = 128;

            n = input[i];

            for (int l = 0; l<8; l++){


                if (k<=n){
                    print_bulb(1);
                    n = n-k;
                    k = k/2;
                }else{
                    print_bulb(0);
                    k = k/2;
                }

            }
            printf("\n");
    }


}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string text = get_string("Type in your name: ");
    printf("Hello, %s\n", text);
}

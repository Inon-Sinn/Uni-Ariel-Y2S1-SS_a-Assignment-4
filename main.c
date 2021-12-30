#include <stdio.h>
#include "graph.h"

int main(int argc, char const *argv[])
{
    printf("Please Enter your input");
    char input;
    scanf("\n%c",&input);
    while (input == 'A' || input == 'B' || input =='D' || input=='S'|| input == 'T')//TODO check for better ways
    {
        if (input == 'A')//Remove the former Graph
        {
            scanf("\n%c",&input);
            while (input == 'n')
            {
                printf("New Node");
                scanf("\n%c",&input);
            }
            
        }
        if (input == 'B')
        {
            printf("You have entered B\n");
        }
        if (input == 'D')
        {
            printf("You have entered D\n");
        }
        if (input == 'S')
        {
            printf("You have entered S\n");
        }
        if (input == 'T')
        {
            printf("You have entered T\n");
        }
        scanf("\n%c",&input);
    }
    printf("End");

    return 0;
}

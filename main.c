#include <stdio.h>
#include "graph.h"

int main(int argc, char const *argv[])
{
    printf("Please Enter your input");
    char input;
    scanf("\n%c",&input);
    while (input == 'A' || input == 'B' || input =='D' || input=='S'|| input == 'T')//TODO check for better ways
    {
        if (input == 'A')
        {
            //TODO Remove the former Graph
            int amount_of_Nodes;
            scanf("\n%d",&amount_of_Nodes);
            printf("The amount of Nodes is %d\n",amount_of_Nodes);
            scanf("\n%c",&input);
            while (input == 'n')
            {
                int node_id;
                scanf("\n%d",&node_id);
                printf("The new Node id is %d\n",node_id);
                // Find the node 
                scanf("\n%c",&input);
                while (48 <= input && input <= 57)
                {
                    int dest = input - 48;
                    int weight = 0;
                    scanf("\n%d",&weight);
                    printf("The dest is %d and the weight of the edge %d\n",dest,weight);
                    scanf("\n%c",&input);
                }
                
            }
            
        }
        if (input == 'B')
        {
            printf("You have entered B\n");
            int node_id;
            scanf("\n%d",&node_id);
            printf("The new Node id is %d\n",node_id);
            scanf("\n%c",&input);
            while (48 <= input && input <= 57)
            {
                int dest = input - 48;
                int weight = 0;
                scanf("\n%d",&weight);
                printf("The dest is %d and the weight of the edge %d\n",dest,weight);
                scanf("\n%c",&input);
            }
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

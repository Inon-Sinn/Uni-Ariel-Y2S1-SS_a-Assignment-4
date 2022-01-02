#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char const *argv[])
{
    pnode head = NULL;

    int amount_of_Nodes;
    int node_id;
    int dest;
    int weight;
    char input;

    scanf("%c",&input);
    while (input == 'A' || input == 'B' || input =='D' || input=='S'|| input == 'T')
    {
        if (input == 'A')
        {
            //Build a new Graph with the given amount of nodes
            scanf("%d",&amount_of_Nodes);
            build_graph_cmd(&head,amount_of_Nodes);

            scanf("%s",&input);
            while (input == 'n')
            {
                // Find the node
                scanf("%d",&node_id);
                pnode currentNode = getNode(&head,node_id);
                // Add the edges to the node
                while(scanf("%d",&dest) == 1){
                    scanf("%d",&weight);
                    addEdge(currentNode,dest,weight,&head);
                }
                scanf("%c",&input);
            }
        }
        if (input == 'B')
        {
            // Find the node
            scanf("%d",&node_id);
            pnode currentNode = getNode(&head,node_id);
            // Add the edges to the node
            while(scanf("%d",&dest) == 1){
                scanf("%d",&weight);
                addEdge(currentNode,dest,weight,&head);
            }
            scanf("%c",&input);
        }
        if (input == 'D')
        {
            int node_id;
            scanf("%d",&node_id);
            removeNode(&head,node_id);
            scanf("%c",&input);
        }
        if (input == 'S')
        {
            printf("You have entered S\n");
        }
        if (input == 'T')
        {
            printf("You have entered T\n");
        }
        scanf("%c",&input);
    }
    printGraph_cmd(head);

    return 0;
}




//     pnode head = NULL;
//     build_graph_cmd(&head,5);
//     printGraph_cmd(head);
//     printf("-------\n");
//     pnode gotNode = getNode(&head,4);
//     addEdge(gotNode,2,10, &head);
//     addEdge(gotNode,1,20, &head);
//     printGraph_cmd(head);
//     printf("-------\n");
//     removeNode(&head,2);
//     printGraph_cmd(head);
//     printf("-------\n");
//    build_graph_cmd(&head,3);
//     printGraph_cmd(head);
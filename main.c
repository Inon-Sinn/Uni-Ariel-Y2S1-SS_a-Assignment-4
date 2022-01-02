#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algo.h"

//Finds the shortest path using the dijkstra Algorithm
int dijkstra(pnode *head,int amount_of_Nodes, int src, int dest);

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
        if (input == 'B')//TODO not finished
        {
            //Remove the Node if it exists
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
            amount_of_Nodes--;
            scanf("%c",&input);
        }
        if (input == 'S')
        {
            //Collect the source and destination node
            scanf("%d",&node_id);
            scanf("%d",&dest);
            //find the shortest distance
            dijkstra(&head, amount_of_Nodes,node_id,dest);
            scanf("%c",&input);
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

int dijkstra(pnode *head,int amount_of_Nodes,  int src, int dest){
    //Create the array that save the distance and the Queue
    int *d = (int*)malloc(sizeof(int)*amount_of_Nodes);
    int *Queue = (int*)malloc(sizeof(int)*amount_of_Nodes);
    int start = 0,end =amount_of_Nodes-1, min, min_id, edge_dest_id;
    // Check if memory was allocated
    if (d==NULL || Queue ==NULL)
    {
        printf("Memory Not aloocated");
        return -1;
    }
    //initlize the array and Queue
    int i;
    for (i = 0; i < amount_of_Nodes; i++){
        d[i] = -1;
        Queue[i] = i;
    }
    d[src] = 0;
    //Run the algorithm
    while (start<end)
    {
        //Extract the Min in the Queue
        min = start;
        for (i = start+1; i < end; i++){
            if(d[Queue[i]]<d[Queue[min]])
                min = i;
        }
        min_id = Queue[min];
        //Remove min from the Queue
            Queue[min] = Queue[start];
            Queue[start] = min_id;
            start++;
        //Go over the edges of the min node
        pnode minNode = getNode(head,min_id);
        edge *curEdge = minNode -> edges;
        while (curEdge != NULL)
        {
            //Relax algorithm
            edge_dest_id = curEdge->endpoint->node_num;
            if(d[edge_dest_id] > d[min_id] + curEdge->weight){
                d[edge_dest_id] =  d[min_id] + curEdge->weight;
            }
            curEdge = curEdge-> next;
        }
    }
    int res = d[dest];
    //Deallocate the arrays
    free(d);
    free(Queue);
    return res;
}

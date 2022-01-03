#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algo.h"

//Finds the shortest path using the dijkstra Algorithm
int dijkstra(pnode *head,int amount_of_Nodes, int src, int dest);

int TSP(pnode *head,int *cities, int length);

int TSPalgorithm(pnode *head,int *cities,int start,int length);

int min(int x,int y, int w);

int* copyArray(int *arr, int remove, int length);

void removeEdge2(pnode node,int node_id){
    edge *newEdge = (node->edges);
    edge **prev = &(node->edges);
    int found = 0;
    while(newEdge != NULL && found == 0)
    {
        if(newEdge -> endpoint -> node_num == node_id){
            *prev = newEdge->next;
            found = 1;
        }
        else{
            prev = &(newEdge->next);
            newEdge = newEdge -> next;
        };
    }
    //Deallocate the memory of the edge
    if(found==1){
        free(newEdge);
    }

}

int main(int argc, char const *argv[])
{
    pnode head = NULL;

    int node_id;
    int amount_of_cities;
    int dest;
    int weight;
    int res;
    int i,city;
    char input;
    int amount_of_Nodes;

    if(scanf("%c",&input)!=EOF){
        while (input == 'A' || input == 'B' || input =='D' || input=='S'|| input == 'T')//EOF - End of file, use ctrl + Z to get the same thing through user input
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
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
            if (input == 'B')
            {
                //find the Node
                scanf("%d",&node_id);
                pnode currentNode = getNode(&head,node_id);
                if(currentNode != NULL){
                    while (currentNode->edges != NULL)
                        removeEdge(currentNode);
                }
                else{
                    add_node(&head,node_id);
                    currentNode = getNode(&head,node_id);
                    amount_of_Nodes++;
                }
                // Add the edges to the node
                while(scanf("%d",&dest) == 1){
                    scanf("%d",&weight);
                    addEdge(currentNode,dest,weight,&head);
                }
                if(scanf("%c",&input)==EOF)
                    input = 'N';
                if(input == ' '){
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
            if (input == 'D')
            {
                //Remove the incoming edges
                scanf("%d",&node_id);
                node *count = head;
                while (count != NULL) {
                    removeEdge2(count, node_id);
                    count = count->next;
                }
                removeNode(&head,node_id);
                amount_of_Nodes--;
                if(scanf("%c",&input)==EOF)
                    input = 'N';
                if(input == ' '){
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
            if (input == 'S')
            {
                //Collect the source and destination node
                scanf("%d",&node_id);
                scanf("%d",&dest);
                //find the shortest distance
                res = dijkstra(&head, amount_of_Nodes,node_id,dest);
                printf("Dijsktra shortest path: %d \n",res);
                if(scanf("%c",&input)==EOF)
                    input = 'N';
                if(input == ' '){
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
            if (input == 'T')
            {
                //Collect the cities in an array
                scanf("%d",&amount_of_cities);
                int *cities = (int*)malloc(sizeof(int)*amount_of_cities);
                if(cities==NULL){
                    printf("No Memory");
                    exit(0);
                }
                for (i = 0; i < amount_of_cities; i++)
                {
                    scanf("%d",&city);
                    cities[i] = city;
                }
                //Run the TSP Algorithm
                res = TSP(&head,cities,amount_of_cities);
                printf("TSP shortest path: %d \n",res);
                //Deallocate the array
                free(cities);
                if(scanf("%c",&input)==EOF)
                    input = 'N';
                if(input == ' '){
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
        }
    }
    printGraph_cmd(head);
    removeGraph(&head);

    return 0;
}

int dijkstra(pnode *head,int amount_of_Nodes,  int src, int dest){
    //Test if the nodes even exist
    pnode sourceNode = getNode(head,src);
    pnode destinationNode = getNode(head,dest);
    if(sourceNode==NULL || destinationNode==NULL){
        //In case they don't exist then is no path so return -1
        return -1;
    }
    //Create the array that save the distance and the Queue
    int *d = (int*)malloc(sizeof(int)*amount_of_Nodes);
    int *Queue = (int*)malloc(sizeof(int)*amount_of_Nodes);
    int start = 0,end =amount_of_Nodes-1, Min, min_id, edge_dest_id;
    // Check if memory was allocated
    if (d==NULL || Queue ==NULL)
    {
        printf("Memory Not allocated");
        exit(0);
    }
    //initialize the array and Queue
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
        
        Min = start;
        for (i = start+1; i < end; i++){
            if(d[Queue[i]] == min(d[Queue[Min]],d[Queue[i]],0))
                Min = i;
        }
        min_id = Queue[Min];
        //Remove min from the Queue
        Queue[Min] = Queue[start];
        Queue[start] = min_id;
        start++;
        //Go over the edges of the min node
        pnode minNode = getNode(head,min_id);
        edge *curEdge = minNode -> edges;
        while (curEdge != NULL)
        {
            //Relax algorithm
            edge_dest_id = curEdge->endpoint->node_num;
            d[edge_dest_id] = min(d[edge_dest_id],d[min_id],curEdge->weight);
            curEdge = curEdge-> next;
        }
    }
    int res = d[dest];
    //Deallocate the arrays
    free(d);
    free(Queue);
    return res;
}

//The main TSP function
int TSP(pnode *head,int *cities, int length){
    int minDist = -1, i;
    //Easy Cases
    if(length == 0 || length == 1)
        return 0;
    //Run the TSP algorithm
    for (i = 0; i < length; i++)
    {
        int *copy = copyArray(cities,i,length);
        minDist = min(minDist,TSPalgorithm(head,copy,i,length-1),0);
    }
    //Deallocate the memory of the array
    free(cities);
    return minDist;
}

// This function is the tsp algorithm
int TSPalgorithm(pnode *head,int *cities,int start,int length){
    int res = -1,minDist = -1,i;
    // Base Cases
    if(length == 0)
        res = 0;
    else if(length == 1)
        res =  dijkstra(head,length,start,cities[0]);
        //Recursive Tsp call on a smaller amount of cities
    else{
        for (i = 0; i < length; i++)
        {
            int *copy = copyArray(cities,i,length);
            minDist = min(minDist,TSPalgorithm(head,copy,i,length-1),0);
        }
        res = minDist;
    }
    //Deallocate the memory
    free(cities);
    return res;
}

//An auxiliary function to get the shortest path
int min(int x,int y,int w){
    if(x==-1 && y==-1)
        return -1;
    if(x==-1)
        return y + w;
    if(y==-1)
        return x;
    if(x<=(y+w))
        return x;
    return y+w;
}

//An auxiliary function that given an array and an index, it returns a copy of that array without the index
int* copyArray(int *arr, int remove, int length){
    int *copy = (int*)malloc(sizeof(int)*(length-1));
    if(copy==NULL){
        printf("No Memory");
        exit(0);
    }
    int i,count=0;
    for (i = 0; i < length; i++)
    {
        if(i!=remove){
            copy[count] = arr[i];
            count++;
        }
    }
    return copy;

}



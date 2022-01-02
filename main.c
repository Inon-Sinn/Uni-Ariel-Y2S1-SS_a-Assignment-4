#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void printGraph_cmd(pnode head);

void add_node(pnode *head, int node_id);

pnode getNode(pnode *head, int node_id);

void addEdge(pnode node, int dest, int w, pnode *head);

void removeNode(pnode *head, int node_id);

void removeEdge(pnode node);

void removeGraph(pnode *head);

int main(int argc, char const *argv[])
{
    pnode head = NULL;
    add_node(&head,0);
    add_node(&head,1);
    add_node(&head,2);
    add_node(&head,4);
    printGraph_cmd(head);
    printf("-------\n");
    pnode gotNode = getNode(&head,4);
    addEdge(gotNode,2,10, &head);
    addEdge(gotNode,1,20, &head);
    printGraph_cmd(head);
    printf("-------\n");
    removeNode(&head,2);
    removeNode(&head,6);
    printGraph_cmd(head);
    printf("-------\n");
    removeGraph(&head);
    printGraph_cmd(head);
    return 0;
}

void printGraph_cmd(pnode head){
    node *current = head;
    while(current != NULL)
    {
        printf("Id: %d, egdes{",current->node_num);
        edge *cur = current -> edges;
        while(cur != NULL){
            printf("d:%d w:%d, ",cur -> endpoint -> node_num,cur -> weight);
            cur = cur->next;
        }
        printf("}\n");
        current = current->next;
    }
}

void add_node(pnode *head, int node_id){
    //Create the New Node
    pnode newNode = (pnode)malloc(sizeof(node));
    newNode -> node_num = node_id;
    newNode -> edges = NULL;
    newNode -> next = *head;
    *head = newNode;
}

pnode getNode(pnode *head, int node_id){
    node *current = *head;
    while (current != NULL)
    {
        if (current -> node_num == node_id)
            return current;
        current = current -> next;
    }
    printf("Not found");
    return 0;
}

void addEdge(pnode node, int dest, int w, pnode *head){
    pedge newEdge = (pedge)malloc(sizeof(edge));
    newEdge -> weight = w;
    newEdge -> endpoint = getNode(head,dest);
    newEdge -> next = node -> edges;
    node -> edges = newEdge;
}

void removeGraph(pnode *head){
    while (*head != NULL)
        removeNode(head,(*head) -> node_num);
}

void removeNode(pnode *head, int node_id){
    if( *head == NULL)
        return;
    node *current = *head;
    node **prev = head;
    int found = 0;
    while (current != NULL && found == 0)
    {
        if (current -> node_num == node_id) {
            *prev = current -> next;
            found = 1;
        }
        else {
            prev = &(current->next);
            current = current->next;
        }
    }
    //Deallocate the memory of the node and its edges
    if(current != NULL) {
        while (current->edges != NULL)
            removeEdge(current);
        free(current);
    }
}

void removeEdge(pnode node){
    edge *newEdge = (node->edges);
    if(newEdge != NULL){
        node -> edges = newEdge -> next;
        //deallocating the memory of the edge
        free(newEdge);
    }
}







// printf("Please Enter your input");
// char input;
// scanf("\n%c",&input);
// while (input == 'A' || input == 'B' || input =='D' || input=='S'|| input == 'T')//TODO check for better ways
// {
//     if (input == 'A')
//     {
//         //TODO Remove the former Graph
//         int amount_of_Nodes;
//         scanf("\n%d",&amount_of_Nodes);
//         printf("The amount of Nodes is %d\n",amount_of_Nodes);
//         scanf("\n%c",&input);
//         while (input == 'n')
//         {
//             int node_id;
//             scanf("\n%d",&node_id);
//             printf("The new Node id is %d\n",node_id);
//             // Find the node
//             scanf("\n%c",&input);
//             while (48 <= input && input <= 57)
//             {
//                 int dest = input - 48;
//                 int weight = 0;
//                 scanf("\n%d",&weight);
//                 printf("The dest is %d and the weight of the edge %d\n",dest,weight);
//                 scanf("\n%c",&input);
//             }

//         }

//     }
//     if (input == 'B')
//     {
//         printf("You have entered B\n");
//         int node_id;
//         scanf("\n%d",&node_id);
//         printf("The new Node id is %d\n",node_id);
//         scanf("\n%c",&input);
//         while (48 <= input && input <= 57)
//         {
//             int dest = input - 48;
//             int weight = 0;
//             scanf("\n%d",&weight);
//             printf("The dest is %d and the weight of the edge %d\n",dest,weight);
//             scanf("\n%c",&input);
//         }
//     }
//     if (input == 'D')
//     {
//         printf("You have entered D\n");
//     }
//     if (input == 'S')
//     {
//         printf("You have entered S\n");
//     }
//     if (input == 'T')
//     {
//         printf("You have entered T\n");
//     }
//     scanf("\n%c",&input);
// }
// printf("End");
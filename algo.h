#ifndef ALGO_
#define ALGO_
    
//Finds the shortest path using the dijkstra Algorithm
int dijkstra(pnode *head,int amount_of_Nodes, int src, int dest);

int TSP(pnode *head,int *cities, int length,int amount_of_Nodes);

int TSPalgorithm(pnode *head,int *cities,int start,int length,int amount_of_Nodes);

int min(int x,int y, int w);

int* copyArray(int *arr, int remove, int length);

int placeCalc(pnode *head, int node_id,int amount_of_Nodes);

int get_Id_by_Pos(pnode *head, int pos, int amount_of_Nodes);

#endif
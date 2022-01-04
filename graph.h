#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

//-----------

void build_graph_cmd(pnode *head, int num_of_nodes);

void printGraph_cmd(pnode head);

void add_node(pnode *head, int node_id);

pnode getNode(pnode *head, int node_id);

void addEdge(pnode node, int dest, int w, pnode *head);

void removeNode(pnode *head, int node_id);

void removeEdge(pnode node);

void removeGraph(pnode *head);

void removeEdge2(pnode node,int node_id);

//-----------

#endif

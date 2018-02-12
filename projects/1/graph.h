#include "list.h"

typedef struct
{
    int parent;
    int visited;
    List *adjacency;
} GraphNode;

typedef struct
{
    int nodesNumber;
    GraphNode **nodes;
} Graph;

Graph* newGraph(int);
void addEdge(Graph*, int, int);
char* dfs(Graph*, int, int);
void printGraph(Graph*);
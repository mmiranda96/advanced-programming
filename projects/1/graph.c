#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

#define FALSE 0
#define TRUE 1

Graph* newGraph(int nodesNumber)
{
    Graph *g = (Graph*)malloc(sizeof(Graph*));
    g->nodesNumber = nodesNumber;
    g->nodes = (GraphNode**)malloc(sizeof(GraphNode*) * nodesNumber);

    for (int i = 0; i < nodesNumber; i++)
    {
        g->nodes[i] = (GraphNode*)malloc(sizeof(GraphNode*));
        g->nodes[i]->adjacency = newList();
    }

    return g;
}

char* dfs(Graph *g, int a, int b)
{
    // A and B must be reduced by 1
    for (int i = 0; i < g->nodesNumber; i++)
    {
        g->nodes[i]->parent = -1;
        g->nodes[i]->visited = FALSE;
    }

    List *s = newList();
    push(s, a - 1);
    g->nodes[a-1]->visited = TRUE;
    while (!isEmpty(s))
    {
        int current = pop(s);
        if (current == b - 1)
        {
            // Track down the path
            int t;
            List *l = newList();
            
            push(l, b);
            t = g->nodes[b-1]->parent;
            while (t != -1)
            // Return the path as string
            {
                push(l, t + 1);
                t = g->nodes[t]->parent;
            }

            char *result = (char*)malloc(sizeof(char));
            char tString[2];
            while (!isEmpty(l))
            {
                int t = pop(l);
                sprintf(tString, "%d ", t);
                strcat(result, tString);
            }
            // Remove additional space
            result[strlen(result)-1] = '\0';
            
            return result;
        }
        else
        {
            for (ListNode *it = g->nodes[current]->adjacency->head; it != NULL; it = it->next)
            {
                // Add neighbors to the stack if not visited
                int neighbor = it->value;
                if (!g->nodes[neighbor]->visited)
                {
                    g->nodes[neighbor]->visited = TRUE;
                    g->nodes[neighbor]->parent = current;
                    push(s, neighbor);
                }
            }
        }
    }

    return "";
}

// For debug purposes, will be deleted
void printGraph(Graph *g)
{
    printf("Number of nodes: %d\n", g->nodesNumber);
    for (int i = 0; i < g->nodesNumber; i++)
    {
        printf("Node %d:\n", i+1);
        printf("    Visited: %s\n", (g->nodes[i]->visited ? "true" : "false"));
        printf("    Parent: %d\n", g->nodes[i]->parent+1);
        printf("    Adjacency size: %d\n", g->nodes[i]->adjacency->size);
        printf("    Adjacency: ");
        for (ListNode *it = g->nodes[i]->adjacency->head; it != NULL; it = it->next)
        {
            printf("%d ", it->value+1);
        }
        printf("\n");
    }
}

void addEdge(Graph *g, int a, int b)
{
    push(g->nodes[a-1]->adjacency, b - 1); 
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "hashtable.h"

typedef struct c
{
    int number;
    int interfacesNumber;
    int interfaces[5];
} Computer;

Graph* buildGraph(Computer**, int);

int main()
{
    int computersNumber;
    int addrA, addrB, addrC, addrD;
    int maskA, maskB, maskC, maskD;
    int address, netmask, network;
    scanf("%d", &computersNumber);
    Computer **computers = (Computer**)malloc(sizeof(Computer*) * computersNumber);
    for (int i = 0; i < computersNumber; i++)
    {
        computers[i] = (Computer*)malloc(sizeof(Computer*));
        computers[i]->number = i;
        scanf("%d", &computers[i]->interfacesNumber);
        for (int j = 0; j < computers[i]->interfacesNumber; j++)
        {
            scanf("%d.%d.%d.%d %d.%d.%d.%d", &addrA, &addrB, &addrC, &addrD, &maskA, &maskB, &maskC, &maskD);

            address = addrA;
            address |= addrB << 8;
            address |= addrC << 16;
            address |= addrD << 24;
            
            netmask = maskA;
            netmask |= maskB << 8;
            netmask |= maskC << 16;
            netmask |= maskD << 24;
            
            network = address & netmask;
            computers[i]->interfaces[j] = network;
        }
    }
    Graph *g = buildGraph(computers, computersNumber);

    int a, b;
    scanf("%d %d", &a, &b);
    char *path = dfs(g, a, b);
    if (strlen(path))
    {
        printf("Yes\n%s\n", path);
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

Graph* buildGraph(Computer** computers, int size)
{
    HashTable *ht = newHashTable(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < computers[i]->interfacesNumber; j++)
        {
            add(ht, computers[i]->interfaces[j], computers[i]->number);
        }
    }
    
    Graph *g = newGraph(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < computers[i]->interfacesNumber; j++)
        {
            List *computersInNetwork = get(ht, computers[i]->interfaces[j]);
            for (ListNode *it = computersInNetwork->head; it != NULL; it = it->next)
            {
                addEdge(g, i + 1, it->value + 1);
            }
        }
    }
    return g;
}

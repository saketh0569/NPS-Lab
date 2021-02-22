// distance vector routing protocol
// drawback: it can't solve the graph if it contains a negative weighted cycle in it

#include <stdio.h>
#include <stdlib.h>
int A[10][10], n, d[10], p[10];

void Bellmanford()
{
    int i, u, v;
    for (i = 1; i < n; i++)
    {
        for (u = 0; u < n; u++)
        {
            for (v = 0; v < n; v++)
            {
                if (d[v] > d[u] + A[u][v])
                {
                    d[v] = d[u] + A[u][v];
                    p[v] = u;
                }
            }
        }
    }
    for (u = 0; u < n; u++)
    {
        for (v = 0; v < n; v++)
        {
            if (d[v] > d[u] + A[u][v])
            {
                printf("Negative Edge\n");
                printf("There is a negative edge");
                exit(0);
            }
        }
    }
}

int main()
{
    printf("Enter the no of vertices (or) nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency martix (or) the cost matrix\n");
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    int source;

    for (source = 0; source < n; source++)
    {
        for (i = 0; i < n; i++)
        {
            d[i] = 999;
            p[i] = -1;
        }
        d[source] = 0;
        Bellmanford();

        // prints all possibility routes of each node
        printf("Router %d \n", source);
        for (i = 0; i < n; i++)
        {
            if (i != source)
            {
                j = i;
                while (p[j] != -1) //checks for unreachable states
                {
                    printf("%d<-", j);
                    j = p[j];
                }
            }
            printf("%d\tCost %d\n\n", source, d[i]);
        }
    }
    return 0;
}
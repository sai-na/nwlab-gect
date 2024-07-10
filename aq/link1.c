#include <stdio.h>
#define infinity 9999

int n, count, start, costMatrix[20][20];
int dist[20]; // shortest distances from starting node to each node
int visited[20];
int prev[20];

void readCostMatrix()
{
    printf("Enter cost matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int d;
            scanf("%d", &d);
            costMatrix[i][j] = d == 0 ? infinity : d;
        }
    }
}

void dijk()
{
    // initializing all arrays
    for (int i = 0; i < n; i++)
    {
        dist[i] = costMatrix[start][i];
        visited[i] = 0;
        prev[i] = start;
    }

    // process start node
    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    // process all other nodes
    while (count < n - 1)
    {
        // calculate minimum distance
        int min = infinity, next;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                next = i;
            }
        }
        visited[next] = 1;

        // apply dijkstra's equation to update dist with shortest distances
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (dist[i] > min + costMatrix[next][i])
                {
                    dist[i] = min + costMatrix[next][i];
                    prev[i] = next;
                }
            }
        }

        // increment counter to process next node
        count++;
    }
}

void display()
{
    printf("Distance: ");
    for (int i = 0; i < n; i++)
    {
        if (i != start)
        {
            printf("\nDistance to node %d = %d\n", i, dist[i]);
            printf("Path: %d", i);
            int j = i;
            while (j != start)
            {
                j = prev[j];
                printf(" <- %d", j);
            }
            printf("\n");
        }
    }
}

int main()
{
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    readCostMatrix();

    printf("Starting node: ");
    scanf("%d", &start);

    dijk();
    display();
}
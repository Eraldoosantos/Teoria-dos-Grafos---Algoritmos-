 #include <stdio.h>
 #include <stdlib.h>

#define MAX 10
#define INF 99999

void dijkstra(int G[MAX][MAX], int n, int start);

int main()
{
    // G is the grpah that will be used. 
    int G[MAX][MAX], n, start;
    int i, j; 

    // The following lines prompt to user the number of vertices n and the edge's values in G. 
    printf("Please, choose a number of vertices: \n");
    scanf("%d", &n);

    printf("Please, enter the graph: \n");

    // This for loop takes the input from user.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }   
    }

    // Prompt to user which is the initial vertice.
    printf("Please, enter the starting node: \n");
    scanf("%d", &start);

    dijkstra(G, n, start);

    return 0;
    
}

// Dijkstra's algorithm. This function calculates the shortest path between nodes and vertices and find the shortest path, based on the initial vertices and edges' values of weight.   
void dijkstra(int G[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], dist[MAX], visited[MAX], pred[MAX];
    int i, j, count, mindist, nextnode; 


    // Set the "infinite" values to compare between node values. 
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                cost[i][j] = INF;
            }

            else
            {
                cost[i][j] = G[i][j];
            }
            
        }
        
    }

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[start][i]; 
        pred[i] = start;
        visited[i] = 0;
    }
    
    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    // These following lines calulates the distance between the vertices, based on the next node values and the predecessor values. Then, calculate the minimum distance. 
    while (count < n - 1)
    {
        for (i = 0; i < n; i++)
        {
            if (dist[i] < mindist && !visited[i])
            {
                mindist = dist[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for (i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                if((mindist + cost[nextnode][i]) < dist[i])
                {
                    dist[i] = mindist + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }

        count++;
    }
    
    // Print the distance between nodes and print the shortest path. 
    for (i = 0; i < n; i++)
    {
        if(i != start)
        {
            printf("The distance of node %d is %d\n", i, dist[i]);
            printf("The path is: %d", i);

            j = i;

            do
            {
                j = pred[j];
                printf("<-%d", j);

            } while (j != start); 
        }

        printf("\n");
    }
}

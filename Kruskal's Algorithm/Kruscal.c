#include <stdio.h>
#include <stdlib.h>
 
// Adjacency matrix size.

#define MAX 30
 
 // These following lines are related to edge's structures an its datas.

typedef struct edge
{
	int u , v, w;
} edge;
 
typedef struct edge_list
{
	edge data[MAX];
	int n;
} edge_list;
 
edge_list elist;

// G is the adjacency matrix and n is the number of vertices.
 
int G[MAX][MAX],n;
edge_list spanlist;
 
// Functions' prototypes.

void kruskal();
int find(int belongs[],int vertexno);
void union1(int belongs[],int c1,int c2);
void sort();
void print();
 
// Main function

void main()
{
    // i, j are auxiliar variables to store vertices on the matrix. 

	int i, j, total_cost;
	
    // These following lines prompts the user to put values on vertices and the matrix.

	printf("Please, enter number of vertices: \n");
	scanf("%d",&n);
	
	printf("Please, enter the adjacency matrix: \n");
	
	for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
        
    } 

    // Kruskal's function and the output for user.
			
	kruskal();
	print();

} // End of main function.
 
 // Kruskal function to find a Minimum Spaning Tree (MST).

void kruskal()
{
	int belongs[MAX], i, j, column_one, column_two;
	elist.n = 0;
 
    // These following lines creates the edge list of the given graph with theier wights.

	for (i = 1; i < n; i++)
    {
		for (j = 0 ; j < i; j++)
		{
			if(G[i][j] != 0)
			{
				elist.data[elist.n].u = i;
				elist.data[elist.n].v = j;
				elist.data[elist.n].w = G[i][j];
				elist.n++;
			}
		}
    }

    // Sort the edge list according to theier weights.

	sort();
	
	for (i = 0; i < n ;i++)
    {
		belongs[i]=i;
    }
	
	spanlist.n = 0;
	
	for (i = 0; i < elist.n; i++)
	{
		column_one = find(belongs,elist.data[i].u);
		column_two = find(belongs,elist.data[i].v);
		
		if (column_one != column_two)
		{
			spanlist.data[spanlist.n] = elist.data[i];
			spanlist.n = spanlist.n + 1;
			union1(belongs, column_one, column_two);
		}
	}
}
 
int find(int belongs[],int vertexno)
{
	return(belongs[vertexno]);
}
 
void union1(int belongs[],int c1,int c2)
{
	int i;
	
	for (i = 0; i < n; i++)
    {
		if (belongs[i] == c2)
        {
			belongs[i] = c1;
        }
    }
}
 
// This function sorts the edge list according to theier weights by bubble sort method

void sort()
{
	int i, j;
	edge aux;
	
	for (i = 1; i < elist.n; i++)
    {
		for(j = 0; j < elist.n - 1; j++)
        {
			if (elist.data[j].w > elist.data[j + 1].w)
			{
				aux = elist.data[j];
				elist.data[j] = elist.data[j + 1];
				elist.data[j + 1] = aux;
			}
        }
    }
}

// This function prints the columns and the spanning tree's cost
 
void print()
{
	int i, cost = 0;
	
	for (i = 0; i < spanlist.n; i++)
	{
		printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
		
        cost = cost + spanlist.data[i].w;
	}
 
	printf("\n\nCost of the spanning tree is: %d.", cost);
  
}

#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define INF 9999
void printSolution(long int dist[][200],long int n1);
void floydWarshall (long int graph[][200],long int n2)
{
    
  long int dist[200][200], i, j, k;
    
    
    for (i = 0; i < n2; i++)
        for (j = 0; j < n2; j++)
            dist[i][j] = graph[i][j];
    
   
    for (k = 0; k < n2; k++)
    {
        for (i = 0; i < n2; i++)
        {
            
            for (j = 0; j < n2; j++)
            {
               
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    printSolution(dist,n2);
}

void printSolution(long int dist[][200],long int n3)
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < n3; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            if (dist[i][j] == 9999)
                printf("%7s", "INF");
            else
                printf ("%7ld", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
     std::ifstream fp("input1.txt");
    long int graph[200][200],n;
    fp >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {fp >> graph[i][j];
        }
        
       floydWarshall(graph,n);
    return 0;
}




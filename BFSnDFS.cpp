#include <iostream>
using namespace std;

int cost[10][10], i, j, k, node, edge, qu[10], front, rear, v, visit[10], visited[10];

int main()
{
    cout << "Enter number of vertices : ";
    cin >> node;
    cout << "Enter number of edges : ";
    cin >> edge;
    
    cout << "\nEDGES :\n";
    for (k = 1; k <= edge; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    
    
    cout << "The adjacency matrix of the graph is : " << endl;
    for (i = 0; i < node; i++)
    {
        for (j = 0; j < node; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
      cout << "\nThe adjacency list of the graph is:" << endl;
    for (i = 0; i < node; i++) {
        cout << "Vertex " << i << " : ";
        for (j = 0; j < node; j++) {
            if (cost[i][j] == 1) {
                cout<<" -> " << j;  
            }
        }
        cout << endl;
    }

	cout << "Enter initial vertex : ";
    cin >> v;
    cout << "The BFS of the Graph is\n";
    cout << v<<endl;
    visited[v] = 1;
    k = 1;
    while (k < node)
    {
        for (j = 1; j <= node; j++)
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1)
            {
                visit[j] = 1;
                qu[rear++] = j;
            }
        v = qu[front++];
        cout << v << " ";
        k++;
        visit[v] = 0;
        visited[v] = 1;
    }
	cout << endl;
}



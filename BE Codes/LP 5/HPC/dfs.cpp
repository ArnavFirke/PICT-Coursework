#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <omp.h>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void BFS_Sequential(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void BFS_Parallel(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < size; ++i)
            {
                int u = q.front();
                q.pop();
                currentLevel.push_back(u);
                cout << u << " ";
            }

#pragma omp parallel for
            for (int i = 0; i < currentLevel.size(); ++i)
            {
                int u = currentLevel[i];
                for (int v : adj[u])
                {
#pragma omp critical
                    {
                        if (!visited[v])
                        {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }

    void DFS_Sequential(int start)
    {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);

        while (!s.empty())
        {
            int u = s.top();
            s.pop();

            if (!visited[u])
            {
                visited[u] = true;
                cout << u << " ";
                for (int v : adj[u])
                {
                    if (!visited[v])
                    {
                        s.push(v);
                    }
                }
            }
        }
    }

    void DFS_Parallel(int start)
    {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);

        while (!s.empty())
        {
            int u;
#pragma omp critical
            {
                if (!s.empty())
                {
                    u = s.top();
                    s.pop();
                }
                else
                {
                    u = -1;
                }
            }

            if (u != -1 && !visited[u])
            {
#pragma omp critical
                {
                    if (!visited[u])
                    {
                        visited[u] = true;
                        cout << u << " ";
                    }
                }

#pragma omp parallel for
                for (int i = 0; i < adj[u].size(); ++i)
                {
                    int v = adj[u][i];
                    if (!visited[v])
                    {
#pragma omp critical
                        s.push(v);
                    }
                }
            }
        }
    }
};

int main()
{
    int V = 7;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    /*
    0 -------- 1
    |         / \
    |        /   \
    |       /     \
    2 ---- 3       4
    |      |
    |      |
    5      6
*/

    int startNode = 0;
    double startTime, endTime;

    cout << "Sequential BFS: ";
    startTime = omp_get_wtime();
    g.BFS_Sequential(startNode);
    endTime = omp_get_wtime();
    cout << "\nTime: " << endTime - startTime << " seconds\n\n";

    cout << "Parallel BFS: ";
    startTime = omp_get_wtime();
    g.BFS_Parallel(startNode);
    endTime = omp_get_wtime();
    cout << "\nTime: " << endTime - startTime << " seconds\n\n";

    cout << "Sequential DFS: ";
    startTime = omp_get_wtime();
    g.DFS_Sequential(startNode);
    endTime = omp_get_wtime();
    cout << "\nTime: " << endTime - startTime << " seconds\n\n";

    cout << "Parallel DFS: ";
    startTime = omp_get_wtime();
    g.DFS_Parallel(startNode);
    endTime = omp_get_wtime();
    cout << "\nTime: " << endTime - startTime << " seconds\n";

    return 0;
}

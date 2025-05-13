#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int Nodes;
    vector<vector<int>> adjlist;

public:
    Graph(int n) : adjlist(n)
    {
        Nodes = n;
    }
    void add(int n1, int n2)
    {
        adjlist[n1].push_back(n2);
        adjlist[n2].push_back(n1);
    }
    void recDFS(int CurrNode, vector<bool> &visited)
    {
        cout << CurrNode << " ";
        visited[CurrNode] = true;
        for (int Node : adjlist[CurrNode])
        {
            if (!visited[Node])
            {
                recDFS(Node, visited);
            }
        }
    }
    void DFS()
    {
        vector<bool> visited(Nodes, false);

        for (size_t i = 0; i < Nodes; i++)
        {
            if (!visited[i])
            {
                recDFS(i, visited);
                cout << "\n";
            }
        }
    }
    void BFS()
    {
        vector<int> parent(Nodes, -1);
        vector<bool> visited(Nodes, false);
        if (iscyclic(0, visited, parent))
        {
            cout << "Cycle";
        }
        else
            cout << "no cycle";
        cout << endl;
    }
    bool iscyclic(int CurrNode, vector<bool> &visited, vector<int> parent)
    {
        queue<int> q;
        q.push(CurrNode);
        visited[CurrNode] = true;
        while (!q.empty())
        {
            int CNode = q.front();
            q.pop();
            for (int node : adjlist[CNode])
            {
                if (!visited[node])
                {
                    q.push(node);
                    parent[node] = CNode;
                    visited[node] = true;
                }
                else if (parent[CNode] != node)
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Graph g(5);
    g.add(0, 1);
    g.add(0, 2);
    g.add(2, 1);
    g.add(4, 3);
    // g.add(0, 1);
    g.DFS();
    g.BFS();
    return 0;
}
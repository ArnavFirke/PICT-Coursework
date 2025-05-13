#include <bits/stdc++.h>
using namespace std;
class Edge
{
    int to;
    int weight;

public:
    Edge(int t, int w) : to(t), weight(w) {}
    friend class MST;
};

class MST
{
private:
    int edges;
    vector<vector<Edge>> adjlist;

public:
    MST(int n) : edges(n), adjlist(n) {}
    struct compare
    {
        bool operator()(const Edge &a, const Edge &b)
        {
            return a.weight > b.weight;
        }
    };
    void add(int a, int b, int w)
    {
        adjlist[a].push_back({b, w});
        adjlist[b].push_back({a, w});
    }
    void makeMST()
    {
        vector<bool> visited(edges, false);
        vector<int> parent(edges, -1);
        vector<int> distance(edges, INT_MAX);

        priority_queue<Edge, vector<Edge>, compare> pq;
        int start = 0;
        distance[start] = 0;
        pq.push({start, 0});
        while (!pq.empty())
        {
            int currnode = pq.top().to;
            pq.pop();
            visited[currnode] = true;
            for (auto Edges : adjlist[currnode])
            {
                int node = Edges.to;
                int w = Edges.weight;

                if (!visited[node] and w < distance[node])
                {
                    distance[node] = w;
                    pq.push({node, w});
                    parent[node] = currnode;
                    visited[node] = true;
                }
            }
        }

        cout << "MST" << endl;
        for (size_t i = 1; i < edges; i++)
        {
            cout << parent[i] << " - " << i << endl;
        }
    }
};
int main()
{
    MST mt(5);
    mt.add(0, 1, 2);
    mt.add(0, 3, 6);
    mt.add(1, 2, 3);
    mt.add(1, 3, 8);
    mt.add(1, 4, 5);
    mt.add(2, 4, 7);
    mt.add(3, 1, 8);
    mt.makeMST();
    return 0;
}
// MST
// 0 - 1
// 1 - 2
// 0 - 3
// 1 - 4
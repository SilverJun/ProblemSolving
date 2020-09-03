/**
 * Title: 최단 경로
 * Problem no. 1753
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/1753
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <tuple>

using namespace std;

enum {
    MAX_V = 20000,
    MAX_W = 999999999,
};

int V, E;
int graph[MAX_V+1][MAX_V+1] = {0};
int distanceTable[MAX_V+1] = {0};

void dijkstra(int start) {
    // <거리, 노드>
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> minHeap;

    minHeap.push(make_pair(0, start));
    distanceTable[start] = 0;

    while (!minHeap.empty())
    {
        int dist, node;
        tie(dist, node) = minHeap.top();
        minHeap.pop();
        
        if (distanceTable[node] < dist) continue;

        for (int i = 1; i <= V; i++) {
            if (graph[node][i] == MAX_W) continue;
            int cost = dist + graph[node][i];

            if (cost < distanceTable[i]) {
                distanceTable[i] = cost;
                minHeap.push(make_tuple(cost, i));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S;

    cin >> V >> E;
    cin >> S;

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            graph[i][j] = MAX_W;
        }
        distanceTable[i] = MAX_W;
    }

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v], w);
    }

    dijkstra(S);
    
    for (int i = 1; i <= V; i++)
    {
        if (distanceTable[i]!=MAX_W) {
            cout << distanceTable[i] << "\n";
        }
        else {
            cout << "INF\n";
        }
    }
    
    return 0;
}
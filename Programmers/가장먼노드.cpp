#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<bool> check(n+1, false);
    vector<vector<int>> adjList(n+1);
    queue<int> q;

    // convert edge list to adj list
    for (int i = 0; i < edge.size(); i++)
    {
        adjList[edge[i][0]].push_back(edge[i][1]);
        adjList[edge[i][1]].push_back(edge[i][0]);
    }

    int qSize = 0;
    check[1] = true;
    q.push(1);
    // do bfs with degree.
    while (!q.empty())
    {
        qSize = q.size();
        for (size_t i = 0; i < qSize; i++)
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adjList[node])
            {
                if (check[neighbor]) continue;
                q.push(neighbor);
                check[neighbor] = true;
            }
        }
    }

    return qSize;
}

#include <iostream>
int main() {
    auto ret = solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
    cout << ret << "\n";
    return 0;
}

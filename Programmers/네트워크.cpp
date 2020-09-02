#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> check;
vector<vector<int>> graph;
int N;

void BFS(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int com = q.front();
        q.pop();

        for (int i = 0; i < N; i++)
        {
            if (check[i]) continue;
            if (graph[com][i] || graph[i][com]) {
                check[i] = true;
                q.push(i);
            }
        }
        
    }    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph = computers;
    N = n;

    for (int i = 0; i < computers.size(); i++)
    {
        if (!check[i]) {
            BFS(i);
            answer++;
        }
    }

    return answer;
}
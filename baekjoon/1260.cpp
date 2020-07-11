/**
 * Title: DFS와 BFS
 * Problem no. 1260
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/1260
 */

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_VERTEX = 1001;

int N, M, V;
bool G[MAX_VERTEX][MAX_VERTEX] = {false};
bool c[MAX_VERTEX] = {false};

void DFS(int v) {
    cout << v << ' ';
    c[v] = true;
    for(int i=1; i<=N; i++) {
        if(c[i] || !G[v][i]) continue;
        DFS(i);
    }
}

void BFS(int v) {
    queue<int> q;
    q.push(v);

    while(!q.empty()) {
        int v = q.front();
        c[v] = true;
        cout << v << ' ';
        q.pop();
        
        for (int i = 1; i <= N; i++) {
            if(G[v][i] && !c[i]) {
                c[i] = true;
                q.push(i);
            }
        }
    }
    cout << '\n';
    
}

void clear_path() {
    for (int i = 0; i <= N; i++)
    {
        c[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> V;

    int v1, v2;
    
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2;
        G[v2][v1] = G[v1][v2] = true;
    }
    
    DFS(V);
    cout << '\n';
    clear_path();
    BFS(V);

    return 0;
}
/**
 * Title: 플로이드
 * Problem no. 11404
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/11404
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

enum {
    MAX_N = 100,
    MAX_W = 999999999,
};

int N, M;
int graph[MAX_N+1][MAX_N+1] = {0,};

void floyd_warshall() {
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            graph[i][j] = MAX_W;
        }
    }

    for (int i = 1; i <= M; i++)
    {
        int c1, c2, w;
        cin >> c1 >> c2 >> w;
        graph[c1][c2] = min(graph[c1][c2], w);
    }
    
    floyd_warshall();

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i==j || graph[i][j] == MAX_W) cout << "0 ";
            else cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
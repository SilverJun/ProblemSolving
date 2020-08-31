#include <string>
#include <vector>

#include <iostream>

using namespace std;

// 플로이드 워셜 알고리즘 사용.
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    const int V = 101;
    int dist[V][V] = {0}, i, j, k;
    
    for (int i = 0; i < results.size(); i++)
    {
        dist[results[i][0]][results[i][1]] = 1;
        dist[results[i][1]][results[i][0]] = -1;
    }

    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] > 1) {
                    dist[i][j] = 1;
                    dist[j][i] = -1;
                }
                else if (dist[i][k] + dist[k][j] < -1) {
                    dist[i][j] = -1;
                    dist[j][i] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] != 0) cnt++;
        }
        //cout << cnt << "\n";
        if (cnt == n-1) answer++;
    }
    

    return answer;
}

int main() {
    auto ret = solution(5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}});
    
    cout << ret << "\n";
    
    return 0;
}
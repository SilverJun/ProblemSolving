/**
 * Title: 숨바꼭질
 * Problem no. 1697
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/1697
 */

#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int MAX_VERTEX = 100001;

int N, K;
// bool G[MAX_VERTEX] = {false};
bool c[MAX_VERTEX] = {false};

// BFS로 풀면 되겠다.
// 첫번째 경로에서 +, -, 2*x 이동 경우를 큐에 넣음.
// 큐에서 빼내서 또 3경우를 큐에 넣음.
// 가능한 길을 전부 큐에 넣고 평가하고 제거하고 반복.

int BFS() {
    int i;
    int d = 0; // depth
    queue<int> q;
    q.push(N);

    while(!q.empty()) {
        const int size = q.size();
        for (i = 0; i < size; i++)
        {
            int v = q.front();
            c[v] = true;
            q.pop();

            if (K == v)
                goto EXIT;
            
            if (v+1 <= MAX_VERTEX-1 && !c[v+1]) {
                //cout << d << ": " << v+1 << '\n';
                q.push(v+1);
            }
            if (v*2 <= MAX_VERTEX-1 && !c[v*2]) {
                //cout << d << ": " << v*2 << '\n';
                q.push(v*2);
            }
            if (v-1 >= 0 && !c[v-1]) {
                //cout << d << ": " << v-1 << '\n';
                q.push(v-1);
            }
        }
        d++;
    }
EXIT:
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    cout << BFS() << '\n';
    
    return 0;
}
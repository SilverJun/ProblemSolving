/**
 * Title: 1로 만들기
 * Problem no. 1463
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/1463
 */

#include <iostream>
#include <queue>

using namespace std;

const int LIMIT = 1000000;

bool c[LIMIT+1] = {0};

int BFS(int x) {
    int d = 0;
    int next = 0;
    queue<int> q;
    q.push(x);

    while (!q.empty())
    {
        const int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            int v = q.front();
            c[v] = true;
            q.pop();
            
            if (v == 1) {
                return d;
            }
            next = v/3;
            if (v%3 == 0 && !c[next]) {
                
                c[next] = true;
                q.push(next);
            }
            next = v/2;
            if (v%2 == 0 && !c[next]) {
                c[next] = true;
                q.push(v/2);
            }
            next = v-1;
            if (v-1 > 1 && !c[next]) {
                c[next] = true;
                q.push(v-1);
            }
        }
        d++;
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    cout << BFS(x) << '\n';

    return 0;
}

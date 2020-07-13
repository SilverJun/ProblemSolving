/**
 * Title: 벽 부수고 이동하기
 * Problem no. 2206
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/2206
 */

#include <iostream>
#include <string>
#include <tuple>
#include <queue>

using namespace std;

const int MAX_VERTEX = 1000;

int N, M;
int d = 0; // distance
bool G[MAX_VERTEX + 1][MAX_VERTEX + 1] = { 0 };
bool c[MAX_VERTEX + 1][MAX_VERTEX + 1][2] = { 0 };
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void BFS() {
    queue<tuple<int, int, int>> q;
    int x;
    int y;
    int px;
    int py;
    int pcrash;
    int i;
    int cases;
    q.push({0, 0, false});
    c[0][0][0] = true;

    while (!q.empty())
    {
        d++;
        const int qsize = q.size();
        for (i = 0; i < qsize; i++)
        {
            tie(px, py, pcrash) = q.front();
            x = px;
            y = py;
            q.pop();
            
            if (x == M-1 && y == N-1) {
                cout << d << "\n";
                return;
            }

            for (cases = 0; cases < 4; cases++)
            {
                x = px + dx[cases];
                y = py + dy[cases];
                if (x<0 || y<0 || x>M-1 || y>N-1 || c[x][y][pcrash]) continue;

                if (!G[y][x]) {
                    c[x][y][pcrash] = 1;
                    q.push(make_tuple(x, y, pcrash));
                }
                else if (!pcrash) {
                    c[x][y][pcrash] = 1;
                    q.push(make_tuple(x, y, 1));
                }
            }
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //scanf("%d %d", &N, &M);
    cin >> N >> M;

    string t;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        for (int j = 0; j < M; j++)
        {
            G[i][j] = t[j] - '0';
        }
    }

    BFS();
    return 0;
}

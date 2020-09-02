/**
 * Title: 연구소
 * Problem no. 14502
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/14502
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cstring>
#include <array>

using namespace std;

enum {
    Way,
    Wall,
    Virus,
};

const int MAX = 8;

using board_t = array<array<int, MAX>, MAX>;
using check_t = array<array<bool, MAX>, MAX>;

int N, M;
board_t board;
int max_result = 0;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void sim_virus(board_t board) {
    queue<tuple<int, int>> q;
    check_t ck = {{false}};

    for (int y = 0; y < N; y++) // 보드에 있는 바이러스 좌표들을 큐에 미리 넣음.
    {
        for (int x = 0; x < M; x++)
        {
            if (board[y][x] == Virus)
                q.push(make_tuple(x, y));
        }
    }

    // BFS 시작
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (0 > newX || newX >= M || 0 > newY || newY >= N) continue; // check boundary
            if (board[newY][newX] != Way || ck[newY][newX]) continue; // check it is not Way
            ck[newY][newX] = true;
            board[newY][newX] = Virus;
            q.push(make_tuple(newX, newY));
        }
    }
    
    int count = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            //cout << board[y][x];
            if (board[y][x] == Way) count++;
        }
        //cout << '\n';
    }
    //cout << '\n';
    max_result = max(max_result, count);
}

// 벽을 만들 3개의 후보를 DFS로 선택한다.
void DFS(int depth, int j, int i) {
    if (depth == 3) {
        sim_virus(board);
        return;
    }

    for (int y = i; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (board[y][x] != Way) continue;

            board[y][x] = Wall;
            DFS(depth + 1, x, y);
            board[y][x] = Way;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    
    //sim_virus(board);
    DFS(0, 0, 0);

    cout << max_result << '\n';

    return 0;
}

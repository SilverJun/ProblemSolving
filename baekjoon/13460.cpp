/**
 * Title: 구슬 탈출 2
 * Problem no. 13460
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/13460
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

typedef struct {
    int x;
    int y;
} pos;

enum {
    Way = '.',
    Wall = '#',
    Red = 'R',
    Blue = 'B',
    Hole = 'O',
};

const int MAX = 10;

// 중력을 사용해 두 개의 공을 동시에 한 쪽 방향으로 이동시킴.
// 파란 공이 구멍에 들어가면 게임오버, 빨간공과 동시에 들어가도 게임오버 -> -1 리턴
// 10회 이상 걸리면 게임오버 -> -1 리턴
// 빨간공만 구멍으로 나와야 함 -> 최소 행동 횟수를 반환하도록
// R 또는 B 둘중에 하나만 이동가능해도 큐에 넣기.
// 세로 크기는 N, 가로 크기는 M
int N, M;
char board[MAX][MAX] = {'\0'};
const pos dir[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

// 다녀온 곳 추천
bool check[2][MAX][MAX] = {false}; // 0 = R, 1 = B

// c를 d방향으로 벽 닿을때 까지 이동, 홀에 들어가면 true 반환.
bool move(pos& c, const pos& d) {
    pos temp = {c.x + d.x, c.y + d.y};
    char type = board[temp.y][temp.x];
    while (Way == type)
    {
        //swap(temp, c);
        c.x = temp.x;
        c.y = temp.y;
    }
    if (type == Hole) {
        return true;
    }
    return false;
}

int BFS(pos R, pos B, pos O) {
    queue<tuple<pos, pos>> q;
    q.push(make_tuple(R, B));
    int d = 1;
    pos curR, curB, nextR, nextB;
    bool canRMove;
    bool canBMove;
    bool isRMoved;
    bool isBMoved;
    bool isRReachHole = false;
    bool isBReachHole = false;

    while (!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            tie(R, B) = q.front();
            q.pop();
            //cout << "Q R: " << R.x << ":" << R.y << ", Q B: " << B.x << ":" << B.y << '\n';

            // 4방향으로 다음 칸이 벽이 아니고 Blue가 홀에 들어가지 않으면 (R,B)를 방향대로 이동하고 큐에 넣음.
            for (int k = 0; k < 4; k++)
            {
                isRReachHole = false;
                isBReachHole = false;
                curR.x = R.x;
                curR.y = R.y;
                curB.x = B.x;
                curB.y = B.y;

                nextR.x = R.x + dir[k].x;
                nextR.y = R.y + dir[k].y;
                nextB.x = B.x + dir[k].x;
                nextB.y = B.y + dir[k].y;

                //cout << "dir: " << dir[k].x << ":" << dir[k].y << '\n';

                canRMove = (Wall != board[nextR.y][nextR.x]
                        && !(nextR.x == B.x && nextR.y == B.y));
                canBMove = (Wall != board[nextB.y][nextB.x]
                        && !(nextB.x == R.x && nextB.y == R.y));

                //cout << "Can R move: " << canRMove << ", Can B move: " << canBMove << '\n';
                if (!canRMove && !canBMove) {
                    continue;
                }

                do {
                    if (canRMove) {
                        curR.x = nextR.x;
                        curR.y = nextR.y;
                        nextR.x += dir[k].x;
                        nextR.y += dir[k].y;
                    }
                    if (canBMove) {
                        curB.x = nextB.x;
                        curB.y = nextB.y;
                        nextB.x += dir[k].x;
                        nextB.y += dir[k].y;
                    }
                    if (curB.x == O.x && curB.y == O.y) {
                        isBReachHole = true;
                        curB.x = 0;
                        curB.y = 0;
                    }
                    if (curR.x == O.x && curR.y == O.y) {
                        isRReachHole = true;
                        curR.x = 0;
                        curR.y = 0;
                    }

                    canRMove = (Wall != board[nextR.y][nextR.x]
                            && !(nextR.x == curB.x && nextR.y == curB.y));
                    canBMove = (Wall != board[nextB.y][nextB.x]
                            && !(nextB.x == curR.x && nextB.y == curR.y));

                    //cout << "R: " << curR.x << ":" << curR.y << ", B: " << curB.x << ":" << curB.y << '\n';
                } while(canRMove || canBMove);
                
                // cout << isBReachHole << ", " << isRReachHole << '\n';
                // cout << "R: " << curR.x << ":" << curR.y << ", B: " << curB.x << ":" << curB.y << '\n';

                if (isBReachHole) continue; // blue공이 구멍으로 들어가면 실패니까 큐에 넣지 않고 스킵
                if (isRReachHole) return d; // blue가 들어가지 않고 red가 들어가면 성공.

                //cout << check[0][curR.y][curR.x] << ", " << check[1][curB.y][curB.x] << ", " << (!check[0][curR.y][curR.x] || !check[1][curB.y][curB.x]) << '\n';
                
                // 왔던 길 중복체크하면 안됌!!!! 다시 돌아가야할 때가 생기기 때문이다.
                
                //if (!(check[0][curR.y][curR.x] && check[1][curB.y][curB.x])) {
                    //check[0][curR.y][curR.x] = check[1][curB.y][curB.x] = true;
                q.push(make_tuple(curR, curB));
                    //cout << "push! R: " << curR.x << ":" << curR.y << ", B: " << curB.x << ":" << curB.y << '\n';
                //}
            }
            //cout << "-----\n";
        }
        d++;
        if (d > MAX) return -1;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    pos R;
    pos B;
    pos O;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            switch (board[i][j]) {
                case Red:
                R.x = j;
                R.y = i;
                board[i][j] = '.';
                break;
                case Blue:
                B.x = j;
                B.y = i;
                board[i][j] = '.';
                break;
                case Hole:
                O.x = j;
                O.y = i;
                break;
            }
        }
    }

    // 보드 제대로 받는지 확인 
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << board[i][j]; 
    //     }
    //     cout << '\n';
    // }

    // BFS로 풀기.
    cout << BFS(R, B, O) << '\n';

    return 0;
}

/*
6 8
########
##.#.#.#
#...O#.#
#.#..###
#B#R#..#
########
*/
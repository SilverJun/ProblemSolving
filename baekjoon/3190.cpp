/**
 * Title: 뱀
 * Problem no. 3190
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/3190
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int LIMIT = 100;

int N; // 보드 크기
int K; // 사과 갯수
int L; // 뱀의 방향 변환 횟수

enum {
    EMPTY,
    APPLE,
    SNAKE,
};

int board[LIMIT][LIMIT] = {SNAKE};

enum {
    RIGHT,
    DOWN,
    LEFT,
    UP,
    COUNT
};

// const char* DIR[] = {
//     "RIGHT",
//     "DOWN",
//     "LEFT",
//     "UP",
// };

typedef struct {
    int x;
    int y;
} pos_t;
pos_t snake[LIMIT+1] = {{0,0},};
int snake_len = 1;

const pos_t dir[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int snake_dir = RIGHT;

const int MAX_COMMAND = 10000;
char command_list[MAX_COMMAND+1] = {'\0'};

int phase = 0;

// void print_board() {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             cout << board[i][j];
//         }
//         cout << '\n';
//     }
//     cout << "--------" << '\n';
// }

void change_dir(char d) {
    switch (d)
    {
    case 'L': // left
        snake_dir--;
        break;
    case 'D': // right
        snake_dir++;
        break;
    default:
        break;
    }
    snake_dir = (snake_dir & (COUNT-1)); // bound 처리.
}

bool snake_move() {
    pos_t last = snake[snake_len-1]; // 맨 끝에꺼는 따로 복사해둠.
    for (int i = snake_len-1; i > 0; i--) // 꼬리들 따라오기.
    {
        snake[i] = snake[i-1];
    }

    snake[0].x += dir[snake_dir].x; // 헤드처리
    snake[0].y += dir[snake_dir].y;

    if (0 > snake[0].x || N <= snake[0].x || 0 > snake[0].y || N <= snake[0].y) // boundary check
        return true;

    // check
    switch (board[snake[0].y][snake[0].x]) // head 처리
    {
    case EMPTY:
        board[snake[0].y][snake[0].x] = SNAKE;
        board[last.y][last.x] = EMPTY;
        break;
    case APPLE:
        board[snake[0].y][snake[0].x] = SNAKE;
        snake[snake_len] = last;
        snake_len++;
        break;
    case SNAKE:
        return true;
    default:
        break;
    }
    
    return false;
}

int simulation() {
    while (true)
    {
        //cout << "phase: " << phase << '\n';
        //cout << DIR[snake_dir] << '\n';
        //print_board();
        phase++;
        if (snake_move()) {
            return phase;
        }
        change_dir(command_list[phase]);
    }
    return phase;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> y >> x;
        board[y-1][x-1] = APPLE;
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int t = 0;
        cin >> t;
        cin >> command_list[t];
    }
    
    cout << simulation() << '\n';

    return 0;
}

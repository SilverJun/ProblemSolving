/**
 * Title: 2048 (Easy)
 * Problem no. 12100
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/12100
 */

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

enum {
    RIGHT,
    DOWN,
    LEFT,
    UP,
    COUNT
};

const int LIMIT = 20;
using board_t = array<array<int, LIMIT>, LIMIT>;
using check_t = array<array<bool, LIMIT>, LIMIT>;
int N;
int max_val = 0;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void print_board(board_t& board) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

inline void move(board_t& board, int i, int j, int dir, check_t& check) {
    if (0 == board[i][j]) return;

    // move to dir
    int curX = j;
    int curY = i;
    int newX;
    int newY;
    for (newX = j+dx[dir], newY = i+dy[dir];
        (newX >= 0 && newX < N) && (newY >= 0 && newY < N);
        curX = newX, curY = newY,
        newX += dx[dir], newY += dy[dir])
    {
        if (0 == board[newY][newX]) {
            // cout << "cur: " << curX << ", " << curY << '\n';
            // cout << "next: " << newX << ", " << newY << '\n';
            board[newY][newX] = board[curY][curX];
            board[curY][curX] = 0;
        }
        else if (check[newY][newX]) {
            return;
        }
        else if (board[curY][curX] == board[newY][newX]) {
            board[curY][curX] = 0;
            board[newY][newX] *= 2;
            check[newY][newX] = true;
            // cout << "merged: " <<  newX << ", " << newY << " = " << board[newY][newX] << '\n';
            max_val = max(max_val, board[newY][newX]);
            return;
        }
        else {
            // cout << "cur: " << curX << ", " << curY << " = " << board[curY][curX] << '\n';
            // cout << "next: " << newX << ", " << newY << " = " << board[newY][newX] << '\n';
            return;
        }
    }
}

board_t update_board(board_t board, int dir) {
    check_t check = {false};
    switch (dir)
    {
    case RIGHT:
        for (int i = 0; i < N; i++)
        {
            for (int j = N-2; j >= 0; j--)
            {
                move(board, i, j, dir, check);
            }
        }
        break;
    case DOWN:
        for (int i = N-2; i >= 0; i--)
        {
            for (int j = 0; j < N; j++)
            {
                move(board, i, j, dir, check);
            }
        }
        break;
    case LEFT:
        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < N; j++)
            {
                move(board, i, j, dir, check);
            }
        }
        break;
    case UP:
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                move(board, i, j, dir, check);
            }
        }
        break;
    }

    // print_board(board);

    return board;
}

void solve(board_t board, int depth) {
    if (depth == 5) return;

    for (int i = 0; i < COUNT; i++)
    {
        //cout << depth << '\n';
        //print_board(board);
        solve(update_board(board, i), depth+1);
        //cout << depth << '\n';
        //print_board(board);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    board_t game_board = {0};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> game_board[i][j];
            max_val = max(max_val, game_board[i][j]);
        }
    }
    
    // for loop를 5중으로 돌리고 0~4까지 일일이 체크하면 가능
    solve(game_board, 0);

    cout << max_val << '\n';

    // for test
    // cout << "before" << '\n';
    // print_board(game_board);

    // game_board = update_board(game_board, RIGHT);
    
    // cout << "after" << '\n';
    // print_board(game_board);

    return 0;
}

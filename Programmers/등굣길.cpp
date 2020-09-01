#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    enum { MAX_SIZE = 101, MOD = 1000000007 };
    bool isPuddle[MAX_SIZE][MAX_SIZE] = {false};
    int board[MAX_SIZE][MAX_SIZE] = {{0, 0},{0, 1}};
    
    // copy puddles data
    for (int i = 0; i < puddles.size(); i++)
    {
        isPuddle[puddles[i][1]][puddles[i][0]] = true;
    }
    
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            // boundary check
            if (!isPuddle[y][x-1]) {
                board[y][x] = (board[y][x] + board[y][x-1]) % MOD;
            }
            if (!isPuddle[y-1][x]) {
                board[y][x] = (board[y][x] + board[y-1][x]) % MOD;
            }
        }
    }

    return board[n][m] % MOD;
}

#include <iostream>
int main() {
    auto ret = solution(4, 3, {{2, 2}});
    cout << ret << "\n"; // 4
    return 0;
}

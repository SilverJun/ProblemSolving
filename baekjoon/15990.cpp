/**
 * Title: 1, 2, 3 더하기 5
 * Problem no. 15990
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/15990
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LIMIT = 100000;
const int MOD = 1000000009;
long long dp[LIMIT+1][4] = {0}; // D[n][i] 는 마지막에 오는 수가 i일 때, 1,2,3의 합으로 정수 n을 만드는 경우의 수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // setup base case
    // dp(1) = (1)
    // dp(2) = (2)
    // dp(3) = (1 + 2), (2 + 1), (3)
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    // solve dp first
    for (int i = 4; i <= LIMIT; i++)
    {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
    }
    
    // print out answer
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n = 0;
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << '\n';
    }

    return 0;
}

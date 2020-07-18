/**
 * Title: 2xn 타일링
 * Problem no. 11726
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/11726
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 10007;
const int LIMIT = 1000;

// dp[n][0] = 2*n 크기 맨 마지막을 가로로 마감하는 경우의 수 = dp[n-2][0] + dp[n-2][1]
// dp[n][1] = 2*n 크기 맨 마지막을 세로로 마감하는 경우의 수 = dp[n-1][0] + dp[n-1][1]
int dp[LIMIT+1][2] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // init base cases.
    dp[1][1] = dp[2][0] = dp[2][1] = 1;
    
    for (int i = 3; i <= N; i++)
    {
        dp[i][0] = (dp[i-2][0] + dp[i-2][1])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1])%MOD;
    }
    
    cout << (dp[N][0] + dp[N][1])%MOD << '\n';

    return 0;
}

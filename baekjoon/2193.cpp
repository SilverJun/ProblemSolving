/**
 * Title: 이친수
 * Problem no. 2193
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/2193
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LIMIT = 90;

// dp 1은 1, dp 2는 10임.
// 끝이 0으로 끝나면 다음에는 0과 1로 분화되어서 넘어가고, 끝이 1이면 0으로 넘어감.
long long dp[LIMIT+1][2] = {0}; // d[n][b] = n자리수 b로 끝나는 이친수의 경우의수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    dp[1][1] = 1;
    dp[2][0] = 1;
    
    for (int i = 3; i <= N; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    
    cout << dp[N][0] + dp[N][1] << '\n';

    return 0;
}

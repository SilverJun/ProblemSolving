/**
 * Title: 합분해
 * Problem no. 2225
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/2225
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 1000000000;
const int MAX_N = 200;
const int MAX_K = 200;

// 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[MAX_K+1][MAX_N+1] = {0,}; // dp[K][N] = K자리수로 N을 만들 수 있는 경우의 수

    int N, K;
    cin >> N >> K;

    // init base cases.
    for (int i = 0; i <= N; i++) // 자릿수 하나 짜리는 만들 합으로 만들 수 있는 경우의 수가 한개임.
    {
        dp[1][i] = 1;
    }

    for (int i = 1; i <= K; i++) // 자릿수
    {
        for (int j = 0; j <= N; j++) // 수
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j-k])%MOD;
            }
        }
    }

    // for (int i = 1; i <= K; i++)
    // {
    //     for (int j = 0; j <= N; j++)
    //     {
    //         cout << dp[i][j] << ", ";
    //     }
    //     cout << '\n';
    // }
    
    cout << dp[K][N]%MOD << '\n';

    return 0;
}

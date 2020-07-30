/**
 * Title: 오르막 수
 * Problem no. 11057
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/11057
 */

#include <iostream>
#include <numeric>

using namespace std;

enum { MAX_N = 1000, MOD = 10007 };

int dp[MAX_N+1][10] = {{0,}, {1,1,1,1,1,1,1,1,1,1}, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, result = 0;
    cin >> N;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j]+dp[i-1][k])%MOD;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        result = (result + dp[N][i])%MOD;
    }
    
    cout << result << '\n';
    
    return 0;
}

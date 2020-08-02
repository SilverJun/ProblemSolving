/**
 * Title: 동전 1
 * Problem no. 2293
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/2293
 */

#include <iostream>
#include <numeric>

using namespace std;

enum { MAX_N = 100, MAX_K = 10000 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int coin[MAX_N] = {0};

    int dp[MAX_K+1]= {1};
    int N, K;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> coin[i];
    }

    // dp[n] = dp[K-i] + dp[i] i는 코인으로.

    for (int i = 0; i < N; i++) {
        for (int j = coin[i]; j <= K; j++) { // j는 정해진 코인
            if (j - coin[i] >= 0) {
                dp[j] += dp[j - coin[i]]; // 정해진 코인 + 나머지 경우의 수
            }
        }
    }
    
    cout << dp[K] << '\n';

    return 0;
}

/**
 * Title: 카드 구매하기
 * Problem no. 11052
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/11052
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
const int MAX_P = 10000;

int P[MAX_N + 1] = {0};
int dp[MAX_N + 1] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
    }
    
    // solve dp[N] = max(dp[N] , dp[N-i] + p[i])
    for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i-j] + P[j]);
		}
	}

    cout << dp[N] << '\n';
    
    return 0;
}

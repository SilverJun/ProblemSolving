/**
 * Title: 포도주 시식
 * Problem no. 2156
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/2156
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_LENGTH = 10000;
int e[MAX_LENGTH+3] = {0};
int dp[MAX_LENGTH+3] = {0};
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 3; i < N+3; i++)
    {
        cin >> e[i];
    }

    for (int i = 3; i < N+3; i++) {
        dp[i] = max(dp[i-3] + e[i-1] + e[i], dp[i-2] + e[i]); // XOO, OXO
        dp[i] = max(dp[i-1], dp[i]); // OOX
    }
    
    cout << dp[N+2] << '\n';

    return 0;
}

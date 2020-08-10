/**
 * Title: 크리보드
 * Problem no. 11058
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/11058
 */

#include <iostream>
#include <algorithm>

using namespace std;

enum { MAX_N = 100};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long dp[MAX_N+1] = {0,1,2,3,4,5,6,0,};
    int N;

    cin >> N;

    for(int i = 7; i <= N; ++i) {
        dp[i] = dp[i-1]+1;
        for(int j = 1; j < i-2; ++j) // CA, CC하고 CV * j번 하는 경우
            dp[i] = max(dp[i], dp[j] * (i-j-1));
    }

    cout << dp[N] << '\n';

    return 0;
}

/**
 * Title: 점프
 * Problem no. 1890
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/1890
 */

#include <iostream>

using namespace std;

enum { LIMIT = 101 };

int N = 0;
int arr[LIMIT][LIMIT] = {0};
long long dp[LIMIT][LIMIT] = {0};

long long solve() {
    dp[0][0] = 1;
    for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){ // 오른쪽 먼저 여행
            if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;

			int next = arr[i][j];

			if (i + next < N) {
				dp[i + next][j] += dp[i][j];
            }
			if (j + next < N) {
				dp[i][j + next] += dp[i][j];
            }
		}
	}
    return dp[N-1][N-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
        for (int j = 0; j < N; j++)
        {
		    cin >> arr[i][j];
        }
	}

    cout << solve() << '\n';
    
	return 0;
}


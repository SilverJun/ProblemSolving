/**
 * Title: 퇴사
 * Problem no. 14501
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/14501
 */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int LIMIT = 15;
const int T_MAX = 5;
const int P_MAX = 1000;

int N = 0;
int T[LIMIT] = { 0 };
int P[LIMIT] = { 0 };

int dp[LIMIT + 1] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> T[i] >> P[i];
	}

	for (int i = N - 1; i >= 0; --i)
	{
		if (N < i + T[i])
			dp[i] = dp[i + 1];
		else
			dp[i] = max(P[i] + dp[i+T[i]], dp[i+1]);
	}

	cout << dp[0] << '\n';

	return 0;
}

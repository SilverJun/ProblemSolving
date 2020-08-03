/**
 * Title: 팰린드롬?
 * Problem no. 10942
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/10942
 */

#include <iostream>
#include <cmath>

using namespace std;

enum { LIMIT = 2000 };

int N, M;
int num[LIMIT+1] = {0};
bool check[LIMIT+1][LIMIT+1] = {0};
bool isPalindrome[LIMIT+1][LIMIT+1] = {0}; // isPalindrome[S][E] = S부터 E까지 펠린드롬인지

bool dp(int S, int E) {
    if (S >= E) return true;
    if (check[S][E]) return isPalindrome[S][E];

    check[S][E] = true; // 이미 해결한 subproblem 확인용.
    isPalindrome[S][E] = (num[S]==num[E]) && dp(S+1, E-1); // 처음과 끝이 같은지 비교 후 가운데 남은 부분을 재귀적으로 호출.

    return isPalindrome[S][E];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
        cin >> num[i];
	}

    cin >> M;
    cout << noboolalpha;

    for (int i = 0; i < M; i++)
    {
        int S, E;
        cin >> S >> E;
        cout << dp(S, E) << '\n';
    }
    
	return 0;
}


/**
 * Title: 구슬 탈출 2
 * Problem no. 13460
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/13460
 */

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

enum { MAX_N = 3, MAX_LIFE = 60 };

int N;

int min_count[MAX_LIFE+1][MAX_LIFE+1][MAX_LIFE+1] = {0};

int dp(int first, int second, int third) {
    if (first <= 0 && second <= 0 && third <= 0) return 0;

    // 음수를 0으로 바꿔주기
    if (first < 0) first = 0;
    if (second < 0) second = 0;
    if (third < 0) third = 0;

    // 현재 케이스의 min_count값
    int& cur_case = min_count[first][second][third];
    if (cur_case > 0) return cur_case;


    int cases[3] = {0};
    // 9 3 1
    // 9 1 3
    cases[0] = min(dp(first - 9, second - 3, third - 1) + 1, dp(first - 9, second - 1, third - 3) + 1);

    // 3 9 1
    // 3 1 9

    cases[1] = min(dp(first - 3, second - 9, third - 1) + 1, dp(first - 3, second - 1, third - 9) + 1);

    // 1 9 3
    // 1 3 9

    cases[2] = min(dp(first - 1, second - 9, third - 3) + 1, dp(first - 1, second - 3, third - 9) + 1) ;

    cur_case = *min_element(cases, cases + 3);
    return cur_case;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    array<int, MAX_N> SCV = {0};
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> SCV[i];
    }
    
    cout << dp(SCV[0], SCV[1], SCV[2]) << '\n';
    return 0;
}

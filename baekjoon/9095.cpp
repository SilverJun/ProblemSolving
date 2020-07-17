/**
 * Title: 1, 2, 3 더하기
 * Problem no. 9095
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/9095
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int record[11] = {0, 1, 2, 4}; // 무조건 1,2,3의 합으로 나타내야 함....

int dp(int n) {
    if (record[n]) return record[n];
    record[n] = dp(n-3) + dp(n-2) + dp(n-1);
    return record[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n = 0;
        cin >> n;
        cout << dp(n) << '\n';
    }

    return 0;
}

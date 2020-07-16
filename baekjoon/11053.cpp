/**
 * Title: 가장 긴 증가하는 부분 수열
 * Problem no. 11053
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/11053
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_LENGTH = 1000;
int e[MAX_LENGTH] = {0};
int dp[MAX_LENGTH] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> e[i];
    }
    
    int maxD = 0;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) { // N^2 compare
            if (e[i] > e[j]) {
                dp[i] = max(dp[i], dp[j] + 1); // d[i] = arr[i]까지의 최장 길이
            }
        }
        maxD = max(maxD, dp[i]);
    }
    
    cout << maxD << '\n';

    return 0;
}

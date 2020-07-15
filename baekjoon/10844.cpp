/**
 * Title: 쉬운 계단 수
 * Problem no. 10844
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/10844
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_LENGTH = 100000;
int elem[MAX_LENGTH] = {0};
int sum[MAX_LENGTH] = {0};
int ms = -1000;
int N;

void dp() {
    long t = 0;
    ms = sum[0] = elem[0];
    for (int i = 1; i < N; i++)
    {
        sum[i] = max(sum[i-1] + elem[i], elem[i]); // select maximum sub-sum
        ms = max(ms, sum[i]); // update maximum sub-sum
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> elem[i];
    }
    dp();
    
    cout << ms << '\n';

    return 0;
}

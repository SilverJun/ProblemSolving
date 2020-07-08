/**
 * Title: GCD 합
 * Problem no. 9613
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/9613
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 유클리드 호제법 사용
int GCD(int A, int B)
{
    int n = A%B;
    if (n==0) return B;
	return GCD(B, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        int N;
        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        long long sum = 0;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                sum += GCD(arr[i], arr[j]);

        cout << sum << "\n";
    }

    return 0;
}
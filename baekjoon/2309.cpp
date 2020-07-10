/**
 * Title: 일곱 난쟁이
 * Problem no. 2309
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/2309
 */

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int ELEM_COUNT = 9;

    array<int, ELEM_COUNT> arr;

    // boute-forcely find sum 100
    int sum = 0;
    for (int i = 0; i < ELEM_COUNT; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());
    int i;
    int j;
    for (i = 0; i < ELEM_COUNT; i++)
    {
        for (j = i+1; j < ELEM_COUNT; j++)
        {
            if (100 == sum - arr[i] - arr[j]) {
                //cout << arr[i] << ", " << arr[j] << '\n';
                goto EXIT; // break nasted for loop
            }
        }
    }

EXIT:
    for (int x = 0; x < ELEM_COUNT; x++)
    {
        if (x != i && x != j)
            cout << arr[x] << '\n';
    }

    return 0;
}
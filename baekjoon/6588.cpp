/**
 * Title: 골드바흐의 추측
 * Problem no. 6588
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/6588
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> primes;

// n보다 작은 소수를 구함, 에라토스테네스의 체 사용.
void get_prime(int n)
{
    // setup numbers
    vector<int> n_list(n, 0);
    
    for (int i = 0; i < n_list.size(); i++) // 0...n
        n_list[i] = i;

    n_list[1] = 0; // 1 없앰
    for (int i = 2; i < n; i++)
    {
        if (n_list[i] == 0) continue;
        primes.push_back(n_list[i]);
        for (int j = i+i; j < n; j+=i) // 배수 찾아서 지우기
            n_list[j] = 0;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    get_prime(1000000);

    while(true)
    {
        int n;
        cin >> n;

        if (n == 0) break;

        int p = 0;

        while (primes[p] < n)
        {
            auto val = n - primes[p];
            if (binary_search(primes.begin(), primes.end(), val)) {
                cout << n << " = " << primes[p] << " + " << val << "\n";
                break;
            }
            p++;
        }
    }

    return 0;
}

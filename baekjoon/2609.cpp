/**
 * Title: 최대공약수와 최소공배수
 * Problem no. 2609
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/2609
 */

#include <iostream>

using namespace std;

int GCD(int num1, int num2)
{
    int min = num1 > num2 ? num2:num1; // 작은 수를 가져간다. 24랑 18이면 GCD는 적어도 18보다 작음.
    for (int i = min; i >= 1; --i) // 18부터 하나씩 계산하기 시작한다.
    {
        if (num1%i==0 && num2%i==0) // 둘 다 나누어 떨어지는가?
            return i;
    }
    return 1;
}

// 유클리드 호제법 사용
int EucGCD(int num1, int num2)
{
    int n = num1 % num2;
    if (n == 0) return num2;
    return EucGCD(num2, n);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a, b;

    cin >> a >> b;

    int gcd = EucGCD(a, b);
    cout << gcd << endl;
    // a * b / gcd = lcm
    cout << (a*b/gcd) << endl;

    return 0;
}
/**
 * Title: 나머지
 * Problem no. 10430
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/10430
 */

#include <iostream>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);

    int A, B, C;

    std::cin >> A >> B >> C;

    // 첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.
    std::cout << (A+B)%C << std::endl;
    std::cout << ((A%C) + (B%C))%C << std::endl;
    std::cout << (A*B)%C << std::endl;
    std::cout << ((A%C) * (B%C))%C << std::endl;
    
    return 0;
}
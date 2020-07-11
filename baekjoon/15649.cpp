/**
 * Title: N과 M (1)
 * Problem no. 15649
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/11723
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<int> c(8, 0);
vector<bool> ck(8, false);

int N, M;

void C(int i) {
    if (i == M) {
        v.push_back(c);
        return;
    }

    for (int x = 0; x < N; x++)
    {
        if (ck[x]) continue;
        ck[x] = true;
        c[i] = x+1;
        C(i+1);
        ck[x] = false;
    }
}

// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    C(0);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i][0];
        for (int e = 1; e < M; e++)
        {
            cout << ' ' << v[i][e];
        }
        cout << '\n';
    }
    
    return 0;
}
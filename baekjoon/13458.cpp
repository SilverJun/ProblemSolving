/**
 * Title: ���� ����
 * Problem no. 13458
 * Author: Eunjun Jang
 * Link: https://www.acmicpc.net/problem/13458
 */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int LIMIT = 1000000;

int N; // ������ ����
int A[LIMIT] = {0}; // ������ ����� ��
long long B; // �Ѱ����� ���ð��� ��
long long C; // �ΰ����� ���ð��� ��

long long result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	cin >> B;
	cin >> C;

	for (int i = 0; i < N; ++i)
	{
		result += 1;
		A[i] -= B;
		if (A[i] > 0)
		{
			result += A[i] / (double)C;
			if (A[i]%C)
				result += 1;
			//ceil(A[i] / (float)C);
		}
	}

	cout << result;
	
	return 0;
}

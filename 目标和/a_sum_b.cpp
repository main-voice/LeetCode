#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const* argv[])
{
	int n, m, x;
	cin >> n >> m >> x;

	vector<int> A(n + 5), B(m + 5);
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> B[i];
	}

	for (int i = 0, j = 0; i < n; ++i)
	{
		if (A[i] + B[j] == x) {
			cout << i << " " << j;
			return 0;
		}
		while (j < m && A[i] + B[j + 1] <= A[i + 1] + B[j]) j++;
	}
	return 0;
}

/*
10 10 30
9 13 15 19 20 26 40 43 44 49
1 5 6 21 22 28 31 32 46 49
*/
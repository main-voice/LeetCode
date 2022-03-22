#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[200001];

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);

	for (size_t i = 1; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	std::sort(a + 1, a + n + 1);
	int x = 0;
	for (size_t i = 0; i < m; i++)
	{
		scanf("%d", &x);

		int l(0), r(n + 1);
		while (l + 1 < r)
		{
			int m = l + (r - l) / 2;
			if (a[m] < x)
			{
				l = m;
			}
			else {
				r = m;
			}
		}
		int z = l;

		l = 0; r = n + 1;
		while (l + 1 < r)
		{
			int m = l + (r - l) / 2;
			if (a[m] <= x)
			{
				l = m;
			}
			else {
				r = m;
			}
		}

		printf("%d %d %d", z, l - z, n - l);
	}
	return 0;
}
//
//class Solution {
//public:
//	void binarySearch(vector<int>input, int x)
//	{
//		int size = input.size();
//
//		int l(0), r(size);
//
//		while (l + 1 < r) {
//			int m = l + (r - l) / 2;
//			if (input[m] < x) {
//				l = m;
//			}
//			else {
//				r = m;
//			}
//		}
//		int z = l;//smaller than x
//
//		l = 0; r = size;
//		while (l + 1 < r) {
//			int m = l + (r - l) / 2;
//			if (input[m] <= x) {
//				l = m;
//			}
//			else {
//				r = m;
//			}
//		}
//
//		cout << z << " " << l - z << " " << size - l;
//		return;
//	}
//};
//int main() {
//	cout << "hello world.\n";
//	int n, m;
//	cin >> n >> m;
//	vector<int> input(n);
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> input[i];
//	}
//	int x;
//	std::sort(input.begin(), input.end());
//		
//	for (size_t i = 0; i < m; i++)
//	{
//		cin >> x;
//		binarySearch(input, x);
//	}
//
//	cin.get();
//	return 0;
//}
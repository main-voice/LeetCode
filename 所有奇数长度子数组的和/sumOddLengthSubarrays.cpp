
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

//math method
class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		auto size = arr.size();
		int ans = arr[0]; // init
		if (size == 1) {
			return ans;
		}


		//统计对于每个字母，究竟在多少个奇数长度的数组中出现过
		//由于偶数 + 1 + 偶数 = 奇数
		//奇数 + 1 + 奇数 = 奇数
		//所以找该位置之前之后有多少个奇数和偶数长度的数组
		//当元素arr[i]的左边和右边的元素个数同为奇数时，在区间[0,leftCount] 范围内的奇数有 (leftCount+1)/2, [0,rightCount] 范围内的奇数有 (rightCount+1)/2, 
		//包含该位置的数字的数组，则有两者相乘即可

		for (size_t i = 0; i < size; i++)
		{
			int leftCount = i;
			int rightCount = size - i - 1;

			int leftOdd = (leftCount + 1) / 2;
			int rightOdd = (rightCount + 1) / 2;

			int leftEven = leftCount / 2 + 1;
			int rightEven = rightCount / 2 + 1;

			ans += arr[i] * (leftOdd * rightOdd + leftEven * rightEven);

		}

		return ans;

	}
};


class Solution1 {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		auto size = arr.size();
		int ans = arr[0]; // init
		if (size == 1) {
			return ans;
		}

		auto preSum(arr);

		for (size_t i = 1; i < size; i++) {
			preSum[i] += preSum[i - 1];
			ans += arr[i];
		}

		for (int start = size - 1; start >= 2; start--)
		{
			for (int j = start - 2; j >= 0; j-=2)
			{
				if (j == 0) {
					ans += (preSum[start]);
				}
				else {
					ans += (preSum[start] - preSum[j - 1]);
				}
			}
		}

		return ans;
	}
};

int main() {
	cout << "hello world.\n";
	Solution sln;

	vector<int> v{ 1,4,2,5,3 };
	sln.sumOddLengthSubarrays(v);
	
	cin.get();
	return 0;
}
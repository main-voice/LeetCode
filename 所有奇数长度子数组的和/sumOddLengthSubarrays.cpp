
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


		//ͳ�ƶ���ÿ����ĸ�������ڶ��ٸ��������ȵ������г��ֹ�
		//����ż�� + 1 + ż�� = ����
		//���� + 1 + ���� = ����
		//�����Ҹ�λ��֮ǰ֮���ж��ٸ�������ż�����ȵ�����
		//��Ԫ��arr[i]����ߺ��ұߵ�Ԫ�ظ���ͬΪ����ʱ��������[0,leftCount] ��Χ�ڵ������� (leftCount+1)/2, [0,rightCount] ��Χ�ڵ������� (rightCount+1)/2, 
		//������λ�õ����ֵ����飬����������˼���

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
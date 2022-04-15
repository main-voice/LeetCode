#include <iostream>
#include <vector>
#include <string>
using namespace std;

//����
//time limit exceeded
class Solution1 {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1) {
			return;
		}

		k > size ? k %= size : 1;

		for (int count = 0; count < k; count++) {
			nums[0] = nums[size - 1];

			for (int i = size - 1; i > 0; i--) {
				nums[i] = nums[i - 1];
			}
		}
		return;
	}
};

//�ҵ����մ���λ��
//O(n)ʱ�䣬O(n)�ռ�
class Solution2 {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1) {
			return;
		}

		k > size ? k %= size : 1;

		//�ҵ�����ÿ��Ԫ����˵����һ���洢��λ��
		vector<int> posi(size);

		for (size_t i = 0; i < size; i++)
		{
			posi[i] = (i + k) % size;
		}

		vector<int> copy(nums);

		for (size_t i = 0; i < size; i++)
		{
			copy[posi[i]] = nums[i];
		}

		nums = copy;
	}
};

//����Ҫ���⿪�ռ����洢������λ��
class Solution3 {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1) {
			return;
		}

		k > size ? k %= size : 1;

		vector<int> copy = nums;
		for (size_t i = 0; i + k < size; i++)
		{
			nums[i + k] = copy[i];
		}

		//0-k
		for (size_t i = 0; i < k; i++)
		{
			nums[i] = copy[size - k + i];
		}
	}
};

//���������Ҫ��ԭ����
class Solution4 {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1) {
			return;
		}

		k > size ? k %= size : 1;

		vector<int> copy(nums.begin() + size - k, nums.end());

		for (int i = size - 1; i >= k; i--) {
			nums[i] = nums[i - k];
		}
		
		//0-k
		for (size_t i = 0; i < k; i++)
		{
			nums[i] = copy[i];
		}
	}
};

//�������������ƶ��ľ����������Ƿ��������������ƶ�
class Solution5 {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1) {
			return;
		}

		k > size ? k %= size : 1;

		if (k < size / 2) {
			rightMove(nums, k);
		}
		else {
			leftMove(nums, k);
		}

		
	}

	void leftMove(vector<int>& nums, int k) {
		int size = nums.size();
		k = size - k;

		vector<int> copy(nums.begin(), nums.begin() + k);

		for (int i = 0; i < size - k; i++) {
			nums[i] = nums[i + k];
		}

		for (int i = 0; i < k; i++) {
			nums[size - k + i] = copy[i];
		}
	}
	void rightMove(vector<int>& nums, int k) {
		int size = nums.size();

		vector<int> copy(nums.begin() + size - k, nums.end());

		for (int i = size - 1; i >= k; i--) {
			nums[i] = nums[i - k];
		}

		//0-k
		for (size_t i = 0; i < k; i++)
		{
			nums[i] = copy[i];
		}
	}
};

//����6ز�ۣ���Ȼ�뵽�˱������Ƕ�������������������ǰ�󽻻����������������о���Ľ����±��ʧ��
class Solution6 {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1) {
			return;
		}
		//�����Ƕ�������λ��k���뿪�����齻��λ��
		//˫ָ���ٴκ�֮�������Լ�������ģ�

		k > size ? k %= size : 1;

		if (k > size / 2) {
			rightLonger(nums, k, size);//k�ƶ��࣬�ұ�һ��������壬�ұ߸���
		}
		else {
			leftLonger(nums, k, size);//k�ƶ��٣����һ��������壬��߸���
		}
	}

	void leftLonger(vector<int>& nums, int k, int size) {

		int start1 = 0;
		int start2 = size - k;
		const int end1 = start2;
		const int end2 = size;

		while (start1 < end1 && start2 < end2) {
			swap(nums[start1], nums[start2]);
			start1++; start2++;
		}

		while (start1 < end1) {
			nums[start1 + k] = nums[start1];
			start1++;
		}

	}
	void rightLonger(vector<int>& nums, int k, int size) {

		int start1 = 0;
		int start2 = size - k;
		const int end1 = start2;
		const int end2 = size;

		while (start1 < end1 && start2 < end2) {
			swap(nums[start1], nums[start2]);
			start1++; start2++;
		}

		while (start1 < end1) {
			nums[start1 + k] = nums[start1];
			start1++;
		}

	}
};

//���������
//�����ô����ڣ���Ȼ�Ƕ���ǰ���������������н���λ�ã���ô���ȿ����ȿ��ǰѺ���Ķ��ŵ�ǰ�棨˳������ν��ֻҪ�ŵ�ǰ�漴�ɣ���ͬʱ��ǰ��Ķ����ں��桪��>���������ȶ�������з�ת
//���巭ת�������������ǰ��λ���Ѿ����ģ������������ڲ�������������ս�������ǵ�����������ڲ���ת����
class Solution7 {
public:
	void reverse(vector<int>& nums, int start, int end) {
		while (start < end)//ԭ��˫ָ��������
		{
			swap(nums[start], nums[end]);
			start++; end--;
		}
	}
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();

		k %= size;
		reverse(nums, 0, size - 1);

		reverse(nums, 0, k - 1);
		reverse(nums, k, size);
	}
};
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1) {
			return;
		}

		k > size ? k %= size : 1;

		//���ڵ��������Ϊ��ת���䣬��������
		vector<int> ans(nums);

		//���뵹��д����ֹд���
		for (int i = size - 1; i >= 1; i--) {
			ans[i] = ans[i] - ans[i - 1];//ans[i]=nums[i]-nums[i-1];
		}
		

		//two changes
		ans[0] = nums[size - k];//���Ԫ�ص�����λ
		ans[k] = ans[k] - nums[size - 1];

		//others change:

		nums[0] = ans[0];

		for (int i = 1; i < size; i++) {
			nums[i] = ans[i] + nums[i - 1];
		}

		return;
	}
};

int main() {
	cout << "hello world.\n";
	Solution6 sln;
	//vector<int> v = { 1,2,3 };
	//vector<int> v = { 1, 2, 3, 4, 5, 6 };
	vector<int> v = { 3,4,7,9,15,20,1,2 };
	//vector<int> v = { -1,-100,3,99 };
	for (auto x : v) {
		cout << x << " ";
	}
	cout << "\n\n";

	sln.rotate(v,3);

	for (auto y : v) {
		cout << y << " ";
	}
	cout << "\n\n";
	cin.get();
	return 0;
}
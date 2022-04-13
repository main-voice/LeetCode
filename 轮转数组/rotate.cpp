#include <iostream>
#include <vector>
#include <string>
using namespace std;

//暴力
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

//找到最终储存位置
//O(n)时间，O(n)空间
class Solution2 {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1) {
			return;
		}

		k > size ? k %= size : 1;

		//找到对于每个元素来说，下一个存储的位置
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

//不需要额外开空间来存储将来的位置
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

//仅仅保存必要的原数组
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

//根据向左向右移动的距离来决定是否真正向左向右移动
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

//方法6夭折，虽然想到了本质上是对两个大的数据整体进行前后交换，但是受困于其中具体的交换下标而失败
class Solution6 {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if (size <= 1) {
			return;
		}
		//本质是对两个由位置k隔离开的数组交换位置
		//双指针再次呼之欲出（自己想出来的）

		k > size ? k %= size : 1;

		if (k > size / 2) {
			rightLonger(nums, k, size);//k移动多，右边一大块是整体，右边更长
		}
		else {
			leftLonger(nums, k, size);//k移动少，左边一大块是整体，左边更长
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

//求助于题解
//方法好处在于，既然是对于前后两个大的数组进行交换位置，那么首先可以先考虑把后面的都放到前面（顺序无所谓，只要放到前面即可），同时把前面的都放在后面——>所以我们先对整体进行翻转
//整体翻转后，两个大数组的前后位置已经更改，接下来考虑内部，发现相比最终结果，都是倒叙，因此再在内部翻转过来
class Solution7 {
public:
	void reverse(vector<int>& nums, int start, int end) {
		while (start < end)//原来双指针在这里
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

		//相邻的相减，因为轮转后差不变，最多变两个
		vector<int> ans(nums);

		//必须倒序写，防止写后读
		for (int i = size - 1; i >= 1; i--) {
			ans[i] = ans[i] - ans[i - 1];//ans[i]=nums[i]-nums[i-1];
		}
		

		//two changes
		ans[0] = nums[size - k];//这个元素到了首位
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
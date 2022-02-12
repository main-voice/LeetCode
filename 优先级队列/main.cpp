#include <iostream>
#include <vector>
using namespace std;

// to compare bigger or smaller, we need to overloading the operator '<'
//use array
#if 0
class prioQueue {
	vector<int> Array; // front element has higher priority, which means smaller weight.
public:
	prioQueue() { ; }
	void push(int x) {
		Array.push_back(x);
		adjust();// only need to adjust the last element
	}

	void adjust() {
		auto temp = Array.back();
		int i = 0;
		for (i = static_cast<int>(Array.size()) - 2; i >= 0; i--) {
			if (Array.at(i) <= temp) {
				break;
			}
			else {
				Array.at(i + 1) = Array.at(i);
			}
		}

		Array.at(i + 1) = temp;
	}

	void removeMin() {
		for (int i = 0; i < static_cast<int>(Array.size()) - 2; i++) {
			Array.at(i) = Array.at(i + 1);
		}
		Array.resize(Array.size() - 1);
	}

	void print() {
		for (auto& each : Array) {
			cout << each << endl;
		}
	}
};
#endif


//use heap
#if 1
class prioQueue {
	vector<int> Array; // front element has higher priority, which means smaller weight.
public:
	prioQueue() { ; }
	void push(int x) {
		Array.push_back(x);
		adjust();// only need to adjust the last element
	}

	void adjust() {
		auto temp = Array.back();
		int i = 0;
		for (i = static_cast<int>(Array.size()) - 2; i >= 0; i--) {
			if (Array.at(i) <= temp) {
				break;
			}
			else {
				Array.at(i + 1) = Array.at(i);
			}
		}

		Array.at(i + 1) = temp;
	}

	void removeMin() {
		for (int i = 0; i < static_cast<int>(Array.size()) - 2; i++) {
			Array.at(i) = Array.at(i + 1);
		}
		Array.resize(Array.size() - 1);
	}

	void print() {
		for (auto& each : Array) {
			cout << each << endl;
		}
	}
};
#endif



int main() {
	cout << "hello world.\n";

	prioQueue pQ;
	pQ.push(2);
	pQ.push(1);
	pQ.push(10);
	pQ.push(5);
	pQ.push(3);
	pQ.push(8);
	pQ.push(0);

	pQ.print();

	cin.get();
	return 0;
}
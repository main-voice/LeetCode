#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

#define B 0
#define A 1
#define L 2
#define O 3
#define N 4
const int SIZE = 5;

class Solution {
public:
	int maxNumberOfBalloons(string text) {
		int Array[SIZE]{};

		for (char each : text) {
			if (each == 'b') {
				Array[B]++;
			}
			else if (each == 'a') {
				Array[A]++;
			}
			else if (each == 'l') {
				Array[L]++;
			}
			else if (each == 'o') {
				Array[O]++;
			}
			else if (each == 'n') {
				Array[N]++;
			}
		}

		int min = Array[B];
		if (Array[A] < min) {
			min = Array[A];
		}
		if (Array[L] / 2 < min) {
			min = Array[L] / 2;
		}
		if (Array[O] / 2 < min) {
			min = Array[O] / 2;
		}
		if (Array[N] < min) {
			min = Array[N];
		}

		return min;
	}
};

int main() {
	cout << "hello world.\n";
	cin.get();
	return 0;
}
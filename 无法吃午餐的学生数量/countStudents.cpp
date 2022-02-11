#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {

		int donotLike = 0;

		while (students.size() && donotLike <= students.size())
		{
			if (students.at(0u) == sandwiches.at(0u)) {
				students.erase(students.begin(), students.begin() + 1); // delete this student
				sandwiches.erase(sandwiches.begin(), sandwiches.begin() + 1); // delete this sandwiches
				donotLike = 0;
			}
			else {
				students.push_back(students.at(0u));
				students.erase(students.begin(), students.begin() + 1); // delete this student
				donotLike++;
			}
		}


		return students.size();
	}
};


class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {

		int donotLike = 0;

		do
		{
			donotLike = 0;

			while (students.size() && donotLike <= students.size())
			{
				if (students.at(0u) == sandwiches.at(0u)) {
					students.erase(students.begin(), students.begin() + 1); // delete this student
					sandwiches.erase(sandwiches.begin(), sandwiches.begin() + 1); // delete this sandwiches
					donotLike = 0;
					break;
				}
				else {
					students.push_back(students.at(0u));
					students.erase(students.begin(), students.begin() + 1); // delete this student
					+donotLike++;
				}
			}

		} while (students.size() && donotLike <= students.size());

		return students.size();
	}
};

int main()
{
	vector<int> students = { 1,1,1,0,0,1 };
	vector<int> sandwiches{ 1,0,0,0,1,1 };
	Solution sln;
	sln.countStudents(students, sandwiches);
	return 0;
}
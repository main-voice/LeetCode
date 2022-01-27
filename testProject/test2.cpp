extern int Global_Test;

#include <iostream>
using namespace std;

void fun2() {
	cout << "in test2.cpp, address: " << &Global_Test << endl;
}
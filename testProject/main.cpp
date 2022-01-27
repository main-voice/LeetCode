
#include <iostream>
using namespace std;
extern int Global_Test;
void fun1();
void fun2();
int main()
{
	Global_Test = 1;
	cout << "in main, address : "<< & Global_Test << endl;

	fun1();
	fun2();
	return 0;
}
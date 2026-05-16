#include <iostream>
using namespace std;
#pragma region ex01_01
/*
void fun(int* ptr) {
	*ptr = 30;
}
*/
#pragma endregion
#pragma region ex01_13
class Foo {
public:
	int x;
	Foo() = default;
	Foo(int a): x(a) {}
};
class Bar {
public:
	Foo* ptr;
	int z;
	Bar() = default;
	Bar(Foo*p, int a): ptr(p), z(a) {}
};
#pragma endregion

int main() {
#pragma region ex01_01
	/*
	int y = 20;
	fun(&y);
	cout << y << endl;
	*/
#pragma endregion
#pragma region ex01_02
	/*
	int* ptr;
	int x;

	ptr = &x;
	*ptr = 0;

	cout << "x = " << x << endl;
	cout << "*ptr = " << *ptr << endl;

	*ptr += 5;
	cout << "x = " << x << endl;
	cout << "*ptr = " << *ptr << endl;

	(*ptr)++;
	cout << "x = " << x << endl;
	cout << "*ptr = " << *ptr << endl;
	*/
#pragma endregion
#pragma region ex01_13
	/*
	Foo* f = new Foo(20);
	cout << f->x << endl;
	*/
#pragma endregion
#pragma region ex01_14
	Bar b(new Foo(10), 20);
	cout << (*b.ptr).x << endl;
	cout << b.ptr->x << endl;
#pragma endregion

	return 0;
}
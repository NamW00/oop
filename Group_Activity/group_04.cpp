#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;
const int MAX = 100;

#pragma region ex1.3
/*class A {
public:
	int data;
	// 1. 기본 생성자 강제 생성
	// A() = default;
	A(int a) : data(a) {}
	// 2.
};*/
#pragma endregion
#pragma region ex1.4
/*
class A {
public:
	int data;
	A(int a) : data(a) {}
};
*/
#pragma endregion
#pragma region ex1.5
/*class A {
public:
	int data;
	A() {
		cout << "constructor1" << endl;
	}
	A(int a) : data(a) {
		cout << "constructor2" << endl;
	}
};
class B {
public:
	A mem;
	B(A c) : mem(c) {
		cout << "B's constructor" << endl;
	}
};*/
#pragma endregion

int main() {
#pragma region ex1.3
	/*
	A x;	// A() 형태의 기본생성자가 없어서 객체를 만들 수 없음
	A y(10);
	vector<A> vec_a; // vector를 만들기만 하는 것은 OK
	vector<A> vec_b(2); // But, 기본 생성자가 없어서
	*/
#pragma endregion
#pragma region ex1.4
	/*
	A arr[3];
	A arr2[4] = { 1, 2, 3, 4 };
	*/
#pragma endregion
#pragma region ex1.5
	/*	A obj_a(2);
		B obj_b(obj_a);*/
#pragma endregion


	return 0;
}


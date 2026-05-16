#include <iostream>
using namespace std;

#pragma region ex01_03
/*
class A {
public:
	static int a;
	void show() {
		a++;
		cout << "a: " << a << endl;
	}
};

int A::a = 5;
*/
#pragma endregion
#pragma region ex01_04
/*
class A {
	int a = 0;
public:
	A() {
		cout << "Object of A is created\n";
	}
	void show() {
		a++;
		cout << "a: " << a << endl;
	}
};
*/
#pragma endregion
#pragma region ex01_05
/*class A {
	int a;
public:
	void show() {
		a++;
		cout << "a: " << a << endl;
	}
	void operator.() {
		cout << "operator . called\n";
	}
};*/
#pragma endregion
#pragma region ex01_08
/*
class Box {
	int capacity;
public:
	Box(){}
	Box(double capacity) {
		this->capacity = capacity;
	}
	bool operator<(Box b) {
		return b.capacity < this->capacity ?
			true : false;
	}
};
*/
#pragma endregion
#pragma region ex01_07, ex03
class complex {
	int i, j;
public:
	complex() : i(0), j(0) {}
	complex(int a, int b) {
		i = a;
		j = b;
	}
	complex operator+(complex c) {
		complex temp;
		temp.i = this->i + c.i;
		temp.j = this->j + c.j;
		return temp;
	}

	complex operator-(complex c) {
		complex temp;
		temp.i = this->i - c.i;
		temp.j = this->j - c.j;
		return temp;
	}

	complex operator*(complex c) {
		complex temp;
		temp.i = this->i * c.i;
		temp.j = this->j * c.j;
		return temp;
	}
	// this->i = a
	// this->j = b
	// f.i     = c
	// f.j     = d
	// c*c + d*d : f.i*f.i + f.j*f.j
	// ac + bd : this->i*f.i + this->j*f.j
	// bc - ad : this->j*f.i - this->i*f.j

	complex operator/(complex f) {
		complex temp;
		temp.i = (this->i * f.i + this->j * f.j) / (f.i * f.i + f.j * f.j);
		temp.j = (this->j * f.i - this->i * f.j) / (f.i * f.i + f.j * f.j);
		return temp;
	}

	void show() {
		cout << "Complex Number: " << i
			<< ", " << j << endl;
	}
};

#pragma endregion


int main() {
#pragma region ex01_03
	/*
	A a, b;
	a.show();
	cout << A::a << endl;
	b.a = 10;
	cout << a.a << endl;
	*/
#pragma endregion
#pragma region ex01_04
	/*
	A a1, a2;
	A a3 = a1 + a2;
	*/
#pragma endregion
#pragma region ex01_05
	/*
	A a1, a2;
	*/
#pragma endregion
#pragma region ex01_07, ex03
	complex c1(1, 2);
	complex c2(3, 4);
	complex c3 = c1 + c2;
	c3.show();
	complex c4 = c1 - c2;
	c4.show();
	complex c5 = c1 * c2;
	c5.show();
	complex c6 = c1 / c2;
	c6.show();
#pragma endregion

#pragma region ex01_08
	/*
	Box b1(10);
	Box b2 = Box(14);
	if (b1 < b2)
		cout << "B1's capacity is small";
	else
		cout << "B2's capacity is small";
	*/
#pragma endregion


	return 0;
}
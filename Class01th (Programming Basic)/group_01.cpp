#include <iostream>

// const int MAX = 100; // ex22, 24, 25
// const int M = 100; // ex25
// const int N = 100; // ex25

using namespace std;

int main() {
#pragma region Group Activity 01
#pragma region ex03
	/*
	int age;
	bool teenager;
	cin >> age;


	if (age >= 13) {
		if (age <= 19){
			teenager = true;
			cout << "teenager True!" << endl;
		}
		else{
			teenager = false;
			cout << "teenager False!" << endl;
		}
	}
	else if (age < 13)
	{
		teenager = false;
		cout << "teenager False!" << endl;
	}

	//	if (age >= 13 && age <= 19)
	//		teenager = true;
	//	else
	//		teenager = false;
	*/

#pragma endregion
#pragma region ex09
	/*
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b < c || a > d)
		cout << "두 구간은 겹치는 구간이 존재하지 않는다!" << endl;
	else
		cout << "두 구간은 겹친다!" << endl;
	*/
#pragma endregion
#pragma region ex14
	/*
	int v = 1, N = 20;
	while (v <= N / 2) {
		cout << v;
		v *= 2;
		cout << " >> " << v << " ";
	}
	cout << endl;
	cout << "while문 밖에서의 v값 : " << v << endl;

	// 1 >> 2  2 >> 4  4 >> 8  8 >> 16
	// while문 밖에서의 v값 : 16
	*/


	/*
	int v = 1, N = 20;
	for (int v = 1; v <= N/2; )
	{
		v *= 2;
		cout << " >> " << v << " ";
	}
	cout << endl;
	cout << "for문 밖에서의 v값 : " << v << endl;
	//	1 >> 2  2 >> 4  4 >> 8  8 >> 16
	//	for문 밖에서의 v값 : 1
	*/

	/*
	int v = 1, N = 20;
	for (int v = 1; v <= N / 2; v *= 2)
	{
		cout << v << "\t";
	}
	cout << endl;
	cout << "for문 밖에서의 v값 : " << v << endl;
	// v 출력값
	// for문 내부 : 1 2 4 8
	// for문 밖에서는 1
	// 정답
	// (c)세 코드 모두 문법적으로 문제가 없다.
	// (d) 첫 번째와 두번째 코드는 동일한 일을 하고, 세 번째 코드는 다른 일을 한다.
	*/
#pragma endregion
#pragma region ex20
	/*
	// 다음 프로그램이 하는 일은?
	int N = 6;
	int b[6] = {1, 2, 3, 4, 5, 6};

	for (int i = 0; i < N/2; i++)
	{
		double temp = b[i];
		b[i] = b[N - 1 - i];
		b[N - 1 - i] = temp;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << b[i] << "\t";
	}
	// 배열의 요소들을 역순으로 뒤집어주는 역할을 합니다.
	// ex) [1, 2, 3, 4, 5, 6] -> [6, 5, 4, 3, 2, 1]
	*/

#pragma endregion
#pragma region ex22
	/*
	// 다음 프로그램이 하는 일은?
	int N;
	cin >> N;
	int data[MAX];
	// int data[MAX]; // MAX는 충분히 크다고 가정한다.
	// 배열 data에는 data[0]에서 data[N-1]까지 N개의 정수가 저장되어 있다고 가정한다.
	int tmp = data[0];
	for (int i = 1; i < N; i++)
		data[i - 1] = data[i];
	data[N - 1] = tmp;

	// 전체적인 배열을 왼쪽으로 1칸씩 shift하는 일을 한다.
	// 단 data[0]값은 임의의 변수 tmp에 저장하여 data[N-1]칸으로 이동시킨다.
	// ex) [1, 2, 3, 4, 5, 6] -> [2, 3, 4, 5, 6, 1]
	*/
#pragma endregion
#pragma region ex24
	/*
	int a[MAX];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];

	int count = 1, tmp = a[0];

	for (int i = 1; i < N; i++)
	{
		if (tmp != a[i])
		{
			tmp = a[i];
			count++;
		}
	}

	cout << endl;
	cout << "The count is " << count << endl;
	*/
#pragma endregion
#pragma region ex25
	/*
	// 두 배열 A와 B에 각각 M개와 N개의 정수가 오름차순으로 정렬되어 저장되어 있다.
	// 다음의 프로그램이 하는 일은 무엇인가? 단 각 배열에는 중복된 정수가 없다고 가정
	int i = 0, j = 0, k = 0;
	int A[M] = {1, 2, 4, 6, 7, 9};
	int B[N] = { 1, 3, 4, 5, 6, 7 };
	int C[MAX] = { 0, };
	while (i<M && j<N)
	{
		if (A[i] < B[j]) i++;
		else if (A[i] > B[j]) j++;
		else
		{
			C[k++] = A[i];
			i++, j++;
		}
		for (int i = 0; i < MAX; i++)
		{
			cout << C[i] << " ";
		}
		cout << "< A[" << i <<  "]= " << A[i] << ", B[" << j << "]= " << B[j] << ", k = " << k << " > " << endl;
	}
	// 작동 원리
	// A[i] < B[j]일 경우 A배열의 값이 더 작으므로, B[j]값과 같은 값을 찾기위해 i를 한칸 증가시킨다.
	// A[i] > B[j]일 경우 B배열의 값이 더 작으므로, A[i]값과 같은 값을 찾기위해 j를 한칸 증가시킨다.
	// A[i] == B[j]일 경우 공통된 값을 C[k]칸에 대입하고, 다음 공통값을 찾기위해  k값, i값, j값 모두 한칸씩 증가시킨다.
	// 결과적으로 C배열은 두 배열 A, B의 교집합 값들이 저장된다.
	*/
#pragma endregion
#pragma region ex27
	// 다음의 2차원 배열에 대한 선언들 중에서 문법적으로 올바른 것을 모두 고르면?
	// (a) int array2D[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	// (b) int array2D[][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	// (c) int array2D[2][] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	// (d) int array2D[][] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	// 정답 (a), (b)
	// C++에서는 열의 크기는 반드시 적어야 한다. 
	// 컴파일러는 2차원 배열을 메모리에 할당할 때 실제로는 일렬(1차원)로 늘어뜨려 저장합니다.
	// 열의 크기를 알아야 메모리의 위치도 계산할 수 있다.

#pragma endregion
#pragma endregion
	return 0;
}
#include <iostream>
#include <string> // string을 사용하기위해 선언 해야하는 헤더파일
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100; // define MAX 100

int main() {
#pragma region 1.5 벡터(vector)
#pragma region 백터의 생성, 초기화, 복사
	/*
	// 벡터의 생성과 초기화
	vector<int> v1;	// 정수를 저장하는 벡터는 이렇게 선언한다. 크기가 0인 벡터가 생성된다.

	// push_back()함수 - 맨 끝에 새로운 원소 추가
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	// size()함수 - 벡터의 크기를 반환
	int s = v1.size();

	// 중괄호를 이용하여 벡터를 초기화할 수 있다.
	vector<int> v2 = { 1, 2, 3, 4 };
	vector<int> v3{ 1, 2, 3, 4 };

	// 벡터의 복사 - 아래와 같이 다른 벡터를 복사하여 생성 가능
	vector<int> v4(v2);
	vector<int> v5{ v2 };
	vector<int> v6 = v2;

	v1 = v2; // 벡터들 간에 치환할 수 있다. 배열은 이렇게 못함
	*/
#pragma endregion
#pragma region code36(벡터 생성, 치환, 원소 추가)
	/*
	vector<int> v; // 정수(int)들을 저장하기 위한 빈(empty) 벡터 v를 생성

	v.push_back(1); // push_back은 항상 벡터의 맨 뒤에 새로운 원소를 삽입
	v.push_back(2);
	v.push_back(3);

	int s = v.size(); // 3개의 원소를 push_back으로 삽입했으므로 size는 3
	cout << s << endl;

	// v[] : 지정된 원소에 대한 참조 리턴 (bound check를 안함)
	// at(int index) : index 위치의 원소에 대한 참조 리턴(bound check를 함) -> 이 방법이 훨씬 좋은 방법
	cout << v[0] << " " << v.at(1) << " " << v[2] << endl;

	// 벡터의 원소들을 at 메서드나 혹은 배열처럼 [] 연산자로 접근하여 읽기/쓰기가 가능
	v[1] = 4; // v[1] = 2 -> 4
	v.at(2) = 5; // v[2] = 3 -> 5

	cout << v[0] << " " << v.at(1) << " " << v[2] << endl;

	// 존재하지 않는 원소에 대한 읽기/쓰기
	// cout << v[3] << v[4] << endl; // 오류가 발생하지 않을 수 있지만 그것은 그냥 운이 좋은 것임. 이렇게 하면 안됨
	// v[3] = 100;
	// cout << v.at(4) << endl; // error : v.at(int index)에서 bound check 후에 범위를 벗어난 값이므로 error 발생

	// vector initialization
	vector<int> v2 = { 1, 2, 3, 4 };// v2: size=4
	vector<int> v3{ 1, 2, 3, 4 }; // preferred way v3: size=4
	// vector<int> v4 = (3, 4); // wrong
	vector<int> v5(3, 4); // v5 contains 3, 4

	// vector can be copied
	vector<int> v6(v2); // v6: size=4
	vector<int> v7{ v2 }; // v7: size=4
	vector<int> v8 = v2; // v8:size=4
	cout << v2.size() << " " << v3.size() << " " << v5.size() << " " << v6.size() << " " << v7.size() << " " << v8.size() << endl;

	v2[0] = 100; // 아무리 v2를 복사했다 해도 v2의 요소를 변경한다고해서 v6, 7, 8에서의 요소도 같이 변하지는 않는다
	for (int a: v6)
		cout << a << " ";
	cout << endl;

	for (int a : v7)
		cout << a << " ";
	cout << endl;

	for (int a : v8)
		cout << a << " ";
	cout << endl;

	int arr[] = { 1, 2, 3, 4 };
	int arr2[4];
	// arr2 = arr //배열은 통으로 복사할 수는 없다.
	*/
#pragma endregion
#pragma region code37("range for"문)
	/*
	vector<int> data = { 1, 2, 3, 4 }; // 1, 2, 3, 4를 저장하는 길이가 4인 벡터 생성
	int sum = 0;
	for (int t: data) // 벡터 data에 저장된 각각의 정수 t에 대하여
		sum += t;	// 4정수의 합 10이 출력됨
	cout << sum << endl;

	// 배열의 크기와 배열에 실제로 저장된 데이터의 개수가 다른 경우 -> 사용해서는 안된다.
	int arr[10]; // 크기가 10인 배열 arr
	arr[0] = 1, arr[1] = 2, arr[3] = 3; // 실제로는 앞에 3칸에만 3개의 정수가 저장됨

	int sum_arr = 0;
	for (int t : arr) // 3개의 정수가 아니라 10개의 정수가 더해지는데
		sum_arr += t;	// 그 중 7개는 무의미한 쓰레기 값
	cout << sum_arr << endl; // 무의미한 값이 출력됨
	*/
#pragma endregion
#pragma region code38(2개 이상의 정수 입력 후 최소값과 두번쨰로 작은 값을 찾아 출력)
	/*
	vector<int> data;
	int k;
	while (true)
	{
		cin >> k;
		if (k == -1) break;
		data.push_back(k);
	}
	int min = data[0], second_min = data[1];
	if (min > second_min)
	{
		min = data[1];
		second_min = data[0];
	}
	for (int i = 2; i < data.size(); i++)
	{
		if (data[i] < min)
		{
			second_min = min;
			min = data[i];
		}
		else if (data[i] < second_min)
		{
			second_min = data[i];
		}
	}
	cout << min << ", " << second_min << endl;
	*/
#pragma endregion
#pragma endregion

	return 0;
}
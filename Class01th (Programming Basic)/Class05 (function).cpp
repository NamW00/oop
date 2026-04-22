#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> // find 함수 사용
using namespace std;
const int MAX = 100;
#pragma region 함수정의 모음(code46~53)
// int power(int x, int y);			// code46

// bool isPrime(int k);				// code47

// void swap(int a, int b);				// code48
// void bubble_sort(int n, int data[]); // code48

// void test_vec(vector<int> v);		// code49
// void test_arr(int arr[]);			// code49

// string trim(string);					// code50
// void tolowercase(string);			// code50

// void bubble_sort(int n, int data[]);	 // code51
// void swap(int& a, int& b);			 // code51

// double calculate_average(vector<int> w); // code52
// double calculate_average(vector<int> &w);// code53

#pragma endregion

int main() {
#pragma region 1.6 함수(function), 매개변수, 그리고 프로그램의 기능적 분할
#pragma region code46(a, b를 입력으로 받아 a^b 계산)
	/*
	int a, b;
	cin >> a >> b;
	int result = power(a, b);
	cout << result << endl;
	*/
#pragma endregion
#pragma region code47(1~100000사이의 모든 소수 출력)
	/*
	for (int i = 2; i < 100; i++){
		if (isPrime(i))
			cout << i << endl;
	}
	*/
#pragma endregion
#pragma region code48(n개의 정수 배열값을 받고, 버블 정렬 함수 설계)
	/*
	int data[MAX], n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];

	bubble_sort(n, data);

	for (int i = 0; i < n; i++)
		cout << data[i] << " ";
	cout << endl;
	*/
#pragma endregion
#pragma region code49(배열 혹은 벡터 매개변수)
	/*
	vector<int> v = { 1, 2, 3, 4, 5 };
	int arr[] = { 1, 2, 3, 4, 5 }; // 크기가 5인 배열 자동 생성
	// 배열을 선언할때 초기화 할 값들이 정해져 있다면 굳이 배열의 크기를 지정하지 않아도 된다.

	// test 전
	cout << "Before:\n";
	for (auto x : v)
		cout << x << " ";
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;

	test_vec(v);
	test_arr(arr);

	// test 이후
	cout << "After:\n";
	for (auto x : v)
		cout << x << " ";			// 벡터는 바뀌지 않음(정상적)
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";		// 배열은 test 결과 값이 반영되어 바뀜(비정상적) -> 값에 의한 호출의 위반적 사례
	cout << endl;
	*/
#pragma endregion
#pragma region code50(txt파일을 읽고 단어의 앞뒤에 붙은 특수문자들 모두 제거, 소문자 변환)
	/*
	ifstream infile("input35.txt"); // txt파일 불러옴
	string str;
	vector<string> words;
	while (infile >> str){			// 불러온 txt 파일을 단어별로 읽어들임
		str = trim(str);			// 원하는 부분만 잘라내는 함수
		if (str.length() > 0){		// 단어가 맞으면(trim함수에서 s <= t이면)
			str = tolowercase(str);	// 소문자 변환 (방법1)
			// tolowercase(str);
			// 값에 의한 호출로 str이 소문자 변환 되지 않음
			// 참조에 의한 호출로 바꾸면 정상적으로 작동된다.
			auto it = find(words.begin(), words.end(), str);
			// vector<int>::iterator it = find(first, last,
			// 벡터에서의 find 사용법
			// 첫번째 인자: vector의 시작부분
			// 두번째 인자: (vector의 끝부분 + 1)(= words.end())
			// 세번째 인자: 찾는 문자(=str)
			if (it == words.end())
				words.push_back(str);
		}
	}
	infile.close();
	for (auto s : words)
		cout << s << " ";
	*/
#pragma endregion
#pragma region code51(code48을 참조에 의한 연산)
	/*
	int data[MAX], n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];
	bubble_sort(n, data);
	for (int i = 0; i < n; i++)
		cout << data[i] << " ";
	cout << endl;
	*/
#pragma endregion
#pragma region code52(값 호출) vs code53(참조 호출):벡터 평균값 구하기)
	/*
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };
	double avg = calculate_average(v);
	cout << avg << endl;
	*/
#pragma endregion
#pragma endregion
	return 0;
}

#pragma region code46(int power(int, int);)
/*int power(int x, int y) { // <cmath>의 power함수와 동일한 기능
	int result = 1;
	for (int i = 0; i < y; i++)
		result *= x;
	return result;
}*/
#pragma endregion
#pragma region code47(bool isPrime(int);)
/*bool isPrime(int k) {
	if (k < 2)
		return false;
	// 약수의 대칭성 1 2 4 8 16을 보면 4까지만 조사해봐도 나머지 8은 2를 조사하면 발견되므로 굳이 8, 16까지 갈필요가 없는것
	for (int i = 2; i * i <= k; i++)
		if (k % i == 0)
			return false;
	return true;
}*/
#pragma endregion
#pragma region code48(void swap(int,int);void bubble_sort(int,int data[]);)
/*void swap(int a, int b);
void bubble_sort(int n, int data[]);

void swap(int a, int b) { // 값에 의한 호출 -> 참조에 의한 호출 그래야 원래 변수의 값도 영향을 미침
	int tmp = a;
	a = b;
	b = tmp;
}
void bubble_sort(int n, int data[]) { // 정수 배열을 매개변수로 받을 때는 int data[]로 받아온다.
	for (int i = n-1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (data[j] > data[j+1]){
				//	int tmp = data[j];
				//	data[j] = data[j + 1];
				//	data[j + 1] = tmp;
				swap(data[j], data[j+1]); // 정렬이 안되는 이유: 값에 의한 호출
			}
		}
	}
}*/
#pragma endregion
#pragma region code49(void test_vec(vector<int>);void test_arr(int arr[]);)
/*
void test_vec(vector<int> v) {
	v[0] = 0, v[1] = 1;
	cout << "Within:\n";
	for (auto x : v)
		cout << x << " ";
	cout << endl;
}
void test_arr(int arr[]) {
	arr[0] = 0, arr[1] = 1;
	cout << "WIthin:\n";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
}
*/
#pragma endregion
#pragma region code50(string trim(string);void tolowercase(string);)
/*
string trim(string str) {
	int s = 0, t = str.length() - 1;
	while (s < str.length() && !isalnum(str[s]))
		s++;
	while (t >= 0 && !isalnum(str[t]))
		t--;
	if (s <= t)
		return str.substr(s, t-s+1);
	else
		return "";
}
// 방법 1 : return 값 string 지정
string tolowercase(string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
	return str;
}
// 방법 2 : 참조에 의한 호출
void tolowercase(string& str){
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
}
*/
#pragma endregion
#pragma region code51(void bubble_sort(int,int arr[]; void swap(int,int);)
/*
void bubble_sort(int n, int data[]) {
	for (int i = n-1; i>=0; i--){
		for (int j = 0; j < i; j++){
			if(data[j]>data[j+1])
				swap(data[j], data[j + 1]);
		}
	}
}
void swap(int& a, int& b) { // 참조에 의한 연산
	int tmp = a;
	a = b;
	b = tmp;
}
*/
#pragma endregion
#pragma region code52(double calculate_average(vector);)
/*
double calculate_average(vector<int> w) { // 값에 의한 호출
	double sum = 0.0;
	for (auto e : w)
		sum += e;
	return sum / w.size();
}
*/
#pragma endregion
#pragma region code53(double calculate_average(vecto<int> &w);)
/*
double calculate_average(vector<int> &w) { // 참조에 의한 호출
	double sum = 0.0;
	for (auto e : w)
		sum += e;
	return sum / w.size();
}
*/
#pragma endregion


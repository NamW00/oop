#include <iostream>
#include <string> // string을 사용하기위해 선언 해야하는 헤더파일
#include <vector>
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
#pragma region code36(push_back으로 벡터 원소 추가)
	vector<int> v; // 정수(int)들을 저장하기 위한 빈(empty) 벡터 v를 생성

	v.push_back(1); // push_back은 항상 벡터의 맨 뒤에 새로운 원소를 삽입
	v.push_back(2);
	v.push_back(3);

	int s = v.size(); // 3개의 원소를 push_back으로 삽입했으므로 size는 3
	cout << s << endl;

	cout << v[0] << " " << v.at(1) << " " << v[2] << endl;
	// 벡터의 원소들을 at 메서드나 혹은 배열처럼 [] 연산자로 접근하여 일기/쓰기가 가능
	v[1] = 4;
	v.at(2) = 5;

	cout << v[0] << " " << v.at(1) << " " << v[2] << endl;

	// 존재하지 않는 원소에 대한 읽기/쓰기
	// cout << v[3] << v[4] << endl;
	// 오류가 발생하지 않을 수 있지만 그것은 그냥 운이 좋은 것임. 이렇게 하면 안됨
	v[3] = 100;

#pragma endregion

#pragma endregion


	return 0;
}
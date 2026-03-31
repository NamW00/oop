#include <iostream>
#include <string> // string을 사용하기위해 선언 해야하는 헤더파일
#include <algorithm>
#include <cctype>
using namespace std;
const int MAX = 100;
int main() {
#pragma region 1.4 문자열(code28~35)
#pragma region code28(문자열 생성방법)
	/*
	string str;							// 빈(empty) 스트링
	string str1 = "John Doe";			// 스트링 초기화 방법 1
	string str2("Namgu, Busan, Korea");	// 스트링 초기화 방법 2
	string name = str1;					// 스트링 치환1 (name = str1)
	string address(str2);				// 스트링 치환2 (address = str2)
	cout << "str: " << str << ", str1: " << str1 << ", str2: " << str2
		<< ", name: " << name << ", address: " << address << endl;

	string str3 = { "Hello World" };	// 스트링 초기화 방법 3
	string str4{ "Hello World" };		// 스트링 초기화 방법 4
	string str5{ str3 };				// 스트링 치환3
	cout << "str3: " << str3 << ", str4: " << str4 << ", str5: " << str5 << endl;
	*/
#pragma endregion
#pragma region code29(문자열 입력)
	/*
	string text;

	while (true) {
		getline(cin, text); // 라인 전체를 한 번에 읽어서 두 번째 매개변수인 text에 저장.(줄바꿈은 저장X)
		if (text == "exit")
			break;
		cout << text << ":" << text.length() << endl;
	}
	*/
#pragma endregion
#pragma region code30(입력된 문자열에서 중복되는 단어들의 빈도수를 계산하여 출력)
	/*
	string words[MAX], str;
	int count[MAX] = { 0 };
	int n, k = 0;
	cin >> n;
	// 변수 값 정리
	// n : 단어를 몇번 입력할 것인지
	// k : 실제 저장된 단어의 개수
	for (int i = 0; i < n; i++){
		cin >> str;

		int j = 0; // for문(i에 대한) 안에서만 존재
		for (; j < k; j++)
		{
			if (words[j] == str)
				break;
		} // 만약 겹친다면 몇번째 항이 겹치는지 j를 통해 알 수 있다.
		if (j >= k) // 겹치지 않는다면 j = k이므로 새로운 words[k]에
		{
			words[k] = str;
			count[k] = 1;
			k++;
		}
		else
			count[j]++;

		//	int j = 0;
		//	for (;  j < k; j++)
		//		if (words[j] == str)
		//			break;
		//	if (j < k) // str값이 중복된 값이라면
		//		count[j]++;
		//	else {		// j >= k라면 break를 거치지 않고 다 돌린 후 나온거니깐 새로운 단어 입력
		//		words[k] = str;
		//		count[k++] = 1;
		//	}
	}

	for (int i = 0; i < k; i++)
		cout << words[i] << " " << count[i] << endl;
	*/

#pragma endregion
#pragma region code31(팰린드롬 검사 - 거꾸로 읽어도 동일한 문자열)

#pragma endregion

#pragma endregion
	return 0;
}
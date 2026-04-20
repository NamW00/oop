#include <iostream>
#include <string> // string을 사용하기 위해 선언
#include <vector> // vector를 사용하기 위해 선언
#include <algorithm> // std::sort함수를 사용하기 위해 선언
using namespace std;

const int MAX = 100; // define MAX 100

int main() {
#pragma region 1.5 벡터(code36~45)
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

	// v[] : 지정된 원소에 대한 참조 리턴 (bound check를 안함) -> 인덱스가 유효하지 않을 떄에도 실행
	// at(int index) : index 위치의 원소에 대한 참조 리턴(bound check를 함) -> 인덱스가 유효하지 않으면 에러나 exception으로 처리
	cout << v[0] << " " << v.at(1) << " " << v[2] << endl;

	// 벡터의 원소들을 at 메서드나 혹은 배열처럼 [] 연산자로 접근하여 읽기/쓰기가 가능
	v[1] = 4; // v[1] = 2 -> 4
	v.at(2) = 5; // v[2] = 3 -> 5

	cout << v[0] << " " << v.at(1) << " " << v[2] << endl;

	// 존재하지 않는 원소에 대한 읽기/쓰기
	// cout << v[3] << v[4] << endl;
	// 오류가 발생하지 않을 수 있지만 그것은 그냥 운이 좋은 것임. 이렇게 하면 안됨
	// v[3] = 100;
	// cout << v.at(4) << endl; // error : v.at(int index)에서 bound check 후에 범위를 벗어난 값이므로 error 발생

	// vector initialization
	vector<int> v2 = { 1, 2, 3, 4 };// v2: size=4
	vector<int> v3{ 1, 2, 3, 4 }; // preferred way v3: size=4
	// vector<int> v4 = (3, 4); // 없는 문법
	vector<int> v5(3, 4); // v5 : size는 3이고 각각의 값들은 모두 4인 벡터 생성

	// vector can be copied
	vector<int> v6(v2);		// v6: size=4
	vector<int> v7{ v2 };	// v7: size=4
	vector<int> v8 = v2;	// v8: size=4 (가장 전통적인 방식)
	cout << v2.size() << " " << v3.size() << " " << v5.size() << " "
		<< v6.size() << " " << v7.size() << " " << v8.size() << endl;

	v2[0] = 100; // 아무리 v2를 복사했다 해도 v2의 요소를 변경한다고해서 v6, 7, 8에서의 요소도 같이 변하지는 않는다
	for (int a : v6)
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
	while (true){
		cin >> k;
		if (k == -1) break; // 입력 받은 정수가 -1이면 break
		data.push_back(k);
	}
	int min = data[0], second_min = data[1];
	if (min > second_min){
		min = data[1];
		second_min = data[0];
	}
	for (int i = 2; i < data.size(); i++){
		if (data[i] < min){					// 입력받은 data가 min보다 작으면 
			second_min = min;				// 두번째 최솟값에는 min을 넣어주고
			min = data[i];					// 최솟값에는 data값을 넣어줌
		}
		else if (data[i] < second_min){		// 만약 data가 min보다는 크고 second_min보다는 작을때
			second_min = data[i];			// data값이 second_min자리에 들어감
		}
	}
	cout << min << ", " << second_min << endl;
	*/
#pragma endregion
#pragma region code39(입력된 단어들의 빈도수를 계산하여 출력)
	/*	
	vector<string> words;
	string str;
	vector<int> count;
	// 파일과 달리 표준입력(std::cin)에는 끝이 없다. 
	// 표준입력의 끝을 알려주는 방법은 ctrl + Z 사용(Window 기준)
	while (cin >> str) { 
		int j = 0;
		for (; j < words.size(); j++)
			if (words[j] == str)
				break;

		if (j < words.size())
			count[j]++;
		else {
			words.push_back(str);
			count.push_back(1);
		}
	}
	for (int i = 0; i < words.size(); i++)
		cout << words[i] << " " << count[i] << endl;
	*/
#pragma endregion
#pragma region code40(벡터에서 원소의 삽입)
	/*
	// 벡터의 맨뒤에 원소를 삽입 -> push_back()을 사용
	// 맨 앞이나 혹은 가운데 삽입
	// 원소를 삭제
	vector<string>  sentence{ "how", "is", "programming" };
	string str = "fun";
	// "how"와 "is"사이에 "fun"을 넣고싶다.


	// auto 사용방법
	// 잘못된 예
	// auto x; // 컴파일러가 x에 대해 어떠한 형태인지 추론할 수 없다.
	// x = 1; // 이렇게 해도 인식 못함

	// 올바른 예
	// auto x = 1; // 컴파일러가 입력된 값을 보고 int형으로 추론

	// first try
	sentence[1] = str;
	for (auto word : sentence)
		cout << word << " ";
	cout << endl;
	// 삽입된 것이 아니라 "is"가 "fun"으로 바뀜

	// second try
	sentence[1] = "is"; // 벡터 sentence를 원래로 되돌린다.("fun" -> "is")

	// 배열에서 처럼 한칸씩 뒤로 옮긴다.
	// for (int i = 2; i >= 1; i--)
	// 	sentence[i + 1] = sentence[i];
	// sentence[3] = sentence[2] 과정에서 일어나는 문제
	// vector sentence.size() = 3이므로([0], [1], [2]까지 존재) sentence[3]은 적법한 인덱스의 범위를 벗어남.
	// 인덱스 연산자 []는 range check를 하지 않으므로 보통 오류가 발생하지는 않지만,
	// 정확히 어떤 일이 일어날지는 알 수 없다.
	// sentence[1] = str;

	// sentence의 size는 여전히 3이므로 "how fun is"까지만 출력
	// for (auto word : sentence)
	// 	cout << word << " ";
	// cout << endl;

	// Third Try
	// vector<string> sentence2{ "how", "is", "programming" };
	// for (int i = 2; i >= 1; i--)
	// 	sentence2.at(i + 1) = sentence2.at(i);
	// sentence2.at(3) = sentence2.at(2);에서 문제가 생김
	// 인덱스 연산자[] 대신 at을 쓰면 index out of range 오류 발생(bound check)
	// sentence2.at(1) = "fun";
	// error가 발생하기 때문에 출력은 생략

	// Fourth try
	// 굳이 하려면 먼저 무의미한 값을 하나 push_back하여 벡터 size를 1키운 다음에
	// "is"와 "programming"을 한 칸씩 뒤로 옮기고(그러면 추가했던 무의미한 값은 삭제)
	// "fun"을 원하는 위치에 삽입하면 되기는 한다. -> 세련된 방법은 X

	vector<string> sentence3{ "how", "is", "programming" };
	sentence3.push_back(""); // 무의미한 empty string을 뒤에 추가
	for (int i = sentence3.size()-2; i >= 1; i--)
		sentence3.at(i + 1) = sentence3.at(i);
	sentence3.at(1) = "fun";
	for (auto word : sentence3)
		cout << word << " ";
	cout << endl;
	*/
#pragma endregion
#pragma region ex41(벡터에서 원소의 삭제)
	/*
	vector<string> sentence{ "how", "fun", "is", "programming" };

	// "fun"을 삭제해보자
	for (int i = 1; i <= 2; i++)
		sentence[i] = sentence[i + 1];
	sentence[3] = "";

	cout << sentence.size() << endl;
	for (auto s : sentence)
		cout << s << " ";
	*/
#pragma endregion
#pragma region ex42(iterator 사용)
	/*
	vector<int> v;
	for (int i = 0; i < 4; i++)
		v.push_back(i + 1);

	vector<int>::iterator it; // it 선언 방법
	it = v.begin();
	cout << "it가 가리키는 값: " << *it << endl; // result: 1

	// iterator의 증가
	it++; // it+=1, it*=2 지원

	// iterator를 이용한 원소 읽기/쓰기
	// *it을 이용해 원소 읽기
	int n = *it; // 포인터에서 사용하는 연산과 동일
	cout << "it가 가리키는 값: " << n << endl; // result: 2

	// *it을 이용해 원소 쓰기
	*it = n * 2; // it이 가리키고 있는 값 2 -> 4로 바뀜
	cout << "결과: ";
	for (auto x : v)
		cout << x << " "; // result: 1 4(*it) 3 4
	cout << endl;

	// 원소 삽입
	// insert(pos, value): 특정 위치에 어떠한 값을 넣을 것인지 지정
	v.insert(it, 100); // 이렇게 삽입하게 되면 it가 없어짐(무효화 된다)
	cout << "v.insert(it, 100) 결과: ";
	for (auto x : v)
		cout << x << " "; // result: 1 100(itX) 4 3 4(it은 없어졌지만 삽입한 값은 남아있음)
	cout << endl;
	// cout << "it가 가리키는 값: " << * it << endl; // it이 insert 이후에 없어지므로, 무의미한 값이 출력

	it = v.begin(); // v[0] 가리킴
	it += 2; // 두 칸 전진: v[2] 가리킴

	it = v.insert(it, 200); // 이 방식을 통해 it이 사라지지 않고 유지된다.
	cout << "it = v.insert(it, 200) 결과: ";
	for (auto x : v)
		cout << x << " "; // result: 1 100 200(*it) 4 3 4
	cout << endl;
	cout << "it가 가리키는 값: " << *it << endl; // it는 새로 insert된 원소의 위치를 가리킴: v[2] = 200

	// 원소 삭제
	it = v.begin();
	it += 3; // 3칸 전진: v[0+3]가리킴

	// v.erase()를 사용하면 벡터의 원소가 삭제되면서 size도 같이 줄어듦
	it = v.erase(it); // 이때 it은 삭제된 다음 원소를 가리킴(정확히는 뒤의 원소가 당겨져온다)
	cout << "it = v.erase(it) 결과: ";
	for (auto x : v)
		cout << x << " "; // 1 100 200 3(*it) 4
	cout << endl;
	cout << *it << endl; // result: 3
	// it은 erase된 원소의 다음 위치를 가리킴: v[3] = 3
	*/
#pragma endregion
#pragma region ex43(벡터의 순회:홀수 제거, 짝수 *= 2)
	/*
	vector<int> vec{ 10, 8, 1, 5, 4, 6, 11, 2 };

	//	for (int i = 0; i < vec.size(); i++){
	//		if (vec[i] % 2 == 0)
	//			vec[i] *= 2;
	//		// else
	//			// vec[i]로 erase 불가능
	//	}
	//	for (int k: vec) {
	//		if (k % 2 == 0)
	//			k *= 2; // 이것은 k에 2를 곱한 것일뿐 벡터에 저장된 값에는 영향이 없음
	//		// else
	//			// range for로도 erase 불가능
	//	}


	vector<int>::iterator it = vec.begin();
	while (it!=vec.end()){ // it.end()는 (마지막 원소+1)을 가리키므로 모든 원소를 거치게 된다.
		if (*it % 2 == 0){
			*it *= 2;
			it++;
		}
		else
			it = vec.erase(it); // it은 삭제된 다음 원소를 가리킨다.
	}

	for (auto it = vec.begin(); it < vec.end(); it++)
		cout << *it << " ";
	cout << endl;
	*/
#pragma endregion
#pragma region ex44(exit 전까지 입력된 단어를 사전식 순서 정렬후 출력)
	/*
	vector<string> words;
	string str;
	while (true) {
		cin >> str;
		if (str == "exit")
			break;
		words.push_back(str);
	}

	sort(words.begin(), words.end()); // sort(시작it위치, 끝it위치+1);
	// <algorithm>헤더를 사용하면 std::sort함수를 사용하여 vector를 정렬할 수 있다.
	// 숫자는 오름차순, 문자열은 사전식 순서로 정렬

	for (auto s : words) {
		cout << s << " ";
	}
	cout << endl;
	*/
#pragma endregion
#pragma region ex45(exit 전까지의 단어들을 입력될때마다 사전식 순서 정렬후 출력)
	/*
	vector<string> words;
	string str;
	while (true) {
		cin >> str;
		if (str == "exit")
			break;

		auto it = words.begin();

		// 뒤에서 부터 it를 조사하는게 더 효율적임
		while (it != words.end() && *it < str) // it이 끝까지 닿기 전까지, str보다 사전순으로 앞에 있는 단어들은 그냥 지나침.
			it++; // str이 끼어들 자리를 찾는 과정.

		if (it == words.end()) // it이 끝자리라면 str을 push_back()
			words.push_back(str);
		else
			words.insert(it, str); // it이 end보다 전에 있다면 insert(it, str);
			// it = words.insert(it, str);

		for (auto s : words)
			cout << s << " ";
		cout << endl;
	}
	*/
#pragma endregion
#pragma endregion

	return 0;
}
#include <iostream>
#include <string> // string을 사용하기위해 선언
#include <fstream> // 파일로부터 데이터를 읽기 위해 선언
#include <algorithm> // std::sort함수를 사용하기 위해 선언
#include <cctype> // isalnum, tolower과 같은 함수를 사용하기 위해 선언
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
	// string str;
	// cin >> str;	- 공백이나 줄바꿈 문자를 무시한다. 즉, 라인의 끝을 인식할 수 없다.
	// getline -> 지정한 문자가 나올때 까지 읽어 주는 함수이다.
	// getline(cin, str); == getline(cin, text, '\n');
	// getline(cin, str, '\t'); - 탭문자(\t)가 나올때 까지 읽는다.
	// 
	/*
	string text;

	while (true) {
		getline(cin, text); // getline(cin, text, '\n')과 동일
		// 라인 전체를 한 번에 읽어서 두 번째 매개변수인 text에 저장.(줄바꿈은 저장X)
		if (text == "exit")
			break;
		cout << text << ":" << text.length() << endl;
		// length() 혹은 size() 메서드는 스트링의 길이를 반환한다.
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
	// n : 단어 입력 횟수
	// k : 실제 저장된 단어의 개수(중복 제외)
	for (int i = 0; i < n; i++){
		cin >> str;
		
		// 다른 방법
		// int j = 0;
		// while (j < k) {
		// 	if (words[j] == str)
		// 		break;
		// 	j++;
		// }
		int j = 0; // for문(i에 대한) 안에서만 존재
		for (; j < k; j++) // 이 for문에 극한하지 않게 j를 사용하고 싶기 때문에 밖에 따로 정의
		{
			if (words[j] == str)
				break;
		} // 만약 겹친다면 몇번째 항이 겹치는지 j를 통해 알 수 있다.
		if (j >= k) // 겹치지 않는다면 j = k이므로 새로운 words[k]에 str을 입력하고 count[k]값도 1로 초기화
		{
			words[k] = str;
			// count[k++] = 1; 과 동일
			count[k] = 1;
			k++;
		}
		else
			count[j]++;

	for (int i = 0; i < k; i++)
		cout << words[i] << " " << count[i] << endl;
	*/

#pragma endregion
#pragma region ex31(팰린드롬 검사 - 바로 읽으나 거꾸로 읽으나 동일한 문자열)
	/*
	string str;
	cin >> str;
	for (int i = 0; i < str.length() / 2; i++) {
		if (tolower(str.at(i)) != tolower(str.at(str.length()-i-1)))
		{
			cout << "Not palindrome." << endl;
			return 0;
		}
	}
	cout << "Palindrome." << endl;
	*/
#pragma endregion	
#pragma region ex32(N개의 단어를 입력받고)
	/*
	string words[MAX], pattern;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> words[i];
	cin >> pattern;
	for (int i = 0; i < N; i++) {
		// string::find 함수
		// 스트링에서 매개변수로 주어진 pattern을 검색해서 매치되는 시작위치 반환
		// 매치되지 않으면 string::npos, 즉 -1을 반환
		int index = words[i].find(pattern);
		if (index > -1) // pattern 문자열과 동일한 부분이 존재하면 해당 문자열 출력
			cout << words[i] << endl;
	}
	*/
#pragma endregion
#pragma region ex33(여러 수를 더한 덧셈식의 문자열을 입력받아 계산)
	/*
	string s;
	getline(cin, s);
	int sum = 0, start = 0; // sum은 합, start는 문자열 내에 검색할 시작 인덱스 값
	while (true){
		int fIndex = s.find("+", start);
		if (fIndex == -1){					// '+' 문자를 발견할 수 없다는 뜻 = 마지막 수 or 문자열 비어있음
			string part = s.substr(start);  // start위치에서 문자열의 끝까지
			if (part == "") break;			// 만약 문자열이 비어있으면 break
			sum += stoi(part);
			break;
		}
		// 2) "+"를 find했을때의 fIndex = (start위치 이후의 +위치)
		int count = fIndex - start;				// count는 +감지 되기 전까지의 숫자 개수
		string part = s.substr(start, count);	// start위치부터 count개 만큼 추출해서 part문자열에 저장
		sum += stoi(part);
		start = fIndex + 1;						// start는 +위치를 가리키고 있으므로 다음 숫자를 가리키게 +1
	}
	cout << "sum = " << sum << endl;
	*/
#pragma endregion
#pragma region ex34(txt 파일을 읽고 파일의 라인들의 길이를 내림차순 정렬)
	/*
	ifstream infile("input34.txt"); // 읽고자하는 파일에 대한 ifstream을 이렇게 생성
	// 출력을 할때는 ofstream을 사용
	// 데이터파일이 프로그램의 working directory에 위치해 있다면 이렇게 파일 이름만 명시하면 된다.
	// 아닌 경우에는 절대 경로 혹은 working directory에서 부터의 상대경로를 제공해야 한다.

	string lines[MAX];
	string line;
	int n = 0;
	while (getline(infile, line)) // 파일로 부터 한 라인을 읽는다. 파일의 끝에 도달하면 false가 된다.
		lines[n++] = line;		  // 각 라인들을 line이라는 문자열에 불러들여서 문자열 배열인 lines에 입력

	infile.close(); // 파일을 열었으면 반드시 close해주어야 한다.

	// bubble sort
	for (int i = n-1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (lines[j].length() > lines[j+1].length()){
				string tmp = lines[j];
				lines[j] = lines[j + 1];
				lines[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << lines[i] << endl;
	*/
#pragma endregion
#pragma region ex35(텍스트 파일을 읽고 등장하는 목록을 출력하는 프로그램 작성-중복 제외)
	ifstream infile("input35.txt");
	string str;
	string words[MAX];
	int n = 0;

	while (infile >> str) {	//파일의 끝에 도달하면 false가 된다.
		int s = 0, t = str.length() - 1;
		while (s < str.length() && !isalnum(str[s]))	// 문자열에 앞에서부터 처음으로 등장하는 알파벳이나 숫자의 위치 s를 찾는다.
			s++;
		while (t >= 0 && !isalnum(str[t]))				// 문자열의 뒤에서부터 처음으로 등장하는 알파벳이나 숫자의 위치 t를 찾는다.
			t--;
		if (s <= t)	// 특수문자로만 이루어진 문자열이라면 s > t가 될 것이다.
		{
			string pure_word = str.substr(s, t - s + 1); // 위치 s에서 시작되는 길이가 t-s+1인 부분 문자열을 잘라낸다.
			for (int i = 0; i < pure_word.length(); i++)
				pure_word[i] = tolower(pure_word[i]);

			bool found = false;
			for (int i = 0; i < n; i++) {
				if (words[i] == pure_word) { // 이미 목록에 등록된 문자열인지 검사
					found = true;
					break;
				}
			}
			if (!found)
				words[n++] = pure_word; // 목록에 없는 문자열만 목록에 추가한다.

		}
	}
	infile.close();

	for (int i = 0; i < n; i++)
		cout << words[i] << endl;

#pragma endregion
#pragma endregion
	return 0;
}
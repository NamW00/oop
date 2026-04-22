// 자료구조부터 만들어 보자. 대부분의 프로그램에서 제일 먼저 생각해야 할 것은 데이터를 저장할 자료구조를 정의하는 것
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> words;		   // 단어들의 목록을 저장할 벡터
vector<vector<int>> lineNums; // 각 단어들이 등장하는 라인번호들을 저장할 벡터들의 벡터

void makeIndex(string fileName);
void handle_find(string keyword);
void addWord(string word, int lineNum);
void addWord_it(string word, int lineNum);
int findWord(string word);
void saveAs(string fileName);
vector<string> split_line(string line, char delimiter);

int main() {
	string command;
	while (true) {
		cout << "$";
		cin >> command;
		if (command == "read") {
			string fileName;
			cin >> fileName;
			makeIndex(fileName); // 불러올 파일명 지정
		}
		else if (command == "saveas") {
			string fileName;
			cin >> fileName;
			saveAs(fileName);
		}
		else if (command == "find") {
			string keyword;
			cin >> keyword;
			handle_find(keyword);
		}
		else if (command == "exit")
			break;
	}
	return 0;
}

void makeIndex(string fileName) {
	ifstream theFile(fileName);
	int lineNum = 0;
	string line;
	while (getline(theFile, line)) {
		// 각 단어가 등장하는 라인 번호를 알아야 하므로 한라인씩 입력
		vector<string> tokens = split_line(line, ' ');
		// 한 라인은 여러 개의 단어로 구성되므로 라인을 단어들로 분할(split) 해야함
		for (auto s : tokens)
			if (s.length() > 0)
				addWord(s, lineNum);
		lineNum++;
	}

}

vector<string> split_line(string line, char delimiter) {
	// delimiter은 어떤 문자를 기준으로 분할할지를 지정 - 여기서는 공백(' ')
	vector<string> tokens;
	stringstream sstream(line); // 문자열 line을 저장하는 stringstream 생성

	string str;
	while (getline(sstream, str, delimiter))
		tokens.push_back(str);

	return tokens;
}

void addWord(string word, int lineNum) {
	int index = findWord(word); // word 존재O index값, 존재X -1 반환
	if (index > -1)	// word가 이미 존재하는 경우
		lineNums[index].push_back(lineNum); // lineNums[index]칸에 lineNum을 추가
	else {	// word가 처음 등장하는 경우
		words.push_back(word);		   // word를 words벡터에 추가하고
		vector<int> tmp = { lineNum }; // line
		lineNums.push_back(tmp);
	}
}
void addWord_it(string word, int lineNum) {
	auto it = find(words.begin(), words.end(), word);
	// <algorithm>의 find함수를 사용: 
	// word가 있는 위치를 iterator로 반환
	int index = distance(words.begin(), it);
	// <algorithm>의 distance함수 이용:
	// words의 시작부터 it가 가리키는 값까지의 거리
	if (index < words.size()) // 이미 존재하는 경우
		lineNums[index].push_back(lineNum);
	else { // it == words.end()라면 처음 등장하는 경우
		words.push_back(word);
		// 새로운 행(vector<int>)을 생성하여 lineNum삽입 후 추가
		vector<int> tmp = { lineNum };
		lineNums.push_back(tmp);
	}
}

int findWord(string word) { // 벡터 words에서 word를 검색하여 존재하면 index를, 없으면 -1을 반환한다.
	for (int i = 0; i < word.size(); i++)
		if (words[i] == word)
			return i;
	return -1;
}

void handle_find(string keyword) {
	int index = findWord(keyword);
	if (index != -1) {
		cout << "The word " << keyword << " appear" <<
			lineNums[index].size() << "times in lines: ";
		for (auto v : lineNums[index])
			cout << v << ", ";
		cout << endl;
	}
	else
		cout << "The word " << keyword << " doesn't appear." << endl;
}



void saveAs(string fileName) {
	ofstream outFile(fileName); // 파일로 출력하려면 ofstream을 만들면 된다. 
	for (int i = 0; i < words.size(); i++) {
		outFile << words[i] << endl;
		// file에 출력할때는 (ofstream 변수명 << 출력할 내용 << endl;)
		for (auto c : lineNums[i])
			outFile << c << " ";
		outFile << endl;
	}
}



#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split_line(string line, char delimiter);

int main() {
	string s1 = "  string tokening   is  fun   ";
	vector<string> tokens1 = split_line(s1, ' ');
	for (auto t : tokens1)
		cout << ":" << t << ":" << t.length() << endl;
	cout << endl;
	string s2 = " splitting string  ###using another  #delimiter";
	vector<string> tokens2 = split_line(s2, '#');
	for (auto t : tokens2)
		cout << ":" << t << ":" << t.length() << endl;
	cout << endl;
	return 0;
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

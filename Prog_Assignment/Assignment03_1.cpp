#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;
const int MAX = 100;

struct Location
{
	int line;
	int pos;
};

struct WordInfo {
	string word;
	vector<Location> locs;
};

string cleanWord(string s) {
	while (!s.empty()) {
		if (isalpha(s[0]))
			break;
		s.erase(0, 1);
	}

	while (!s.empty()) {
		if (isalpha(s[s.length() - 1]))
			break;
		s.pop_back();
	}

	for (int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);

	return s;
}

bool compare(const WordInfo& a, const WordInfo& b) {
	return a.word < b.word;
}
/*
// class 보다는 struct로 하는건
class Word {
public:
	string word;
	vector<pair<int, int>>spot;
	// pair라는 순서쌍 컨테이너를 사용
};
void bubble(vector<Word>& lists);
*/


int main() {
	/*	
	string sent;
	vector<Word> lists;

	int lcount = 1;
	while (true) {
		getline(cin, sent);
		if (sent == "End.") break;
		stringstream sstream(sent); // 쪼개서 sstream 통에 넣음
		string tmp; // 쪼갠거 받는 통
		int wcount = 1;
		while (sstream >> tmp) {
			Word w;
			string clean = "";
			while (!tmp.empty() && !isalpha(tmp.front());
			tmp.erase(0, 1);
			// stringstream : 내가 이미 가지고 있는 string 객체를 
			while (!tmp.empty())
			{

			}if (tmp.empty()) continue;
			bool value = true;
			int i = 0;
			for (i = 0; i < list.size(th)); i++)
			{

			}

		}
	}
	*/
	vector<WordInfo> wordList;
	string line;
	int lineNum = 1;
	while (getline(cin, line)) {
		if (line == "End.") break;

		stringstream ss(line);
		string rawWord;
		int wordPos = 1;

		while (ss >> rawWord) {
			string cleaned = cleanWord(rawWord);
			if (cleaned.empty()) {
				wordPos++;
				continue;
			}

			// 중복 단어 확인
			bool found = false;
			for (int i = 0; i < wordList.size(); i++) {
				if (wordList[i].word == cleaned)
				{
					wordList[i].locs.push_back({ lineNum, wordPos });
					found = true;
					break;
				}
			}

			// 처음 등장하는 단어
			if (!found) {
				WordInfo newWord;
				newWord.word = cleaned;
				newWord.locs.push_back({ lineNum, wordPos });
				wordList.push_back(newWord);
			}
			wordPos++;
		}
		lineNum++;
	}

	sort(wordList.begin(), wordList.end(), compare);

	for (const auto& item : wordList)
	{
		cout << item.word << " ";
		for (const auto& l : item.locs) {
			cout << "(" << l.line << "," << l.pos << ")";
		}
		cout << endl;
	}

	return 0;
}
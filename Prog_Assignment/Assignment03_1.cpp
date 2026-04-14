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

int main() {
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
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int MAX = 100;

#pragma region ex09
bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}
#pragma endregion
#pragma region ex09_1
bool cmp(string& s1, string& s2) {
	auto it1 = s1.rbegin();
	auto it2 = s2.rbegin();
	while (it1 != s1.rend() && it2 != s2.rend()) {
		if (*it1 != *it2) {
			return *it1 < *it2;
		}
		++it1; ++it2;
	}
	return s1.length() < s2.length();
}
#pragma endregion



int main() {
#pragma region ex01(입력받은 문자열 공백 제거후 남은 텍스트와 길이 출력)
    /*  
    string str;
    while (true)
    {
        getline(cin, str);
        if (str == "exit")
            break;

        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);

        string result = "";
        bool spaceFound = false;
        for (char c : str)
        {
            if (isspace(c)) {
                if (!spaceFound) { // 
                    result += ' ';
                    spaceFound = true;
                }
            }
            else {
                result += c;
                spaceFound = false;
            }
        }
        cout << result << ":" << result.length() << endl;
    }
    */
#pragma endregion
#pragma region ex02(입력된 단어들의 빈도수를 카운트하여 빈도수에 대한 내림차순으로 정렬)
	/*
	string words[MAX], str;
	int count[MAX] = { 0 };
	int k = 0;
	while (true) {
		cin >> str;
		if (str == "End.") break;

		for (int i = 0; i < str.length(); i++)
			str[i] = tolower(str[i]);

		int j = 0;
		for (; j < k; j++)
			if (words[j] == str) break;

		if (j >= k)
		{
			words[k] = str;
			count[k++] = 1;
		}
		else
			count[j]++;
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			bool swapIndex = false;

			if (count[j] < count[j + 1])
				swapIndex = true;
			else if (count[j] == count[j + 1])
				if (words[j] > words[j + 1])
					swapIndex = true;

			if (swapIndex) {
				swap(words[j], words[j + 1]);
				swap(count[j], count[j + 1]);
			}
		}
	}

	for (int i = 0; i < k; i++)
		cout << words[i] << ":" << count[i] << endl;
	*/
#pragma endregion
#pragma region ex03(불필요한 공백 제거 후 단어의 개수 카운트)
	/*
	string words[MAX], str;
	int count[MAX] = { 0 };
	int k = 0;

	while (true) {
		getline(cin, str);
		if (str == "End.") break;
		if (str == " ") continue;

		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);

		string result = "";
		int wCount = 0;
		bool spaceFound = false;
		for (int i = 0; i < str.length(); i++) {
			if (isspace(str[i])) {
				if (!spaceFound) {
					result += ' ';
					spaceFound = true;
				}
			}
			else {
				if (result.empty() || spaceFound)
					wCount++;
				result += str[i];
				spaceFound = false;
			}
		}

		if (wCount > 0 && k < MAX) {
			words[k] = result;
			count[k++] = wCount;
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if (count[j] < count[j + 1]) {
				swap(words[j], words[j + 1]);
				swap(count[j], count[j + 1]);
			}
		}
	}

	for (int i = 0; i < k; i++)
	{
		cout << words[i] << ":" << count[i] << endl;
	}
	*/
#pragma endregion
#pragma region ex04(새로 입력 받은 단어를 전에 입력받은 단어에 이어서 출력)
	/*
	string words[MAX], str;
	int k = 0;

	while (true) {
		cin >> str;
		if (str == "exit") break;

		int j = 0;
		for (; j < k; j++)
			if (words[j] == str)
				break;

		if (j < k) {
			cout << "duplicate" << endl;
			continue;
		}
		else
			words[k++] = str;

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k - i - 1; j++) {
				if (words[j] > words[j + 1])
					swap(words[j], words[j + 1]);
			}
		}

		for (int i = 0; i < k; i++)
			cout << words[i] << " ";
		cout << endl;
	}
	*/
#pragma endregion
#pragma region ex05(n개의 영문 소문자 단어 입력으로 받아 모든 문자열의 가장 긴 공통 접두사 출력)
	/*
	string words[MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> words[i];

	string text = words[0];
	for (int i = 0; i < n; i++)
	{
		while (words[i].find(text))
		{
			text = text.substr(0, text.length() - 1);
			if (text.empty()) break;
		}
		if (text.empty()) break;
	}
	cout << text << endl;
	*/
#pragma endregion
#pragma region ex06(n개의 정수를 입력받아 벡터에 저장한 후 크기순 정렬, 중복된 수 제거)

#pragma endregion

#pragma region ex07(n개의 정수 입력후 벡터에 크기순 정렬후 중복된 수를 제거)
	/*
	int n, k;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	vector<int> result;
	sort(v.begin(), v.end());

	if (!v.empty())
	{
		result.push_back(v[0]);
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] != result.back())
				result.push_back(v[i]);
		}
	}

	cout << result.size() << ": ";
	for (int i : result)
	cout << i << " ";
	cout << endl;
	*/
#pragma endregion
#pragma region ex08(영문 문자열의 길이가 짧은 것부터 긴 것 순서로 정렬하여 출력)
	/*	
	string words[MAX], str;
	int count[MAX] = { 0 };
	int n, k = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> words[i];
		count[i] = words[i].length();
	}

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			bool swapIndex = false;
			if (count[j] > count[j + 1]) swapIndex = true;
			else if (count[j] == count[j + 1])
				if (words[j] > words[j + 1]) swapIndex = true;

			if (swapIndex) {
				swap(words[j], words[j + 1]);
				swap(count[j], count[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << words[i] << endl;
	*/
#pragma endregion
#pragma region ex09(순서쌍 이용하여 각 개구간 끝지점 오른차순 정렬)
	/*	
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), compare);

	vector<pair<int, int>> result;

	if (n > 0) {
		result.push_back(v[0]);
		int last_end = v[0].second;

		for (int i = 1; i < n; i++) {
			if (v[i].first >= last_end) {
				result.push_back(v[i]);
				last_end = v[i].second;
			}
		}
	}

	cout << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i].first << " " << result[i].second << endl;
	*/
#pragma endregion
#pragma region ex09_1(문자열 입력 후 각 문자열을 뒤집었을때의 사전식 순서 정렬)
	/*
	int n;
	cin >> n;
	vector<string> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	std::sort(v.begin(), v.end(), cmp);

	for (string& s : v)
		cout << s << endl;
	*/
#pragma endregion

	return 0;
}
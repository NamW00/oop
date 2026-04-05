#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string trim(string str) {
	int s = 0, t = str.length() - 1;
	while (s < str.length() && !isalpha(str[s]))
		s++;
	while (t >= 0 && !isalpha(str[t]))
		t--;
	if (s <= t)
		return str.substr(s, t - s + 1);
	else
		return " ";
}

void tolowercase(string& str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
}

int main() {
	/*	
	string str = " How fun is C++ !!! ";
	tolowercase(trim(str));
	cout << str << endl;
	*/
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class MyDate {
private:
	string month_str;
	int month;
	int day;
	int year;
	int monthNum(string& m) {
		if (m == "Jan") return 1;
		if (m == "Feb") return 2;
		if (m == "Mar") return 3;
		if (m == "Apr") return 4;
		if (m == "May") return 5;
		if (m == "Jun") return 6;
		if (m == "Jul") return 7;
		if (m == "Aug") return 8;
		if (m == "Sep") return 9;
		if (m == "Oct") return 10;
		if (m == "Nov") return 11;
		if (m == "Dec") return 12;
		return 0;
	}

public:
	MyDate() : month_str(""), month(0), day(0), year(0) {}
	MyDate(string m, int d, int y) : month_str(m), day(d), year(y) {
		month = monthNum(m);
	}
	void readDate() {
		string m, d_str;
		int y;
		cin >> m >> d_str >> y;

		if (!d_str.empty() && d_str.back() == ',') {
			d_str.pop_back();
		}
		this->month_str = m;
		this->month = monthNum(m);
		this->day = stoi(d_str);
		this->year = y;
	}
	void printDate() {
		cout << month_str << " " << day << ", " << year << endl;
	}
	// 1. < 연산자
	bool operator<(MyDate& other) {
		if (this->year != other.year)
			return this->year < other.year;
		if (this->month != other.month)
			return this->month < other.month;
		return this->day < other.day;
	}
	// 2. == 연산자
	bool operator==(MyDate& other) {
		return (this->year == other.year &&
			this->month == other.month &&
			this->day == other.day);
	}
	// 3. > 연산자
	bool operator>(MyDate& other) {
		return other < *this;
	}
	// 4. != 연산자
	bool operator!=(MyDate& other) {
		return !(*this == other);
	}
	// 5. <= 연산자
	bool operator<=(MyDate& other) {
		return (*this < other) || (*this == other);
	}
	// 6. >= 연산자
	bool operator>=(MyDate& other) {
		return (other < *this) || (*this == other);
	}
};

int main() {
	int N;
	if (!(cin >> N)) return 0;
	vector<MyDate> dates(N);
	for (int i = 0; i < N; ++i)
		dates[i].readDate();

	sort(dates.begin(), dates.end());

	for (int i = 0; i < N; i++)
		dates[i].printDate();

	return 0;
}
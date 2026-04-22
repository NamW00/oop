#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#pragma region code01~03(SalesData)
class SalesData {
public:
	string isbn;
	int units_sold = 0;
	double revenue = 0.0;
};

#pragma endregion
#pragma region 함수 정의
vector<string> split_line(string& line, char delimiter);  // code03
SalesData parse_line(string& line);						  // code03
void insertRecord(SalesData r, vector<SalesData>& record);// code03
void sort_by_average_price(vector<SalesData>& records);	  // code03

#pragma endregion



int main() {
#pragma region 2.1 클래스와 객체

#pragma region code01(객체 생성과 필드(멤버변수)값 초기화)
	/*
	SalesData first; // 하나의 SalesData(Class) 타입의 객체 = first(object)라고 한다
	first.isbn = "978-0-321"; // first객체의 필드들에 .연산자로 접근하여 값을 쓰고 읽는다.
	first.units_sold = 3;
	first.revenue = 32000;
	cout << first.isbn << " " << first.units_sold << " "
		<< first.revenue << endl;

	SalesData data[10]; // SalesData 타입의 배열도 만들 수 있다.

	data[0] = first; // 클래스 객체들 간에 치환도 가능하다.
	cout << data[0].isbn << " " << data[0].units_sold << " "
		<< data[0].revenue << endl;

	data[1].isbn = "978-0-111";
	data[1].units_sold = 11;
	data[1].revenue = 56000;
	cout << data[1].isbn << " " << data[1].units_sold << " "
		<< data[1].revenue << endl;
	*/
#pragma endregion
#pragma region code03(csv파일 분석 후 각 도서당 판매권수,매출 집계 오름차순 정렬)
	vector<SalesData> records; // SalesData 타입의 벡터에 저장. 하나의 책은 하나의 항목으로 합쳐서 저장
	ifstream infile("sales_records.csv");
	string line;

	while (getline(infile, line)) {
		if (line.length() <= 0)
			continue;
		SalesData r = parse_line(line); // 한라인을 분해하여 하나의 SalesData 객체로 만들어 반환
		insertRecord(r, records); // 벡터 records에 추가. 
		// 이미 등록된 책이면 팔린 권수, 매출 반영
		// 새로운 책이면 새로 추가
	}
	infile.close();
	sort_by_average_price(records); // 평균 판매가격의 내림차순으로 출력
	for (auto r : records)
		cout << r.isbn << ":" << r.units_sold << ":" << r.revenue
		<< ":" << r.revenue / r.units_sold << endl;

#pragma endregion


#pragma endregion

	return 0;
}

#pragma region code03
SalesData parse_line(string& line) { // 복사 할 필요 없기 때문에 참조로 받음
	SalesData r;
	vector<string> tokens = split_line(line, ','); // ','를 기준으로 분할
	r.isbn = tokens[0];
	r.units_sold = stoi(tokens[1]); // string -> int
	r.revenue = stod(tokens[2]);    // string -> double
	return r;
}
SalesData parse_line2(string& line) { // 참고용 코드(parse_line과 동일한 역할 수행)
	SalesData r;
	int start = 0;
	int end = line.find(',');
	r.isbn = line.substr(0, end - start);

	start = end + 1;
	end = line.find(',', start);
	r.units_sold = stoi(line.substr(start, end - start));

	start = end + 1;
	end = line.find(',', start);
	r.revenue = stod(line.substr(start, end - start));
	return r;
}
vector<string> split_line(string& line, char delimiter) { // ','를 기준으로 단어 분할
	vector<string> tokens;
	stringstream sstream(line);
	string str;
	while (getline(sstream, str, delimiter)) // 구분문자가 나올때 까지만 읽어서 str에 저장함
		tokens.push_back(str);
	return tokens;
}
void insertRecord(SalesData r, vector<SalesData>& records) { // 기존있던 책: ++, 새로운 책: push_back
	for (auto it = records.begin(); it != records.end(); it++) {
		if ((*it).isbn == r.isbn) { // .연산자 우선순위가 높기 때문에 괄호를 꼭 쳐줘야함
			it->units_sold += r.units_sold; // it이 가리키는 것을 '->'(화살표 연산자)로 표현가능
			it->revenue += r.revenue;		// (*it). 과 it-> 는 동일하다
			return;
		}
	}
	records.push_back(r);
}
void sort_by_average_price(vector<SalesData>& records) { // 평균 오름차순 (bubble sort)
	for (int i = records.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (records[j].revenue / records[j].units_sold < records[j + 1].revenue / records[j + 1].units_sold) {
				SalesData tmp = records[j];
				records[j] = records[j + 1];
				records[j + 1] = tmp;
				// swap(records[j], records[j + 1]); // <algorithm> 사용시
			}
		}
	}
}

#pragma endregion

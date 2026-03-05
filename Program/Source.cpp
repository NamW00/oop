#include <iostream>
#include <cmath> // 수학 함수를 사용하기 위한 헤더 파일

// 상수 정의(code06)
const int MIN = 0; // #define MIN 0 -> c언어에서의 상수 정의 방식
const int MAX = 360; // constant
const int STEP = 10;

using namespace std;

int main(){
#pragma region 1.1 표준 입출력(code01~04)
#pragma region code01(문자와 문자열)
	/*	char c = 'A';   // 문자
		string s = "A"; // 문자열
		// string w = 'abc'; -> error 문자열은 작은	따옴표로 감싸면 안됨
		string v = "abc"; // 문자열 */
#pragma endregion
#pragma region code02(정수 입력)
		/*	int number = 123, input;
			cout << "please enter an integer: ";

			cin >> input;
			// std::cin은 표준입력스트림이다.
			// >>로 cin으로부터 하나의 정수를 입력받아 정수형 변수 input에 저장

			if (input == number)
			{
				cout << "Numbers match! :-)" << endl;
			}
			else
			{
				cout << "Numbers do not match! :-(" << endl;
			}*/
#pragma endregion
#pragma region code03(문자열 입력)
			/*	string input;
				cout << "please enter a string: ";

				cin >> input;

				if (input == "hello"){
					cout << "String matches! :-)" << endl;
				}
				else{
					cout << "String does not match! :-(" << endl;
				}*/
#pragma endregion
#pragma region code03_1(다양한 유형의 데이터 입력)
				/*	char c;
					int v;
					double w;
					string s;

					cout << "int값 입력: ";
					cin >> v; cout << v << endl;

					cout << "double값 입력: ";
					cin >> w; cout << w << endl;

					cout << "string값 입력: ";
					cin >> s; cout << s << endl;

					cout << "char값 입력: ";
					cin >> c; cout << c << endl;*/
#pragma endregion
#pragma region code04(문자열 연속 입력)
/*	string name;
	int age;
	string gender;
	cout << "Please enter your name, age, and gender:";

	cin >> name >> age >> gender;
	if (gender == "male")
		cout << name << ", you're " << age << " years old man." << endl;
	else if (gender == "female")
		cout << name << ", you're " << age << " years old woman." << endl;
	else
		cout << name << ", you're " << age << " years old." << endl;*/
#pragma endregion
#pragma endregion
#pragma region 1.2 Flow Control:반복문과 조건문(code05~16)
#pragma region code05(반복문을 이용해 평균 구하기)
	/*
	int N;
	cout << "반복할	횟수 입력: ";
	cin >> N;
	int v, sum = 0;

	for (int i = 0; i < N; i++) // 0부터 N-1까지 반복(총 N회 반복)
	{
		cout << i+1 <<"번째 정수 입력: "; cin >> v;
		sum += v; 
	}
	cout << "The average is : " << sum / N << endl;
	// sum/N에서 각각의 변수가 정수형이므로, 결과도 정수형(몫)이 된다. 
	// 만약 평균을 소수점까지 계산하려면, sum 또는 N 중 하나를 double로 변환해야 한다. 
	// (double)sum / N 
	// type casting을 이용하여 sum을 double로 변환하여 계산하면, 평균이 소수점까지 정확하게 계산된다.
	*/
#pragma endregion
#pragma region code06(Sine함수값 계산)
/*	// cmath 라이브러리 사용하여 Sine함수값 계산
	double radian, pi, value;
	// tan(45도) = 1 -> 역탄젠트인 atan(1) (= 45도 = pi/4) 로 표현
	pi = 4.0 * atan(1.0); // pi = 4.0 * pi/4
	cout << "Angle : Sine" << endl;
	for (int degree = MIN; degree <= MAX; degree+=STEP)
	{
		radian = pi * (degree / 180.0); // degree를 라디안으로 변환
		// 여기서 결과값이 올바르게 계산되게 하려면 여러가지 방법이 있다.
		// 방법 1 : pi * degree / 180 -> pi*degree를 먼저 계산하여 결과값이 double로 나오게 한다.(최선의 방법)
		// 방법 2 : pi * (degree / 180) -> degree를 double로 변환하여 계산
		// 방법 3 : pi * degree / 180.0 -> 180을 double로 변환하여 계산
		value = sin(radian); // 라디안 값을 이용하여 Sine 함수값 계산
		cout << degree << " : " << value << endl;
	}*/
#pragma endregion
#pragma region code07(2의배수, 3의배수, 2와3의 배수가 아닌 것들의 개수 출력)
/*	int s, t;
	cout << "2개의 정수를 입력하시오 : ";
	cin >> s >> t;
	int count1 = 0, count2 = 0, count3 = 0; // 초기화 해주지 않으면, 쓰레기값이 들어가서 결과값이 다르게 나온다.

	for (int i = s; i <= t; i++) {

		if (i % 2 == 0)
			count1++;
		if (i % 3 == 0)
			count2++;
		if (i % 2 != 0 && i % 3 != 0) // !(i % 2 == 0 || i % 3 == 0)
			count3++;
	}
	cout << "2의 배수 : " << count1 << "개, 3의 배수 : " << count2 
		<< "개, 2, 3의 배수가 아닌 것 : " << count3 << "개 " << endl;*/
#pragma endregion	
#pragma region 소득세율
/*double rate;
int income;
cin >> income;

if (income < 40000) rate = 0.22;
else if (income < 100000) rate = 0.25;
else if (income < 170000) rate = 0.28;
else if (income < 300000) rate = 0.33;
else if (income >= 300000) rate = 0.35;

cout << "해당 소득에 따른 세율 : " << rate <<"% 입니다." << endl;*/
#pragma endregion
#pragma region code08(입력된 정수 중, 홀수들의 합)
	/*int count_odd = 0, sum = 0;
	int tmp;

	// 반복의 횟수가 미리 정해진 경우 >> for문을 사용, 
	// 그렇지 않은 경우 >> while문을 사용
	// 모든 for문은 while문으로 바꿀 수 있고 반대의 경우에도 마찬가지다.
	while (count_odd < 10) {
		cin >> tmp;
		if (tmp % 2 == 1)
		{
			cout << "count: " << count_odd + 1 << "\t";
			cout << sum << " + " << tmp << endl;

			sum += tmp;
			count_odd++;
		}
	}
	cout << "홀수들의 총 합: " << sum << endl;*/
#pragma endregion
#pragma region code09(-1을 입력할때 까지의 홀수들의 합)
/*	int sum = 0;
	int tmp;

	while (1)
	{
		cin >> tmp;
		if (tmp == -1)
			break;
		if (tmp % 2 == 1)
			sum += tmp;
	}

	// 올바른 다른 예시
	//	cin >> tmp;
	//	while (tmp != -1) {
	//		if (tmp%2==1)
	//			sum += tmp;
	//		cin >> tmp;
	//	}

	// 잘못된 코드
	// 초기화 되지 않은 변수 tmp가 우연히 -1이 된다면 코드가 작동X
	//	while (tmp != -1) {
	//		cin >> tmp;
	//		if (tmp % 2 == 1)
	//			sum += tmp;
	//	}
	cout << "The sum is " << sum << endl;*/
#pragma endregion
#pragma region code10(정수 입력 후 sum<=0 이면 입력된 정수의 개수 출력)
/*	int sum = 0, count = 0;
	int tmp;

	// 내가 짠 코드
	// while 문만 쓰게 된다면 sum = 0이므로 바로 종료된다
	// -> 따라서 count = 1로 초기화하고 
	// 반복문 앞에 tmp입력과 sum값을 갱신해주면 해결되지 않을까란 생각을 함
	// 이럴때 do-while문을 이용하는게 효율적이다는 것을 깨달음
	// 
	cin >> tmp; 
	sum += tmp;
	
	while (sum>0) {
		cin >> tmp;
		count++;
		sum += tmp;
	}

	cout << "The count is " << count << endl;

	// 개선 코드(do-while문 사용)
	//	do {
	//		cin >> tmp;
	//		count++;
	//		sum += tmp;
	//	} while (sum>0);
	//	cout << "The count is " << count << endl;
	// 
	// 참고 코드(break 사용)
	//	while (1) {
	//		cin >> tmp;
	//		count++;
	//		sum += tmp;
	//		if (sum<=0)
	//		{
	//			cout << "The count is " << count << endl;
	//			break;
	//		}
	//	}*/
#pragma endregion
#pragma region code11(각 자리수의 합 구하기)
	/*int N;
	cin >> N;
	int sum = 0;
	while (N > 0) {
		sum += N % 10;
		N /= 10;
	}
	cout << "The Sum is " << sum << endl;*/
#pragma endregion
#pragma region code12(양의 정수 N보다 작거나 같은 수중 가장 큰 2의 거듭제곱 수 출력)
/*	int N;
	cin >> N;

	int p = 1;

	// 실수 했던점
	// 조건문에서 무조건 p에 2를 곱해줘야 된다. 그래야 더 커진 값이 안나온다.
	while (p * 2 <= N)
		p *= 2;
	cout << "The answer is " << p << endl;

	// break문 사용
	// 
	//	while (1)
	//	{
	//		if (N < p*2)
	//		{
	//			cout << "Max power is " << p << endl;
	//			break;
	//		}
	//		p *= 2;
	//	}*/
#pragma endregion

#pragma endregion

	return 0;
}
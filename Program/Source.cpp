#include <iostream>
using namespace std;

const int MAX = 100; // 배열의 최대 크기를 정의하는 상수

int main() {
#pragma region 1.3 배열 (code17~27)
	// 배열에는 동일한 타입의 여러개의 데이터를 저장하며, 배열의 크기는 고정이다. 
	// 배열의 크기와 배열에 저장된 데이터 개수는 다를 수 있다.
	// 
#pragma region code17(사용자로부터 n<=100 개의 정수를 입력받은 후 합(sum)과 최대값(maximum)을 구하여 출력한다.)
	int data[MAX];

	int n;
	cin >> n; // 배열에 저장된 데이터 개수 입력
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}

	int sum = 0, max = data[0];
	for (int i = 0; i < n; i++)
	{
		sum += data[i];
		if (data[i] > max)
		{
			max = data[i];
		}
	}
	cout << "The sum is " << sum << "and the m,aximum is " << max << endl;
#pragma endregion


#pragma endregion

	return 0;
}
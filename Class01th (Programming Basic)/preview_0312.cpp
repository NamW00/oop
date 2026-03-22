#include <iostream>
#include <string>
using namespace std;

int main() {
#pragma region 1.3 배열(array)
#pragma region code17(n개의 정수 입력후, 합과 최대값 구하기)
	/*
	// 배열에는 동일한 타입의 여러개의 데이터 저장 가능하다.
	// 배열의 크기는 고정이다.
	// 배열의 크기와 배열에 저장된 데이터 개수는 다를 수 있다.
	int data[MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	int sum = 0, max = data[0];
	for (int i = 0; i < n; i++)
	{
		sum += data[i];
		if (data[i]>max)
		{
			max = data[i];
		}
	}
	cout << sum << ", " << max << endl;
	*/
#pragma endregion
#pragma region code18(입력된 정수중 몇번째 정수인지 출력, 존재하지 않으면 -1출력)
	/*
	int n, k;
	int data[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];
	cin >> k;
	for (int i = 0; i < n; i++){
		// 이렇게 순서대로 검사하는 방법을 순차검색(sequential search)라고 부른다.
		if (data[i] == k){
			cout << i << endl;
			return 0; // 꼭 main함수에서 return 0가 하나일 필요는 없다.
		}
	}
	cout << -1 << endl;
	*/
#pragma endregion
#pragma region code19(문자열 입력받아 저장하고 두 문자열을 입력받아 사전식 순서로 출력)
	/*
	string words[MAX];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> words[i];

	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i < n; i++){
		if (words[i] >= str1 && words[i] <= str2){
			// 연산자(==, !=, >, <, >=, <=)로 문자열을 비교할 수 있다.
			cout << words[i] << endl;
		}
	}
	*/
#pragma endregion
#pragma region code20(n개의 정수를 입력받아 배열에 저장, 하나의 정수s를 입력받은후 합이 s가되는 쌍의 개수 카운트)
	/*
	int n;
	int data[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];

	int s;
	cin >> s;
	int count = 0;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){ // i < j인 만족하는 순서쌍만 구하면 되므로
			if (data[i] + data[j] == s)
				count++;
		}
	}
	cout << count << endl;
	*/
#pragma endregion
#pragma region code21(n개의 배열중 1개 이상의 연속된 정수들을 더하여 얻을 수 있는 최대값 구하기)
	/*
	int n;
	int data[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];

	int maxSum = 0;
	for (int i = 0; i < n; i++){
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += data[j];
			if (sum > maxSum)	// 이때까지의 합이 maxSum으로 저장했던 값 보다 크면
				maxSum = sum;	// sum값을 maxSum값으로 갱신한다.
		}
	}
	cout << maxSum << endl;
	*/
#pragma endregion
#pragma region code22(n개의 입력받은 정수를 순서대로 배열 후 같은 수가 가장 많이 나오면 카운트)
	/*
	int n;
	int data[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];
	int count = 1, max_count = 1;
	for (int i = 0; i < n; i++)
	{
		if (data[i] == data[i - 1])
			count++;
		else
			count = 1;
		if (count > max_count)
			max_count = count;
	}

	std::cout << max_count << endl;
	*/
#pragma endregion
#pragma region code23(버블정렬 오름차순)
	/*
	int n;
	int data[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];
	// bubble sort
	int tmp = 0;
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			// data[0] ~ data[i] 중에서 최대값을 data[i]위치로 몰아가는것
			if (data[j] > data[j+1]){
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << data[i] << ", ";
	}
	*/
#pragma endregion
#pragma region code24( )

#pragma endregion
#pragma region code25( )

#pragma endregion

#pragma endregion

	return 0;
}
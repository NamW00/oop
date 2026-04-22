#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
#pragma region 1.3 배열(code17~27)
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
	for (int i = 0; i < n-1; i++){ // i와 j가 순서가 겹치지 않을때의 마지막 i가 n-2번째 항을 가리켜야하므로
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

	int maxSum = 0;					// 합 계산할때 주의할 점 : 초기값 설정
	// if 모든 입력값이 음수라면 초기값인 0보다 작으므로 maxSum에 제대로 반영되기 힘들다
	// 따라서 초기값은 data[0]과 같은 값으로 해주어야 오류 방지가 가능하다. 
	for (int i = 0; i < n; i++){	// 구간합의 시작점 i
		int sum = 0;				// i++ 하며 sum의 값 계산
		for (int j = i; j < n; j++){ // i번째항 부터 임의의 값 j번째항(j<n)까지의 구간 합이 maxSum보다 큰지에 대해 조사
			sum += data[j];
			if (sum > maxSum)		// 이때까지의 합이 maxSum 값 보다 크면
				maxSum = sum;		// sum값을 maxSum값으로 갱신한다.
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
#pragma region code24(n개의 정수를 입력받은 후 중복된 정수들을 제거하고 남은 정수들만 출력)
	/*
	int n;
	int data[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];

	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (data[j] > data[j+1])
			{
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (data[i] != data[i - 1]) data[++k] = data[i];
	}

	for (int i = 0; i < k; i++)
	{
		cout << data[i] << " ";
	}
	*/
#pragma endregion
#pragma region code25(정수가 입력될 때 마다 오름차순으로 정렬)
	/*
	int n, t;
	int data[MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		int j = i - 1; // 앞에서 부터 조사하기보다 뒤에서 부터 조사하는게 효율적
		while (j >= 0 && data[j] > t) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = t;
		for (int k = 0; k <= i; k++)
			cout << data[k] << " ";
		cout << endl;
	}
	*/
#pragma endregion
#pragma region code26(n*n크기의 2차원 배열을 입력받아 열우선 순위로 출력)
	/*
	int n;
	int mat[MAX][MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];

	//for (int i = 0; i < n; i++)
	//	for (int j = 0; j < n; j++)
	//		cout << mat[j][i] << " ";
	cout << endl;
	for (int j = 0; j < n; j++) //열 우선순위
		for (int i = 0; i < n; i++)
			cout << mat[i][j] << " ";
	*/
#pragma endregion
#pragma region code27(n*n 크기의 2차원 배열에서 행의 합과 열의 평균을 계산하여 )
	/*
	int n;
	int mat[MAX][MAX];
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];

	int row_sum[MAX] = { 0 }, col_sum[MAX] = { 0 }; // 배열의 모든 값 0으로 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			row_sum[i] += mat[i][j]; // 행의 합
			col_sum[j] += mat[i][j]; // 열의 합
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << " | " << (double)row_sum[i] / n << endl;
	}
	for (int j = 0; j < n; j++)
		cout << "--";
	cout << endl;
	for (int j = 0; j < n; j++)
	{
		cout << (double)col_sum[j] / n << " ";
	}
	*/
#pragma endregion
#pragma endregion
	return 0;
}
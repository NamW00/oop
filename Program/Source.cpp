#include <iostream>

using namespace std;

int main() {
#pragma region Group Activity 01
#pragma region ex03
	/*	
	int age;
	bool teenager;
	cin >> age;

	
	if (age >= 13) {
		if (age <= 19){
			teenager = true;
			cout << "teenager True!" << endl;
		}
		else{
			teenager = false;
			cout << "teenager False!" << endl;
		}
	}
	else if (age < 13)
	{
		teenager = false;
		cout << "teenager False!" << endl;
	}
	
	//	if (age >= 13 && age <= 19)
	//		teenager = true;
	//	else
	//		teenager = false; 
	*/

#pragma endregion
#pragma region ex09
		/*
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (b < c || a > d)
			cout << "두 구간은 겹치는 구간이 존재하지 않는다!" << endl;
		else
			cout << "두 구간은 겹친다!" << endl;
		*/
#pragma endregion
#pragma region ex14
		/*
		int v = 1, N = 20;
		while (v <= N / 2) {
			cout << v;
			v *= 2;
			cout << " >> " << v << "\t";
		}
		cout << endl;
		cout << "while문 밖에서의 v값 : " << v << endl;

		// 1 >> 2  2 >> 4  4 >> 8  8 >> 16
		// while문 밖에서의 v값 : 16
		*/


		/*
		int v = 1, N = 20;
		for (int v = 1; v <= N/2; )
		{
			cout << v;
			v *= 2;
			cout << " >> " << v << "\t";
		}
		cout << endl;
		cout << "for문 밖에서의 v값 : " << v << endl;
		//	1 >> 2  2 >> 4  4 >> 8  8 >> 16
		//	for문 밖에서의 v값 : 1
		*/

		/*
		int v = 1, N = 20;
		for (int v = 1; v <= N / 2; v *= 2)
		{
			cout << v << "\t";
		}
		cout << endl;
		cout << "for문 밖에서의 v값 : " << v << endl;
		// v 출력값
		// for문 내부 : 1 2 4 8
		// for문 밖에서는 1
		*/
#pragma endregion
#pragma region ex20

		int N = 6;
		int b[6] = {1, 2, 3, 4, 5, 6};

		for (int i = 0; i < N/2; i++)
		{
			double temp = b[i];
			b[i] = b[N - 1 - i];
			b[N - 1 - i] = temp;
		}
		cout << endl;
		for (int i = 0; i < N; i++)
		{
			cout << b[i] << "\t";
		}

#pragma endregion

#pragma endregion

	

	return 0;
}
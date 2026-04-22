#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> unionVectors(vector<int> nums1, vector<int> nums2) {
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	vector<int> result;
	result.reserve(nums1.size() + nums2.size());

	int i = 0, j = 0;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
			result.push_back(nums1[i++]);
		else if (nums1[i] > nums2[j])
			result.push_back(nums2[j++]);
		else {
			result.push_back(nums1[i++]);
			j++;
		}
	}
	while (i < nums1.size()) result.push_back(nums1[i++]);
	while (j < nums2.size()) result.push_back(nums2[j++]);

	return result;
}
string reverse_str(string& str) {
	string result = ""; // 변수명을 함수명과 다르게 설정

	// 1. i의 시작을 마지막 인덱스(length - 1)로 설정
	// 2. i가 0이 될 때까지(첫 번째 문자 포함) 반복
	for (int i = str.length() - 1; i >= 0; i--) {
		result += str[i]; // push_back 또는 += 를 사용하여 안전하게 추가
	}

	return result;
}
int main() {
#pragma region ex07

#pragma endregion
#pragma region ex08_1
	/*
	vector<int> v;
	for (int i = 1; i <= 5; i++)
		v.push_back(i);
	vector<int>::iterator it = v.begin();
	*it = 3;
	for (it = v.begin(); it < length; i++)
	{

	}
	*/
#pragma endregion
#pragma region ex08_2
	/*
	vector<string> vec;
	vector<string> vec2;

	vec.push_back("India ");
	vec.push_back("UP ");
	vec.push_back("Noida ");
	vec2 = vec;

	vector<string>::reverse_iterator iter = vec.rbegin();
	vector<string>::reverse_iterator iter2 = vec2.rbegin();
	while (iter != vec.rend())
	{
		cout << *iter;
		++iter;
	}
	cout << endl;
	while (iter2 != vec2.rend())
	{
		cout << *iter2;
		++iter2;
	}
	*/
#pragma endregion
#pragma region ex08_3
	/*
	vector<int> v1;
	vector<int> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(7);
	v2.push_back(8);
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	v1.swap(v2);
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	*/
#pragma endregion
#pragma region ex08_4
	/*
	vector<int> v1;
	vector<int> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	if (v1 == v2)
	{
		cout << "both are equal";
	}
	else
	{
		cout << "both are not equal";
	}
	*/
#pragma endregion
#pragma region ex08_5
	/*
	vector<int> vec;
	for (int i = 1; i <= 10; i++)
	{
		vec.push_back(i);
	}

	// vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	vec.erase(vec.begin() + 5); // 6
	vec.erase(vec.begin(), vec.begin() + 3); // 시작점 포함, 끝점은 포함X

	cout << "The vec.size() = " << vec.size() << endl;

	for (unsigned i = 0; i < vec.size(); ++i)
	{
		cout << ' ' << vec[i];
	}
	*/
#pragma endregion
#pragma region ex11
/*	vector<int> nums1 = { 3, 2, 1 };
	vector<int> nums2 = { 3, 4, 5 };
	vector<int> result = unionVectors(nums1, nums2);
	for (int num : result)
	cout << num << " "; // "1, 2, 3, 4, 5"가 출력됨. 단, 순서는 상관없음
	cout << endl;*/
	#pragma endregion
#pragma region ex12
	
#pragma endregion


	return 0;
}
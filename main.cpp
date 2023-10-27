#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	//1~52 중 랜덤 숫자
	srand(time(nullptr));
	cout << "임의 숫자 추출" << endl;
	for (int i = 0; i <= 4; i++)
	{
		cout << (rand() % 52)<<" ";
	}
	


	cout << endl;
	cout << endl;
	cout << endl;
	//금일 로또 추천 번호
	cout << "이번주 로또 추천번호" << endl;
	for  (int i = 1; i <= 7; i++)
	{
		cout << rand() % 52<<" ";
	}
	cout<< endl;
}
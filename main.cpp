#include <iostream>
#include <ctime>

#define MaxNumber 52

using namespace std;
class NumberExtract
{
public:
	NumberExtract();
	~NumberExtract();

	void start();

private:

	int Array[52];
};

NumberExtract::NumberExtract()
{
}

NumberExtract::~NumberExtract()
{
}
void NumberExtract::start()
{
	cout << "���� ���� ����" << endl;
	for (int i = 0; i < MaxNumber; i++)
	{
		Array[i] = i + 1;
	}


	for (int i = 0; i < 1000; i++)
	{
		int First = rand() % 52;
		int Second = rand() % 52;
		//
		int Temp = Array[First];
		Array[First] = Array[Second];
		Array[Second] = Temp;
		//
	}
	for (int i = 0; i < 4; ++i)
	{
		cout << Array[i] << " ";
	}
}
int main()
{
	//1~52 �� ���� ����
	srand((unsigned int)time(nullptr));
	int Array[52];//0~51

	

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	//���� �ζ� ��õ ��ȣ
	cout << "�̹��� �ζ� ��õ��ȣ" << endl;
	for (int i = 1; i <= 7; i++)
	{
		Array[i] = (rand() % 52);
		cout << Array[i] << " ";
	}
	cout << endl;
}
	
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
	srand((unsigned int)time(nullptr));
	cout << "임의 숫자 추출" << endl;
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
		
		int CardType = (Array[i]) / 13;
		if (CardType == 0)
		{
			cout << "spade" << endl;
		}
		else if (CardType == 1)
		{
			cout << "CLover" << endl;
		}
		else if (CardType == 2)
		{
			cout << "HEart" << endl;
		}
		else
		{
			cout << "Diamond" << endl;
		}

		int CardNumber = Array[0] % 13;

		if (CardNumber == 10)
		{
			cout << "J" << endl;
		}
		else if (CardNumber == 12)
		{
			cout << "K" << endl;
		}
		else if (CardNumber == 13)
		{
			cout << "Q" << endl;
		}
		else
		{
			cout << Array[i] << endl;
		}

		int PlayerScore = 0;
		int ComputerScore = 0;

		if (i<2)
		{
			if (CardNumber > 10)
			{
				ComputerScore += 10;
			}
			else
			{
				ComputerScore += CardNumber;
			}
		}
		else
		{
			if (CardNumber>10)
			{
				PlayerScore += 10;
			}
			else
			{
				PlayerScore += CardNumber;
			}

		}
	}

	
}
int main()
{
	//1~52 중 랜덤 숫자
	
	
	NumberExtract numbverextract;
	numbverextract.start();

	cout << endl;

	
}
	
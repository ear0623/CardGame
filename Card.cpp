#include "Card.h"


using namespace std;


CardDeck::CardDeck()
{
	//ī�� ����
	string Shape[] = { "��","��","��","��" };
	string Number[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	//����
	for (const string& shape : Shape)
	{
		for (const string& number : Number)
		{
			Card.push_back(shape + number);


			if (number == "A")
			{
				StringToInt = 1;
			}
			else if (number == "J" || number == "Q" || number == "K")
			{
				StringToInt = 10;
			}
			else
			{
				StringToInt = std::stoi(number);
			}
			//ī�帶�� ���� ����
			Value.push_back(StringToInt);

		}
	}


}


CardDeck::~CardDeck()
{

}



void CardDeck::Shuffle()
{
	//ī�� ����
	//std::random_shuffle(Card.begin(), Card.end());

	//�ٸ����
	//for (int Shuffle = 0; Shuffle < 52; Shuffle++)
	//{
	//	std::swap(Card[Shuffle], Card[Shuffle+1]);
	//}

	//�ٸ����
	for (int Shuffle = 0; Shuffle < 52; Shuffle++)
	{
		//ī�� ����
		std::string Temp_String;
		Temp_String = Card[Shuffle];
		Card[Shuffle] = Card[Shuffle + 1];
		Card[Shuffle + 1] = Temp_String;
		//���� ������ ���� ����
		int Temp_Number;
		Temp_Number = Value[Shuffle];
		Value[Shuffle] = Value[Shuffle + 1];
		Value[Shuffle + 1] = Temp_Number;
	}

}


Player::Player()
{
	//�޸� ���� �ʿ� �������� �����Ͱ� ���.
	//string�̶� vector�� �̹� �迭�̶� �׳� ����Ʈ �ع���;
	DrawCard = new std::vector<string>;
	RandomIndex = 0;
	LastNumber = 0;
	Sum = 0;

	ExtractNumber = LastNumber;


}

Player::~Player()
{
	delete DrawCard;
	DrawCard = nullptr;

}

int Player::Addcard(int AddIndex)
{
	//�Ź� �ʱ�ȭ
	srand((unsigned int)time(nullptr));
	//�̱�
	RandomIndex = (std::rand() % AddCard.Card.size());
	RandomIndex += AddIndex;

	//DrawCard->push_back(AddCard.Card.back());//���ٷ� �����°� �����ϱ� �� ����
	std::string LastCard = AddCard.Card[RandomIndex];
	DrawCard->push_back(LastCard);

	//���� ����
	//Score->push_back(AddCard.Value.back());//���ٷ� �����°� �����ϱ� �� ����
	LastNumber = AddCard.Value[RandomIndex];
	SaveNumber.push_back(LastNumber);

	
	//����
	AddCard.Card.erase(AddCard.Card.begin() + RandomIndex);
	//���� ����
	AddCard.Value.erase(AddCard.Value.begin() + RandomIndex);
	//���� ����
	//erase �Լ�// �����~// pop_back() �����.
	cout << LastCard;

	Sum += LastNumber;
	ExtractNumber = Sum;
	return ExtractNumber;
}

void Player::CalculateScore()
{
	
	cout << Sum;

}
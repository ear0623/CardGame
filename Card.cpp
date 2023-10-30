#include "Card.h"


CardDeck::CardDeck()
{
	//ī�� ����
	std::string Shape[] = { "��","��","��","��" };
	std::string Number[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	//����
	for (const std::string& shape : Shape)
	{
		for (const std::string& number : Number)
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
	//�޸� ���� �ʿ�
	DrawCard = new std::vector<std::string>;
	RandomIndex = 0;
	LastNumber = 0;
	Sum = 0;


}

Player::~Player()
{
	//delete[] DrawCard;

}

void Player::Addcard()
{
	//�Ź� �ʱ�ȭ
	srand((unsigned int)time(nullptr));
	//�̱�
	RandomIndex = std::rand() % AddCard.Card.size();

	//DrawCard->push_back(AddCard.Card.back());//���ٷ� �����°� �����ϱ� �� ����
	std::string LastCard = AddCard.Card[RandomIndex];
	DrawCard->push_back(LastCard);

	//���� ����
	//Score->push_back(AddCard.Value.back());//���ٷ� �����°� �����ϱ� �� ����
	LastNumber = AddCard.Value[RandomIndex];
	SaveNumber.push_back(LastNumber);

	std::cout << LastCard << " ";

	//����
	AddCard.Card.erase(AddCard.Card.begin() + RandomIndex);
	//���� ����
	AddCard.Value.erase(AddCard.Value.begin() + RandomIndex);
	//���� ����
	//erase �Լ�// �����~// pop_back() �����.



}

void Player::CalculateScore()
{

	for (int i = 0; i < SaveNumber.size(); i++)
	{


		Sum += SaveNumber[i];


	}
	std::cout << Sum << std::endl;

}
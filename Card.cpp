#include "Card.h"


CardDeck::CardDeck()
{
	//카드 정의
	std::string Shape[] = { "♠","♣","♡","◆" };
	std::string Number[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	//생성
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
			//카드마다 값을 대입
			Value.push_back(StringToInt);

		}
	}


}


CardDeck::~CardDeck()
{

}



void CardDeck::Shuffle()
{
	//카드 셔플
	//std::random_shuffle(Card.begin(), Card.end());

	//다른방법
	//for (int Shuffle = 0; Shuffle < 52; Shuffle++)
	//{
	//	std::swap(Card[Shuffle], Card[Shuffle+1]);
	//}

	//다른방법
	for (int Shuffle = 0; Shuffle < 52; Shuffle++)
	{
		//카드 섞기
		std::string Temp_String;
		Temp_String = Card[Shuffle];
		Card[Shuffle] = Card[Shuffle + 1];
		Card[Shuffle + 1] = Temp_String;
		//같은 순서로 값도 섞기
		int Temp_Number;
		Temp_Number = Value[Shuffle];
		Value[Shuffle] = Value[Shuffle + 1];
		Value[Shuffle + 1] = Temp_Number;
	}

}


Player::Player()
{
	//메모리 해제 필요
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
	//매번 초기화
	srand((unsigned int)time(nullptr));
	//뽑기
	RandomIndex = std::rand() % AddCard.Card.size();

	//DrawCard->push_back(AddCard.Card.back());//두줄로 나누는게 대입하기 더 편함
	std::string LastCard = AddCard.Card[RandomIndex];
	DrawCard->push_back(LastCard);

	//값도 같이
	//Score->push_back(AddCard.Value.back());//두줄로 나누는게 대입하기 더 편함
	LastNumber = AddCard.Value[RandomIndex];
	SaveNumber.push_back(LastNumber);

	std::cout << LastCard << " ";

	//제거
	AddCard.Card.erase(AddCard.Card.begin() + RandomIndex);
	//값도 같이
	AddCard.Value.erase(AddCard.Value.begin() + RandomIndex);
	//값도 같이
	//erase 함수// 지운다~// pop_back() 지운다.



}

void Player::CalculateScore()
{

	for (int i = 0; i < SaveNumber.size(); i++)
	{


		Sum += SaveNumber[i];


	}
	std::cout << Sum << std::endl;

}
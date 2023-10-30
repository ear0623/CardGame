#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

class CardDeck
{
public:
	CardDeck();
	~CardDeck();

	//�����Ҵ�
	std::vector<std::string> Card;
	std::vector<int> Value;

	void Shuffle();




private:

	int StringToInt = 0;
};

class Player :public CardDeck
{
public:
	Player();
	~Player();

	void Addcard();
	void CalculateScore();



private:
	CardDeck AddCard;
	std::vector<std::string>* DrawCard;
	int RandomIndex;
	int LastNumber;
	std::vector<int> SaveNumber;
	int Sum;

};

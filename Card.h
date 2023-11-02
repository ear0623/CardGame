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
	//PROPERTy
	int ExtractNumber;
	//동적할당
	std::vector<std::string> Card;
	std::vector<int> Value;

	void Shuffle();

protected:



private:

	int StringToInt = 0;
};

class Player :public CardDeck
{
public:
	Player();
	~Player();

	int Addcard(int AddIndex);
	void CalculateScore();

protected:


private:
	CardDeck AddCard;
	std::vector<std::string>* DrawCard;
	int RandomIndex;
	int LastNumber;
	std::vector<int> SaveNumber;
	int Sum;
};

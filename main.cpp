#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> CardDeck(52);

	// 덱에 카드를 저장
	for (int CardNumber = 0; CardNumber < 52; CardNumber++)
	{
		CardDeck[CardNumber] = (CardNumber + 1);
	}
	//카드 셔플
	srand((unsigned int)time(NULL));


	std::random_shuffle(CardDeck.begin(), CardDeck.end());

	//카드 만들기
	int DrawCardType{};
	int DrawCardNumber{};

	//스코어
	int PlayerScore{};
	int AiScore{};

	//PlayCharacter
	std::vector<int> PlayerCards;
	std::vector<int> AiCards;
	int GetCard = 0;


	//게임 플레잉
	for (int DrawCard = 0; DrawCard < 4; DrawCard++)
	{

		//카드모양
		DrawCardType = CardDeck[DrawCard] / 13;

		if (DrawCardType == 0)
		{
			std::cout << "♠";


		}
		else if (DrawCardType == 1)
		{
			std::cout << "♣";

		}
		else if (DrawCardType == 2)
		{
			std::cout << "♡";

		}
		else
		{
			std::cout << "◆";


		}

		//카드넘버
		DrawCardNumber = CardDeck[DrawCard] % 13;

		if (DrawCardNumber == 11)
		{
			std::cout << "J";
		}
		else if (DrawCardNumber == 12)
		{
			std::cout << "Q";
		}
		else if (DrawCardNumber == 13)
		{
			std::cout << "K";
		}
		else if (DrawCardNumber == 0)
		{
			DrawCardNumber = 1;
			std::cout << DrawCardNumber;
		}
		else
		{
			std::cout << DrawCardNumber;
		}
		std::cout << " " << std::endl;

		//카드data 저장

		if ((float)(DrawCard / 2) == 0.0f)
		{
			PlayerCards.push_back(DrawCardNumber);
		}
		else
		{
			AiCards.push_back(DrawCardNumber);
		}
	}

	//점수계산
	for (int HaveCard  = 0; HaveCard < 2; HaveCard++)
	{
		if (PlayerCards[HaveCard] == 11 || PlayerCards[HaveCard] == 12 || PlayerCards[HaveCard] == 13)
		{
			PlayerScore += 10;
			std::cout << PlayerCards[HaveCard] << std::endl;
		}
		else
		{
			PlayerScore += PlayerCards[HaveCard];
			std::cout << PlayerCards[HaveCard] << std::endl;

		}
		if (AiCards[HaveCard] == 11 || AiCards[HaveCard] == 12 || AiCards[HaveCard] == 13)
		{
			AiScore += 10;
			std::cout << AiCards[HaveCard] << std::endl;
		
		}
		else
		{
			AiScore += AiCards[HaveCard];
			std::cout << AiCards[HaveCard] << std::endl;
		}
	}
	

	

		std::cout << " " << std::endl;

	std::cout <<"PlaerScore " << PlayerScore << " : " <<" AiScore " << AiScore << std::endl;
	
	//승패 계산
	if (PlayerScore >=AiScore)
	{
		if (PlayerScore < 22)
		{
			std::cout << "PlayerWin" << std::endl;

		}
		else
		{
			std::cout << "AiWin" << std::endl;
		}
	}
	else
	{
		if (AiScore < 22)
		{
			std::cout << "AiWin" << std::endl;

		}
		else
		{
			std::cout << "PlayerWin" << std::endl;
		}
	}

	return 0;

}
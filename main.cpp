#include "Card.h"
#include <iostream>


class Play
{
public:
	Play();
	~Play();

	void Init();
	void Draw();
	void Play_Game();
	void End_Game();
	void Restart();



private:
	CardDeck Main_Card;
	Player Main_Player;
	Player Main_Dealer;
	bool bIsRunning;

	//PlayGame
	const std::string Text = "get";
	const std::string Text_Exit = "break";
	const std::string ReStart = "Yes";
	const std::string Exit = "No";
	std::string Input = " ";

	

};

Play::Play()
{
	bIsRunning = true;
	
}

Play::~Play()
{
	

}
void Play::Init()
{

}
void Play::Draw()
{

}
void Play::Play_Game()
{
	std::cout << "get을 입력해주세요" << std::endl;

	
	while (bIsRunning)
	{
		std::cin >> Input;

		if (Input == Text)
		{
		
			if (Main_Player.ExtractNumber<22)
			{
				std::cout << "  " << " Player Card : ";
				Main_Player.Addcard(0);
				std::cout << "      ";
				std::cout << "  " << " Dealer Card : ";
				Main_Dealer.Addcard(1);
				std::cout << "      ";
			
				if (Main_Player.ExtractNumber > 22 && Main_Dealer.ExtractNumber > 22)
				{
					
					std::cout << "    " << std::endl;
					std::cout << "Player Score : ";
					Main_Player.CalculateScore();
					std::cout << "      ";
					std::cout << "Dealer Score : ";
					Main_Dealer.CalculateScore();
					std::cout << "      ";
					std::cout << "Draw!";
				
					break;
				}
				else if(Main_Player.ExtractNumber>22)
				{
					
					std::cout << "    "<< std::endl;
					std::cout << "Player Score : ";
					Main_Player.CalculateScore();
					std::cout << "      ";
					std::cout << "Dealer Score : ";
					Main_Dealer.CalculateScore();
					std::cout << "      ";
					std::cout << " Dealer Wim!";
				
					break;
				}
				else if(Main_Player.ExtractNumber > 22)
				{
					
					std::cout << "    " << std::endl;
					std::cout << "Player Score : ";
					Main_Player.CalculateScore();
					std::cout << "      ";
					std::cout << "Dealer Score : ";
					Main_Dealer.CalculateScore();
					std::cout << "      ";
					std::cout << " Player Wim! ";
					
					break;
				}
				else
				{

				}
			}
			else
			{

			}
			
		}
		else if (Input == Text_Exit)
		{
			std::cout << "    ";
			std::cout << "Player Score : ";
			Main_Player.CalculateScore();
			std::cout << "      ";
			std::cout << "Dealer Score : ";
			Main_Dealer.CalculateScore();
			std::cout << "      ";
			
		}
		else
		{
			
		}


	}
	Restart();

}
void Play::End_Game()
{

}
void Play::Restart()
{
	std::cout << "한판 더 하시겠습니까? (Yes or No) :";
	std::cin >> Input;
	if (Input == ReStart)
	{
		//게임 재시작
		bIsRunning = true;
		std::cout << "Ture" << std::endl;

	}
	else if (Input == Exit)
	{
		bIsRunning = false;
		
	}
	else
	{
		bIsRunning = false;
	}
}
int main()
{

	Play play;
	play.Play_Game();
	




	return 0;
}
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



private:
	CardDeck Main_Card;
	Player Main_Player;
	bool bIsRunning;

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

	std::string Text = "get";
	std::string Text_Exit = "break";
	std::string Input = " ";

	while (bIsRunning)
	{
		std::cin >> Input;
		if (Input == Text)
		{
			std::cout << "  " << " Player Card : ";
			Main_Player.Addcard();

		}
		else if (Input == Text_Exit)
		{
			bIsRunning = false;
			break;
		}
		else
		{
			std::cout << "  " << " Dealer Card : ";
			Main_Player.Addcard();
		}
	}



}
void Play::End_Game()
{

}
int main()
{

	Play play;
	play.Play_Game();




	return 0;
}
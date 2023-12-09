#include "GameEngine.h"
#include "TicTacToeGame.h"

int main(int argc, char* args[])
{
	GameEngine engine = GameEngine();
	TicTacToeGame* loadedGame =  engine.InitGame<TicTacToeGame>();
	engine.Run();
	return 0;
}



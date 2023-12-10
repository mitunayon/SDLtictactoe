#include "pch.h"
#include "../TicTacToeGame/include/GameEngine.h"
#include "../TicTacToeGame/include/TicTacToeGame.h"

// Walking Skeleton
TEST(WalkingSkeleton, SmokeTest)
{
	bool gameRan = false;

	//Start the engine and load a game
	GameEngine engine = GameEngine();
	TicTacToeGame* loadedGame = engine.InitGame<TicTacToeGame>();
	engine.Run();
	gameRan = engine.IsRunning();
	engine.Shutdown();

	EXPECT_TRUE(gameRan);
}


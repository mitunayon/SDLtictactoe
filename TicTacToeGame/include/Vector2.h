#pragma once
struct Vector2
{
	Vector2() 
	{
		X = 0;
		Y = 0;
	};

	Vector2(int x, int y) 
	{
		X = x;
		Y = y;
	};

	int X;
	int Y;
};


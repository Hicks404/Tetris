#include "block.h"

#include <iostream>

namespace MathLibrary
{
	Block::Block(blockStruct data, int x, int y) 
		: data{ data }, xPos{ x }, yPos{ y }, freeze{ false }
	{}

	Block::~Block() {}

	void Block::Move(int x, int y)
	{
		xPos += x;
		yPos += y;
	}

	void Block::Set(int x, int y)
	{
		xPos = x;
		yPos = y;
	}

	int Block::GetX()
	{
		return xPos;
	}

	int Block::GetY()
	{
		return yPos;
	}

	bool Block::GetSpecShape(int i, int j)
	{
		if (data.shape[i][j] != 0)
		{
			return true;
		}
		return false;
	}

	void Block::SetFreeze(bool val)
	{
		freeze = val;
	}

	bool Block::GetFreeze()
	{
		return freeze;
	}
}

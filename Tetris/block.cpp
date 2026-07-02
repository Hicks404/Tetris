#include "block.h"

#include <iostream>

namespace MathLibrary
{
	Block::Block(blockStruct data, int x, int y) 
		: data{ data }, xPos{ x }, yPos{ y }, freeze{ false }, width{ data.width }, height{ data.height }
	{}

	Block::~Block() {}

	void Block::Move(int x, int y)
	{
		xPos += x;
		yPos += y;

		xPos = std::min(xPos, 10 - data.leftOffset - width);
		xPos = std::max(xPos, 0 - data.leftOffset);
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

	int Block::GetH()
	{
		return height;
	}

	int Block::GetW()
	{
		return width;
	}

	void Block::SetH(int h)
	{
		height = h;
	}

	void Block::SetW(int w)
	{
		width = w;
	}

	void Block::SwapDim()
	{
		int oldWidth = width;
		width = height;
		height = oldWidth;
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

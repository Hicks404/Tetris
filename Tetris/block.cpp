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

		xPos = std::min(xPos, 10 - data.offset - width);
		xPos = std::max(xPos, 0 - data.offset);
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

	Color Block::GetColor()
	{
		return data.color;
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

		// Also fixes offset
		for (int i = 0; i < 4; ++i)
		{
			bool foundOne = false;
			for (int j = 0; j < 4; ++j)
			{
				if (data.shape[j][i] == 1)
				{
					foundOne = true;
					break;
				}
			}

			if (foundOne)
			{
				data.offset = i;
				return;
			}
		}
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

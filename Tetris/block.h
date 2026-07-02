#pragma once

#include "blockdata.h"

namespace MathLibrary
{
	class Block
	{
	public:
		Block(blockStruct data, int x, int y);
		~Block();

	public:
		void Move(int x, int y);
		void Set(int x, int y);

		int GetX();
		int GetY();
		int GetH();
		int GetW();

		void SetH(int h);
		void SetW(int w);

		void SwapDim();

		bool GetSpecShape(int i, int j);

		void SetFreeze(bool val);
		bool GetFreeze();

	public:
		blockStruct data;
		int shape[4][4];
		
	private:
		int xPos;
		int yPos;
		bool freeze;

		int width;
		int height;
	};
}
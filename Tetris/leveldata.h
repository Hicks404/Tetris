#pragma once

#include <raylib/raylib.h>
#include <unordered_map>

using std::unordered_map;

namespace MathLibrary
{
	// level of each score
	inline unordered_map<int, int> levelmap
	{
		{1, 0},
		{2, 10},
		{3, 30},
		{4, 60},
		{5, 100},
		{6, 150},
		{7, 220},
		{8, 300},
		{9, 390},
		{10, 500},
		{11, 620},
		{12, 780},
		{13, 1000},
		{14, 12000},
		{15, 1500},
		{16, 1900},
		{17, 2400},
		{18, 3000},
		{19, 3800},
		{20, 5000},
	};
}
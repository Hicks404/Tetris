#pragma once

#include <raylib/raylib.h>
#include <unordered_map>

using std::unordered_map;

struct blockStruct
{
	int shape[4][4];
	int width;
	int height;
	int leftOffset;
	int rightOffset;
	Color color;
	int weight;
};

namespace MathLibrary
{
	inline unordered_map<int, blockStruct> blockMap
	{
		{1, {
			{
			0,1,0,0,
			0,1,0,0,
			0,1,0,0,
			0,1,0,0
			},
			1,4,
			1,2,
			BLUE, 20} },

		{2, {
			{
			0,1,1,0,
			0,1,1,0,
			0,0,0,0,
			0,0,0,0
			},
			2,2,
			1,1,
			YELLOW, 20} },

		{3, {
			{
			0,0,0,0,
			0,1,1,0,
			1,1,0,0,
			0,0,0,0
			},
			3,2,
			0,1,
			RED, 20} },

		{4, {
			{
			0,0,0,0,
			1,1,0,0,
			0,1,1,0,
			0,0,0,0
			},
			3,2,
			0,1,
			GREEN, 20} },

		{5, {
			{
			0,1,0,0,
			0,1,0,0,
			0,1,1,0,
			0,0,0,0
			},
			2,3,
			1,1,
			ORANGE, 20} },

		{6, {
			{
			0,0,1,0,
			0,0,1,0,
			0,1,1,0,
			0,0,0,0
			},
			2,3,
			1,1,
			PINK, 20} },

		{7, {
			{
			0,0,0,0,
			0,1,0,0,
			1,1,1,0,
			0,0,0,0
			},
			3,2,
			0,1,
			PURPLE, 20} }
	};
}
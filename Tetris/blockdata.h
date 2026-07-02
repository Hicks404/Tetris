#pragma once

#include <raylib/raylib.h>
#include <unordered_map>

using std::unordered_map;

struct Pivot2dDim
{
	int x;
	int y;
};

struct blockStruct
{
	int shape[4][4];
	int width;
	int height;
	int offset;
	Pivot2dDim pivot;
	Color color;
	int weight;
};

namespace MathLibrary
{
	inline unordered_map<int, blockStruct> blockMap
	{
		// standard tetris blocks

		{1, {
			{
			0,0,0,0,
			1,1,1,1,
			0,0,0,0,
			0,0,0,0
			},
			4,1,
			0,
			{4,4},
			BLUE, 20} },

		{2, {
			{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0
			},
			2,2,
			1,
			{4,4},
			YELLOW, 20} },

		{3, {
			{
			0,1,1,0,
			1,1,0,0,
			0,0,0,0,
			0,0,0,0
			},
			3,2,
			0,
			{3,3},
			RED, 20} },

		{4, {
			{
			1,1,0,0,
			0,1,1,0,
			0,0,0,0,
			0,0,0,0,
			},
			3,2,
			0,
			{3,3},
			GREEN, 20} },

		{5, {
			{
			0,0,1,0,
			1,1,1,0,
			0,0,0,0,
			0,0,0,0
			},
			3,2,
			0,
			{3,3},
			ORANGE, 20} },

		{6, {
			{
			1,0,0,0,
			1,1,1,0,
			0,0,0,0,
			0,0,0,0
			},
			3,2,
			0,
			{3,3},
			BLUE, 20} },

		{7, {
			{
			0,1,0,0,
			1,1,1,0,
			0,0,0,0,
			0,0,0,0
			},
			3,2,
			0,
			{3,3},
			PURPLE, 20} },
		
		// custom blocks

		{8, {
			{
			1,1,0,0,
			0,0,0,0,
			0,0,0,0,
			0,0,0,0
			},
			2,1,
			0,
			{2,2},
			RED, 10} },
		
		{9, {
			{
			1,1,1,0,
			1,0,1,0,
			0,0,0,0,
			0,0,0,0
			},
			3,2,
			0,
			{3,3},
			RED, 10} },
		
		{10, {
			{
			0,1,0,0,
			1,1,1,0,
			0,1,0,0,
			0,0,0,0
			},
			3,3,
			0,
			{3,3},
			RED, 10} }
	};
}

// To do list
// fix rotation so it consistently goes 90 deg right
// stop push down controls for like half a second after block is frozen
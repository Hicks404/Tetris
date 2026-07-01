#pragma once

#include <raylib/raylib.h>
#include <unordered_map>

using std::unordered_map;

struct blockStruct
{
	int shape[4][4];
	Color color;
	int weight;
};

namespace MathLibrary
{
	inline unordered_map<int, blockStruct> blockMap
	{
		{1, {
			{
			1,0,0,0,
			1,0,0,0,
			1,0,0,0,
			1,0,0,0
			},
			BLUE, 20} },

		{2, {
			{
			1,1,0,0,
			1,1,0,0,
			0,0,0,0,
			0,0,0,0
			},
			YELLOW, 20} },

		{3, {
			{
			0,1,1,0,
			1,1,0,0,
			0,0,0,0,
			0,0,0,0
			},
			RED, 20} },

		{4, {
			{
			1,1,0,0,
			0,1,1,0,
			0,0,0,0,
			0,0,0,0
			},
			GREEN, 20} },

		{5, {
			{
			1,0,0,0,
			1,0,0,0,
			1,1,0,0,
			0,0,0,0
			},
			ORANGE, 20} },

		{6, {
			{
			0,1,0,0,
			0,1,0,0,
			1,1,0,0,
			0,0,0,0
			},
			PINK, 20} },

		{7, {
			{
			0,0,0,0,
			0,0,0,0,
			0,0,0,0,
			0,0,0,0
			},
			PURPLE, 20} }
	};
}
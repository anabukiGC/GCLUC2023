#include "AnimData.h"


static TexAnim playerRun[] = {
	{0,4},
	{1,4},
	{2,4},
	{3,4},
	{4,4},
	{5,4},
	{6,4},
	{7,4},
	{8,4},
};
static TexAnim playerJumpUp[] = {
	{9,4},
	{10,4},
	{11,4},
	{12,4},
};
static TexAnim playerJumpDown[] = {
	{13,10},
	{14,10},
	{15,8},
	/*
	{8,4},
	{6,4},
	{5,4},
	{4,4},
	*/
};

static TexAnim playerDamage[] = {
	{18,4},
	{23,1},
	{19,4},
	{23,1},
	{20,14},
	{23,1},
	{21,4},
	{23,1},
	{22,4},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerDamage),
};
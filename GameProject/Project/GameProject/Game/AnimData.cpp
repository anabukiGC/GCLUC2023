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
	{12,4},
	{13,4},
	{14,4},
	{15,4},
};
static TexAnim playerJumpDown[] = {
	{16,10},
	{17,10},
	{18,8},
	/*
	{8,4},
	{6,4},
	{5,4},
	{4,4},
	*/
};

static TexAnim playerDamage[] = {
	{19,4},
	{9,1},
	{20,4},
	{9,1},
	{21,14},
	{9,1},
	{22,4},
	{9,1},
	{23,4},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerDamage),
};
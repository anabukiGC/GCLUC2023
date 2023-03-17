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

static TexAnim playerFall[] = {
	/*{27,4},
	{28,4},
	{29,4},
	{30,4},
	{31,4},
	{32,4},
	{33,4},
	{34,4},
	{35,4},
	{26,4},*/

	//ÉRÉ~ÉJÉã
	{27,60},
	{28,2},
	{29,2},
	{30,60},
	{31,2},
	{32,2},
	{33,2},
	{34,2},
	{35,2},
	{26,4},

};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerDamage),
	ANIMDATA(playerFall),
};
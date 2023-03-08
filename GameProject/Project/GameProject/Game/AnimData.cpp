#include "AnimData.h"


static TexAnim playerRun[] = {
	
	{5,4},
	{6,4},
	{7,4},
	{8,4},
	{0,4},
	{1,4},
	{2,4},
	{3,4},
	{4,4},
};
static TexAnim playerJumpUp[] = {
	{11,4},
	{12,4},
	{13,4},
	{14,4},
};
static TexAnim playerJumpDown[] = {
	{15,8},
	{16,8},
	{8,4},
	{6,4},
	{5,4},
	{4,4},
};

static TexAnim playerDamage[] = {
	{17,4},
	{18,4},
	{19,4},
	{20,4},
	{21,14},
};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerDamage),
};


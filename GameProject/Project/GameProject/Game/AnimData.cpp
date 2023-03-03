#include "AnimData.h"


static TexAnim playerRun[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
	{ 5,4 },
	{ 6,4 },
	{ 7,4 },
	{ 8,4 },
};
static TexAnim playerJumpUp[] = {
	{ 12,4 },
	{ 13,4 },
	{ 14,4 },
	{ 15,4 },
};
static TexAnim playerJumpDown[] = {
	{ 16,4 },
	{ 17,4 },

};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
};


#pragma once
#include <GLLibrary.h>

//!アニメーションの種類
enum  {
	eAnimRun,
	eAnimJumpUp,
	eAnimJumpDown,
	eAnimDamage,
};

//プレイヤーのアニメーションデータ
extern TexAnimData player_anim_data[];
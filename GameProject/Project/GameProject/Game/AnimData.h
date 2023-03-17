#pragma once
#include <GLLibrary.h>

//!アニメーションの種類
enum  {
	eAnimRun,
	eAnimJumpUp,
	eAnimJumpDown,
	eAnimDamage,
	eAnimFall,
};

//プレイヤーのアニメーションデータ
extern TexAnimData player_anim_data[];
#include "ScreenPrintf.h"
#include <Novice.h>

//ï`âÊèàóù
void ScreenPrintf::Draw(static int enemyAlive_) {
	Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", enemyAlive_);
	Novice::ScreenPrintf(0, 20, "enemyB isAlive = %d", enemyAlive_);
	Novice::ScreenPrintf(0, 40, "WASD : player Move");
	Novice::ScreenPrintf(0, 60, "shot : SRACE");
	Novice::ScreenPrintf(0, 80, "enemy respawn : R");
}
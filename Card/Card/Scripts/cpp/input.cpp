#include "../h/GV.h"
// ---------------------------------------- ì¸óÕèàóù ----------------------------------------

void input() {
	beforeSpaceKey = keyBuffer[KEY_INPUT_SPACE];
	beforeUpKey = keyBuffer[KEY_INPUT_UP];
	beforeDownKey = keyBuffer[KEY_INPUT_DOWN];
	beforeRightKey = keyBuffer[KEY_INPUT_RIGHT];
	beforeLeftKey = keyBuffer[KEY_INPUT_LEFT];

	GetHitKeyStateAll(keyBuffer);
}

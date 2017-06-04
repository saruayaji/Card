#include "../h/GV.h"
// ---------------------------------------- ì¸óÕèàóù ----------------------------------------

void input() {
	beforeSpaceKey = keyBuffer[KEY_INPUT_SPACE];
	beforeZKey = keyBuffer[KEY_INPUT_Z];
	beforeXKey = keyBuffer[KEY_INPUT_X];
	beforeCKey = keyBuffer[KEY_INPUT_C];
	beforeVKey = keyBuffer[KEY_INPUT_V];
	beforeAKey = keyBuffer[KEY_INPUT_A];
	beforeSKey = keyBuffer[KEY_INPUT_S];
	beforeDKey = keyBuffer[KEY_INPUT_D];
	beforeFKey = keyBuffer[KEY_INPUT_F];
	beforeEnterKey = keyBuffer[KEY_INPUT_H];

	beforeUpKey = keyBuffer[KEY_INPUT_UP];
	beforeDownKey = keyBuffer[KEY_INPUT_DOWN];
	beforeRightKey = keyBuffer[KEY_INPUT_RIGHT];
	beforeLeftKey = keyBuffer[KEY_INPUT_LEFT];

	GetHitKeyStateAll(keyBuffer);
}

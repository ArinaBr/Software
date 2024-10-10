
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DriveStateMashine(struct DriveStateMashine* inst)
{
	/*TODO: Add your code here*/
	UINT mask = inst->state & 0x6F;
	if (inst->enable) {
		switch(mask) {
			case state_disabled:
				inst->command = cmd_shutdown;
				break;
			
			case state_ready:
				inst->command = cmd_enabled;
				break;
			
			case state_switched_on:
				inst->command = cmd_switched_on;
				break;
			
		}
	}
	else {
		inst->command = cmd_shutdown;
	}
}

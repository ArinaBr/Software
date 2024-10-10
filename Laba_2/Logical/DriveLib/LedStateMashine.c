
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
void LedStateMashine(struct LedStateMashine* inst)
{
	/*TODO: Add your code here*/
	switch(inst->state) {
		case st_init:
				break;
		
		case st_unknown:
			if(inst->timer % 10 == 1){
					inst->led1 = !inst->led1;
					inst->led2 = !inst->led2;
					inst->led3 = !inst->led3;
					inst->led4 = !inst->led4;
			}
			break;
		
		case st_close:
			inst->led1 = 1;
			inst->led2 = 1;
			inst->led3 = 1;
			inst->led4 = 1;
			break;
		
		case st_neg:
			inst->led1 = 0;
			if(inst->timer % 10 == 1) inst->led2 = !inst->led2;
			inst->led3 = 1;
			inst->led4 = 1;
			break;
		
		case st_acc_neg:
			inst->led1 = 0;
			inst->led2 = 0;
			if(inst->timer % 10 == 1) inst->led3 = !inst->led3;
			inst->led4 = 1;
			break;
		
		case st_dec_neg:
			inst->led1 = 0;
			inst->led2 = 0;
			inst->led3 = 0;
			if(inst->timer % 10 == 1) inst->led4 = !inst->led4;
			break;
		
		case st_open:
			inst->led1 = 0;
			inst->led2 = 0;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		
		case st_pos:
			inst->led1 = 0;
			inst->led2 = 0;
			if(inst->timer % 10 == 1) inst->led3 = !inst->led3;
			inst->led4 = 1;
			break;
		
		case st_acc_pos:
			inst->led1 = 0;
			if(inst->timer % 10 == 1) inst->led2 = !inst->led2;
			inst->led3 = 1;
			inst->led4 = 1;
			break;
		
		case st_dec_pos:
			if(inst->timer % 10 == 1) inst->led1 = !inst->led1;
			inst->led2 = 1;
			inst->led3 = 1;
			inst->led4 = 1;
			break;
	}
	inst->timer++;
}

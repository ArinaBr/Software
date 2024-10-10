
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
void DoorStateMashine(struct DoorStateMashine* inst)
{
	/*TODO: Add your code here*/
	switch(inst->state) {
		case st_init:
			if(inst->sw1==0 && inst->sw2==0 && inst->sw3==0 && inst->sw4==0)
				inst->state = st_unknown;
			break;
		
		case st_unknown:
			if(inst->direction==0 && inst->sw1!=inst->sw01)
				inst->state = st_close;
			if(inst->direction==1 && inst->sw1!=inst->sw01)
				inst->state = st_neg;
			if(inst->direction==1 && inst->sw2!=inst->sw02)
				inst->state = st_acc_neg;
			if(inst->direction==1 && inst->sw3!=inst->sw03)
				inst->state = st_dec_neg;
			if(inst->direction==1 && inst->sw4!=inst->sw04)
				inst->state = st_open;
			if(inst->direction==0 && inst->sw4!=inst->sw04)
				inst->state = st_pos;
			if(inst->direction==0 && inst->sw3!=inst->sw03)
				inst->state = st_acc_pos;
			if(inst->direction==0 && inst->sw2!=inst->sw02)
				inst->state = st_dec_pos;
			break;
		
		case st_close:
			inst->speed = 0;
			if(inst->direction==1)
				inst->state = st_neg;
			break;
		
		case st_neg:
			inst->speed = -250;
			if(inst->direction==1 && inst->sw2!=inst->sw02)
				inst->state = st_acc_neg;
			if(inst->direction==0)
				inst->state = st_dec_pos;
			break;
		
		case st_acc_neg:
			inst->speed = -800;
			if(inst->direction==1 && inst->sw3!=inst->sw03)
				inst->state = st_dec_neg;
			if(inst->direction==0)
				inst->state = st_acc_pos;
			break;
		
		case st_dec_neg:
			inst->speed = -250;
			if(inst->direction==1 && inst->sw4!=inst->sw04)
				inst->state = st_open;
			if(inst->direction==0)
				inst->state = st_pos;
			break;
		
		case st_open:
			inst->speed = 0;
			if(inst->direction==0)
				inst->state = st_pos;
			break;
		
		case st_pos:
			inst->speed = 250;
			if(inst->direction==0 && inst->sw3!=inst->sw03)
				inst->state = st_acc_pos;
			if(inst->direction==1)
				inst->state = st_dec_neg;
			break;
		
		case st_acc_pos:
			inst->speed = 800;
			if(inst->direction==0 && inst->sw2!=inst->sw02)
				inst->state = st_dec_pos;
			if(inst->direction==1)
				inst->state = st_acc_neg;
			break;
		
		case st_dec_pos:
			inst->speed = 250;
			if(inst->direction==0 && inst->sw1!=inst->sw01)
				inst->state = st_close;
			if(inst->direction==1)
				inst->state = st_neg;
			break;
	}
	inst->sw01 = inst->sw1;
	inst->sw02 = inst->sw2;
	inst->sw03 = inst->sw3;
	inst->sw04 = inst->sw4;
}

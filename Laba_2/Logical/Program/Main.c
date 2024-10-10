
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	StateMashine.enable = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	DoorStateMashine(&doorSM);
	DriveStateMashine(&StateMashine);
	LedStateMashine(&ledSM);
	StateMashine.speed = doorSM.speed;
	ledSM.state = doorSM.state;
}

void _EXIT ProgramExit(void)
{

}


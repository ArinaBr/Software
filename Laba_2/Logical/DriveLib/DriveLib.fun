
{REDUND_ERROR} FUNCTION_BLOCK DriveStateMashine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : UINT;
		enable : BOOL;
	END_VAR
	VAR_OUTPUT
		command : {REDUND_UNREPLICABLE} UINT;
		speed : {REDUND_UNREPLICABLE} INT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK DoorStateMashine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : UINT;
		sw1 : BOOL;
		sw2 : BOOL;
		sw3 : BOOL;
		sw4 : BOOL;
		direction : BOOL;
	END_VAR
	VAR_OUTPUT
		speed : {REDUND_UNREPLICABLE} INT;
	END_VAR
	VAR
		sw01 : BOOL;
		sw02 : BOOL;
		sw03 : BOOL;
		sw04 : BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK LedStateMashine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : UINT;
	END_VAR
	VAR_OUTPUT
		led1 : {REDUND_UNREPLICABLE} BOOL;
		led2 : {REDUND_UNREPLICABLE} BOOL;
		led3 : {REDUND_UNREPLICABLE} BOOL;
		led4 : {REDUND_UNREPLICABLE} BOOL;
		timer : {REDUND_UNREPLICABLE} INT;
	END_VAR
END_FUNCTION_BLOCK

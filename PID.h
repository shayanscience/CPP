// PID.h
// Creator: Shayan Sheikhrezaei
// Email: Shayan_rezaei@csu.fulerton.edu
// Date:	1/14/2021
//

#ifndef _PID_h
#define _PID_h

#ifndef _INC_TIME
#include <time.h>
#endif // !_INC_TIME




class pid_control {
private:
	/* Declaring and Initializing some variables */
	float	ki = 0.0,	// Integral Coefficient.
		kp = 0.0,		// Proportional Coefficient.
		kd = 0.0;		// Derivative Coefficient.
public:
	/* Declaring and Initializing some variables */
	float	P = 0.0,		// Error.
		I = 0.0,		// Integral -> Error accumulated over time.
		D = 0.0,		// Derivative -> Rate of change.
		oldI = 0.0,		// Integral previous value.
		oldP = 0.0,		// Error previous value.
		oldD = 0.0,		// Derivative previous value.
		oldT = 0.0,		// Previous time.
		oldOutput = 0.0,// Previous output.
		newInput,		// Input of the system -> output of the pid_seek function.
		dt = 0.0;		// Time Interval, dt = now - then.

	
	void pid_init(float kp_coef, float ki_coef, float kd_coef);

	float pid_seek(float setpoint, float currentVal);
};


#endif // !PID_h

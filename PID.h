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
	float	ki = 0.0f,	// Integral Coefficient.
		kp = 0.0f,		// Proportional Coefficient.
		kd = 0.0f;		// Derivative Coefficient.
public:
	/* Declaring and Initializing some variables */
	float	P = 0.0f,		// Error.
		I = 0.0f,		// Integral -> Error accumulated over time.
		D = 0.0f,		// Derivative -> Rate of change.
		oldI = 0.0f,		// Integral previous value.
		oldP = 0.0f,		// Error previous value.
		oldD = 0.0f,		// Derivative previous value.
		oldT = 0.0f,		// Previous time.
		oldOutput = 0.0f,// Previous output.
		newInput,		// Input of the system -> output of the pid_seek function.
		dt = 0.0f;		// Time Interval, dt = now - then.

	
	void pid_init(float kp_coef, float ki_coef, float kd_coef);

	float pid_seek(float setpoint, float currentVal);
};


#endif // !PID_h

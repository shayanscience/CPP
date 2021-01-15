#include <PID.h>

// This function initializes PID coefficients.
void pid_control::pid_init(float kp_coef, float ki_coef, float kd_coef) {
	ki = ki_coef;
	kp = kp_coef;
	kd = kd_coef;
}


// This function takes two parameters and return a input that
// must be added to the system's output for the correction.
float pid_control::pid_seek(float setpoint, float currentVal) {
	P = setpoint - currentVal;					// Error
	I = 0;								// Make sure current I and D values are reset
	D = 0;
	dt = clock() - oldT;						// Time Interval
	
	// If time is negative!!! :|
	if (dt < 0) {
		// Do nothing, I haven't called you yet.
	}
	else {
		
		// If time hasn't gone by or for some reason time is stopped! (The future is the present and vice versa!) :)
		if (dt == 0) {
			newInput = oldOutput;		// New input is the prevo=
		}
		else {
			I = ((P + oldI) / dt);		// Integral operation freq = 1/time!
			D = ((P - oldP) / dt);		// Derivative operation.
			newInput = kp * P + ki * I + kd * D;
		}

		// Storing Current values for the future use.
		oldP = P;
		oldI = I;
		oldD = D;
		oldT = dt;
		oldOutput = newInput;
	}

	return newInput;
}

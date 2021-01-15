#include <PID.h>

/// <summary>
/// This function initializes PID coefficients.
/// </summary>
/// <param name="kp_coef="> KP</param>
/// <param name="ki_coef="> KI</param>
/// <param name="kd_coef">  KD</param>
void pid_control::pid_init(float kp_coef, float ki_coef, float kd_coef) {
	ki = ki_coef;
	kp = kp_coef;
	kd = kd_coef;
}

/// <summary>
/// This function two parameters and return an output that
/// must be added to the system for the correction.
/// </summary>
/// <param name="setpoint="> Desired Value </param>
/// <param name="currentVal="> Sensor Output </param>
/// <returns> PID output</returns>
float pid_control::pid_seek(float setpoint, float currentVal) {
	P = setpoint - currentVal;					// Error
	I = 0;										// Make sure current I is zero
	D = 0;
	dt = clock() - oldT;						// Time Interval
	if (dt < 0) {
		// Do nothing, I haven't called you yet.
	}
	else {
		if (dt == 0) {
			newInput = oldOutput;
		}
		else {
			I = ((P + oldI) / dt);
			D = ((P - oldP) / dt);
			newInput = kp * P + ki * I + kd * D;
		}

		// Storing Current value for the future use.
		oldP = P;
		oldI = I;
		oldD = D;
		oldT = dt;
		oldOutput = newInput;
	}

	return newInput;
}
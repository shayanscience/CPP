# Cplusplus
PID-Controller 
PID library contains PID header and source code files.

One class named:
1. pid_control

Two class member functions:
1. pid_init(float kp_coef, float ki_coef, float kd_coef)
    * kp_coef -> corresponds to the KP coefficient of the controller.
    * ki_coef -> corresponds to the KI coefficient of the controller.
    * kd_coef -> corresponds to the KD coefficient of the controller.
    
2. float pid_control::pid_seek(float setpoint, float currentVal)
    * setpoint -> is the desired value.
    * currentVal -> the output of the system.
    
e.g:
below peice of code is just for the demonstration purposes to show how to implement the library with its functions otherwise it has no functionality at this point unless you modify line 39.

#include <iostream>
#include <PID.h>
using namespace std;

pid_control   Temperature;

int main(void){

float kp =  0.23;
float ki =  0.12;
float kd =  0.003;
float desired_Temp = 75.2;         // Fahrenheit, 24 deg in C
float new_Input = 0.0; 

Temperature.pid_init( kp, ki, kd);

while(true){

// Temp_out => reading temperature
new_Input = Temperature.pid_seek( desired_Temp, Temp_out);
Temp_out += new_Input;

}

return 0;
}



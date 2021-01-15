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
    

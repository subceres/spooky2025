#ifndef _PROS_PID_HPP
#define _PROS_PID_HPP

#define leeway 10 //leeway between actual motor positon and target position
void move(double leftTarget, double rightTarget, double autonDelay, double timeout, double maxPower, double kP, double kD);
#endif

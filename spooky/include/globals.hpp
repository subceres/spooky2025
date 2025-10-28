#ifndef _PROS_GLOBALS_HPP
#define _PROS_GLOBALS_HPP

// Motor Ports
#define FLMotorPort 1
#define MLMotorPort 2
#define BLMotorPort 3
#define FRMotorPort 4
#define MRMotorPort 5
#define BRMotorPort 6
#define intakeMotorPort 7
#define chainMotorPort 8
#define outtakeMotorPort 9

// Motor Cartridges
#define baseMotorCartridge MotorGears::blue
#define intakeMotorCartridge MotorGears::green 
#define chainMotorCartridge MotorGears::green //temp, need to check  
#define outtakeMotorCartridge MotorGears::green

// Motor Reverse
#define FLMotorReverse false
#define MLMotorReverse false
#define BLMotorReverse false
#define FRMotorReverse false
#define MRMotorReverse false
#define BRMotorReverse false

// Pneumatics
#define tonguePistonPort 'a'
#define tonguePistonStartExtended false

#endif
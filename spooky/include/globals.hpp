#ifndef _PROS_GLOBALS_HPP
#define _PROS_GLOBALS_HPP

// Motor Ports (add negative sign to indicate reversed motor)
#define FLMotorPort 1
#define MLMotorPort 2
#define BLMotorPort 3
#define FRMotorPort 4
#define MRMotorPort 5
#define BRMotorPort 6
#define intakeMotorPort 9 //
#define chainMotorPort 8 //
#define scoreMotorPort 9

// Motor Cartridges
#define baseMotorCartridge MotorGears::blue
#define intakeMotorCartridge MotorGears::green 
#define chainMotorCartridge MotorGears::red
#define scoreMotorCartridge MotorGears::green

// Motor Reverse
#define FLMotorReverse false
#define MLMotorReverse false
#define BLMotorReverse false
#define FRMotorReverse false
#define MRMotorReverse false
#define BRMotorReverse false

// Motor Powers

#define intakePower 127 //intake voltage, 0-127
// #define chainPower 127 //chain voltage, 0-127
#define scorePower 127 //score voltage, 0-127

// Pneumatics
#define tonguePistonPort 'a'
#define tonguePistonStartExtended false

//sensors
#define opticalPort 20
#define opticalBallDistance 100 // 0-255

#endif
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_
#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

//include paths
#include "api.h"
#include "globals.hpp"
#include "pid.hpp"

//namespace
using namespace pros;
using namespace pros::literals;



// control functions
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
}

//mechanical motor functions
void chainSpin(int chainPower);

#endif  // _PROS_MAIN_H_

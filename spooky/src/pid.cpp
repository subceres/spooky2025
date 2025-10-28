#include "main.h"
double abscap(double val, double cap){
    double ret = val;
    if (val > cap){
        ret = cap;
    }
    else if (val < -cap){
        ret = -cap;
    }
    return ret;
}

// Variables
double leftEncoding=0, rightEncoding=0, leftTarget=0, rightTarget=0, leftError=0, rightError=0, leftPower=0, rightPower=0, kP=0, kD=0, maxPower=0, timeout=0, autonDelay=0; 
void move(double leftTarget, double rightTarget, double autonDelay, double timeout, double maxPower, double kP, double kD){

    // Drive Motors
	Motor FLMotor(FLMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor MLMotor(MLMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor BLMotor(BLMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor FRMotor(FRMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor MRMotor(MRMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor BRMotor(BRMotorPort,baseMotorCartridge,MotorUnits::degrees);

	FLMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	MLMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	BLMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	FRMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	MRMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	BRMotor.set_brake_mode(E_MOTOR_BRAKE_BRAKE);

    FLMotor.tare_position_all();
    MLMotor.tare_position_all();
    BLMotor.tare_position_all();
    FRMotor.tare_position_all();
    MRMotor.tare_position_all();
    BRMotor.tare_position_all();

    double startTime=millis();
    leftEncoding=MLMotor.get_position();
    rightEncoding=MRMotor.get_position();
    leftError=leftTarget-leftEncoding;
    rightError=rightTarget-rightEncoding;
    while (fabs(leftError)>leeway || fabs(rightError)>leeway && millis()-startTime<timeout){
        leftEncoding=MLMotor.get_position();
        rightEncoding=MRMotor.get_position();
        leftError=leftTarget-leftEncoding;
        rightError=rightTarget-rightEncoding;

        leftPower=abscap(kP*leftError,maxPower);
        rightPower=abscap(kP*rightError,maxPower);

        FLMotor.move(leftPower);
        MLMotor.move(leftPower);
        BLMotor.move(leftPower);
        FRMotor.move(rightPower);
        MRMotor.move(rightPower);
        BRMotor.move(rightPower);

        delay(5);
    }
    FLMotor.move(0);
    MLMotor.move(0);
    BLMotor.move(0);
    FRMotor.move(0);
    MRMotor.move(0);
    BRMotor.move(0);

    delay(autonDelay);
}
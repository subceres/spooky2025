#include "main.h"

/* example function for me
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
*/


void initialize() {

	// Drive Motors
	Motor FLMotor(FLMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor MLMotor(MLMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor BLMotor(BLMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor FRMotor(FRMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor MRMotor(MRMotorPort,baseMotorCartridge,MotorUnits::degrees);
	Motor BRmotor(BRMotorPort,baseMotorCartridge,MotorUnits::degrees);

	// Mechanical Motors
	Motor intakeMotor(intakeMotorPort,intakeMotorCartridge,MotorUnits::degrees);
	Motor chainMotor(chainMotorPort,chainMotorCartridge,MotorUnits::degrees);
	Motor outtakeMotor(outtakeMotorPort,outtakeMotorCartridge,MotorUnits::degrees);   

	//Pneumatics
	adi::Pneumatics tongue(tonguePistonPort,tonguePistonStartExtended);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	double autonDelay = 200;
}

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	while (true) {

		pros::delay(20);
	}
}
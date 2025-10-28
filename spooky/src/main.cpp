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

//initialise funciton
void initialize() {

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

	// Mechanical Motors
	Motor intakeMotor(intakeMotorPort,intakeMotorCartridge,MotorUnits::degrees);
	Motor chainMotor(chainMotorPort,chainMotorCartridge,MotorUnits::degrees);
	Motor scoreMotor(scoreMotorPort,scoreMotorCartridge,MotorUnits::degrees);   

	//Pneumatics
	adi::Pneumatics tongue(tonguePistonPort,tonguePistonStartExtended);
}


void disabled() {}

void competition_initialize() {}

void autonomous() {
	double autonDelay = 200;
}


// Controls: R1 intake, R2 outtake, L1 score high, L2 score low, X tongue
void opcontrol() {
	// Definitions
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

	// Mechanical Motors
	Motor intakeMotor(intakeMotorPort,intakeMotorCartridge,MotorUnits::degrees);
	Motor chainMotor(chainMotorPort,chainMotorCartridge,MotorUnits::degrees);
	Motor scoreMotor(scoreMotorPort,scoreMotorCartridge,MotorUnits::degrees);   

	//Pneumatics
	adi::Pneumatics tongue(tonguePistonPort,tonguePistonStartExtended);
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	while (true) {
		// Controller inputs
		int leftPower=master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int rightPower=master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
		bool intake=master.get_digital(E_CONTROLLER_DIGITAL_R1);
		bool outtake=master.get_digital(E_CONTROLLER_DIGITAL_R2);
		bool scoreHigh=master.get_digital(E_CONTROLLER_DIGITAL_L1);
		bool scoreLow=master.get_digital(E_CONTROLLER_DIGITAL_R2);

		// Base move code
		FLMotor.move(leftPower);
		MLMotor.move(leftPower);
		BLMotor.move(leftPower);
		FRMotor.move(rightPower);
		MRMotor.move(rightPower);
		BRMotor.move(rightPower);

		// Score move code
		
		if (intake==true and outtake==false){
			intakeMotor.move(intakePower);
		} else if (intake==false && outtake==true){
			intakeMotor.move(-intakePower);
		} else {
			intakeMotor.move(0);
		}

		// Score move code
		if (scoreHigh==true and scoreLow==false){
			scoreMotor.move(scorePower);
		} else if (scoreHigh==false && scoreLow==true){
			scoreMotor.move(-scorePower);
		} else {
			scoreMotor.move(0);
		}

		// Universal delay (no touchie)
		pros::delay(20);
	}
}
#pragma config(Motor,  port10,           rightmotor,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port6,           armmotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           clawmotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port1,          leftmotor,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void moveForward(int timeMoving) {
	wait1Msec(250);
	motor[leftmotor] = -60;
	motor[rightmotor] = -60;
	wait1Msec(timeMoving);
	motor[leftmotor] = 0;
	motor[rightmotor] = 0;
}

void moveBackward(int timeMoving) {
	wait1Msec(250);
	motor[leftmotor] = 60;
	motor[rightmotor] = 60;
	wait1Msec(timeMoving);
	motor[leftmotor] = 0;
	motor[rightmotor] = 0;
}

void openClaw() {
	wait1Msec(250);
	motor[clawmotor] = -60;
	wait1Msec(1000);
	motor[clawmotor] = 0;
}

void closeClaw() {
	wait1Msec(250);
	motor[clawmotor] = 60;
	wait1Msec(1000);
	motor[clawmotor] = 0;
}

void elevateArm() {
	wait1Msec(250);
	motor[armmotor] = 100;
	wait1Msec(1500);
	motor[armmotor] = 0;
}

void lowerArm() {
	wait1Msec(250);
	motor[armmotor] = 100;
	wait1Msec(1500);
	motor[armmotor] = 0;
}

void rotate90(){
	wait1Msec(250);
	motor[rightmotor] = 60;
	motor[leftmotor] = -60;
	wait1Msec(925);
	motor[rightmotor] = 0;
	motor[leftmotor] = 0;
}

void rotate180(){
	rotate90();rotate90(); //genius
}

// The geniusness of this function is just 10/10
void rotate270(){
	rotate90();rotate90();rotate90(); //genius
}

task main()
{

	moveForward(2000);
	lowerArm();
	openClaw();
	moveForward(200);
	closeClaw();
	elevateArm();
	moveForward(3000);
	elevateArm();
	openClaw();
	moveBackward(500);
	lowerArm();
	closeClaw();
	rotate180();
	moveForward(5200);
	rotate180();


}

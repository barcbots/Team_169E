
void Autonomous7r(){
RunArm(-20);
Claw(1);
SensorValue[QuadArm]=0;
pidBackward(10,15);
wait10Msec(40);
pidForward(87,135);
wait10Msec(10);
	Claw(0);
	//wait10Msec(20);
	 PIDTUNE(3.5,0.05,0.08);
	//	pidholder=50;
	pidRequestedValue=27;
	wait10Msec(50);
pidForward(15,50);

	ArmDown();
	wait10Msec(40);

	Claw(1);
	wait10Msec(20);
	pidForward(40,50);
	wait10Msec(20);
	Claw(0);
	wait10Msec(20);
	PIDTUNE(3.5,0.05,0.08);
	pidRequestedValue=40;
	pidLeftAngle(10,25);
	pidBackward(20,30);
	pidLeftAngle(80,105);
	pidBackward(30,40);
ArmUp();
pidBackward(40,60);
wait10Msec(90);
pidBackward(10,20);
pidForward(10,15);
pidRightAngle(23,25);
pidForward(65,75);
wait10Msec(20);
Claw(0);
pidBackward(20,30);
ArmUp();
pidBackward(40,60);





}

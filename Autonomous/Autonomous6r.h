
void Autonomous6r(){

RunArm(-20);
Claw(1);
SensorValue[QuadArm]=0;
pidBackward(10,15);
wait10Msec(40);
pidForward(85,100);
wait10Msec(10);
	Claw(0);
	//wait10Msec(20);
	 PIDTUNE(3.0,0.05,0.08);
	 pidRequestedValue=40;
	wait10Msec(20);
pidLeftAngle(10,20);
wait10Msec(20);
pidBackward(75,85);
wait10Msec(20);
 PID_DRIVE_MAXD=65;
 PID_DRIVE_MIND=-65;
pidLeftAngle(115,140);
PID_DRIVE_MAXD=90;
 PID_DRIVE_MIND=-90;
wait10Msec(20);

pidBackward(85,105);
pidRightSide(-40,50);
ArmUp();
//pidBackward(30,60);

pidBackward(50,20);
wait10Msec(30);

pidBackward(20,40);
	PIDTUNE(1.9,0.05,0.08);

	pidRequestedValue=0;
	wait10Msec(100);
pidForward(15,20);
Claw(0);
ArmUp();
pidBackward(50,60);
wait10Msec(140);
	PIDTUNE(1.9,0.05,0.08);

	pidRequestedValue=0;
	wait10Msec(80);
pidForward(15,20);
Claw(0);
ArmUp();


//////////////////////////////////////////////////



}

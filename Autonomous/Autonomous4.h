
void Autonomous4(){
RunArm(-20);
Claw(1);
SensorValue[QuadArm]=0;
pidBackward(10,15);
wait10Msec(40);
pidForward(88,115);
wait10Msec(10);
	Claw(0);
	//wait10Msec(20);
	 PIDTUNE(3.0,0.05,0.08);
	 pidRequestedValue=38;
	wait10Msec(20);
pidRightAngle(10,15);
//wait10Msec(20);
pidBackward(82,90);
wait10Msec(20);
pidRightAngle(73,90);
wait10Msec(20);

pidBackward(20,25);
ArmUp();
pidBackward(40,60);
wait10Msec(70);
pidBackward(10,20);
//////////////////////////////////////////////////
pidForward(15,20);

pidLeftAngle(65,70);
pidForward(75,80);
Claw(0);

	PIDTUNE(3.0,0.05,0.08);
	pidRequestedValue=25;

ArmUp();
pidRightAngle(50,70);
pidBackward(40,50);





}

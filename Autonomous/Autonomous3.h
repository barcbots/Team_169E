
void Autonomous3(){

RunArm(-20);
Claw(1);
SensorValue[QuadArm]=0;
ArmDown();
pidBackward(10,15);
wait10Msec(40);
pidForward(90,110);
wait10Msec(10);
	Claw(0);
	//wait10Msec(20);
	 pidIntegrala=0;
	 PIDTUNE(3.0,0.05,0.08);
	 pidRequestedValue=50;
	wait10Msec(70);
pidRightAngle(10,15);
//wait10Msec(20);
pidBackward(100,103);
//wait10Msec(20);
pidRightAngle(50,50);
//wait10Msec(20);

pidBackward(20,25);
ArmUp();
pidBackward(50,70);
wait10Msec(70);
pidBackward(10,20);
//////////////////////////////////////////////////
pidForward(15,20);
pidRightAngle(25,27);
pidForward(88,90);
Claw(0);
wait10Msec(20);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);


}

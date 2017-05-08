
void Autonomous3r(){

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
	wait10Msec(20);
pidLeftAngle(10,15);
//wait10Msec(20);
pidBackward(100,103);
//wait10Msec(20);
pidLeftAngle(55,65);
//wait10Msec(20);

pidBackward(20,25);
ArmUp();
pidBackward(45,60);
wait10Msec(70);
pidBackward(10,20);
//////////////////////////////////////////////////
pidForward(15,20);
pidLeftAngle(35,35);
pidForward(100,105);
Claw(0);
wait10Msec(20);
pidBackward(24,25);
ArmUp();
pidBackward(45,65);





}

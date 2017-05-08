
void Autonomous5r(){
RunArm(-20);
Claw(1);
SensorValue[QuadArm]=0;
pidBackward(10,15);
wait10Msec(40);
pidForward(82,110);
wait10Msec(10);
	Claw(0);
	//wait10Msec(20);
	 PIDTUNE(3.0,0.05,0.08);
	 pidRequestedValue=38;
	wait10Msec(20);
pidLeftAngle(10,15);
//wait10Msec(20);
pidBackward(97,103);
//wait10Msec(20);
pidLeftAngle(60,65);
//wait10Msec(20);

pidBackward(20,25);
ArmUp();
pidBackward(40,60);
wait10Msec(70);
pidBackward(10,20);
//////////////////////////////////////////////////
wait10Msec(50);//wait time
pidForward(30,50);
Claw(0);
ArmUp();
pidBackward(40,50);
wait10Msec(70);/////////////////////loopable



}


void Autonomous8(){
	RunArm(-20);

stopTask(AutoReliz);
pidBackward(40,45);
SensorValue[QuadArm]=0;


	Claw(1);
	wait10Msec(40);
	pidBackward(10,10)
	pidRequestedValue=95;
	pidBackward(35,40);
	wait10Msec(200);

	startTask(AutoReliz)
	wait10Msec(70);
	pidBackward(20,30);
	pidForward(15,20);

pidLeftAngle(70,80);
pidForward(80,85);
Claw(0);

	PIDTUNE(3.0,0.05,0.08);
	pidRequestedValue=25;

pidRightAngle(60,100);
ArmUp();
pidBackward(40,50);
wait10Msec(100);
pidBackward(20,30);

pidLeftSide(10,15);
pidForward(70,90);
Claw(0);
wait10Msec(10);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);
wait10Msec(90);



pidRightSide(18,23);
pidForward(70,90);
Claw(0);
wait10Msec(10);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);

}

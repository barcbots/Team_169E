
void Autonomous10r(){
RunArm(-20);
Claw(1);
SensorValue[QuadArm]=0;
ArmDown();
pidForward(30,80);
Claw(0);

//pidForward(5,10);
//PIDTUNE(1.7,0.3,1.8);

//	pidRequestedValue=100;

	PIDTUNE(3.0,0.05,0.08);

	pidRequestedValue=25;
pidLeftAngle(30,40);
pidForward(110,120)
pidLeftAngle(60,70);
ArmUp();
 PID_DRIVE_MAXD=65;
 PID_DRIVE_MIND=-65;
pidLeftAngle(20,35);

PID_DRIVE_MAXD=90;
 PID_DRIVE_MIND=-90;
pidBackward(75,85);
wait10Msec(70);
pidBackward(10,30);
//pidForward(15,20);
pidLeftSide(25,30);
pidForward(85,90);
Claw(0);
wait10Msec(20);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);


}

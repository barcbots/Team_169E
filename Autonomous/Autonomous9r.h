
void Autonomous9r(){
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


pidLeftAngle(65,75);
pidBackward(85,95);
ArmUp();
 PID_DRIVE_MAXD=65;
 PID_DRIVE_MIND=-65;
pidLeftAngle(35,45);

PID_DRIVE_MAXD=90;
 PID_DRIVE_MIND=-90;
pidBackward(40,50);
wait10Msec(90);
pidBackward(10,20);
pidForward(15,20);
pidLeftAngle(45,50);
pidForward(85,95);
Claw(0);
wait10Msec(25);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);





}

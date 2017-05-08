
void Autonomous2(){
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


pidRightAngle(85,70);
//defence=1; /////////
ArmUp();
 PID_DRIVE_MAXD=65;
 PID_DRIVE_MIND=-65;
pidRightAngle(30,35);

PID_DRIVE_MAXD=90;
 PID_DRIVE_MIND=-90;
pidBackward(40,70);

wait10Msec(60);
pidBackward(20,10);

pidLeftSide(5,10);
pidForward(70,90);
Claw(0);
wait10Msec(10);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);
wait10Msec(90);



pidRightSide(15,20);
pidForward(70,90);
Claw(0);
wait10Msec(10);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);


//ArmUp();

}

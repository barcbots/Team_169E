
void Autonomous11(){

	RunArm(-20);
	pidBackward(45,60)
	Claw(1);
	//SensorValue[QuadArm]=0;
	ArmDown();
	pidLeftSide(-45,45)
	pidForward(25,30);
	pidLeftAngle(34,30);
	pidForward(40,40);
	wait10Msec(40);
	Claw(0);
	wait10Msec(30);
	pidRightAngle(20,25);

	pidBackward(24,25);
	defence=1;
	ArmUp();
	pidBackward(40,60);
	wait10Msec(90);


}

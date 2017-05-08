void Claw(int pos)
{
	SensorValue(LeftClaw) = pos;
	SensorValue(RightClaw) = pos;
}
void RunArm(int Power){

	motor[armLOT] = Power;
	motor[armLIT] = Power;
	motor[armROT] = Power;
	motor[armRIT] = Power;

}
	void LeftDrive(int Speed)
	{
		motor(driveLY) = Speed;
		motor(driveLM) = Speed;

	}
	void RightDrive(int Speed)
	{
		motor(driveRM) = Speed;
		motor(driveRY) = Speed;

	}

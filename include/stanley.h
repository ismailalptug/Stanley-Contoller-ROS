#ifndef STANLEY_H_
#define STANLEY_H_
#include <iostream>
#include <math.h>

class stanleyController {

private:
	
	float cross_track_error_, heading_angle_, velocity_;
	float gain_;
	float steering_angle_;


	/**
	 * @param cross_track_error_    Lateral distance of the center of the vehicle s front wheels from the nearest point on the trajectory. [m]
	 * @param heading_angle_        Yaw angle of the vehicle with respect to the closest trajectory segment [Degree]
	 * @param velocity_             Speed of the vehicle [m/s]
	 * @param steering_angle_       Angle of the front wheels with respect to the vehicle [Degree]
	 * @param gain_ 				Stanley controller coefficient 
	 */


public:


	void setInputError(const float& cross_track_error,const float& heading_angle);
	void setInputVelocity(const float& velocity);
	void execute();
	float getOutput() const;

	stanleyController()
	{
		gain_ = 1.0;
	}

	/** 
	 * setInputError()  			sets the cross_track_error and heading_angle for controller
	 * setInputVelocity() 			sets velocity for controller
	 * execute() 					calculates the steering angle according to controller
	 * getOutput()					returns the steering angle which is calculated in execute
	 */


};
#endif // !STANLEY_H_

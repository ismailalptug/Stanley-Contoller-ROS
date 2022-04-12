#ifndef STANLEY_H_
#define STANLEY_H_
#include <ros/ros.h>

class stanleyController {

private:
	
	float cross_track_error_, heading_angle_, velocity_;
	float gain_;
	float steering_angle_;


public:


	void setInputError(const float& cross_track_error,const float& heading_angle);
	void setInputVelocity(const float& velocity);
	void execute();
	float getOutput() const;

	/**
	 * @brief Construct a new stanley Controller object
	 * 
	 * @param cross_track_error_    Lateral distance of the center of the vehicle s front wheels from the nearest point on the trajectory. [m]
	 * @param heading_angle_        Yaw angle of the vehicle with respect to the closest trajectory segment [Degree]
	 * @param velocity_             Speed of the vehicle [m/s]
	 * @param steering_angle_       Angle of the front wheels with respect to the vehicle [Degree]
	 * 
	 */

	stanleyController()
	{
		gain_ = 2;
	}

	
	


};
#endif // !STANLEY_H_
#include "stanley.h"

void stanleyController::setInputError(const float& cross_track_error,const float& heading_angle)
{
    cross_track_error_ = cross_track_error;
    heading_angle_ = heading_angle;
}

void stanleyController::setInputVelocity(const float& velocity)
{
    velocity_ = velocity;
}

void stanleyController::execute()
{
    steering_angle_ = heading_angle_ + atan((cross_track_error_ * gain_) / velocity_);
}

float stanleyController::getOutput() const
{
    return steering_angle_;
}

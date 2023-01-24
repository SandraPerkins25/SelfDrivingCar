#include <iostream>
#include <cmath>

const double MAX_SPEED = 10;
const double MAX_STEERING_ANGLE = M_PI / 4;

class SelfDrivingCar {
public:
    SelfDrivingCar() : speed_(0), steering_angle_(0) {}

    void set_speed(double speed) {
        speed_ = std::min(speed, MAX_SPEED);
    }

    void set_steering_angle(double angle) {
        steering_angle_ = std::clamp(angle, -MAX_STEERING_ANGLE, MAX_STEERING_ANGLE);
    }

    void drive(double time) {
        double distance = speed_ * time;
        double angle = distance / 2.0 * tan(steering_angle_);
        std::cout << "Driving " << distance << " meters at " << speed_ << " m/s with a steering angle of "
                  << angle << " radians." << std::endl;
    }

private:
    double speed_;
    double steering_angle_;
};

int main() {
    SelfDrivingCar car;
    car.set_speed(5);
    car.set_steering_angle(M_PI / 8);
    car.drive(5);
    return 0;
}

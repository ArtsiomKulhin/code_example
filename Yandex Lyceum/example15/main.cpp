enum class Mode {
    OFF,
    HEATING,
    COOLING
};

class Thermostat{
private:
    double target_temp_, current_temp_;
public:
    Thermostat(double initial_target, double initial_current) {
        target_temp_ = initial_target;
        current_temp_ = initial_current;
    }

    void setTargetTemperature(double temp) {
        target_temp_ = temp;
    }

    void setCurrentTemperature(double temp) {
        current_temp_ = temp;
    }

    double getTargetTemperature() const {
        return target_temp_;
    }

    double getCurrentTemperature() const {
        return current_temp_;
    }

    Mode getMode() const {
        if (current_temp_ < target_temp_ - 0.5) {
            return Mode::HEATING;
        }
        else if (current_temp_ > target_temp_ + 0.5) {
            return Mode::COOLING;
        }
        else {
            return Mode::OFF;
        }
    }
};

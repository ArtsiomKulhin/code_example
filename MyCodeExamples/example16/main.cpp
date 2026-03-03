class ElectronicDevice {
private:
    bool isOn_ = false;
public:
    void turnOn() {
        isOn_ = true;
    }

    void turnOff() {
        isOn_ = false;
    }

    bool isOn() const {
        if (isOn_ == true) {
            return true;
        }
        return false;
    }

    virtual ~ElectronicDevice(){}
};

class Phone : public ElectronicDevice {
private:
    std::string phoneNumber_;
public:
    Phone(std::string phoneNumber){
        phoneNumber_ = phoneNumber;
    };

    std::string call(const std::string& number) {
        if (isOn()) {
            std::stringstream s;
            s << "Calling " << number << " from " << phoneNumber_;
            return s.str();
        }
        else {
            return "Device is off";
        }
    }

    std::string getPhoneNumber() const{
        return phoneNumber_;
    }
};

class Smartphone : public Phone {
private:
    std::string operatingSystem_;
public:
    Smartphone(std::string phoneNumber, std::string operatingSystem): Phone(phoneNumber){
        operatingSystem_ = operatingSystem;
    }

    std::string installApp(const std::string& appName) {
        if (ElectronicDevice::isOn()) {
            std::stringstream ss;
            ss << "Installing " << appName << " on " << operatingSystem_ ;
            return ss.str();
        }
        else {
            return "Device is off";
        }
    }

    std::string getOS() const{
        return operatingSystem_;
    }
};

class Lamp {
private:
    bool lamp;
    unsigned int level;
public:
    Lamp() {
        lamp = false;
        level = 0;
    }
    void turnOn() {
        if (lamp == true && level == 0) {
            level = 50;
        }
        else if (!lamp && level == 0) {
            lamp = true;
            level = 50;
        }
        else {
            lamp = true;
        }
    }
    void turnOff() {
        lamp = false;
    }

    void setBrightness(int lv) {
        if (isOn() == true) {
            if (lv >= 0 && lv <= 100) {
            level = lv;
            }
            else if (lv < 0) {
                level = 0;
            }
            else if (lv > 100) {
                level = 100;
            }
        }
        if (level == 0) {
            turnOff();
        }
    }

    int getBrightness() {
        return level;
    }

    bool isOn() {
        if (lamp == true) {
            return true;
        }
        return false;
    }
};

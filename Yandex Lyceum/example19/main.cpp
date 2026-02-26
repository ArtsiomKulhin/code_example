class ParameterDescriptor {
private:
    std::string name_;
public:
    ParameterDescriptor(std::string name) {
        name_ = name;
    }

    std::string getName() const {
        return name_;
    }

    virtual std::string getType() const {

    }

    virtual std::string getDefaultValue() const {
        return "";
    }

    virtual ~ParameterDescriptor() {}
};

class IntParameter : public ParameterDescriptor{
private :
    int defaultValue_, minValue_, maxValue_;
public:
    IntParameter(std::string name, int defaultValue, int minValue, int maxValue) : ParameterDescriptor(name) {
        defaultValue_ = defaultValue;
        minValue_ = minValue;
        maxValue_ = maxValue;
    }

    std::string getType() const override {
        return "Integer";
    }

    std::string getDefaultValue() const override {
        return std::to_string(defaultValue_);
    }

    int getMin() const {
        return minValue_;
    }

    int getMax() const {
        return maxValue_;
    }
};

class StringParameter : public ParameterDescriptor{
private :
    std::string defaultValue_;
    size_t maxLength_;
public:
    StringParameter(std::string name, std::string defaultValue, size_t maxLength) : ParameterDescriptor(name) {
        defaultValue_ = defaultValue;
        if (maxLength < 0) {
            maxLength_ = 0;
        }
        else {
            maxLength_ = maxLength;
        }
    }
    std::string getType() const override {
        return "String";
    }

    std::string getDefaultValue() const override {
        return defaultValue_;
    }

    size_t getMaxLength() const {
        return maxLength_;
    }
};

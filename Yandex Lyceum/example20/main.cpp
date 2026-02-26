class Notifier {
public:
    virtual void send(const std::string& message) const {

    };

    virtual ~Notifier() {}
};

class EmailNotifier : public Notifier{
private:
    std::string emailAddress_;
public:
    EmailNotifier(std::string emailAddress) {
        emailAddress_ = emailAddress;
    }

    void send(const std::string& message) const override{
        std::cout << "Sending Email to " << emailAddress_ << ": " << message ;
    }

    std::string getEmailAddress() const {
        return emailAddress_;
    }
};

class SmsNotifier : public Notifier{
private:
    std::string phoneNumber_;
public:
    SmsNotifier(std::string phoneNumber) {
        phoneNumber_ = phoneNumber;
    }

    void send(const std::string& message) const override{
        std::cout << "Sending SMS to "<< phoneNumber_ << ": " << message ;
    }

    std::string getPhoneNumber() const{
        return phoneNumber_;
    }
};

struct Contact {
    std::string name;
    std::unique_ptr<Notifier> notifier;
};

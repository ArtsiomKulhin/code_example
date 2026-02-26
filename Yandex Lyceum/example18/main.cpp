struct Point {
    int x, y;
};

class GraphicalObject {
protected:
    Point position_;
    std::string color_;
public:
    GraphicalObject(Point position, std::string color) {
        position_ = position;
        color_ = color;
    }

    Point getPosition() const{
        return position_;
    }

    std::string getColor() const{
        return color_;
    }

    virtual std::string draw() const {
        std::stringstream st;
        st << "GraphicalObject at " << position_.x << "," << position_.y << " with " << color_;
        return st.str();
    }

    virtual ~GraphicalObject() {}
};

class Line : public GraphicalObject {
private:
    Point endPoint_;
public:
    Line(Point st, Point en, std::string color) : GraphicalObject(st, color){
        endPoint_ = en;
    }

    Point getEndPoint() const {
        return endPoint_;
    }

    std::string draw() const override {
        std::stringstream s;
        s << "Drawing Line from " << GraphicalObject::position_.x << "," << GraphicalObject::position_.y << " to " << endPoint_.x << "," << endPoint_.y << " with " << color_;
        return s.str();
    }
};

class Rectangle : public GraphicalObject{
private:
    int width_, height_;
public:
    Rectangle(Point topLeft, int width, int height, std::string color) : GraphicalObject(topLeft, color){
        if (width <= 0) {
            width_ = 1;
        }
        else {
            width_ = width;
        }

        if (height <= 0) {
            height_ = 1;
        }
        else {
            height_ = height;
        }
    }

    int getWidth() const{
        return width_;
    }

    int getHeight() const{
        return height_;
    }

    std::string draw() const override {
        std::stringstream stri;

        stri << "Drawing Rectangle at " << GraphicalObject::position_.x << "," << GraphicalObject::position_.y << " with size " << width_ << "x" << height_ << " and " << GraphicalObject::color_;
        return stri.str();
    }
};

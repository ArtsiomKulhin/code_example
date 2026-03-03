class FileSystemNode {
private:
    std::string name_;
public:
    FileSystemNode(std::string name) {
        name_ = name;
    }

    std::string getName() const {
        return name_;
    }

    virtual size_t getSize() const {

    }

    virtual void display(int depth = 0) const {
    }

    virtual ~FileSystemNode() {}

    virtual bool isDirectory () const {
        return false;
    }
};

class File : public FileSystemNode{
private :
    size_t size_;
public:
    File(std::string name, size_t size): FileSystemNode(name) {
        if (size < 0) {
            size_ = 0;
        }
        else {
            size_ = size;
        }
    }

    size_t getSize() const override{
        return size_;
    }

    void display(int depth = 0) const override{
        for (int i = 0; i < depth; i++) {
            std::cout << "  ";
        }
        std::cout << "[F] " << getName() << " (" << size_ << " bytes)" << '\n';
    }
};

class Directory : public FileSystemNode {
private:
    std::vector<std::unique_ptr<FileSystemNode>> contents_;
public:
    Directory(std::string name): FileSystemNode(name) {

    }

    FileSystemNode* find(const std::string& name) const {
        for (auto& i : contents_) {
            if (i->getName() == name) {
                return i.get();
            }
        }
        return nullptr;
    }

    void add(std::unique_ptr<FileSystemNode> node) {
        contents_.push_back(std::move(node));
    }

    size_t getSize() const override{
        size_t sz = 0;

        for (auto& i : contents_) {
            sz += i->getSize();
        }

        return sz;
    }

    void display(int depth = 0) const override {
        for (int i = 0; i < depth; i++) {
            std::cout << "  ";
        }

        std::cout << "[D] " << getName() << '\n';

        for (auto& i : contents_) {
            i->display(depth + 1);
        }
    }

    bool isDirectory() const override {
        return true;
    }
};

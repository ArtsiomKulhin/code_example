class InventoryItem {
private:
    int itemId_, quantity_;
    std::string name_;
public:
    InventoryItem(int id, std::string name, int quantity) {
        itemId_ = id;
        name_ = name;
        if (quantity < 0) {
            quantity_ = 0;
        }
        else {
            quantity_ = quantity;
        }
    }

    int getItemId() const{
        return itemId_;
    }

    std::string getName() {
        return name_;
    }

    int getQuantity() {
        return quantity_;
    }

    void addStock(int amount) {
        if (amount > 0) {
            quantity_ += amount;
        }
    }

    bool removeStock(int amount) {
        if (amount > 0 && quantity_ - amount >= 0) {
            quantity_ -= amount;
            return true;
        }
        return false;
    }

    virtual ~InventoryItem(){}
};

class BookItem : public InventoryItem{
private:
    std::string author_;
    std::string isbn_;
public:
    BookItem(int id, std::string name, int quantity, std::string author, std::string isbn): InventoryItem(id, name, quantity){
        author_ = author;
        isbn_ = isbn;
    }

    std::string getAuthor() const {
        return author_;
    }

    std::string getISBN() const {
        return isbn_;
    }
};

class ElectronicItem : public InventoryItem{
private:
    int warrantyMonths_;
public:
    ElectronicItem(int id, std::string name, int quantity, int warrantyMonths):InventoryItem(id, name, quantity) {
        if(warrantyMonths < 0) {
            warrantyMonths_ = 0;
        }
        warrantyMonths_ = warrantyMonths;
    }

    int getWarrantyMonths() const {
        return warrantyMonths_;
    }
};

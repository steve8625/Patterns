
#include "operation.h"

class Component 
{
public:
    virtual ~Component() {}
    virtual int operation() const = 0;
    virtual bool is_composite() const = 0;
};

class Leaf : public Component 
{
private:
    int value_;
public:
    Leaf(int value) {
        value_ = value;
    }
    int operation() const override {
        return value_;
    }
    bool is_composite() const override {
        return false;
    }

};

class Composite : public Component 
{
private:
    Operation* op_;
    Component* left_;
    Component* right_;

public:
    Composite(Operation *op, Component *left, Component *right) {
        left_ = left;
        right_ = right;
        op_ = op;
    }

    bool is_composite() const override {
        return true;
    }

    int operation() const override {
        int count = 0;
        if (left_) count += left_->operation();
        if (right_) {
            if (op_->get_type() == '+') {
                count += right_->operation();
            }
            else if (op_->get_type() == '-') {
                count -= right_->operation();
            }
        }
        return count;
    }
};
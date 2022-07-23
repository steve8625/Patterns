class Operation
{
private:
    char op_;
public:
    Operation(char op) {
        op_ = op;
    }
    char get_type() {
        return op_;
    }
};
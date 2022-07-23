#include <iostream>
#include <list>
#include <string>

#include "component.h"

// we would like to do a arithmetic parser that could calculate the result
// by using the composite pattern so that we could freely add new operators

int main() {
    Operation op_plus('+');
    Operation op_minus('-');

    // should be (1+2) + (3-4)

    Component *leaf_1 = new Leaf(1);
    Component *leaf_2 = new Leaf(2);
    Component *branch1 = new Composite(&op_plus, leaf_1, leaf_2);

    Component *leaf_3 = new Leaf(3);
    Component *leaf_4 = new Leaf(4);
    Component *branch2 = new Composite(&op_minus, leaf_3, leaf_4);

    Component *tree = new Composite(&op_plus, branch1, branch2);
    
    std::cout << "b1 : " << branch1->operation() << std::endl;
    std::cout << "b2 : " << branch2->operation() << std::endl;
    std::cout << "tree : " << tree->operation() << std::endl;

    return 0;
}

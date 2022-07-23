#include <iostream>
#include <list>
#include <string>
#include <memory>

#include "component.h"

// we would like to do a arithmetic parser that could calculate the result
// by using the composite pattern so that we could freely add new operators

int main() {
    std::unique_ptr<Component> leaf_1(new Leaf(1));
    std::unique_ptr<Component> leaf_2(new Leaf(2));
    std::unique_ptr<Component> branch1(new Composite('+', leaf_1.get(), leaf_2.get()));

    std::unique_ptr<Component> leaf_3(new Leaf(3));
    std::unique_ptr<Component> leaf_4(new Leaf(4));
    std::unique_ptr<Component> branch2(new Composite('-', leaf_3.get(), leaf_4.get()));

    std::unique_ptr<Component> tree(new Composite('+', branch1.get(), branch2.get()));
    
    std::cout << "b1 : " << branch1->operation() << std::endl;
    std::cout << "b2 : " << branch2->operation() << std::endl;
    std::cout << "tree : " << tree->operation() << std::endl;
    return 0;
}

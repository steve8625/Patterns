#include <gtest/gtest.h>
#include "../component.h"

TEST(testCase, testAddTwoLeaf) {
    std::unique_ptr<Component> leaf_1(new Leaf(1));
    std::unique_ptr<Component> leaf_2(new Leaf(2));
    std::unique_ptr<Component> branch1(new Composite('+', leaf_1.get(), leaf_2.get()));
    ASSERT_EQ(branch1->operation(), 3);
}

TEST(testCase, testAddLeftLeaf) {
    std::unique_ptr<Component> leaf_1(new Leaf(1));
    std::unique_ptr<Component> branch1(new Composite('+', leaf_1.get(), nullptr));
    ASSERT_EQ(branch1->operation(), 1);
}

TEST(testCase, testAddRightLeaf) {
    std::unique_ptr<Component> leaf_2(new Leaf(2));
    std::unique_ptr<Component> branch1(new Composite('+', nullptr, leaf_2.get()));
    ASSERT_EQ(branch1->operation(), 2);
}

TEST(testCase, testMinusTwoLeaf) {
    std::unique_ptr<Component> leaf_1(new Leaf(1));
    std::unique_ptr<Component> leaf_2(new Leaf(2));
    std::unique_ptr<Component> branch1(new Composite('-', leaf_1.get(), leaf_2.get()));
    ASSERT_EQ(branch1->operation(), -1);
}

TEST(testCase, testMinusLeftLeaf) {
    std::unique_ptr<Component> leaf_1(new Leaf(1));
    std::unique_ptr<Component> branch1(new Composite('-', leaf_1.get(), nullptr));
    ASSERT_EQ(branch1->operation(), 1);
}

TEST(testCase, testMinusRightLeaf) {
    std::unique_ptr<Component> leaf_2(new Leaf(2));
    std::unique_ptr<Component> branch1(new Composite('-', nullptr, leaf_2.get()));
    ASSERT_EQ(branch1->operation(), -2);
}

TEST(testCase, testOperationWithBranches) {
    std::unique_ptr<Component> leaf_1(new Leaf(1));
    std::unique_ptr<Component> leaf_2(new Leaf(2));
    std::unique_ptr<Component> branch1(new Composite('+', leaf_1.get(), leaf_2.get()));

    std::unique_ptr<Component> leaf_3(new Leaf(3));
    std::unique_ptr<Component> leaf_4(new Leaf(4));
    std::unique_ptr<Component> branch2(new Composite('-', leaf_3.get(), leaf_4.get()));

    std::unique_ptr<Component> tree(new Composite('+', branch1.get(), branch2.get()));
    ASSERT_EQ(tree->operation(), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include "gtest/gtest.h"
#include "linked_list.h"

using xi::LinkedList;
using xi::Node;



TEST(linked_list_tests, CreatedEmptyList_HasSizeZero) {
    LinkedList<int> list;
    ASSERT_EQ(0, list.size());
}



TEST(linked_list_tests, AddingOneElementToEmptyList_HasSizeOne) {
    LinkedList<int> list;
    int inserted_element = 2;
    list.addElementToEnd(inserted_element);

    ASSERT_EQ(1, list.size());
}

TEST(linked_list_tests, AddingTwoElementsToEmptyList_HasSizeTwo) {
    LinkedList<int> list;
    int inserted_element = 2;
    list.addElementToEnd(inserted_element);

    int inserted_element_2 = 56;
    list.addElementToEnd(inserted_element_2);

    ASSERT_EQ(2, list.size());
}

TEST(linked_list_tests, AddingOneElementToEmptyList_ReturnFirstElement_ReturnsInsertedElement) {
    LinkedList<int> list;
    int inserted_element = 234;
    list.addElementToEnd(inserted_element);

    ASSERT_EQ(inserted_element, list.getPreHead()->next->value);
}




#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <iostream>

// ============================================================
// PART 2 Tests: DoublyLinkedList
// ============================================================

/// Create a DoublyLinkedList. Verify length() is 0 on a new list.
void test_new_list_is_empty(void)
{
    DoublyLinkedList x;

    TEST_ASSERT_TRUE_MESSAGE(x.length()==0, "NOT 0");
}

/// Create a DoublyLinkedList. Call pushFrontValue and pushBackValue.
/// Verify length() is 2.
void test_push_increases_length(void)
{
    DoublyLinkedList x;
    x.pushFrontValue(5);
    x.pushBackValue(6);

    TEST_ASSERT_TRUE_MESSAGE(x.length()==2, "did not equal 2");
}

/// Create an EMPTY DoublyLinkedList.
/// Verify popFrontValue() and popBackValue() both have NO value (has_value() is false).
void test_pop_on_empty_list(void)
{
    DoublyLinkedList x;

    TEST_ASSERT_TRUE_MESSAGE(x.popFrontValue().has_value()==false, "has value");
    TEST_ASSERT_TRUE_MESSAGE(x.popBackValue().has_value()==false, "has value");
}

/// Push 1, 2, 3 with pushBackValue.
/// Verify popBackValue() gives 3, then popFrontValue() gives 1, then length() is 1.
void test_pop_order(void)
{
    DoublyLinkedList x;
    x.pushBackValue(1);
    x.pushBackValue(2);
    x.pushBackValue(3);
    std::optional<NodeValue> val1 = x.popBackValue();
    TEST_ASSERT_TRUE_MESSAGE(val1==std::optional<NodeValue>(3), "doesn't equal 3");
    std::optional<NodeValue> val2 = x.popFrontValue();
    TEST_ASSERT_TRUE_MESSAGE(val2==std::optional<NodeValue>(1), "doesn't equal 1");
    TEST_ASSERT_TRUE_MESSAGE(x.length()==1, "did not equal 1");
}

/// Push one value, then call deleteValue with a value that is NOT in the list.
/// Verify it returns false and length() does not change.
void test_delete_value_not_found(void)
{
    DoublyLinkedList x;
    x.pushBackValue(5);
    TEST_ASSERT_TRUE_MESSAGE(x.deleteValue(3)==false, "not false");
    TEST_ASSERT_TRUE_MESSAGE(x.length()==1, "length is not 1");
}

/// Push 1, 2, 3 with pushBackValue. Call deleteValue(2).
/// Verify popBackValue() gives 3 and the next popBackValue() gives 1.
/// (popBackValue follows prevPtr: this fails if you forgot to repair the backward link.)
void test_delete_middle_keeps_links(void)
{
    DoublyLinkedList x;
    x.pushBackValue(1);
    x.pushBackValue(2);
    x.pushBackValue(3);
    
    x.deleteValue(2);
    TEST_ASSERT_TRUE_MESSAGE(x.popBackValue()==std::optional<NodeValue>(3), "not 3");
    TEST_ASSERT_TRUE_MESSAGE(x.popBackValue()==std::optional<NodeValue>(1), "not 1");
}

// ============================================================
// PART 3 Tests: StdDoublyLinkedList
// ============================================================

/// Push 1, 2, 1 with pushBackValue. Call deleteValue(NodeValue{1}).
/// Verify length() is 2 and popFrontValue() gives 2 (only the FIRST 1 was removed).
void test_std_delete_only_first(void)
{
    StdDoublyLinkedList x;
    x.pushBackValue(1);
    x.pushBackValue(2);
    x.pushBackValue(1);
    x.deleteValue(NodeValue{1});
    TEST_ASSERT_TRUE_MESSAGE(x.length()==2, "length is not 2");
    TEST_ASSERT_TRUE_MESSAGE(x.popFrontValue()==std::optional<NodeValue>(2), "pop front is not 2 is not 2");
}

/// Create an EMPTY StdDoublyLinkedList.
/// Verify popFrontValue() and popBackValue() have NO value and do not crash.
void test_std_pop_on_empty_list(void)
{
    StdDoublyLinkedList x;
    TEST_ASSERT_TRUE_MESSAGE(x.popFrontValue()==std::nullopt, "has value");
    TEST_ASSERT_TRUE_MESSAGE(x.popBackValue()==std::nullopt, "has value");
}

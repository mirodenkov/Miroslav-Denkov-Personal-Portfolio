#include "LinkedList.h"
#include "gtest/gtest.h"

class LinkedListTest : public ::testing::Test
{
protected:
  virtual void SetUp()
  {
  }

  virtual void TearDown()
  {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(LinkedListTest, addFirst) // success
{
  LinkedList list;
  ASSERT_EQ(0, list.addFirst(1));
  int result = list.getHeadValue();
  int expected = 1;
  ASSERT_EQ(expected, result);
}
TEST_F(LinkedListTest, addlast) // success
{
  LinkedList list;
  ASSERT_EQ(0, list.addFirst(1));
  ASSERT_EQ(0, list.addLast(2));
  int result = list.getTailValue();
  int expected = 2;
  ASSERT_EQ(expected, result);
}
TEST_F(LinkedListTest, addAfter) // success
{
  LinkedList list;
  list.addFirst(1);
  list.addLast(2);

  Node *head = list.getHead();
  int expected = 4;
  int expected2 = 5;
  list.addAfter(head, expected);
  list.addAfter(head->getNext(), expected2);
  ASSERT_EQ(expected, head->getNext()->getValue());
  ASSERT_EQ(expected2, head->getNext()->getNext()->getValue());
}

TEST_F(LinkedListTest, getElementValue)
{
  LinkedList list;
  list.addFirst(1);

  for (int i = 2; i < 11; i++)
  {
    list.addLast(i);
  }

  Node *head = list.getHead();

  ASSERT_EQ(1, head->getValue());            // the head must equal 1
  ASSERT_EQ(2, head->getNext()->getValue()); // after the head equals 2
  ASSERT_EQ(5, list.getElementValue(4));     // this function should return the 4th element value which is 5
}

TEST_F(LinkedListTest, remFirst)
{
  LinkedList list;
  list.addFirst(1);
  for (int i = 2; i < 11; i++)
  {
    list.addLast(i);
  }
  Node *head = list.getHead();
  ASSERT_EQ(1, head->getValue());
  list.remFirst();
  head = list.getHead();
  ASSERT_EQ(2, head->getValue());
}
TEST_F(LinkedListTest, RemFirst_SingleElement)
{
  LinkedList list;
  list.addFirst(42);
  ASSERT_EQ(0, list.remFirst());
  ASSERT_EQ(nullptr, list.getHead());
  ASSERT_EQ(nullptr, list.getTail());
}

TEST_F(LinkedListTest, Clean)
{
  LinkedList list;
  for (int i = 1; i <= 5; ++i)
  {
    list.addLast(i);
  }
  // Now clean out all 5 nodes:
  ASSERT_EQ(0, list.clean());
  // List should be empty:
  ASSERT_EQ(nullptr, list.getHead());
  ASSERT_EQ(nullptr, list.getTail());
}

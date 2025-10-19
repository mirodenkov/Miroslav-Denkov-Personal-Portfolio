#include "MyStack.h"
#include "gtest/gtest.h"

class metaTest : public ::testing::Test
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

/* A simple framework for Unit Test */
TEST(Test, StackCreationTest)
{
  MyStack *stack = new MyStack(sizeof(int)); // create a stack of size int
  
  ASSERT_EQ(0, stack->myStackNoOfElem());
  
  int data = 11;
  int result = stack->myStackPush(&data);
  ASSERT_EQ(0, result);
  
  ASSERT_EQ(1, stack->myStackNoOfElem());
  
  delete stack;
}

TEST(Test, StackPushPopTest)
{
  MyStack *stack = new MyStack(sizeof(int)); // create a stack of size int
  
 
  int data = 42;
  int result = stack->myStackPush(&data);
  ASSERT_EQ(0, result);
  
  ASSERT_EQ(1, stack->myStackNoOfElem());
  
  int poppedData;
  result = stack->myStackPop(&poppedData);
  ASSERT_EQ(0, result);
  
  ASSERT_EQ(data, poppedData);
  
  ASSERT_EQ(0, stack->myStackNoOfElem());
  
  delete stack;
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#include "MyStack.h"
#include "MyQueue.h"
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
/* Test enqueue functionality */
TEST(QueueEnqueueTest, EnqueueSingleElement)
{
  MyQueue *queue = new MyQueue(sizeof(int));
  int value = 42;

  // Test successful enqueue
  int result = queue->myQueueEnqueue(&value);
  EXPECT_EQ(result, 0);

  delete queue;
}

TEST(QueueEnqueueTest, EnqueueMultipleElements)
{
  MyQueue *queue = new MyQueue(sizeof(int));
  int values[] = {10, 20, 30, 40, 50};

  // Enqueue multiple elements
  for (int i = 0; i < 5; i++)
  {
    int result = queue->myQueueEnqueue(&values[i]);
    EXPECT_EQ(result, 0);
  }

  delete queue;
}

TEST(QueueEnqueueTest, EnqueueNullPointer)
{
  MyQueue *queue = new MyQueue(sizeof(int));

  // Test enqueue with null pointer - should fail
  int result = queue->myQueueEnqueue(nullptr);
  EXPECT_EQ(result, -1);

  delete queue;
}

TEST(QueueDequeueTest, DequeueNullPointer)
{
  MyQueue *queue = new MyQueue(sizeof(int));
  int value = 42;
  queue->myQueueEnqueue(&value);

  // Test dequeue with null pointer - should fail
  int result = queue->myQueueDequeue(nullptr);
  EXPECT_EQ(result, -1);

  delete queue;
}

TEST(QueueDequeueTest, EnqueueThenDequeue)
{
  MyQueue *queue = new MyQueue(sizeof(int));
  int inputValue = 42;
  int outputValue;

  // Enqueue then dequeue
  queue->myQueueEnqueue(&inputValue);
  int result = queue->myQueueDequeue(&outputValue);

  EXPECT_EQ(result, 0);
  EXPECT_EQ(outputValue, inputValue);

  delete queue;
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

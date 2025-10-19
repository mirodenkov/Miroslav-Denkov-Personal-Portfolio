#include <string.h>

#include "linkedlist.h"
#include "unity.h"

#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
  // This is run before EACH test
}

void tearDown(void)
{
  // This is run after EACH test
}

void test_add_first(void)
{
  int ret;
  ITEM *list = NULL;
  int value = 5;
  int result = value;

  ret = add_first(&list, value);
  TEST_ASSERT_EQUAL(0, ret); // check if function executes correctly

  ITEM *current_node = list;
  TEST_ASSERT_NOT_NULL(current_node); // Ensure the list isn't NULL

  int actual_result = current_node->value;
  TEST_ASSERT_EQUAL(result, actual_result); // check if value is correct

  clean(&list); // Ensure clean works correctly
  TEST_ASSERT_NULL(list);
}

void test_add_last(void)
{
  int frst;
  ITEM *list = NULL;
  frst = add_first(&list, 1);
  int lst = add_last(&list, 2);
  TEST_ASSERT_EQUAL(0, frst);
  TEST_ASSERT_EQUAL(0, lst);
  clean(&list);
}

void test_add_after(void)
{
  ITEM *list = NULL;
  int value1 = 1, value2 = 2, value3 = 3, value4 = 4;

  // Add items to the list
  add_first(&list, value1); // List: [1]
  add_last(&list, value2);  // List: [1] -> [2]
  add_last(&list, value3);  // List: [1] -> [2] -> [3]

  // Now the list is: [1] -> [2] -> [3]

  ITEM *c_item = list->next; // c_item is the node with value 2 (second node)

  // Insert a new node with value 4 after c_item
  int ret = add_after(list, c_item, value4);
  TEST_ASSERT_EQUAL(0, ret); // Ensure function executed successfully

  // Check if the new node with value 4 is correctly placed after value 2
  ITEM *current = list;
  int found = 0;
  while (current != NULL && current->next != NULL)
  {
    if (current->value == value2 && current->next->value == value4)
    {
      found = 1; // The node with value 4 is after the node with value 2
      break;
    }
    current = current->next;
  }

  TEST_ASSERT_EQUAL(1, found); // Test passes if the condition is met

  // Clean up
  clean(&list);
}

void test_rem_last(void)
{
  ITEM *list = NULL;

  // Add elements to the list
  add_last(&list, 1);
  add_last(&list, 2);
  add_last(&list, 3);

  // Remove last element
  int ret = rem_last(&list);
  TEST_ASSERT_EQUAL(0, ret); // Check if function executes correctly

  // Traverse list and check if last element is 2 now
  ITEM *current = list;
  while (current->next != NULL)
  {
    current = current->next;
  }

  TEST_ASSERT_EQUAL(2, current->value); // Ensure last item is now 2

  // Clean up
  clean(&list);
}
void test_rem_after(void)
{
  ITEM *list = NULL;

  // Create a sample linked list: [1] -> [2] -> [3]
  add_first(&list, 3);
  add_first(&list, 2);
  add_first(&list, 1);

  ITEM *first_node = list;               // Points to [1]
  int ret = rem_after(list, first_node); // Remove [2]

  TEST_ASSERT_EQUAL(0, ret);               // Check function executed successfully
  TEST_ASSERT_NOT_NULL(list);              // List should still exist
  TEST_ASSERT_EQUAL(1, list->value);       // First node should still be [1]
  TEST_ASSERT_EQUAL(3, list->next->value); // Next node should now be [3]
  TEST_ASSERT_NULL(list->next->next);      // There should be no more nodes after [3]

  clean(&list); // Free memory
}

void test_clean(void)
{
  ITEM *list = NULL;

  clean(&list);
  TEST_ASSERT_NULL(list);

  add_last(&list, 10);
  add_last(&list, 20);
  add_last(&list, 30);

  TEST_ASSERT_NOT_NULL(list);
  TEST_ASSERT_EQUAL(10, list->value);

  clean(&list);

  TEST_ASSERT_NULL(list);

  clean(&list);
  TEST_ASSERT_NULL(list);
}

int main(int argc, char *argv[])
{
  UnityBegin();

  /* Put your UTs here */
  MY_RUN_TEST(test_add_first);
  MY_RUN_TEST(test_add_last);
  MY_RUN_TEST(test_add_after);
  MY_RUN_TEST(test_rem_last);
  MY_RUN_TEST(test_rem_after);
  MY_RUN_TEST(test_clean);

  return UnityEnd();
}

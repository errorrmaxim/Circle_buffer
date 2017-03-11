#include "tst_ewq.h"

#include <gtest/gtest.h>

ring_buff<int, 10>test_ring;


TEST(TestRingBuffer, Empty_Test)
{

    ASSERT_EQ(test_ring.max_size(), 10);        //try max size of buffer
    ASSERT_TRUE(test_ring.empty() == true);     //+
    ASSERT_TRUE(test_ring.full() == false);     //+

}
TEST(TestRingBuffer, InitialState)
{
    //put three elements inside R_B
   for(int i = 0; i < 3; i++)
       test_ring.push(i);

    ASSERT_EQ(test_ring.size(), 3);

    //put more elements and test of occupancy
    for(int i = 0; i < 7; i++)
        test_ring.push(i);

    test_ring.push(-1);
    ASSERT_TRUE(test_ring.full() == true);

    //try last element which redefined
    ASSERT_EQ(test_ring.back(), -1);

    //remove five elements and look at size of R_B
    test_ring.erase_back(5);
    ASSERT_EQ(test_ring.size(), 5);

    //try last element
    ASSERT_EQ(test_ring.back(), 4);

}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

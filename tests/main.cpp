#include <gtest/gtest.h>

TEST(DummyTest, dummyTest)
{
    ASSERT_TRUE(true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
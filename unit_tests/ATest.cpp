#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

namespace Tests
{
    TEST(ATest,test)
    {
        EXPECT_THAT(1,Eq(1));
    }
}
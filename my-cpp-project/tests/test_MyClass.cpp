#include "gtest/gtest.h"
#include "MyClass.h"
#include <sstream>
#include <iostream>

TEST(MyClassTest, TestMyMethod) {
    MyClass myClass;
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    myClass.myMethod();
    std::cout.rdbuf(oldCout);
    EXPECT_EQ(buffer.str(), "Hello, World!\n");
}
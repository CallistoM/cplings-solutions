#include <iostream>
#include <stdint.h>
#include <vector>

// templates5.cpp
// Make me compile! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on shape given exercise,
// even after you already figured it out.

// Step 1: Make me compile. Make the class Repeater a template class.
// function so that it could support generic inputs (vectors of both int and deque of double) 
// Use two generic types to accept both deque and vector.
// Use the keyword auto for the generic T returned by the function max

template<typename T, typename R, typename F>  // Fix: Fix me
class Repeater {
private:
    std::vector<T> v;
public:
    Repeater() {
        int repeat = 0;
        if (std::is_same<T, int>::value) {
            repeat = 5;
            for (auto _{repeat}; _--;) {
                v.push_back(42);        
            }
        }

        if (std::is_same<T, char>::value) {
            repeat = 3;
            
            for (auto _{repeat}; _--;) {
                v.push_back('A');        
            }
        }
    };
    const auto get() const { 
        return v;
    };
};

std::vector<int> test_templates5_0() {
    Repeater<int, double, int32_t> repeatInt;
    return repeatInt.get();
}

std::vector<char> test_templates5_1() {
    Repeater<char, char, int> repeatChar;
    return repeatChar.get();
}

#include <catch2/catch.hpp>

TEST_CASE("test_template5") {
    std::vector<int> repeatIntResult = test_templates5_0();
    std::vector<char> repeatCharResult = test_templates5_1();
    std::vector<int> repeatIntExpected {42, 42, 42, 42, 42};
    std::vector<char> repeatCharExpected {'A', 'A', 'A'};
    REQUIRE(repeatIntResult == repeatIntExpected);
    REQUIRE(repeatCharResult == repeatCharExpected);
}

import std; // C++23 标准库模块:

import mathlib;

int main() {
    std::println("Hello, C++23 Modules!");  // std::println 需要 C++23
    std::vector<int> v = {1, 2, 3};
    std::println("{} + {} is {}", 3, 5, math::add(3, 5));

    return 0;
}

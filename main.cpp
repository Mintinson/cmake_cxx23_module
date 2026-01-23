import std; // C++23 标准库模块:

import mathlib;

class XX
{
public:
    void func()
    {
        std::println("XX::func called");
    }

private:
    int daTa_;
    int data;
};

auto main() -> int
{
    std::println("Hello, C++23 Modules!"); // std::println 需要 C++23
    std::vector<int> v = { 1, 2, 3 };
    std::println("{} + {} is {}", 3, 5, math::add(3, 5));
    std::array<int, 3> arr = { 10, 20, 30 };
    for (auto x : std::ranges::views::reverse(arr))
    {
        std::println("{}", x);
    }
    auto dx = math::add(1.5, 2.5); // 调用重载的 add 函数
    std::println("1.5 + 2.5 is {}", dx);
    return 0;
    
}
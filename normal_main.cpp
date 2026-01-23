#include <concepts>
#include <print>
#include <ranges>
#include <vector>

namespace normal
{
    template<std::regular T> T add(T a, T b)
    {
        return a + b;
    }
}

int main()
{
    std::println("hello world");

    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    for (const auto& v : vec | std::views::filter([](int n) { return n % 2 == 0; }))
    {
        std::println("Value: {}", v);
    }

    return 0;
}

#include <iostream>
#include <ranges>
#include <algorithm>
#include <memory>
#include <vector>

consteval int foo()
{
    return 5;
}

int main() {
    const auto range = std::views::iota(0, 10);
    const auto countDivisibleBy2 = std::ranges::count_if(range, [](const auto& val) {return val % 2;});
    std::cout << countDivisibleBy2 <<std::endl;
    const auto subrange = range | std::views::drop(3) | std::views::take(10);
    std::cout << subrange.front() << std::endl;
    std::cout << subrange[9] << std::endl;
    
    const auto array_ptr = std::make_shared<int[]>(5);
    
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::shift_left(numbers.begin(), numbers.end(), 2);
    for (int number : numbers) {
        std::cout << number << std::endl;
    }


    return 0;
}

#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
    unsigned long long previous = 0;
    unsigned long long current = 1;
    for (int n = 0; n < i; ++n) {
        const auto next = previous + current;
        previous = current;
        current = next;
    }
    return previous;
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // 迭代实现避免了大量重复的递归计算，90 也可以在编译期完成。
    constexpr auto ANS_N = 90;
    constexpr auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}

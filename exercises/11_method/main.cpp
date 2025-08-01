#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128]={0, 1}; // 初始化前两个斐波那契数
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        cached = 0; // 初始化缓存
        if(!cached)
        {
            cached = 2; // 已经计算了前两个数
            for (; cached<128; ++cached) {
                cache[cached] = cache[cached - 1] + cache[cached - 2];
            }
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}

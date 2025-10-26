#include <stdio.h>

// 故意使用一个只有 MSVC 才认识的关键字
__declspec(dllexport) void hello(void) {
    printf("Hello\n");
}

// 故意使用 GCC/Clang 特有的属性语法
__attribute__((constructor)) void init(void) {
    puts("Init");
}

// 故意使用 C++ 风格的注释（虽然 C99 以后支持，但某些严格 C89 模式会报错）
// This is a C++ style comment

int main() {
    // 故意调用一个未声明的函数
    undeclared_function();

    // 故意使用变长数组（VLA），C90 不支持
    int n = 10;
    int arr[n];

    return 0;
}
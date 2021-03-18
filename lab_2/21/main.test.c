#include <assert.h>
#include "main.h"

void test_area(void)
{
    float a = area(2);
    assert(a - 12.56 < 0.000001);
}
void test_sector(void)
{
    float b = sector(3, 4);
    assert(b - 18 < 0.000001);
}
void test_circumf(void)
{
    float c = circumf(7);
    assert(c - 43.96 < 0.000001);
}
void test_square(void)
{
    float d = square(5.1);
    assert(d - 7.21 < 0.000001);
}
void test_cone(void)
{
    float e = cone(7.9);
    assert(e - 516.04 < 0.000001);
}

#undef main

int main(void)
{
    void test_area();
    void test_sector();
    void test_circumf();
    void test_square();
    void test_cone();
    void test_cone();
    return 0;
}
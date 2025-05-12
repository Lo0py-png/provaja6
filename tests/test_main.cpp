#include <cassert>
extern int add(int, int);          // declaration comes from main.cpp

int main() {
    assert(add(2, 3) == 5);
    return 0;
}

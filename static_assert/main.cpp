#include <cstring>

using namespace std;

#define assert_static(e) \
    do { \
        enum { assert_static__ = 1 / (e) }; \
    } while(0)

template <typename T, typename U> int bit_copy(T& a, U& b) {
//    assert_static(sizeof(b) == sizeof(a));
    static_assert(sizeof(b) == sizeof(a), "bit copy must have same bit width");
    memcpy(&a, &b, sizeof(b));
    return 0;
}

int main() {
    int a = 0x0001;
    double b;
    int c = 0x0003;

    bit_copy(a, b);
    return 0;
}

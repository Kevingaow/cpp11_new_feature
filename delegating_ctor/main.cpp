#include <cstring>
#include <iostream>

using namespace std;

#if 0
class Info {
public:
    Info() {
        initReset();
    }

    Info(int i) : Info() {
        type = i;
    }

    Info(char e) : Info() {
        name = e;
    }

    int getType() {
        return type;
    }

private:
    void initReset() {
        type += 1;
    };
    int type {1};
    char name {'a'};
};
#else
class Info {
public:
    Info() : Info(1, 'a') {
    }

    Info(int i) : Info(i, 'a') {
    }

    Info(char e) : Info(1, 'e') {
    }

    int getType() {
        return type;
    }

private:
    Info(int i, char e)
        :type(i),
        name(e) {
        type += 1;
    };
    int type {1};
    char name {'a'};
};
#endif


int main() {
    Info info(3);
    cout << "info.getType(): " << info.getType() << endl;

    return 0;
}

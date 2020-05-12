#include <iostream>

using namespace std;

#define MOVE_CTOR

class MovePtr {
public:
    MovePtr() : d(new int(0)) {
        cout << "ctor:" << ++n_ctor << endl;
    }
    MovePtr(const MovePtr& m) : d(new int(*(m.d))) {
        cout << "copy ctor:" << ++n_cptr << endl;
    }

#ifdef MOVE_CTOR
    MovePtr(MovePtr&& m) : d(m.d) {
        m.d = nullptr;
        cout << "move ctor:" << ++n_mtor << endl;
    }
#endif

    ~MovePtr() {
        delete d;
        cout << "dtor:" << ++n_dtor << endl;
    }

    static int n_ctor;
    static int n_cptr;
    static int n_dtor;

#ifdef MOVE_CTOR
    static int n_mtor;
#endif

    int* d;
};

int MovePtr::n_ctor = 0;
int MovePtr::n_cptr = 0;
int MovePtr::n_dtor = 0;
#ifdef MOVE_CTOR
int MovePtr::n_mtor = 0;
#endif

MovePtr getMovePtr() {
#ifdef MOVE_CTOR
    MovePtr m1;
    cout << "m1.d:" << hex << m1.d << endl;
    return m1;
#else
    MovePtr a1;
    MovePtr a2(a1);
    return a2;
#endif
}

int main() {
    MovePtr mp = getMovePtr();
    cout << "mp.d:" << hex << mp.d << endl;
    return 0;
}

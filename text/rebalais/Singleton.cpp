#include "Rebalais.h"

Singleton &Singleton::getInstance() {
    static Singleton single;
    return single;
}
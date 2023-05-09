#include "Rebalais.h"

class Singleton {
    private:
        Singleton();
        Singleton(Singleton const &copy);
        void operator=(Singleton const &assign);
    public:
        static Singleton &getInstance();
};
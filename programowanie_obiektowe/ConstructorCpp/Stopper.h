#include <iostream>
#include <chrono>

class Stopper {
    protected:
        std::chrono::milliseconds pocz;
        std::chrono::milliseconds kon;
        int64_t czas;

    public:
        Stopper();
        void start();
        void stop();
        void reset();
        void pokazStoper();

};
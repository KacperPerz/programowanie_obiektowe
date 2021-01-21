#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <chrono>

class Logger {

    private:
        bool debug;

    public:
        Logger(bool debug);
        void log(std::string str);
};
#include "Logger.h"
using namespace std;


Logger::Logger(bool debug=true) {
    this->debug = debug;
}

void Logger::log(string str) {
    if(this->debug) {
        auto now = chrono::system_clock::now();
        auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;
        auto timer = chrono::system_clock::to_time_t(now);

        tm bt = *localtime(&timer);

        ostringstream ss;

        ss << put_time(&bt, "%H:%M:%S");
        ss << '.' << setfill('0') << setw(3) << ms.count();

        string czas = ss.str();
        cout << czas << ": " << str << endl;
    }
}
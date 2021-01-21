#include <iostream>
#include <memory>

class Wezel {

    public:
        std::weak_ptr<Wezel> next;
        ~Wezel();
        Wezel();
};
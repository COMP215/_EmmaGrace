#ifndef EXAM1MUSHROOM
#define EXAM1MUSHROOM

#include <vector>

class Mushroom {
    public:
    std::string common_name_, scientific_name_;
    short quantity_, dollars_;
    float dollar_per_oz_;
};

class Satchel {
    public:
    void PackSatchel(std::vector<Mushroom>);
    
    short capacity_;
};

#endif

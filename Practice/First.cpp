#include <iostream>
#include <vector>

class Sensor {
    std::string name;
    int count;
    double lastValue;
    double sum;
    mutable int accessCount;
    static int objectCount;

public:
    Sensor(const std::string& n)
        : name(n), count(0), lastValue(0.0), sum(0.0), accessCount(0) {
        ++objectCount;
    }

    ~Sensor() {
        --objectCount;
    }

    void update(double v) {
        lastValue = v;
        sum += v;
        ++count;
    }

    double average() const {
        ++accessCount;
        return count ? sum / count : 0.0;
    }

    static int getObjectCount() {
        return objectCount;
    }

    friend std::ostream& operator<<(std::ostream& os, const Sensor& s);
};

int Sensor::objectCount = 0;

std::ostream& operator<<(std::ostream& os, const Sensor& s) {
    os << s.name << " " << s.count << " "
       << s.lastValue << " " << s.average();
    return os;
}

int main(){
std::vector<int> vec{3};

for(int x:vec){
  std::cout<< x<<"" ;
}

}
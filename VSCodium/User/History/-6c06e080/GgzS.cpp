#include <iostream>

using namespace std;

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    Counter operator++(int) {
        Counter temp = *this;
        ++count;
        return temp;
    }

    void display() const {
        cout << "Count: " << count << endl;
    }
};

int main() {
    Counter c;
    c.display();

    c++;
    c.display();

    return 0;
}

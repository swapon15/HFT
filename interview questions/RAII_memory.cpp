#include<iostream>
using namespace std;

class custom_array {
    private:
        int *mBuffer;
        int mSize;
    public:
        custom_array(int size): mSize {size} {
            mBuffer = new int[size]; // memory allocated
        }

        ~custom_array() {
            delete [] mBuffer; // memory de-allocated when object of custom_array goes out of scope
        }

        int get(int idx) const {
            if (idx >= mSize) {
                throw std::invalid_argument("index out of bound");
            }
            return mBuffer[idx];
        }

        void put(int idx, int value) {
            if (idx >= mSize) {
                throw std::invalid_argument("index out of bound");
            }
            mBuffer[idx] = value;
        }

};

int main() {
    custom_array ca(10); // memory allocated during declaration/initialization
    ca.put(0, 10);
    ca.put(1, 20);
    std::cout << ca.get(0) << " " << ca.get(1) << std::endl;
    // ca goes out of scope here. So, destructor is called and memory is freed.
    return 0;
}
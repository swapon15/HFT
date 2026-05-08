#include <iostream>
#include <fstream>

using namespace std;

class FileHandler {
    private:
        ofstream file;
    
    public:

    FileHandler (const std::string& fileName) {
        file.open(fileName);
        std::cout << "File Opened" << std::endl;
    }

    void write(const std::string& text) {
        file << text << std::endl;
    }

    ~FileHandler() {
        file.close();
        std::cout << "File Closed" << std::endl;
    }
};

int main() {
    std::string file_name = "my_file.txt";
    FileHandler fh(file_name); // Resource created
    fh.write("Hello");
    //Resource released

}
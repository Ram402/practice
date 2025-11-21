#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    
    
    fstream file("cpp.pdf",ios::in | ios::out | ios::app);
    try
    {
            if (!(file.is_open()))
    {
        cout << "files not exist" << endl;
        return 1;
    }

    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    // file.seekg(0);
    // file << "hello world!";
    string line;
    while(getline(file,line))
    {
        cout << line << endl;   
    }
    file.close();
    return 0;
}
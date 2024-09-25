#include <iostream>
using namespace std;

int main() {
    cout << "A variable is a named or otherwise addressable area of memory that can be used to access data." << endl;
    cout << "In C++, variables are divided into 4 types:" << endl; 
    cout << "1. Integer" << endl;
    cout << "2. Character" << endl; 
    cout << "3. Floating-point" << endl; 
    cout << "4. Boolean" << endl;

    // Integer types
    cout << "\n1) Integer Types:" << endl;
    cout << "   1. int, Size = 4 bytes (32 bits), Range = (-2,147,483,648 to 2,147,483,647)" << endl;
    cout << "   2. short, Size = 2 bytes (16 bits), Range = (-32,768 to 32,767)" << endl;
    cout << "   3. long, Size: Typically 4 bytes (32 bits) / 8 bytes (64 bits), Range = (-2,147,483,648 to 2,147,483,647)" << endl;
    cout << "   4. long long, Size = 8 bytes (64 bits), Range = (-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807)" << endl;

    // Character type
    cout << "\n2) Character Type:" << endl;
    cout << "   char, Size = 1 byte (8 bits), Range = (-128 to 127 or 0 to 255 depending on signed/unsigned)" << endl;

    // Floating-point types
    cout << "\n3) Floating-point Types:" << endl;
    cout << "   1. float, Size = 4 bytes (32 bits), Precision ~6-7 decimal digits" << endl;
    cout << "   2. double, Size = 8 bytes (64 bits), Precision ~15 decimal digits" << endl;
    cout << "   3. long double, Size = Typically 8 or more bytes (depends on the compiler), Precision > double" << endl;

    // Boolean type
    cout << "\n4) Boolean Type:" << endl;
    cout << "   bool, Size = 1 byte (8 bits), Values: true or false" << endl;
    return 0;
}

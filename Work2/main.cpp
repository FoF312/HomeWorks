#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double R;
    const double PI = acos(-1.0);
    cout << "Enter the radius of the circle( 0 to 100):";
    cin >> R;
    if (R <= 0 || R > 100)
    {
        cout << "Error! the number doesn't fit";
        return 1;
    }      
        double area = PI * R * R;
    
    cout << fixed << setprecision(9);
    cout << "Area of a circle with radius " << R << "  equal  " << area << endl;
    system("pause");
    return 0;
}


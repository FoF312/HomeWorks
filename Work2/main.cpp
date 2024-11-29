#include <iostream>
#include <iomanip>
#include <limits>

/**
 * Program to calculate the area of a circle given its radius
 * Validates input and handles errors appropriately
 */

namespace {
    constexpr double PI = 3.141592653589793238463;  // More precise PI value
    constexpr double MIN_RADIUS = 0.0;
    constexpr double MAX_RADIUS = 100.0;
}

double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

bool isValidRadius(double radius) {
    return radius > MIN_RADIUS && radius <= MAX_RADIUS;
}

int main() {
    double radius;

    // Input with validation
    std::cout << "Enter the radius of the circle (between " 
              << MIN_RADIUS << " and " << MAX_RADIUS << "): ";
    
    while (!(std::cin >> radius) || !isValidRadius(radius)) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Invalid input. Please enter a number.\n";
        } else {
            std::cout << "Error: Radius must be between " << MIN_RADIUS 
                      << " and " << MAX_RADIUS << ".\n";
        }
        std::cout << "Please try again: ";
    }

    // Calculate and display result
    double area = calculateCircleArea(radius);
    
    std::cout << std::fixed << std::setprecision(9);
    std::cout << "Area of a circle with radius " << radius 
              << " is equal to " << area << std::endl;

    return 0;
}

#include <iostream>
#include "mathpp.h"

int main() {
    mathpp::Fraction fra1 (0.75);
    mathpp::Fraction fra2 (-2, -3);
    std::cout << fra1 + fra2;
}

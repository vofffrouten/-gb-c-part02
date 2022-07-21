#include <iostream>
#include <fstream>
#include <iomanip>

void firstTask () {
    int input { 0 };
    ///бесконечный цикл подсмотрел в интернетах,
    //т.к. не придумал другого критерия
    while(true){
        std::cout << "enter integer: ";
        std::cin >> input;
        if (std::cin.good()){
            std::cout << "your number is integer!" << std::endl;
            return;
        } else {
            std::cout << "your number isnt integer!" << std::endl;
            std::cin.clear();
            std::cin.ignore(65535, '\n'); // не уверен в размере streamsize (65535)
        }
    }
}

//seconTask манипулятор endll 
std::ostream& endll(std::ostream &out) {
    out << "\n\n";
    std::cout.flush();
    return out;
}

void secondTask () {
    std::cout << "endll test" << endll
              << "endll check pass" << std::endl;
}

int main () {
    firstTask();
    secondTask();
    return 0;
}
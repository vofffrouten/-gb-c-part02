#include <iostream>

#define PI 3.14;

class Figure {
public:
    virtual float getArea() = 0;
};

class Circle : public Figure {
float rad;

public:
    Circle (float r = 0) : rad (r) {}

    float getArea () override {
        return rad*rad*PI;
    }
};

class Parallelogram : public Figure {
protected:
    float a;
    float h;    
public: 
    Parallelogram (float _a, float _h) : a(_a), h(_h) {} 

    float getArea () override {
        return a*h;
    }
};

class Rectangale : public Parallelogram {
public: 
    Rectangale (float _a, float _h) : Parallelogram (_a, _h) {} 
};

class Square : public Parallelogram {
public: 
    Square (float a) : Parallelogram (a, a) {
        h = a;
    } 
};

class Rhombus : public Parallelogram {
    float d1, d2; //диагонали

public: 
    Rhombus (float _a, float _h, float _d1, float _d2) : 
            Parallelogram (_a, _h),  d1 (_d1), d2 (_d2) {} 
    float getArea () override {
        return d1*d2/2;
    }
};

class Car {
protected:
    std::string company;
    std::string model;
public:
    Car (std::string _company, std::string _model) : company (_company), model (_model) {
        std::cout << "Company: " << company << "  Model: " << model << std::endl;
        std::cout << "Type: Car\n";
    }
};

class PassengerCar : public Car {
public:
    PassengerCar (std::string company, std::string model) : Car (company, model) {
        std::cout << "Class: Passenger Car\n";
    }
};

class Bus : public Car {
public:
    Bus (std::string company, std::string model) : Car (company, model) {
        std::cout << "Class: Bus\n";
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan (std::string company, std::string model) : PassengerCar (company, model), Bus (company, model) {
        std::cout << "Subclass: Minivan\n";
    }
};

class Fraction{
    int numer;
    int denom;
public:
    Fraction () {}
    Fraction (int numer, int denom){
        if (denom <= 0 ){
            std::cout << "Fraction couldnt be created (denom is 0)\n";
        } else {
            this -> numer = numer;
            this -> denom = denom;
        }
    }

    // переопределение, которое показывали на уроке 
    // с двумя аргументами не компилится g++
    Fraction operator+ (Fraction& f){ 
        Fraction temp;
        if (denom == f.denom){
            temp.denom = denom;
            temp.numer = numer + f.numer;
        } else {
            temp.denom = denom * f.denom;
            temp.numer = numer * f.denom + f.numer * denom;
        }
        std::cout<< numer << "/" << denom << " + " << f.numer <<"/"<< f.denom << 
                    " = " << temp.numer << "/" << temp.denom << std::endl;
        return temp;
    }

    Fraction operator- (Fraction& f){ 
        Fraction temp;
        if (denom == f.denom){
            temp.denom = denom;
            temp.numer = numer - f.numer;
        } else {
            temp.denom = denom * f.denom;
            temp.numer = numer * f.denom - f.numer * denom;
        }
        std::cout<< numer << "/" << denom << " - " << f.numer <<"/"<< f.denom << 
                    " = " << temp.numer << "/" << temp.denom << std::endl;
        return temp;
    }

    Fraction operator* (Fraction& f){
        Fraction temp;
        temp.numer = numer * f.numer;
        temp.denom = denom * f.denom;
        std::cout<< numer << "/" << denom << " * " << f.numer <<"/"<< f.denom << 
                    " = " << temp.numer << "/" << temp.denom << std::endl;
        return temp;
    }

    Fraction operator/ (Fraction& f){
        Fraction temp;
        temp.numer = numer * f.denom;
        temp.denom = denom * f.numer;
        std::cout<< numer << "/" << denom << " / " << f.numer <<"/"<< f.denom << 
                    " = " << temp.numer << "/" << temp.denom << std::endl;
        return temp;
    }

    bool operator== (Fraction& f){
        if (numer * f.denom == f.numer * denom){
            return true;
        } else {
            return false;
        }
    }

    bool operator!= (Fraction& f){
        if (numer * f.denom != f.numer * denom){
            return true;
        } else {
            return false;
        }
    }

    bool operator< (Fraction& f){
        if (numer * f.denom < f.numer * denom) {
            return true;
        } else {
            return false;
        }
    }

    bool operator> (Fraction& f){
        if (numer * f.denom > f.numer * denom) {
            return true;
        } else {
            return false;
        }
    }
    bool operator<= (Fraction& f){
        if (numer * f.denom <= f.numer * denom) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>= (Fraction& f){
        if (numer * f.denom >= f.numer * denom) {
            return true;
        } else {
            return false;
        }
    }
};

enum Suit { HEARTS = 1, CLUBS, DIAMONDS, SPADES };
enum CardRank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
                EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card {
    int suit;
    int rank;
    bool faceUp;
public:
    Card (int _suit, int _rank, bool _faceUp) : 
        suit (_suit), rank (_rank), faceUp (_faceUp) {} //конструктор пока что пустой

    void Flip () {
        faceUp = !faceUp;
    }

    int GetValue ()
    {
        return rank;
    }
};

int main () {
    Circle cir(2);
    std::cout << cir.getArea() << "\n";
    Square sq(3);
    std::cout << sq.getArea() << "\n";
    Rectangale rec(3, 4);
    std::cout << rec.getArea() << "\n";
    Rhombus rhom(3, 4, 5, 6);
    std::cout << rhom.getArea() << "\n";

    Car car01 ("somecar", "wow");
    PassengerCar car02 ("bmw", "m3");
    Bus car03 ("volvo", "g976");
    Minivan car04 ("hyundai", "h1");

    Card firstCard(HEARTS, ACE, 0); 
    
    std::cout << firstCard.GetValue() << "\n";

    Fraction f1 (1, 3);
    Fraction f2 (2, 6);
    Fraction tmp (2, 1);

    tmp = f1 + f2;
    tmp = f1 - f2;
    tmp = f1 * f2;
    tmp = f1 / f2;

    std::cout << "f1 == f2  " << (f1 == f2) << std::endl;
    std::cout << "f1 != f2  " << (f1 != f2) << std::endl;
    std::cout << "f1 < f2  " << (f1 < f2) << std::endl;
    std::cout << "f1 > f2  " << (f1 > f2) << std::endl;
    std::cout << "f1 >= f2  " << (f1 >= f2) << std::endl;
    std::cout << "f1 <= f2  " << (f1 <= f2) << std::endl;

    return 0;
}
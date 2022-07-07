#include <iostream>

int stdCount = { 0 }; // ничего лучше, чем вынести счетчик в глобальные переменные не придумал ((

class Person
{
protected:
    std::string name;
    int age;
    char sex;
    float weight;

public:
    Person (std::string _name, int _age, char _sex, float _weight) : 
        name (_name), age (_age), sex (_sex), weight (_weight) {
            stdCount ++;
        }

    ~Person () 
    {
        stdCount--;
    }

    void setName (std::string name)
    {
        this -> name = name;
    }
    
    void setAge (int age)
    {
        this -> age = age;
    }

    void setWeight (int weight)
    {
        this -> weight = weight;
    }    
};

class Student : public Person
{
private:
    int educationYear;

public:
    Student (std::string name, int age, char sex, float weight, int year) : Person(name, age, sex, weight), educationYear(year){}

    void setEducationYear (int year)
    {
        educationYear = year;
    }

    void plusEducationYear ()
    {
        educationYear++;
    }

    void printStudent ()
    {
        std::cout << "name: " << name << std::endl
                << "age: " << age << std::endl
                << "sex: " << sex << std::endl
                << "weight: " << weight << std::endl
                << "year of study: " << educationYear << std::endl;
    }
};

class Fruit 
{
    protected:
        std::string name;
        std::string color;
    public:
        Fruit (std::string _name, std::string _color) : name (_name), color (_color) {};
               
        std::string getName ()
        {
            return name;
        }

        std::string getColor ()
        {
            return color;
        }
};

class Banana : public Fruit
{
public:
    Banana () : Fruit ("banana", "yellow") {};
};

class Apple : public Fruit
{
public:
    Apple (std::string color) : Fruit ("apple", color) {};
    Apple (std::string name, std::string color) : Fruit (name, color) {};
};

class GrannySmith : public Apple
{
public:
    GrannySmith () : Apple ("Granny Smith", "green") {};
};

int main ()
{
    Student stA("Frank", 20, 'M', 71, 2);
    Student stB("Lena", 21, 'F', 53, 3);
    Student stC("Carl", 18, 'M', 65, 1);

    stA.printStudent();
    stB.printStudent();
    stC.printStudent();
    std::cout << stdCount << "\n";

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

/* 
Блэк-Джек

Глобальный класс Game (?)

Класс: Person - Dealer 
              - Player
И для крупье, и для игрока куча одинаковых параметров.

Класс: Card

На самом деле мне пока не понятно насколько нужно паковать классы в классы ((

*/
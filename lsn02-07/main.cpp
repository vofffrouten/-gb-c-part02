#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date (int dd = 1, int mm = 1, int yy = 1900) : day(dd), month(mm), year(yy) {}
    ~Date() = default;
    friend std::ostream& operator<< (std::ostream& out, Date d);

    void setDay (int d){
        day = d;
    }
    void setMonth (int m){
        month = m;
    }
    void setYear (int y){
        year = y;
    }
    
    int getDay (){
        return day;
    }
    int getMonth (){
        return month;
    }
    int getYear (){
        return year;
    }
};

std::ostream& operator<< (std::ostream& out, Date d){
    return out << d.day << "-" << d.month << "-" << d.year;
}

Date compareDate (Date* d1, Date* d2){
    
    
    return 0;
} 

int main () {
    Date* today;
    Date* date;

    today -> setDay(4);
    today -> setMonth(8);
    today -> setYear(2022);

    std::cout << "Day: "<< today -> getDay() << std::endl
              << "Month: "<< today -> getMonth() << std::endl
              << "Year: "<< today -> getYear() << std::endl;

    std::cout << *today << std::endl;

    date = today;

    today = nullptr;

    std::cout << date << std::endl;
    std::cout << today << std::endl;

    Date* date1;
    Date* date2;

    date1 = today;
    date2 -> setDay(15);
    date2 -> setMonth(9);
    date2 -> setYear(1956);

    return 0;
}
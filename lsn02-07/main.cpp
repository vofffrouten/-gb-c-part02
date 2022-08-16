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
    if (d1 -> getYear() == d2 -> getYear())
        if (d1 -> getMonth() == d2 -> getMonth())
            if (d1 -> getDay() == d2 -> getDay())
                return *d1;
            else if (d1 -> getDay() > d2 -> getDay())
                    return *d1;
                else
                    return *d2;
        else if (d1 -> getMonth() > d2 -> getMonth())
                return *d1;
            else
                return *d2;
    else if (d1 -> getYear() == d2 -> getYear())
            return *d1;
        else
            return *d2;    
} 

void swapDate (Date* d1, Date* d2){
    Date temp = *d1;
    *d1 = *d2;
    *d2 = temp;
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

    *date = *today;

    today = nullptr; // не очень понял нужно ли чистить указатель

    std::cout << date << std::endl;
    std::cout << today << std::endl;

    //до сих пор работает верно, compare и swap тоже работают (пробовал на date и today)
    //дальше при создании date1 и date2 начинает "моросить" на setDay. без этого блока все огонь, буду разбираться что происходит

    Date* date1;
    Date* date2;

    date1 -> setDay(1);
    date1 -> setMonth(10);
    date1 -> setYear(1995);

    date2 -> setDay(15);
    date2 -> setMonth(9);
    date2 -> setYear(1956);

    std::cout << compareDate(date, today) << std::endl;

    std::cout << *date1 << std::endl;
    std::cout << *date2 << std::endl;

    swapDate (date, today);
    std::cout << "SWAP!" << std::endl;

    std::cout << *date1 << std::endl;
    std::cout << *date2 << std::endl;

    return 0;
}
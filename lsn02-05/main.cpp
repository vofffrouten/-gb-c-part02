#include <iostream>
#include <vector>
#include <string>

template <class T> 
class Pair1 {
    T firstNum;
    T secondNum;
public:
    Pair1 (T _first, T _second) : firstNum(_first), secondNum(_second) {}
    
    T& first () const {
        return firstNum;
    }
    
    T& second () const {
        return secondNum;
    }
};

template <class T1, class T2>
class Pair {
private:
    T1 firstNum;
    T2 secondNum;
public:
    Pair (T1 _first, T2 _second) : firstNum(_first), secondNum(_second) {}

    T1& first () const {
        return firstNum;
    }
    
    T2& second () const {
        return secondNum;
    }
};

template <class T2>
class StringValuePair: public Pair <std::string, T2> {
public:
    StringValuePair (std::string _first, T2 _second) : Pair <std::string, T2> (_first, _second) {}
};

// ~~~~ BJ ~~~~
enum CardSuit { HEARTS, CLUBS, DIAMONDS, SPADES };
enum CardRank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
                EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };

class Card {
    CardSuit suit;
    CardRank rank;
    bool faceUp;
public:
    Card (CardSuit _suit, CardRank _rank, bool _faceUp) : 
        suit (_suit), rank (_rank), faceUp (_faceUp) {} //конструктор пока что пустой

    void Flip () {
        faceUp = !faceUp;
    }

    int GetValue ()
    {
        return rank;
    }
};

class Hand{ //водопады памяти еще не поправил )))
protected:
    std::vector <Card> cardsInHand;  
public:
    void add (Card income){
        cardsInHand.push_back(income);
    }

    void clear ()
    {
        cardsInHand.clear();
    }

    int getValue (){
        int sum = { 0 };
        bool aceIn = { 0 };
        for (auto i : cardsInHand){
            sum += i.GetValue();
            if (i.GetValue() == ACE) { aceIn = true; }
        }
        if (aceIn  && sum <= 11) { sum += 10; }  //добавил потерянную проверку туза
        return sum;
    }
};

class GenericPlayer : public Hand {
    std::string name;
public:
    void setName(std::string _name) {
        name = _name;
    }
    
    virtual bool IsHitting () { }

    bool IsBusted () {
        if (getValue() > 21) { 
            return true; 
        } else {
            return false; 
        }
    }

    std::string Bust() {
        return name + ", you've over maximum";
    }
};

int main () {
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
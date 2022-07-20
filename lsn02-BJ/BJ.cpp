#include <iostream>
#include <iomanip>
#include <vector>

enum CardSuit { HEARTS, CLUBS, DIAMONDS, SPADES };
enum CardRank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
                EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };

template <typename T>
T getInput () {
    T input { 0 };
    while(true){
        std::cin >> input;
        if (std::cin.good()){
            return input;
        } else {
            std::cout << "input is not correct" << std::endl;
            std::cin.clear();
            std::cin.ignore(65535, '\n'); 
        }
    }
}

class Card {
private:
    CardSuit suit;
    CardRank rank;
    bool faceUp;
    friend std::ostream& operator<< (std::ostream& out, Card& card);

public:
    Card (CardSuit _suit, CardRank _rank, bool _faceUp) : 
        suit (_suit), rank (_rank), faceUp (_faceUp) {} //конструктор пока что пустой

    void flip () {
        faceUp = !faceUp;
    }

    int getValue () {
        return rank;
    }

    int getSuit () {
        return suit;
    }

    bool faceUpCheck () {
        return faceUp;
    }
};

std::ostream& Card::operator<< (std::ostream& out, Card& card){  
    if (card.faceUpCheck()) {
        out << card.rank << " " << card.suit;  //переписать! пока что выводит "шифровки из центра"
    } else {
        out << "XX";
    }
    return out;
}

class Hand {  // подпилил водопад
protected:
    std::vector <Card*> cardsInHand;  
public:
    void add (Card* income){
        cardsInHand.push_back(income);
    }

    void clear () {
    std::vector<Card*>::iterator i = cardsInHand.begin();
    for (i = cardsInHand.begin(); i <= cardsInHand.end(); ++i)
    {
        delete *i;
        *i = 0;
    }
        cardsInHand.clear();
    }

    int getValue () const {
        int sum = { 0 };
        bool aceIn = { 0 };
        for (auto i : cardsInHand){
            sum += i -> getValue();
            if (i -> getValue() == ACE) { 
                aceIn = true; 
            }
        }
        if (aceIn  && sum <= 11) { sum += 10; }
        return sum;
    }
};

class GenericPlayer : public Hand {
private:
    friend std::ostream& operator<< (std::ostream& out, GenericPlayer& player){}
protected:
    std::string name;
public:
    void setName(std::string _name) {
        name = _name;
    }
    
    virtual bool isHitting () const { }

    bool isBusted () {
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

class Player : public GenericPlayer{
public:
    bool isHitting() const override {
        char input { '0' };
        std::cout << "do you need a card? (Y/N)";
        do 
        {
            input = getInput <char> ();
        } while (input != 'Y' || input != 'N');
        return (input == 'Y');
    }

    void win () const {
        std::cout << name << " wins!";
    }

    void lose () const {
        std::cout << name << " loses!";
    }

    void push () const {
        std::cout << "Pushes.";
    }
 
};

class House : public GenericPlayer{
public:
    bool isHitting() const override {
        return (getValue() <= 16);
    }

    void flipFirstCard () {
        cardsInHand[0] -> flip();
    }
};

//не хочет перегружать в самом классе. 
//не дает поставить второй операнд Card& card


//подсмотрел в методичке, что можно через френд работать с классом
//но gcc не дает так сделать все равно
// error: redefinition of ‘std::ostream& operator<<(std::ostream&, GenericPlayer&)’
// std::ostream& operator<< (std::ostream& out, GenericPlayer& player){

std::ostream& operator<< (std::ostream& out, GenericPlayer& player){ 
//    out << player.name << ""; is protected within this context out << player.name << ""; даже если включаю friend в классе
//    

    out << "  " << player.getValue ();
    return out;
}

int main () {
    Player pl01;
    Card crd01(CLUBS, TEN, 1);
    
    pl01.add(&crd01);

    std::cout << pl01.getValue() << std::endl;
    std::cout << crd01 << std::endl;

    return 0;
}
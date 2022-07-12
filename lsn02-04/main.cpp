#include <iostream>
#include <vector>


void mySwap(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}

class Container {
    int* data;
    int size;
    int capacity;

public:
    Container() : size(0), data(nullptr), capacity(0) {}
    Container(int _size) : size(_size), capacity(0) {
        if (_size == 0) {
            Container();
        } else if (_size < 0) {
            printf("%s\n", "Bad things happened");
            Container();
        } else {
            this->data = new int[_size];
        }
    }
    virtual ~Container() { delete[] data; }

    //дз по контейнеру
    void pop_back (){
        if (size == 0) { return; }
        --size;
        int* tmp = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = data[i];
        }
        delete[] data;
        data = new int[size];
        data = tmp;
    }

    //дз по контейнеру
    void pop_front (){
        if (size == 0) { return; }
        --size;
        int* tmp = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = data[i+1];
        }
        delete[] data;
        data = new int[size];
        data = tmp;
    }

    //дз по контейнеру
    void sort(){
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j+1]) {
                    mySwap(data[j], data[j+1]); }
            }
        } 
    }

    //дз по контейнеру   
    void print() {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    int capacityf() { return this->capacity; }
    int get(int idx) { return data[idx]; }
    void set(int idx, int value) { data[idx] = value; }

};

//дз по вектору

void printVec(const std::vector <int> & vec) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int findInVector (const std::vector <int> & vec) {
    std::vector <int> tmp = vec;
    int uniqueNum { 1 };
    //решил делать через сортировку.. почему? фиг знает
    for (size_t i = 0; i < tmp.size() - 1; i++) {    
        for (size_t j = 0; j < tmp.size() - i - 1; j++) {
            if (tmp[j] > tmp[j+1]) {
                mySwap(tmp[j], tmp[j+1]); }
        }
    }
    for (size_t i = 0; i < tmp.size() - 1; i++){
        if (tmp[i] != tmp [i+1]) { ++uniqueNum; }
    }
    printVec(tmp);
    return uniqueNum;
}

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

class Hand{
    std::vector <Card> cardsInHand;  
public:
    void add (Card income){
        cardsInHand.push_back(income);
    }

    void clear ()
    {
        cardsInHand.clear();
    }

    int geValue (){
        int sum = { 0 };
        for (auto i : cardsInHand){
            sum += i.GetValue(); 
        }
        return sum;
    }
};

int main (){

    std::vector <int> vectorOfNum { 1, 23, 4, 1, 4, 54, 5, 2, 3 };
    printVec(vectorOfNum);
    std::cout << "Number of different numbers is " << findInVector(vectorOfNum) << "\n";
    
    int size = 5;
    Container cont01(size);
    for (size_t i = 0; i < size; i++)
    {
        cont01.set(i, 20 - i*3);
    }
    cont01.print();
    cont01.pop_back();
    cont01.print();
    cont01.sort();
    cont01.print();
    return 0;
}
#include <iostream>
#include <string>
#include <deque>
#include <random>
#include <algorithm>
#include <queue>
#include <chrono>  
using namespace std::chrono;
enum class suits{Clubs = 0, Diamonds = 1, Hearts = 2, Spades = 3 };
class card{
private:
int value;
suits suit;
int overall_value;
public:
card(){}
card(suits s, int v): suit(s), value(v){}
std::string get_suit_string(){
    switch (suit)
    {
    case suits::Clubs:
       return "Clubs";

    case suits::Diamonds:
       return "Diamonds";

    case suits::Hearts:
       return "Hearts";

    case suits::Spades:
       return "Spades";

    
    default:
    return "error";

    }
}
std::string get_value_string(){
    switch (value)
    {
    case 1:
        return "Ace";

    case 11:
        return "Jack";
    
    case 12:
        return "Queen";

    case 13:
        return "King";
       
    default:
        return std::to_string(value);
    }
}
int get_overall_value(){
    return (static_cast<int>(suit) * 13) + (value - 1);
}
void print(){
    std::cout<<get_value_string()<<" of "<<get_suit_string()<<" "<<get_overall_value()<<std::endl;
}
};
class deck{
public:
std::deque<card> Deck;
public:
deck(){
    for(int i=1;i<=13;i++){
            Deck.push_back(card(suits::Clubs, i));
    }
           for(int i=1;i<=13;i++){
            Deck.push_back(card(suits::Diamonds, i));
    }
    for(int i=1;i<=13;i++){
            Deck.push_back(card(suits::Hearts, i));
    }
    for(int i=1;i<=13;i++){
            Deck.push_back(card(suits::Spades, i));
    }
    
}
void print(){
    for(int i=0;i<52;i++){
        Deck.at(i).print();
    }
}
};
void shuffle_deck(deck& d,int n){
    for(int k = 0; k<n;k++){
std::queue<card> A,B;
 std::random_device rd;
std::mt19937 gen(rd());
std::normal_distribution<> cut_dist(26.0, 2.0);
int cut_point = std::round(cut_dist(gen));
int i =0;
cut_point = std::max(1, std::min(51, cut_point));  
for(;i<cut_point && !d.Deck.empty();i++){
    A.push(d.Deck.front()); d.Deck.pop_front();
}
while(!d.Deck.empty()){
     B.push(d.Deck.front()); d.Deck.pop_front();
}
while(!A.empty()){
    std::random_device rnd;
    std::mt19937 gen(rnd());  
    std::uniform_real_distribution<> dist(0.0, 1.0);  

    double r = dist(gen);
    double probA = static_cast<double>(A.size()) / (A.size() + B.size());
if (r < probA) {
    d.Deck.push_back(A.front());
    A.pop();
} else {
    d.Deck.push_back(B.front());
    B.pop();
}
}
while(!B.empty()){
    d.Deck.push_back(B.front());
        B.pop();
}
    }
}
int main(){
    deck d1;
    auto start = high_resolution_clock::now();
    shuffle_deck(d1,7);
    auto end = high_resolution_clock::now();    

auto duration = duration_cast<milliseconds>(end - start);  

    d1.print();
    std::cout << "\nTime taken to shuffle: " << duration.count() << " ms\n";
}
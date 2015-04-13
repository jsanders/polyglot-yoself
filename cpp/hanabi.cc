#include <iostream>
#include <vector>
#include <string>
#include <random>

class Card {
    public:

    Card(std::string c, int n) : color{c}, number{n} {}

    void print() const {
        std::cout << color << " " << number << std::endl;
    }

    private:

    std::string color;
    int number;
};

class Deck {
    public:

    Deck() {
        std::vector<std::string> colors = { "white", "yellow", "blue", "red", "green" };
        std::vector<int> numbers = { 1, 1, 1, 2, 2, 3, 3, 4, 4, 5 };
        for(auto color : colors) {
            for(auto number : numbers) {
                cards.push_back(Card { color, number });
            }
        }
    }

    void print() const {
        for(auto card : cards) {
            card.print();
        }
    }

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }

    Card deal() {
        auto card = cards.back();
        cards.pop_back();
        return card;
    }

    private:

    std::vector<Card> cards;

};

class Player {
    public:

    Player() : hand{} {}

    void receive(Card card) {
        hand.push_back(card);
    }

    void print_hand() const {
        for(auto card : hand) {
            card.print();
        }
    }

    private:

    std::vector<Card> hand;
};

int main() {
    Player player1;
    Player player2;

    Deck deck;
    deck.shuffle();

    for(int i=0; i < 4; ++i) {
        player1.receive(deck.deal());
        player2.receive(deck.deal());
    }

    std::cout << "Player 1:" << std::endl;
    player1.print_hand();

    std::cout << "Player 2:" << std::endl;
    player2.print_hand();

    return 0;
}

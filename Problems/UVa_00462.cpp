#include <iostream>
#include <complex>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <bitset>
#include <utility>

std::map<char, int> bindings = {
        std::pair<char, int>('S', 0),
        std::pair<char, int>('H', 1),
        std::pair<char, int>('D', 2),
        std::pair<char, int>('C', 3),

        std::pair<char, int>('2', 0),
        std::pair<char, int>('3', 1),
        std::pair<char, int>('4', 2),
        std::pair<char, int>('5', 3),
        std::pair<char, int>('6', 4),
        std::pair<char, int>('7', 5),
        std::pair<char, int>('8', 6),
        std::pair<char, int>('9', 7),
        std::pair<char, int>('T', 8),
        std::pair<char, int>('J', 9),
        std::pair<char, int>('Q', 10),
        std::pair<char, int>('K', 11),
        std::pair<char, int>('A', 12),
    };

void update_cards(int (&cards)[4][13], std::string &input){
    cards[bindings[input[1]]][bindings[input[0]]]++;
}

int cards_in_a_suit(int (&cards)[4][13], char suit){
    int cnt = 0;
    for(int i = 0; i < 13; i++){
        cnt += cards[bindings[suit]][i];
    }
    return cnt;
}

char longest_suit(int (&cards)[4][13]){
    int max = 0;
    char max_suit = 'S';
    if(cards_in_a_suit(cards, 'S') > max){
        max = cards_in_a_suit(cards, 'S');
        max_suit = 'S';
    }
    if(cards_in_a_suit(cards, 'H')  > max){
        max = cards_in_a_suit(cards, 'H');
        max_suit = 'H';
    }
    if(cards_in_a_suit(cards, 'D')  > max){
        max = cards_in_a_suit(cards, 'D');
        max_suit = 'D';
    }
    if(cards_in_a_suit(cards, 'C')  > max){
        max = cards_in_a_suit(cards, 'C');
        max_suit = 'C';
    }
    return max_suit;
}

void uva_00462(){
    std::string input;
    while(std::cin >> input){
        int cards[4][13];
        bool stopped[4] = {0 ,0, 0, 0};
        for(int i = 0; i < 4; i++)
            std::fill(cards[i], cards[i]+13, 0);
        update_cards(cards, input);
        for(int i = 1; i < 13; i++){
            std::cin >> input;
            update_cards(cards, input);
        }
        int points = 0;
        // Rule 1
        for(int i = 0; i < 4; i++)
            if(cards[i][bindings['A']])
                points += 4;
       // std::cout << points << std::endl;

        for(int i = 0; i < 4; i++)
            if(cards[i][bindings['K']])
                points+= 3;
      //  std::cout << points << std::endl;

        for(int i = 0; i < 4; i++)
            if(cards[i][bindings['Q']])
                points+= 2;
      //  std::cout << points << std::endl;

        for(int i = 0; i < 4; i++)
            if(cards[i][bindings['J']])
                points+= 1;
      //  std::cout << points << std::endl;

        // Rule 2
        if(cards[bindings['S']][bindings['K']]){
            if(cards_in_a_suit(cards, 'S') == 1)
                points -= 1;
            else if(cards_in_a_suit(cards, 'S') >= 2)
                stopped[bindings['S']] = true;
        }
        if(cards[bindings['H']][bindings['K']]){
            if(cards_in_a_suit(cards, 'H') == 1)
                points -= 1;
            else if(cards_in_a_suit(cards, 'H') >= 2)
                stopped[bindings['H']] = true;
        }
        if(cards[bindings['D']][bindings['K']]){
            if(cards_in_a_suit(cards, 'D') == 1)
                points -= 1;
            else if(cards_in_a_suit(cards, 'D') >= 2)
                stopped[bindings['D']] = true;
        }
        if(cards[bindings['C']][bindings['K']]){
            if(cards_in_a_suit(cards, 'C') == 1)
                points -= 1;
            else if(cards_in_a_suit(cards, 'C') >= 2)
                stopped[bindings['C']] = true;
        }
      //  std::cout << points << std::endl;

        //Rule 3

        if(cards[bindings['S']][bindings['Q']]){
            if(cards_in_a_suit(cards, 'S') >= 1 && cards_in_a_suit(cards, 'S') <= 2)
                points -= 1;
            else if(cards_in_a_suit(cards, 'S') >= 3)
                stopped[bindings['S']] = true;
        }
        if(cards[bindings['H']][bindings['Q']]){
            if(cards_in_a_suit(cards, 'H') >= 1 && cards_in_a_suit(cards, 'H') <= 2)
                points -= 1;
            else if(cards_in_a_suit(cards, 'H') >= 3)
                stopped[bindings['H']] = true;
        }
        if(cards[bindings['D']][bindings['Q']]){
            if(cards_in_a_suit(cards, 'D') >= 1 && cards_in_a_suit(cards, 'D') <= 2)
                points -= 1;
            else if(cards_in_a_suit(cards, 'D') >= 3)
                stopped[bindings['D']] = true;
        }
        if(cards[bindings['C']][bindings['Q']]){
            if(cards_in_a_suit(cards, 'C') >= 1 && cards_in_a_suit(cards, 'C') <= 2)
                points -= 1;
            else if(cards_in_a_suit(cards, 'C') >= 3)
                stopped[bindings['C']] = true;
        }
      //  std::cout << points << std::endl;

        // Rule 4

        if(cards[bindings['S']][bindings['J']]){
            if(cards_in_a_suit(cards, 'S') >= 1 && cards_in_a_suit(cards, 'S') <= 3)
                points -= 1;
        }
        if(cards[bindings['H']][bindings['J']]){
            if(cards_in_a_suit(cards, 'H') >= 1 && cards_in_a_suit(cards, 'H') <= 3)
                points -= 1;
        }
        if(cards[bindings['D']][bindings['J']]){
            if(cards_in_a_suit(cards, 'D') >= 1 && cards_in_a_suit(cards, 'D') <= 3)
                points -= 1;
        }
        if(cards[bindings['C']][bindings['J']]){
            if(cards_in_a_suit(cards, 'C') >= 1 && cards_in_a_suit(cards, 'C') <= 3)
                points -= 1;
        }

        // Suit stopping for aces
        if(cards[bindings['S']][bindings['A']])
            stopped[bindings['S']] = true;
        if(cards[bindings['H']][bindings['A']])
            stopped[bindings['H']] = true;
        if(cards[bindings['D']][bindings['A']])
            stopped[bindings['D']] = true;
        if(cards[bindings['C']][bindings['A']])
            stopped[bindings['C']] = true;

    /*    std::cout << points << std::endl;
        for(int i = 0; i < 4; i++)
            std::cout << stopped[i] << ' ';
        std::cout << std::endl;*/
        if(stopped[0] && stopped[1] && stopped[2] && stopped[3] && points >= 16)
            std::cout << "BID NO-TRUMP" << std::endl;
        else{
            //Rule 5
            if(cards_in_a_suit(cards, 'S') == 2)
                points += 1;
            if(cards_in_a_suit(cards, 'H') == 2)
                points += 1;
            if(cards_in_a_suit(cards, 'D') == 2)
                points += 1;
            if(cards_in_a_suit(cards, 'C') == 2)
                points += 1;

            //Rule 6
            if(cards_in_a_suit(cards, 'S') == 1)
                points += 2;
            if(cards_in_a_suit(cards, 'H') == 1)
                points += 2;
            if(cards_in_a_suit(cards, 'D') == 1)
                points += 2;
            if(cards_in_a_suit(cards, 'C') == 1)
                points += 2;

            //Rule 7
            if(cards_in_a_suit(cards, 'S') == 0)
                points += 2;
            if(cards_in_a_suit(cards, 'H') == 0)
                points += 2;
            if(cards_in_a_suit(cards, 'D') == 0)
                points += 2;
            if(cards_in_a_suit(cards, 'C') == 0)
                points += 2;

        //    std::cout << points << std::endl;
            if(points < 14)
                std::cout << "PASS" << std::endl;
            else
                std::cout<< "BID " << longest_suit(cards) << std::endl;
        }
    }
}

int main(){
    uva_00462();
}

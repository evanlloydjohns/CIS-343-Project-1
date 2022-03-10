#include "Board.hpp"
#include "BoardValues.hpp"

#include <algorithm>
#include <iostream>

Board::Board(){
    // Creating grid
    grid = new int[WIDTH*HEIGHT];
    for(int i = 0; i < WIDTH*HEIGHT; i++){
        grid[i] = 68; // Filling grid with ASCII of "SPACES"
    }
}

// What is this for?  takes in a board called other?
Board::Board(const Board& other){
}

Board& Board::operator=(const Board& other){
}

// Destructor - Free any memory back
Board::~Board(){
    delete(grid);
}

// Not sure how this ties into game will have to watch youtube
void Board::setVisible(bool v){
}

int& Board::Internal::operator[](int index){
    if(index >= WIDTH){
        throw std::out_of_range(std::to_string(index) + " is greater value than or equal to grid width of " + std::to_string(WIDTH));
    }
    return _grid[index];
}

Board::Internal Board::operator[](int index){
    if(index >= HEIGHT){
        throw std::out_of_range(std::to_string(index) + " is greater value than or equal to grid height of " + std::to_string(HEIGHT));
    }
    return Board::Internal(grid+(index * WIDTH));
}

// Overloading stream operator so you can print board with std::cout << board
std::ostream& operator<<(std::ostream& os, Board const& b){
    char holder; // Needed as a placeholder for the ASCII value
    std::string value;
    for(int i = 1; i <= HEIGHT; i++){
        for(int j = 1; j <= WIDTH; j++){
            //holder = putchar(b.grid[i*j-1]); // Holds ASCII value to print
            os << " " << (char)b.grid[i*j-1];
        }
        os << std::endl;
    }

    return os;
}

// Not sure probably keeping count of turns
int Board::count() const{
}

// Compares which board is winning sort of i think
bool Board::operator< (const Board& other){
}

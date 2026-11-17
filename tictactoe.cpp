#include <array>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
char checkwin(std::array<char, 9> &spaces);
void computerMove(std::array<char, 9> &spaces, char player);
void takeposition(std::array<char, 9> &spaces, char player);
void drawboard(const std::array<char, 9> &spaces);
int main(int argc, char *argv[]) {
  srand(time(0));
  char player = 'X';
  char computer = 'O';
  std::array<char, 9> spaces{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  bool running = true;
  drawboard(spaces);
  while (running) {
    takeposition(spaces, player);
    drawboard(spaces);
    if (checkwin(spaces) != ' ')
      break;
    computerMove(spaces, computer);
    drawboard(spaces);
    if (checkwin(spaces) != ' ')
      break;
  }
  switch (checkwin(spaces)) {
  case 'X':
    std::cout << "player wins" << "\n";
    break;
  case 'O':
    std::cout << "computer wins" << "\n";
    break;
  case 'T':
    std::cout << "tie" << "\n";
    break;
  }
  return 0;
}

char checkwin(std::array<char, 9> &spaces) {
  int lines[8][3] = {
      {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
      {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
      {0, 4, 8}, {2, 4, 6}             // diagonals
  };

  for (auto &line : lines) {
    char a = spaces[line[0]];

    if (a != ' ' && a == spaces[line[1]] && a == spaces[line[2]]) {
      return a;
    }
  }

  for (char c : spaces) {

    if (c == ' ') {
      return ' ';
    }
  }
  return 'T';
}

void computerMove(std::array<char, 9> &spaces, char player) {

  while (1 == 1) {
    int number = rand() % 9;
    if (spaces[number] == ' ') {
      spaces[number] = player;
      break;
    } else {
      continue;
    }
  }
}
void takeposition(std::array<char, 9> &spaces, char player) {
  int number = 0;
  do {
    std::cout << "Input Position 1 - 9: " << "\n";
    std::cin >> number;
    number--;
    if (spaces[number] == ' ') {

      spaces[number] = player;
      break;

    } else {
      std::cout << "space is occupied!" << "\n";
      continue;
    }
  } while (number > 0 || number < 8);
}

void drawboard(const std::array<char, 9> &spaces) {
  std::cout << "\n";
  for (int row = 0; row < 3; ++row) {
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[row * 3] << "  |  " << spaces[row * 3 + 1]
              << "  |  " << spaces[row * 3 + 2] << "  \n";
    std::cout << "     |     |     \n";
    if (row < 2)
      std::cout << "-----+-----+-----\n";
  }
  std::cout << "\n";
}

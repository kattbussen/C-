#include <iostream>

int main() {
  int number = 0;
  std::cin >> number;

  int tens = 0;
  int fives = 0;
  int rest = 0;

  tens = number / 10;
  rest = number % 10;
  fives = rest / 5;
  rest = rest % 5;

  std::cout << tens+fives+rest << std::endl;

  return 0;
}

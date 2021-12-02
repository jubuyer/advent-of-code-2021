#include <iostream>
#include <fstream>
#include <vector>

void part1() {
  int horizontal = 0;
  int depth = 0;

  std::string line;
  std::fstream file;
  file.open("course.csv");
  if(file.is_open()) {
     while(std::getline(file, line)) {
       if(line.substr(0,2) == "fo") {
         int i = std::stoi(line.substr(8,1));
         horizontal += i;
       } else if(line.substr(0,2) == "do") {
         int j = std::stoi(line.substr(5,1));
         depth += j;
       } else if(line.substr(0,2) == "up") {
         int k = std::stoi(line.substr(3,1));
         depth -= k;
       }
     }
   }

   int ans = horizontal * depth;

   std::cout << ans << '\n';
}

void part2() {
  int horizontal = 0;
  int depth = 0;
  int aim = 0;

  std::string line;
  std::fstream file;
  file.open("course.csv");
  if(file.is_open()) {
     while(std::getline(file, line)) {
       if(line.substr(0,2) == "fo") {
         int i = std::stoi(line.substr(8,1));
         horizontal += i;
         depth += aim * i;
       } else if(line.substr(0,2) == "do") {
         int j = std::stoi(line.substr(5,1));
         aim += j;
       } else if(line.substr(0,2) == "up") {
         int k = std::stoi(line.substr(3,1));
         aim -= k;
       }
     }
   }

   int ans = horizontal * depth;

   std::cout << ans << '\n';
}

int main(int argc, char const *argv[]) {
  part1();
  std::cout << '\n';
  part2();
  return 0;
}

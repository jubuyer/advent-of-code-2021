#include <iostream>
#include <fstream>
#include <vector>

void part1() {
  std::vector<int> depths;
  std::string line;
  int ans = 0;
  std::fstream file;
  file.open("sonar-sweep.csv");
  if(file.is_open()) {
     while(std::getline(file, line)) {
       depths.push_back (std::stoi(line));
     }
  }

  // for(int i = 1; i < depths.size(); i++) {
  //   std::cout << depths[i] << '\n';
  // }

  for(int i = 1; i < depths.size(); i++) {
    if((depths[i] - depths[i-1]) >= 1) {
      ans++;
    }
  }

  std::cout << ans << '\n';

  return;
}

void part2 () {
  int transfer = 0;
  int ans = 0;
  std::vector<int> depths;
  std::string line;
  std::fstream file;
  file.open("sonar-sweep.csv");
  if(file.is_open()) {
     while(std::getline(file, line)) {
       depths.push_back (std::stoi(line));
     }
  }

  std::vector<int> windows;
  for(int i = 0; i+2 < depths.size(); i++) {
    transfer = depths[i] + depths[i+1] + depths[i+2];
    windows.push_back (transfer);
  }

  for(int j = 1; j < windows.size(); j++) {
    if((windows[j] - windows[j-1]) >= 1) {
      ans++;
    }
  }

  std::cout << ans << '\n';
}

int main(int argc, char const *argv[]) {
  std::cout << "PART 1::PUZZLE 1\n";
  part1();
  std::cout << "PART 2::PUZZLE 1\n";
  part2();

  return 0;
}

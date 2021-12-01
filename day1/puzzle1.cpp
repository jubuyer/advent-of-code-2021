#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char const *argv[]) {
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

  return 0;
}

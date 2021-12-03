#include <iostream>
#include <fstream>
#include <vector>

void part1() {
  std::string line;
  std::string gamma = "";
  std::string epsilon = "";
  int diag[12][2] = {};

  std::fstream file;
  file.open("binary-diagnostic.csv");
  if(file.is_open()) {
     while(std::getline(file, line)) {
       for(int i = 0; i < line.length(); i++) {
         if(line[i] == '1') {
           diag[i][0] += 1;
         } else if (line[i] == '0') {
           diag[i][1] += 1;
         }
       }
    }
  }

  for(int j = 0; j < 12; j++) {
    if(diag[j][0] > diag[j][1]) {
      gamma += "1";
    } else if (diag[j][1] > diag[j][0]) {
      gamma += "0";
    }
  }

  for(int j = 0; j < 12; j++) {
    if(diag[j][0] < diag[j][1]) {
      epsilon += "1";
    } else if (diag[j][1] < diag[j][0]) {
      epsilon += "0";
    }
  }


  std::cout << "GAMMA: " << gamma << '\n'; //3827 in decimal
  std::cout << "EPSILON: " << epsilon << '\n'; //268 in decimal

  return;
}

int mostCommon(std::vector<std::string> v, int pos) {
  int ones = 0;
  int zeroes = 0;
  int ans;
  for(int i = 0; i < v.size(); i++) {
    std::string temp = v[i];
    if (temp[pos] == '1') {
      ones++;
    } else if (temp[pos] == '0') {
      zeroes++;
    }
  }

  if(ones > zeroes) {
    ans = 1;
  } else if (zeroes > ones) {
    ans = 0;
  } else if (ones == zeroes) {
    ans = -1;
  }

  return ans;
}

int leastCommon(std::vector<std::string> v, int pos) {
  int ones = 0;
  int zeroes = 0;
  int ans;
  for(int i = 0; i < v.size(); i++) {
    std::string temp = v[i];
    if (temp[pos] == '1') {
      ones++;
    } else if (temp[pos] == '0') {
      zeroes++;
    }
  }

  if(ones < zeroes) {
    ans = 1;
  } else if (zeroes < ones) {
    ans = 0;
  } else if (ones == zeroes) {
    ans = -1;
  }

  return ans;
}

void part2() {
  std::string line;
  // std::vector<std::string> diag;
  std::vector<std::string> o2;
  std::vector<std::string> co2;  
  std::fstream file;
  int most = 0;
  int least = 0;
  file.open("binary-diagnostic.csv");
  if(file.is_open()) {
     while(std::getline(file, line)) {
       o2.push_back(line);    
       co2.push_back(line);    
     }
  }

  while(o2.size() > 1) {
    int filter = mostCommon(o2, most);
    for(int i = 0; i < o2.size(); i++) {
      std::string temp = o2[i];
      if((filter == 1) || (filter == -1)) {
        if(temp[most] == '0') {
          o2.erase(o2.begin()+i);
        }
      } else if (filter == 0) {
        if(temp[most] == '1') {
          o2.erase(o2.begin()+i);
        }
      }
    }
    most++;
  }

  while(co2.size() > 1) {
    int filter = leastCommon(co2, least);
    for(int i = 0; i < co2.size(); i++) {
      std::string temp = co2[i];
      if((filter == 0) || (filter == -1)) {
        if(temp[least] == '1') {
          co2.erase(co2.begin()+i);
        }
      } else if (filter == 1) {
        if(temp[least] == '0') {
          co2.erase(co2.begin()+i);
        }
      }
    }
    least++;
  }

  //printing purposes
  for(int k = 0; k < o2.size(); k++) {
    std::cout << o2[k] << '\n';
  }
  for(int k = 0; k < co2.size(); k++) {
    std::cout << co2[k] << '\n';
  }

  // std::cout << "o2 rating: " << o2[0] << '\n';
  // std::cout << "co2 rating: " << co2[0] << '\n';  

}

int main(int argc, char const *argv[]) {
  //part1();
  part2();
  return 0;
}

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

void part2() {
  std::string line;
  std::vector<std::string> diag;
  std::vector<std::string> o2;
  std::vector<std::string> co2;
  std::string gamma = "111011110011";
  std::string epsilon = "000100001100";


  std::fstream file;
  file.open("binary-diagnostic.csv");
  if(file.is_open()) {
     while(std::getline(file, line)) {
       diag.push_back(line);
     }
   }

   for(int i = 0; i < diag.size(); i++) {
     std::string temp = diag[i];
     if(temp[0] == '1') {
       o2.push_back(diag[i]);
     }
     if(temp[0] == '0') {
       co2.push_back(diag[i]);
     }
   }

   // printing purposes
   // for(int k = 0; k < o2.size(); k++) {
   //   std::cout << o2[k] << '\n';
   // }
   // for(int k = 0; k < co2.size(); k++) {
   //   std::cout << co2[k] << '\n';
   // }


   while(o2.size() > 1) {
     for(int j = 1; j < 12; j++) {
       for(int k = 0; k < o2.size(); k++) {
         std::string temp = o2[k];
         if(temp[j] != gamma[j]) {
           //o2.erase(o2.begin()+k);
         }
       }
     }
   }

   while(co2.size() > 1) {
     for(int l = 1; l < 12; l++) {
       for(int m = 0; m < co2.size(); m++) {
         std::string temp = co2[m];
         if(temp[l] != epsilon[l]) {
           //co2.erase(co2.begin()+m);
         }
       }
     }
   }

   // std::cout << "o2 rating: " << o2[0] << '\n';
   // std::cout << "co2 rating: " << co2[0] << '\n';
}

int main(int argc, char const *argv[]) {
  part1();
  part2();
  return 0;
}

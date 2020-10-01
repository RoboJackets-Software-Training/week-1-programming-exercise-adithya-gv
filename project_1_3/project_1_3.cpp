#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========
  for (int i = 0; i < x.size(); i++) {
    int sum = 0;
    for (int j = i; j < i + 3; j++) {
      int k = j - 1;
      int x1;
      int w1;
      if (k < 0 || k > x.size() - 1) {
        x1 = 0;
      } else {
        x1 = x[k];
      }
      if (j > w.size() - 1) {
        w1 = 0;
      } else {
        w1 = w[j];
      }
      sum = sum +(x1 * w1);
    }
    y[i] = sum;
  }

  std::cout << "{" << y[0];
  for (int i = 1; i < y.size(); i++) {
    std::cout << ", " << y[i];
  }
  std::cout << "}\n";

  // =========== END ===========

  return 0;
}


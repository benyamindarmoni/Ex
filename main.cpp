#include "iostream"
#include "range.hpp"
#include "chain.hpp"
using namespace itertools;
using namespace std;
int main(){
  for (char c : range('n', 'p')) //should print n o
            cout << c;

    return 0;
}
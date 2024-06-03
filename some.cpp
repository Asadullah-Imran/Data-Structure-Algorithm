#include <iostream>

namespace first{
  int y=45;
}
namespace second{
  int x=56;
}

int main(){
  int x=0;
  std::cout<<first::y<<std::endl;
  std::cout<<x;
  using namespace std;
  cout<<x;
}

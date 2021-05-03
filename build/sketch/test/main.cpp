#line 1 "c:\\source\\repos\\ed-irrigation\\test\\main.cpp"
// "Copyright 2021 Francisco Aguilera"

#include <iostream>

template <typename Ret>
class A {
 public:
  Ret& operator<<(const char* str) {
    std::cout << str << std::endl;
    return *(dynamic_cast<Ret*>(this));
  }

  virtual ~A() = default;
};

class B : public A<B> {
 public:
  using A::operator<<;

  B& operator<<(int i) {
    std::cout << i << std::endl;
    return *this;
  }

  virtual ~B() = default;
};

int main(int argc, char* argv[]) {
  B myB;
  B* pMyB = &myB;
  myB << 3 << "four" << 5;

  return 0;
}
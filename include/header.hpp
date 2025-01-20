#include <iostream>

// Example class
class Example {
  private:
    static inline int number = 0;
    int memberVar = 1;

  public:
    void Print();
    // Const member function doesn't affect static member variable (class scope).
    void AccessNumber() const;
    // This function cannot make changes to meberVar (compilation error).
    void ConstMemFn() const;
};

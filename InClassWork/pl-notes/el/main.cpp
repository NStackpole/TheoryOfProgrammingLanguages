#include "el.hpp"

#include <iostream>

int main() {
  // Creates (= (arg 1) (arg2))
  // Using C++ initializers lists.
  auto* e1 = new rel_expr {
    op_eq,
    new arg_expr {1},
    new arg_expr {2}
  };

  // Creates (if (< (arg 1) 0) -1 1)
  // Using parens.
  auto* e2 = new if_expr(
    new rel_expr(
      op_lt,
      new arg_expr(1),
      new int_lit(0)
    ),
    new int_lit(-1),
    new int_lit(1)
  );
  
  auto* e3 = new arith_expr(
    op_add,
    new int_lit(3),
    new int_lit(4)
  );
  print(e3);
  std::cout << '\n';

}

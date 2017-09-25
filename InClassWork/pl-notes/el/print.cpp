#include "el.hpp"

#include <iostream>

void
print_int(int_lit* e)
{
  std::cout << e->val;
}

void
print_arg(arg_expr* e)
{
  std::cout << "(arg " << e->arg << ')';
}

void
print(arith_op op) {
  switch (op) {
    case op_add:
      std::cout << '+';
      break;
    case op_sub:
      std::cout << '-';
      break;
    case op_mul:
      std::cout << '*';
      break;
    case op_div:
      std::cout << '/';
      break;
    case op_rem:
      std::cout << '%';
      break;
  }
}

void
print_arith(arith_expr* e)
{
  std::cout << '(';
  print(e->op);
  std::cout << ' ';
  print(e->lhs);
  std::cout << ' ';
  print(e->rhs);
  std::cout << ')';
}

void
print_if(if_expr* e)
{
  std::cout << "(if ";
  print(e->test);
  std::cout << ' ';
  print(e->pass);
  std::cout << ' ';
  print(e->fail);
  std::cout << ')';
}

void 
print(num_expr* e)
{
  switch (e->kind) {
    case ek_int:
      return print_int(static_cast<int_lit*>(e));
    case ek_arg:
      return print_arg(static_cast<arg_expr*>(e));
    case ek_arith:
      return print_arith(static_cast<arith_expr*>(e));
    case ek_if:
      return print_if(static_cast<if_expr*>(e));
  }
}

void 
print(bool_expr* e)
{

}

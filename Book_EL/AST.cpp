//Nathan Stackpole, 2017
#include "AST.hpp"

integer::integer(int val) : value(val)
{}

boolean::boolean(bool val) : value(val)
{}

addition_expr::addition_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}

subtraction_expr::subtraction_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}

multiplication_expr::multiplication_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}

division_expr::division_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}

remainder_expr::remainder_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}
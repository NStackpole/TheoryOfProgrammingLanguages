//Nathan Stackpole, 2017
#include "AST.hpp"

//Constructors
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

and_expr::and_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}

or_expr::or_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}

less_than_expr::less_than_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}

more_than_expr::more_than_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}

equal_to_expr::equal_to_expr(expression *expr1, expression *expr2) : e1(expr1), e2(expr2)
{}

//eval
int expression::eval()
{
    return -1;
}

int integer::eval()
{
    return value;
}
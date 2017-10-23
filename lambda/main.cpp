#include "ast.hpp"
#include <iostream>

int main()
{
    expr *id = new abs_expr(new var("x"), new var_expr("x"));
}
#include "ast.hpp"
#include <iostream>

int main()
{
    var *x = new var("x");
    expr *id = new abs_expr(x, new var_expr("x"));
    std::cout << id << "\n";

    subst s{x, id};
    expr *r = substitute(id, s);
}
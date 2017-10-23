#include "ast.hpp"

expr::expr(expr_kind k) : kind(k)
{
}

var::var(std::string str) : id(str)
{
}

var_expr::var_expr(std::string str) : ref(str), expr(ek_var)
{
}

abs_expr::abs_expr(var *v, expr *e) : parm(v), body(e), expr(ek_abs)
{
}

#include "ast.hpp"

expr::expr(expr_kind k) : kind(k)
{
}

var::var(const std::string &str) : id(str)
{
}

var_expr::var_expr(std::string str) : ref(str), expr(ek_var)
{
}

abs_expr::abs_expr(var *v, expr *e) : parm(v), body(e), expr(ek_abs)
{
}

expr *substitute(expr *e, const subst &s)
{
    switch (e->kind)
    {
    case ek_var:
    case ek_abs:
    case ek_app:
        break;
    }

    return new expr(ek_abs);
}

// expr *subst_var(var_expr *e, const subst &s)
// {
//     if (s.var == e->id)
//         return s.rep;
//     else
//         return e;
// }

// expr *subst_abs(abs_expr *e, const subst &s)
// {
//     if (e->parm == s.var && ...)
//     {
//         //?
//     }
//     else
//     {
//         //expr *body = substitute(e->body, s);
//         return new abs_expr(e->parm, body);
//     }

//     return new expr(ek_abs);
// }

// expr *subst_app(app_expr *e, const subst &s)
// {
//     expr *abs = substitute(e->abs, s);
//     expr *arg = substitute(e->arg, s);
//     return new app_expr(abs, arg);

//     return new expr(ek_app);
// }
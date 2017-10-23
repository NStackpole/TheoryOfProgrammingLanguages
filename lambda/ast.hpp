#include <string>

enum expr_kind
{
    ek_var,
    ek_abs,
    ek_app
};

struct expr
{
    expr(expr_kind);
    expr_kind kind;
};

struct var
{
    var(const std::string &);

    std::string id;
};

struct subst
{
    var *v;
    expr *s;
};

//A reference to a bound variable
struct var_expr : expr
{
    var_expr(std::string);

    std::string ref;
};

struct abs_expr : expr
{
    abs_expr(var *, expr *);

    var *parm;
    expr *body;
};

struct app_expr : expr
{
    app_expr(expr *, expr *);

    expr *abs;
    expr *arg;
};

expr *substitute(expr *, const subst &s);

expr *subst_var(var_expr *e, const subst &s);
expr *subst_abs(abs_expr *e, const subst &s);
expr *subst_app(app_expr *e, const subst &s);
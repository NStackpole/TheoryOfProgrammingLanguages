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
    var(std::string);

    std::string id;
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
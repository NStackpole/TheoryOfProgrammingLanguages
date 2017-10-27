#include "ast.hpp"

#ifndef sub_hpp
#define sub_hpp

expr *substitute(expr *, const subst &s);

expr *subst_var(var_expr *e, const subst &s);
expr *subst_abs(abs_expr *e, const subst &s);
expr *subst_app(app_expr *e, const subst &s);

#endif
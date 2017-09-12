#include "AST.hpp"

int main()
{
    std::cout << "Hello.\n";

    {
        relational_expression *relation_test = new relational_expression(op_less_than, new integer(10), new integer(20));
        std::cout << relation_test->eval() << "\n";
    }
    
    {
        relational_expression *relation_test = new relational_expression(op_less_than, new integer(100), new integer(20));
        std::cout << relation_test->eval() << "\n";
    }

    return 0;
}
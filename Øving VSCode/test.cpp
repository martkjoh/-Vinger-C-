#include <iostream>
using namespace::std;

class expressionPart
{
    public:
        int kind;       // 0 tall, 1 +, 2 - , 3 * og 4 /
        double value;   // hvis 0, verdien till tallet
};

string getExpression()
{
    string expression;
    cout << "Write an expression" << endl;
    cin >> expression;
    return expression;
}

int main()
{
        // string expressionTemp = getExpression();
        // for (int i = 0; i < expressionTemp.size(); i++)
        // {
        //     vector<expressionPart> expression;
        // } 
        // return 0;

}

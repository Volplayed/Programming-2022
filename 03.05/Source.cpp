#include <iostream>
#include <fstream>

#include <string>
#include <stack>


using namespace std;

//розв'язок на основі зворотньої польської нотації
class FormulaRPNmethod {
    
private:
    string infix;
    bool isOperator(const char& c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
    int priority(char& c)
    {
        if (c == '*' || c == '/')
        {
            return 2;
        }
        if (c == '+' || c == '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

public:
    FormulaRPNmethod(string form) : infix(form) {}
    FormulaRPNmethod() : infix() {}

    void setInput(string inp) {
        infix = inp;
    }


    string infixToRPN() {
        
        string output = "";
        stack<char> s;

        for (unsigned int i = 0; i < infix.size(); i++)
        {
            if (isdigit(infix[i]))
            {
                output += infix[i];
            }
            if (infix[i] == '(')
            {
                s.push(infix[i]);
            }
            if (infix[i] == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    output.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }
            if (isOperator(infix[i]) == true)
            {
                while (!s.empty() && priority(s.top()) >= priority(infix[i]))
                {
                    output += s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
        }

        while (!s.empty())
        {
            output += s.top();
            s.pop();
        }
        return output;
    }


    double evaluate() {
        string expr = infixToRPN();
        stack<double> stk;

        for (char c : expr) {
            if (isdigit(c)) {
                stk.push(int(c - '0'));  // convert character digit to integer value and push to stack
            }
            else if (isOperator(c)) {
                double op2 = stk.top(); stk.pop();
                double op1 = stk.top(); stk.pop();

                switch (c) {
                case '+':
                    stk.push(op1 + op2);
                    break;
                case '-':
                    stk.push(op1 - op2);
                    break;
                case '*':
                    stk.push(op1 * op2);
                    break;
                case '/':
                    stk.push(op1 / op2);
                    break;

                }
            }
        }

        return stk.top();
    }

    friend ostream& operator<<(ostream& os, FormulaRPNmethod& formula) {
        os << formula.infix << "->" << formula.evaluate() << endl;
        return os;
    }
    friend istream& operator>>(istream& is, FormulaRPNmethod& formula) {
        is >> formula.infix;
        return is;
    }
};


//розв'язок на основі поділу на підформули
class FormulaSubmethod {
private:
    string input;
    char operation;

    int evaluateSubformula(int start, int end) {

        string subformula = input.substr(start + 1, end - start - 1);
        FormulaSubmethod formula(subformula);
        return formula.evaluate();
    }

    int findMatchingBracket(int start) {
        stack<int> brackets;
        brackets.push(start);
        int i = start + 1;

        while (!brackets.empty() && i < input.size()) {
            if (input[i] == '(') {
                brackets.push(i);
            }
            else if (input[i] == ')') {
                brackets.pop();
            }
            i++;
        }

        return i - 1;
    }

    int oper(int left, int right) {
        switch (operation) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            throw(invalid_argument("No such operation avaliable"));
            return 0;
        }
    }

public:
    FormulaSubmethod(string input) : input(input) {}
    FormulaSubmethod() : input() {}

    void setInput(string inp) {
        input = inp;
    }

    int evaluate() {
        if (input.size() == 1 && isdigit(input[0])) {
            return stoi(input);
        }
        if (input.size() == 3) {
            operation = input[1];
            return oper(int(input[0] - '0'), int(input[2] - '0'));
        }

        int left = 0;
        int right = 0;
        bool flagL = false, flagR = false;
        int i = 0;
        while (i != input.size()) {
            if (input[i] == '(') {
                int j = findMatchingBracket(i);
                if (i == 0) {
                    left = evaluateSubformula(0, j);
                    flagL = true;
                }
                
                else {

                    right = evaluateSubformula(i, input.size() - 1);
                    flagR = true;
                }

                i = j;
            }
            else if (isdigit(input[i])) {
                int dig = int(input[i] - '0');
                if (i == 0) {
                    flagL = true;
                    left = dig;
                }
                else {
                    flagR = true;
                    right = dig;
                }

            }
            else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
                operation = input[i];
            }
            if (flagL && flagR) {
                break;
            }
            i++;
        }
     

        return oper(left, right);
    }


    friend ostream& operator<<(ostream& os, FormulaSubmethod& formula) {
        os << formula.input << "->" << formula.evaluate() << endl;
        return os;
    }
    friend istream& operator>>(istream& is, FormulaSubmethod& formula) {
        is >> formula.input;
        return is;
    }
};



int main() {

    ifstream file("input.txt");
    FormulaRPNmethod f1;
    FormulaSubmethod f2;
    while (!file.eof()) {
        string inp;
        file >> inp;
        f1.setInput(inp);
        f2.setInput(inp);
        cout << "RPN method: " << f1;
        cout << "Subformula method: " << f2;
    }
   
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void pushLastNumberIntoNumber(string &lastNumber, vector<int> &numbers, vector<char> &operators){
        int multiplier = 1;
        if(operators.size() > 0 && operators.back() == '*'){
            multiplier = -1;
            operators.pop_back();
        }
        numbers.push_back(stoi(lastNumber) * multiplier);
        lastNumber = "";
        return;
    }
    void emptyStackIfPossible(vector<int> &numbers, vector<char> &operators, char &singleOperator, bool &minusIsUnary){
        if(minusIsUnary && singleOperator == '-'){
            singleOperator = '*';
            operators.push_back('*');
        }
        else if(singleOperator == '('){
            operators.push_back('(');
            minusIsUnary = true;
        }else if(singleOperator == '+' || singleOperator == '-'){
            while(operators.size() > 0){
                char lastOperator = operators.back();
                if(lastOperator == '+'){
                    int res = numbers[numbers.size() - 2] + numbers[numbers.size() - 1];
                    numbers.pop_back();
                    numbers.back() = res;
                }else if(lastOperator == '-'){
                    int res = numbers[numbers.size() - 2] - numbers[numbers.size() - 1];
                    numbers.pop_back();
                    numbers.back() = res;
                }
                else{
                    break;
                }
                operators.pop_back();
            }
            operators.push_back(singleOperator);
        }else if(singleOperator == ')'){
            while(operators.size() > 0 && operators.back() != '('){
                char lastOperator = operators.back();
                if(lastOperator == '+'){
                    int res = numbers[numbers.size() - 2] + numbers[numbers.size() - 1];
                    numbers.pop_back();
                    numbers.back() = res;
                }else if(lastOperator == '-'){
                    int res = numbers[numbers.size() - 2] - numbers[numbers.size() - 1];
                    numbers.pop_back();
                    numbers.back() = res;
                }
                operators.pop_back();
            }
            operators.pop_back();
            if(operators.size() > 0 && operators.back() == '*'){
                numbers.back() *= -1;
                operators.pop_back();
            }
        }else{
            // ' ': empty everything
            while(operators.size() > 0){
                char lastOperator = operators.back();
                if(lastOperator == '+'){
                    int res = numbers[numbers.size() - 2] + numbers[numbers.size() - 1];
                    numbers.pop_back();
                    numbers.back() = res;
                }else if(lastOperator == '-'){
                    int res = numbers[numbers.size() - 2] - numbers[numbers.size() - 1];
                    numbers.pop_back();
                    numbers.back() = res;
                }else{
                    numbers.back() *= -1;
                }
                operators.pop_back();
            }
        }
    }
    int calculate(string s) { 
        vector<char> operators; //unary minus is set as *
        vector<int> numbers;
        int lenS = s.size();
        string lastNumber = "";
        bool minusIsUnary = true;
        for(int i = 0; i < lenS; i++){
            char item = s[i];
            if(item >= '0' && item <= '9'){
                lastNumber.push_back(item);
                minusIsUnary = false;
            }else{
                //if lastNumber is not empty, push to numbers stack
                if(lastNumber.size() > 0){
                    pushLastNumberIntoNumber(lastNumber, numbers, operators);
                }
                if(item != ' '){
                    emptyStackIfPossible(numbers, operators, item, minusIsUnary);
                }
            }
           
        } 
        if(lastNumber.size() > 0){
            pushLastNumberIntoNumber(lastNumber, numbers, operators);
        }
        if(operators.size() > 0){
            char randomOperator = ' ';
            bool randomMinusIsUnary = false;
            emptyStackIfPossible(numbers, operators, randomOperator, randomMinusIsUnary);
        }
        int res = numbers.back();
        return res;
    }
};
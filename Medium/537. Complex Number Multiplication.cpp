// https://leetcode.com/problems/complex-number-multiplication/

class Solution
{
public:
    string complexNumberMultiply(string a, string b)
    {
        pair<int, int> num1 = {getReal(a), getImaginary(a)};
        pair<int, int> num2 = {getReal(b), getImaginary(b)};

        int real = (num1.first * num2.first) + (-1) * (num1.second * num2.second);
        int imaginary = (num1.first * num2.second) + (num1.second * num2.first);

        return to_string(real) + "+" + to_string(imaginary) + "i";
    }

    int getReal(string a)
    {
        int position = a.find('+');
        int real = stoi(a.substr(0, position));
        return real;
    }

    int getImaginary(string a)
    {
        int position = a.find('+');
        string temp = a.substr(position + 1);
        temp.pop_back();
        int imaginary = stoi(temp);
        return imaginary;
    }
};

class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        bool isBulky = (length >= 1e4) || (width >= 1e4) || (height >= 1e4);
        long long volume = (long long)length * (long long)width * (long long)height;
        isBulky = isBulky || (volume >= 1e9);

        bool isHeavy = (mass >= 100);

        if (isBulky && isHeavy)
            return "Both";

        if (isBulky && !isHeavy)
            return "Bulky";

        if (!isBulky && isHeavy)
            return "Heavy";

        return "Neither";
    }
};
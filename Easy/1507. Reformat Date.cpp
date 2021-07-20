// https://leetcode.com/problems/reformat-date/

class Solution
{
public:
    string reformatDate(string date)
    {
        string result = getYear(date) + "-" + getMonth(date) + "-" + getDay(date);
        return result;
    }

    string getDay(string &date)
    {
        string result = "";
        int i = 0;

        while (isdigit(date[i]))
        {
            result += date[i];
            i++;
        }

        return mappingDay(result);
    }

    string mappingDay(string &day)
    {
        string result = (day.length() == 1) ? "0" + day : day;
        return result;
    }

    string getMonth(string &date)
    {
        string result = date.substr(date.length() - 8, 3);
        return mappingMonth(result);
    }

    string mappingMonth(string &month)
    {
        unordered_map<string, string> months = {
            {"Jan", "01"},
            {"Feb", "02"},
            {"Mar", "03"},
            {"Apr", "04"},
            {"May", "05"},
            {"Jun", "06"},
            {"Jul", "07"},
            {"Aug", "08"},
            {"Sep", "09"},
            {"Oct", "10"},
            {"Nov", "11"},
            {"Dec", "12"}};

        return months[month];
    }

    string getYear(string &date)
    {
        string result = date.substr(date.length() - 4, 4);
        return result;
    }
};
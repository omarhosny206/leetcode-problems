// https://leetcode.com/problems/unique-email-addresses/

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> uniqueEmails;
        for (string email : emails)
        {
            string address = "";
            int i = 0;
            for (i = 0; i < email.length(); ++i)
            {
                if (email[i] == '+' || email[i] == '@')
                    break;

                if (email[i] == '.')
                    continue;

                address += email[i];
            }

            int j = i;
            for (j = i; j < email.length(); ++j)
                if (email[j] == '@')
                    break;

            address += email.substr(j);
            uniqueEmails.insert(address);
        }
        return uniqueEmails.size();
    }
};
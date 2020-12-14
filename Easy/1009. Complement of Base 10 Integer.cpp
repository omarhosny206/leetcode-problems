// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution
{
public:
	int bitwiseComplement(int N)
	{
		string binary;
		int i, j, result = 0, complement;

		if (N == 0)
			return 1;
		while (N > 0)
		{
			binary += to_string(N % 2);
			N = N / 2;
		}

		reverse(binary.begin(), binary.end());

		for (i = binary.size() - 1, j = 0; i >= 0; i--, j++)
		{
			complement = binary[i] - '0' == 0 ? 1 : 0;
			result += (complement * pow(2, j));
		}
		return result;
	}
};
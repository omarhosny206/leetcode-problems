
class Solution
{
    unordered_map<int, string> url;
    int key = 0;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        url[key++] = longUrl;
        return to_string(key - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return url[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
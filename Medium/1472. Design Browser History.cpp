// https://leetcode.com/problems/design-browser-history/

class BrowserHistory
{
    vector<string> pagesHistory;
    int currentPageIndex;

public:
    BrowserHistory(string homepage)
    {
        pagesHistory.push_back(homepage);
        currentPageIndex = 0;
    }

    void visit(string url)
    {
        currentPageIndex++;
        pagesHistory.erase(pagesHistory.begin() + currentPageIndex, pagesHistory.end());
        pagesHistory.push_back(url);
    }

    string back(int steps)
    {
        currentPageIndex = max(currentPageIndex - steps, 0);
        return pagesHistory[currentPageIndex];
    }

    string forward(int steps)
    {
        currentPageIndex = min(currentPageIndex + steps, (int)pagesHistory.size() - 1);
        return pagesHistory[currentPageIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
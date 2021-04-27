// https://leetcode.com/problems/apply-discount-every-n-orders/

class Cashier
{
    unordered_map<int, int> price;
    int discount;
    int numCustomers;
    int counter = 0;

public:
    Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
    {
        this->numCustomers = n;
        this->discount = discount;

        for (int i = 0; i < products.size(); ++i)
            price[products[i]] = prices[i];
    }

    double getBill(vector<int> product, vector<int> amount)
    {
        double bill = 0.0;
        counter++;

        for (int i = 0; i < product.size(); ++i)
            bill += (amount[i] * price[product[i]]);

        if (counter % numCustomers == 0)
            bill -= (bill * discount) / 100;

        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
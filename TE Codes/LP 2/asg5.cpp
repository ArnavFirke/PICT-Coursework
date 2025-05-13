#include <bits/stdc++.h>
using namespace std;
class product
{

    string name;
    int price;
    int quantity;
    vector<string> constituents;

public:
    product(string n, int p, int q, vector<string> con)
    {
        name = n;
        price = p;
        quantity = q;
        constituents = con;
    }
    friend class manager;
};
class manager
{
    vector<product> prod;

public:
    manager()
    {
        prod = {
            product("pizza", 10, 15, {"topping", "cheese", "base"}),
            product("burger", 16, 20, {"bread", "cheese", "tikki"}),
            product("mac", 29, 15, {"topping", "cheese", "base"}),
            product("sev masala", 150, 15, {"masala", "cheese", "sev"})};
    }

    void displayall()
    {
        for (auto p : prod)
        {
            cout << p.name << endl;
        }
    }
    void display(string pname)
    {
        for (auto p : prod)
        {
            if (pname == p.name)
            {
                cout << p.name << endl;
                cout << p.price << endl;
                cout << p.quantity << endl;
                for (string s : p.constituents)
                {
                    cout << s << endl;
                }
            }
        }
    }
    void pricebw(int min, int max)
    {
        for (auto p : prod)
        {
            if (p.price >= min and p.price <= max)
            {
                cout << p.name << endl;
                cout << p.price << endl;
                cout << p.quantity << endl;
                for (string s : p.constituents)
                {
                    cout << s << endl;
                }
            }
        }
    }
};
int main()
{
    manager m;
    string pname, input;
    int min, max;
    while (true)
    {
        cout << "\nCostumer: ";
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input.find("all products") != string::npos)
        {
            m.displayall();
        }
        else if (input.find("price bw") != string::npos)
        {
            sscanf(input.c_str(), "price bw %d and %d", &min, &max);

            m.pricebw(min, max);
        }
        else if (input.find("details of product") != string::npos)
        {
            int pos = input.find("product") + 8;
            pname = input.substr(pos);
            m.display(pname);
        }
        else if (input.find("exit") != string::npos)
        {
            cout << "Thank you" << endl;
            break;
        }
    }
    return 0;
}
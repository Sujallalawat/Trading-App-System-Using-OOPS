#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int money =5000;
class stock
{
public:
    string name;
    int current_price;
    int previous_price;
    int gain;
    int gain_percent;
    string type;

    void display()
    {
        cout << "Stock: " << name << endl;
        cout << "Price: " << current_price << endl;
        if(gain<0)
        cout << "Loss: -" << gain << endl;
        else
        cout << "Gain: +" << gain << endl;
        if(gain<0)
        cout << "Percentage: -" << gain_percent << "%" << endl;
        else
        cout << "Percentage: +" << gain_percent << "%" << endl;
        cout << "Type: " << type << endl;
    }
};

vector<stock*> stock_list;
vector<stock*> stock_portfolio;

class mrf : public stock
{
public:
    
    mrf()
    {
        name = "mrf";
        current_price = 200;
        previous_price = 190;
        type = "manufacturing";
        gain = current_price - previous_price;
        gain_percent = (gain * 100) / previous_price;
        
    }
    void add_mrf(mrf* mrf)
    {
        stock_list.push_back(mrf);
    }
    void buy(mrf* mrf,int n)
    {
        if(money-current_price*n<0)
        cout<<"Insufficient balance add more!"<<endl;
        else
        {
            for(int i=0;i<n;i++)
            {
            stock_portfolio.push_back(mrf);
            }
            money-=n*current_price;
        }
        
    }
    void sell(mrf* mrf,int n)
    {
        vector<int> v;
        int flag=0;
        int c=0;
        for(int i=0;i<stock_portfolio.size();i++)
        {
            if(mrf->name==stock_portfolio[i]->name)
            {
                flag=1;
                c++;
            }
            
        }
        if(flag==0)
        cout<<"You dont have stocks to sell them!"<<endl;
        else
        {
            if(n<=c)
            {
            int count=0;
            for (int i = 0; i < stock_portfolio.size(); i++)
            {
                if (stock_portfolio[i]->name==mrf->name)
                {
                    if (count < n)
                    {
                        v.push_back(i);
                    // 
                    // stock_portfolio.pop_back();
                    count++;
                    }
                
                }
            }
            int j=0;
            for(int i=0;i<stock_portfolio.size();i++)
            {
                if(i==v[j] && j<n)
                {
                    swap(stock_portfolio[i],stock_portfolio.back());
                    j++;
                }
            }
            for(int i=0;i<n;i++)
            {
                stock_portfolio.pop_back();
            }
            money += (count * current_price);
            }
            else
            cout<<"You don't have "<<n <<" stocks of "<<mrf->name<<" to sell them"<<endl; 
        }
    }
};



class stock_order
{
    public:
    
};

class mutual_fund
{
};

int main()
{
    mrf* m1 = new mrf();
    m1->display();
    m1->add_mrf(m1);
    m1->buy(m1,5);
    // for(int i=0;i<stock_portfolio.size();i++)
    // cout<<stock_portfolio[i]->name<<endl;
    m1->sell(m1,6);
    for(int i=0;i<stock_portfolio.size();i++)
    cout<<stock_portfolio[i]->name<<endl;
    // Add m1 object to the stock_list vector
    // stock_list.push_back(m1);

    return 0;
}

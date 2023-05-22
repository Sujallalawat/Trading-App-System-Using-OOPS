#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;
int money =5000;
int investment=0;
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
set<stock*> s;
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
            investment+=n*current_price;
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
                    count++;
                    }
                
                }
            }
            int j=0;
            for(int i=0;i<stock_portfolio.size();i++)
            {
                if(i==v[j] && j<n)
                {
                    swap(stock_portfolio[i],stock_portfolio[stock_portfolio.size()-(j+1)]);
                    j++;
                }
            }
            for(int i=0;i<n;i++)
            {
                stock_portfolio.pop_back();
            }
            investment-=count*current_price;
            money += (count * current_price);
            }
            else
            cout<<"You don't have "<<n <<" stocks of "<<mrf->name<<" to sell them"<<endl; 
        }
    }
};



class s_portfolio
{
    public:
    void dashboard()
    {
        int current=0;
        int total_returns=0;
        
        int total_gain_per=0;
        for(int i=0;i<stock_portfolio.size();i++)
        {
            current+=stock_portfolio[i]->current_price;
            total_returns+=stock_portfolio[i]->gain;
            total_gain_per+=stock_portfolio[i]->gain_percent;

        }
        cout<<"Current :"<<current<<endl;
        cout<<"Invested :"<<investment<<endl;
        if(total_returns>=0)
        {
        cout<<"Total Returns :+"<<total_returns<<endl;
        cout<<"Total Return(%) :+"<<total_gain_per/stock_portfolio.size()<<endl;
        }
        else
        {
        cout<<"Total Returns :-"<<total_returns<<endl;
        cout<<"Total Return(%) :-"<<total_gain_per/stock_portfolio.size()<<endl;
        }

    }
    void holding()
    {
        set<stock*>::iterator it;
        
        for(int i=0;i<stock_portfolio.size();i++)
        {
            s.insert(stock_portfolio[i]);
        }
        vector<stock*> p(s.begin(),s.end());

        for(int i=0;i!=p.size();i++)
        {
            int count=0;
            for(int j=0;j<stock_portfolio.size();j++)
            {
                if(p[i]==stock_portfolio[j])
                count++;
            }
            cout<<"Stock :"<<p[i]->name<<endl;
            cout<<count<<" shares"<<endl;
            
        }
    }
    
    
};

class mutual_fund
{
    public:
    int returns;
    string name;
    string risk;
};

int main()
{
    mrf* m1 = new mrf();
    m1->display();
    m1->add_mrf(m1);
    m1->buy(m1,5);
    // for(int i=0;i<stock_portfolio.size();i++)
    // cout<<stock_portfolio[i]->name<<endl;
    cout<<money<<endl;
    m1->current_price=300;
    cout<<m1->gain<<endl;
    s_portfolio p1;
    p1.dashboard();
    p1.holding();
    // m1->sell(m1,5);
    // for(int i=0;i<stock_portfolio.size();i++)
    // cout<<stock_portfolio[i]->name<<endl;

    

    return 0;
}

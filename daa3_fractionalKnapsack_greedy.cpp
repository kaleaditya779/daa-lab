#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<double, double> a, pair<double, double> b) {
    return (a.first/a.second < b.first/b.second);
}

int fractional_knapsack(vector<pair<double, double>> w_p, double sackSize) {
    sort(w_p.begin(), w_p.end(), cmp);
    
    double totalValue = 0;
    for (int i=0; i<w_p.size(); i++) {

        if (w_p[i].first < sackSize) {
            sackSize = sackSize - w_p[i].first;
            totalValue += w_p[i].second;
        }
        else {
            // taking fractional part of that item till bag fills..
            totalValue += w_p[i].second*((double)sackSize/(double)w_p[i].first);
        }
    }

    return totalValue;

}



int main() {
    vector<pair<double, double>> weights_profits = {{20,100}, {10,60}, {30,120}};
    double knapsackSize = 50;
    cout<<endl<<"The max profit possible: "<<fractional_knapsack(weights_profits, knapsackSize)<<endl;

    return 0;
}

// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,Item> a, pair<double,Item> b){
        return a.first>b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        vector<pair<double, Item>> k;
        
        for(int i=0; i<n; i++){
            double perUnitValue= (1.0*arr[i].value)/arr[i].weight;
            k.push_back(make_pair(perUnitValue, arr[i]));
        }
        
        sort(k.begin(), k.end(), cmp);
        double maxValue= 0.0;
        
        for(int i=0; i<n; i++){
            if(k[i].second.weight>W){
                maxValue+= W*k[i].first;
                W= 0;
            }
            else{
                maxValue+= k[i].second.value;
                W-= k[i].second.weight;
            }
        }
        
        return maxValue;
    }
        
};



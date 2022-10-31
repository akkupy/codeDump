{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>>v;
        for(int i =0; i<n; i++)
        {
            v.push_back({end[i], start[i]});
        }
        sort(v.begin(), v.end());
        
        int ed= 0;
        int c=0;
        for(auto i:v)
        {
            if(ed<i.second)
            {
                ed = i.first;
                c++;
            }
        }
        return c;
    }
    
};

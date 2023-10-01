
// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> distance(n+1, 1e9);

        distance[1]= 0;
    
        for(int i=1; i<=n; i++){
            for(int j=0; j<edges.size(); j++){
                int first= edges[j][0];
                int second= edges[j][1];
                int weight= edges[j][2];
                if(distance[first]!=1e9 && ((distance[first] + weight)<distance[second]))
                    distance[second]= distance[first] + weight;
            }
        }
        
        for(int j=0; j<edges.size(); j++){
            int first= edges[j][0];
            int second= edges[j][1];
            int weight= edges[j][2];
            if(distance[j]!=1e9 && (distance[first] + weight)<distance[second])
                return true;
        }
    
        return false;
	}
};
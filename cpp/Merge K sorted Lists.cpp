class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        for(int i=0;i<lists.size();i++){
            while(lists[i]){
                v.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        sort(rbegin(v),rend(v));
        ListNode* ans=nullptr;
        for(int i=0;i<v.size();i++){
            ans=new ListNode(v[i],ans);
        }
        return ans;
    }
};

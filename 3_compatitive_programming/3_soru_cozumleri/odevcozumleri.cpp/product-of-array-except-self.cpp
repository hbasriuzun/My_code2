class Solution {
public:
    
    vector<int> _productExceptSelf(vector<int>& nums,int i){
        long p=1;
        vector<int> k(nums.size(),0),ans;
        for(int j=0; j<nums.size(); j++){
            if(j==i)
                continue;
            p*=nums[j];
        }

        if(p==0)
            return k;

        for(int j=0; j<nums.size(); j++){
            if(i==j){
                ans.push_back(p);
                continue;
            }
            ans.push_back(0);
        }
        return ans;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        long p=1;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)
                return _productExceptSelf(nums,i);

            p*=nums[i];
        }

        for(int i=0; i<nums.size(); i++){
            ans.push_back(p/nums[i]);
        }

        return ans;
    }
        
    // 3 tane ihtimal var
    // hiç sıfır olmayabilir, 1 kere olabilir, 1 den fazla olabilir
};
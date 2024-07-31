    int singleNumber(vector<int>& nums) {
        vector<int> counter(32,0);
        long long ans = 0;
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<32;++j){
                if (nums[i] & (1 << j))
                    counter[j]+=1;
            }
        }
        for(int i=0;i<32;++i){
            ans+=counter[i]%3 * pow(2,i);
        }

        return ans;
    }
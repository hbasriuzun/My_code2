class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int s=bills.size(),f=0,t=0;
        for(auto x:bills){
            if(x==5){
                f++;
            }else if(x==10){
                f--;
                if(f<0)
                    return false;
                t++;
            }else{
                f--;
                t--;
                if(t<0){
                    t++;
                    f-=2;
                }
                if(f<0)
                    return false;
            }
        }
        return true;
    }
};
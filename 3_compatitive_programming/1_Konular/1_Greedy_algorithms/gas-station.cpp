class Solution {
public:

        bool static karsilastir(const std::array<double, 2>& a, const std::array<double, 2>& b) {
        return a[0] > b[0]; // İlk elemanlarını karşılaştırıyoruz, büyükten küçüğe sıralama
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s=gas.size(),my=0;
        long sum=0;
        int gassum = std::accumulate(gas.begin(), gas.end(), 0);
        int costsum = std::accumulate(cost.begin(), cost.end(), 0);
        if(costsum>gassum)
            return -1;

        vector<array<double,2>> minus(gas.size()*2);
        for(int i=0; i<gas.size(); i++){
            minus[i][0] = gas[i]-cost[i];
            minus[i][1]=i;
            minus[i+s][0] = gas[i]-cost[i];
            minus[i+s][1]=i;
        }
        
        for(int i=0;i<s*2;i++){
            sum+=minus[i][0];
            if(sum<0){
                sum=0;
                my=minus[i+1][1];
            }
        }
        return my;
        
    }
};
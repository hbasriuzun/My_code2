#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    long long n;
    cin >> n;
    long long sum = 0;
    long long i = 1;
    while(sum<=n){
        sum = (i*(i+1))/2;
        i++;
    }
    cout<<sum-n<<endl;
	return 0;
}
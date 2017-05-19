#include <iostream>
using namespace std;
int gcd(int x, int y){
	while(y != 0){
		int c = x % y;
		x = y;
		y = c;
	}
	return (x > 0) ? x : (-1 * x);
}
int lcm_nod(int x, int y){
	if(x%y != 0) return lcm_nod(y, x%y); 
    else return y;  
}
int array_lcm(int *b, int n){

	for (int i = 1; i < n; ++i){
		b[i] = b[i-1] * b[i] / lcm_nod(b[i-1], b[i]);
		/* code */
	}
	return b[n-1];
}
int main(int argc, char const *argv[]){
	int T;
	cin >> T;
	// while(cin >> T) {
	    int *a = new int [T];
	    int *b = new int [T];
	    int *d = new int [T];
	    char c;
	    for(int i = 0; i < T; ++i) {
	    	cin >> a[i] >> c >> b[i];
	    	d[i] = b[i];
	    }
	    int lcm = array_lcm(b, T);	
	    int numerator_sum = 0;
	    for(int i = 0; i < T; ++i){
	    	numerator_sum += a[i] * (lcm / d[i]);
	    }

	    int result1 = numerator_sum / lcm;
	    int result2 = numerator_sum % lcm;
	    if(result1){
	    	if(result2)
	    		cout << result1 << " " << result2 / gcd(result2, lcm) << "/" << lcm / gcd(result2, lcm) << endl;
	    	else 
	    		cout << result1 << endl;
	    }
	    else {
	    	if(result2)
	    		cout << result2 / gcd(result2, lcm) << "/" << lcm / gcd(result2, lcm) << endl;
	    	else 
	    		cout << result1 << endl;
	    }
	    
	    
	    delete [] a;
	    delete [] b;
	    delete [] d;	    
	    /* code */
	// }
	return 0;
}

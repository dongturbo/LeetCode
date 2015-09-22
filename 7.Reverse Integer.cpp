int reverse(int x) {
    	long int_max = 2147483647;
    	double result = 0;
    	while (x % 10 != 0 || x/10!=0){
    		result = 10 *result + (x % 10);
    		x = x / 10;
    	}
    	if (result > int_max || result <-(int_max+1)){
    		return 0;
    	}
    
    	
    	return (int)result;
    }
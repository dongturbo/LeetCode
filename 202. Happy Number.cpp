 //判断是happy number好判断，若不是的话，由于会造成循环，因此用set记录出现的数，若重复出现则不是
 bool isHappy(int n) {
  	int t=n;
  	unordered_set<int> set;
  	set.insert(n);
  	while (true){
  		n = 0;
  		while (t!=0){
  			n +=pow(t%10,2);
  			t /= 10;
  		}
  		if (n == 1)
  			return true;
  		if (set.find(n) != set.end())
  			break;
  		set.insert(n);
  		t = n;
  	}
  	return false;
  }

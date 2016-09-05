uint32_t reverseBits(uint32_t n) {
    string s = "";
    //将n的二进制数按逆序转换成string
  	for (int i = 0; i < 32; i++){
  		s += to_string(n&1) ;
  		n >>= 1;
  	}
  	n = 0;
  	//把string转换成unit32_t
  	for (int i = 0; i<32; i++){
  		n = n * 2 + (s[i] - '0');
  	}
  	return n;
}

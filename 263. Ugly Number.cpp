//只要判断能否被2,3,5整除就行，若能整除即为ugly number，若不能则不是
bool isUgly(int num) {
    for (int i=2; i<6 && num; i++)
        while (num % i == 0)
            num /= i;
    return num == 1;
}

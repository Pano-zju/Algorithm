 #include<cstdio>
 using namespace std;
 
bool isPrime[10005];
int primeNumber[2005];
int size;
void getPrimeNumber() {
    for(int i = 1 ; i <= 10000 ; i++) {
        isPrime[i] = true;
    }
    size = 0;
    for(int i = 2 ; i <= 10000 ; i++) {
        if(isPrime[i]) {
            primeNumber[size++] = i;
            for(int j = i * i ; j <= 10000 ; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
	getPrimeNumber();
	return 0;
}
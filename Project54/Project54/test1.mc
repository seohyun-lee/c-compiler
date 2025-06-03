
void main()
{
int i,j,k;
float rem, prime;   // rem:remainder
int arr[10];

i=2;
while(i<=max) {
	prime = 1;
	k=i/2;
	j=2;
	while(j<=k){
		rem=i%j;
		if(rem==0) prime=0;  
		++j;
	}
	if(prime==1) write(i);  
	++i;
}
}

int write(char text, int leng)
{
	return 0;
}
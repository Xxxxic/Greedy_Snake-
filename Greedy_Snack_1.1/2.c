#include<stdio.h>

int isPrime(int i);      	//函数原型的声明 

int main()
{
	int m,n;
	int sum=0;
	int cnt=0;
	int i;
	
	scanf("%d %d",&m,&n);
	if(m==1){m=2;
	}	
	for(i=m;i<=n;i++){
		if(isPrime(i)){
			sum+=i;
			cnt++;
		}
	}
 	
	return 0;
}

int isPrime(int i)			
{
	int ret=1;
	int k;
	if(x==1||(x%2==0&&x!=2))
		ret=0;
	for(k=3;k<sqrt(x);k+=2){			//平方根  还有+2是因为排除了偶数 
		if(i%k==0){
			ret=0;	//0是就不是素数 
			break;
		}
	}
	return ret;
}

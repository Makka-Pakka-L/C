#include <stdio.h>
int main(){
	int a[9]={1,12,23,45,56,78,89,90,100};
	int i,j,x,on,left=0,right;
	right = sizeof(a)/sizeof(a[0])-1;
	printf("������һ����Ҫ��ѯ����");
	scanf("%d",&x);
	while(left<=right){
		on=(left+right)/2;
		if(x<a[on]){
			
			right=on-1;
			
		}
		else{
			
			if(x>a[on])
				{
			
				left=on+1;
			
			}
			else
				{
				j=on+1;
				break;
			}
		}
	}
	
	printf("%d",j);
}

















	/*
int low=0,right,i,mid,a;
	printf("������һ����\n");
	scanf("%d",&a);
	i=10-1;
	while(low<=right){
		mid=(low+right)/2;
		if(a<data[a].key)right=mid-1;
		else{
			
		}
	}*/
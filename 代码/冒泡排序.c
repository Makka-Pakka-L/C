#include<stdio.h>
	int main(){
	int i,j,x,n,m,avg=0;
	long int a[avg];
	printf("������һ��������");
	scanf("%d",&avg);
	for(i=0;i<avg;i++){
		printf("�������%dλ��\n",i+1); 
		scanf("%d",&x);
		a[i] = x;
		printf("\n");
	}
	for(n=0;n<avg;n++){
		for(i=0;i<avg;i++){
			if(a[i]>a[i+1]){
				j = a[i];
				for(m=0;m<avg;m++){
					//printf("%d",a[m]);	
				}
				a[i] = a[i+1];
				for(m=0;m<avg;m++){
					//printf("%d\n",a[m]);	
				}
				a[i+1] = j;
				for(m=0;m<avg;m++){
					//printf("%d\n",a[m]);	
				}
		}
	}
	}
	for(i=0;i<avg;i++){
		printf("%d,",a[i]);
}
}
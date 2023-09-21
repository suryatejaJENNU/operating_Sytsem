#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int findmin(int at[],int n,int p[],int ct[],int bt[]) {
	int min = INT_MAX;
	int k = 1;
	for(int i = 1; i <= n;i++) {
		if(at[i] < min) {
			min = at[i];
			k = i;
		}
	}
	p[1] = k;
	ct[1] = min + bt[k];
	bt[k] = INT_MAX;
	return ct[1];
}

int findsmall(int p[],int at[],int bt[],int n,int j) {
	int min = INT_MAX;
	int k = 1;
	for(int i = 1; i <= n;i++) {
		if(bt[i] < min) {
			min = bt[i];
			k = i;
		}
		else if(bt[i] == min) {
			if(at[i] < at[k]) {
				min = bt[i];
				k = i;
			}
		}
	}
	p[j] = k;
	bt[k] = INT_MAX;
	return min;
	
		
}

int result(int p[],int at[],int bt[],int ct[],int n) {
	int min = findmin(at,n,p,ct,bt);
	int time = min;
	
	for(int i = 2; i <= n;i++) {
		int small = findsmall(p,at,bt,n,i);
		time = time + small;
		ct[i] = time;
	}
	for(int i =1; i <= n;i++) {
		printf("p%d %d\n",p[i],ct[i]);
	}
	
}

int main() {
	printf("Enter the value of the n");
	int n;
	scanf("%d",&n);
	int p[n],at[n],bt[n],ct[n];
	printf("Enter the Arraival times");
	
	for(int i = 1; i <= n;i++) {
		scanf("%d",&at[i]);
		p[i] = i;
	}
	printf("Enter the brust time");
	for(int i = 1; i <= n;i++) {
		scanf("%d",&bt[i]);
	}
	result(p,at,bt,ct,n);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int sortAt(int p[],int at[],int bt[],int n) {
	for(int i = 1; i <= n;i++) {
		for(int j = 1; j <= n-1;j++) {
			if(at[j] > at[j+1]) {
				int temp = at[j];
				int temp1 = bt[j];
				at[j] = at[j+1];
				at[j+1] = temp;
				bt[j] = bt[j+1];
				bt[j+1] = temp1;
				int temp3 = p[j];
				p[j] = p[j+1];
				p[j+1] = temp3;
			}
		}
	}
}

int findsol(int at[],int bt[],int p[],int ct[],int tat[],int wt[],int n) {
	int time = at[1];
	float awt = 0,atat = 0;
	for(int i = 1; i <= n;i++) {
		time = time + bt[i];
		ct[i] = time;
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		awt = awt + wt[i];
		atat = atat + tat[i];
		
	}
	awt = awt / n;
	atat = atat / n;
	printf("p	AT	BT	CT	TAT	WT\n");
	for(int i = 1; i<= n;i++) {
		printf("p%d	%d	%d	%d	%d	%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("AWT = %f ATAT = %f",awt,atat);
	
}


int main() {
	printf("enter the value of the n");
	int n;
	scanf("%d",&n);
	int p[n],at[n],bt[n],ct[n],tat[n],wt[n];
	printf("Enter the arraival times");
	for(int i = 1; i <= n;i++) {
		p[i] = i;
		scanf("%d",&at[i]);
	}
	printf("Enter the brust times");
	for(int i = 1; i <= n;i++) {
		scanf("%d",&bt[i]);
	}
	sortAt(p,at,bt,n);
	for(int i = 1; i <= n;i++) {
		printf("%d %d\n",at[i],bt[i]);
	}
	findsol(at,bt,p,ct,tat,wt,n);
}

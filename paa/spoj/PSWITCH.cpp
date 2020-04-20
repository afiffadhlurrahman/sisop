#include<stdio.h>

int main(){
	int array[8][6]= {  {0,0,0,0,0,0},
						{0,0,1,1,1,0},
						{0,1,0,1,0,1},
						{0,1,1,0,1,1},
						{1,0,0,1,0,0},
						{1,0,1,0,1,0},
						{1,1,0,0,0,1},
						{1,1,1,1,1,1} };
	
	bool flag[8], cek = false;
	int N, C, on[100], off[100], a, b;
	
	for (int i=0; i<8; i++)
		flag[i] = true;
		
	scanf ("%d", &N);
	scanf ("%d", &C);
	
	if (C==1){
		flag[1] = false;
		flag[4] = false;
		flag[6] = false;
		flag[7] = false;
	}

	
	a = 0;
	for(int c=1;c==1;){
		scanf ("%d", &on[a]);
		if(on[a]==-1) c=-1;
		else {
			on[a]=on[a]-1;
			on[a]=on[a]%6;
			a++;	
		}
	}
	b = 0;
	for(int d=1;d==1;){
		scanf ("%d", &off[b]);
		if(off[b]==-1)	d=-1;
		else{
			off[b] = off[b] - 1;
			off[b] = off[b] % 6;
			b++;	
		}
	}

	
	for (int i=0; i<8; i++)
		if (flag[i])
			for (int j=0; j<a; j++)
				if (array[i][on[j]]==0)
					flag[i] = false;
	
	for (int i=0; i<8; i++)
		if (flag[i])
			for (int j=0; j<b; j++)
				if (array[i][off[j]]==1)
					flag[i] = false;
					
	for (int i=0; i<8; i++)
		if (flag[i])
		{
			cek = true;
			for (int j=0; j<N; j++)
				printf ("%d", array[i][j%6]);
			printf ("\n");	
		}
	
	if (!cek) 
		printf ("Impossible\n");
	return 0;
}

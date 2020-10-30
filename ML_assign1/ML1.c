#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int Knn_classifier_algo(float trainset[210][8],float testset[1][8],int kvalue,int p,int trc,int testc)
{
					// trc =trained count row ;tesc =tested set and trained set column count
	float store[trc][2];
	for(int l=0;l<trc;l++)
	{
		float sum=0;
		for(int k=0;k<testc-1;k++)
		{
			float md = pow((trainset[l][k] - testset[0][k]),p);		//distance formula .....
			if(md<1)
			{
				md = md*(-1);
				
			}
			else
			{
				md = md*(1);
			}
			sum = sum + md;			//sum of the distances.....
			//printf(" %f  ",sum);
		}
		
		float res = pow(sum,1./p);
		//printf(" result :%f  ",res);
		//printf("\n\n");
		store[l][0] = res;
		store[l][1] = trainset[l][testc-1];		//distances and classs are storing into array....
	}	
	//printf("%f,%f,%f,%f,%f,%f,%f,%f",testset[0][0],testset[0][1],testset[0][2],testset[0][3],testset[0][4],testset[0][5],testset[0][6],testset[0][7]);
							//printf("\n before sorted................  ");
	for(int e=0;e<trc;e++)
	{

		//printf("\n %f -- class: %f ",store[e][0],store[e][1]);
	}
	
	float swap,swap1;
	for(int a=0;a<(trc-1);a++)			//sorting algorithm....
	{
		for(int b=0;b<(trc-1)-a;b++)
		{
			if(store[b][0] > store[b+1][0])
			{
				swap = store[b][0];
				store[b][0] = store[b+1][0];
				store[b+1][0] = swap;
				
				swap1 = store[b][1];
				store[b][1] = store[b+1][1];
				store[b+1][1] = swap1;
				
			}
		}
	}
						//printf("\n after sorted................  ");
	for(int d=0;d<kvalue;d++)
	{
		//printf("\n %f --- class : %f ",store[d][0],store[d][1]);
	}
	int f1=0,f2=0,f3=0;
	for(int d=0;d<kvalue;d++)				//frequency rate finding......
	{
		//printf("\n %f --- class : %f ",store[d][0],store[d][1]);
		if(store[d][1] == 1.000000 )
		{
			f1 +=1;
		}
		else if (store[d][1] == 2.000000 )
		{
			f2+=1;
		}
		else if(store[d][1] == 3.000000 )
		{
			f3+=1;
		}
	}
	int val1=1,val2=2,val3=3;
	if (f1>=f2 && f1>=f3)				//maximum frequency rate finding rate.....
	{
		return val1;
	}
	if(f2>=f1 && f2>=f3)
	{
		return val2;
	}
	if(f3>=f1 && f3>=f2)
	{
		return val3;
	}
	
	
}

int main()
{
	
	float arr[210][8];
	char ch;
	int count = 0;
	FILE *fpt;
	if ((fpt = fopen("ML.txt","r")) == NULL)
	{
		printf("Error! opening File");
	}
	
	while((ch = fgetc(fpt))!=EOF)
	{
		if(ch=='\n')
		{
			count++;
		}
	}
									//printf("row count is : %d ",count);
	fclose(fpt);
	//****************************************************************************
	char ch1;
	int count1 = 0;
	
	if ((fpt = fopen("ML.txt","r")) == NULL)
	{
		printf("Error! opening File");
	}
	
	while((ch1 = fgetc(fpt))!='\n')
	{
		if(ch1=='\t')
		{
			count1++;
		}
	}
	//printf("column count is : %d ",count1);				//colum count of the data......
	fclose(fpt);

	//*****************************************************************//	
	if ((fpt = fopen("ML.txt","r")) == NULL)
	{
		printf("Error! opening File");
	}
	
	srand((unsigned int)time(NULL));
	
	//printf("\nrandom number is : %d ",d);
	printf("\n before shuffling :....................");		//before shuffling.....

	for(int i=0;i<count;i++)
	{
		for(int j=0;j<count1+1;j++)
		{
	
			fscanf(fpt,"%f   ",&arr[i][j]);
			//printf("  %f",arr[i][j]);
		
		}
		//printf("\n\n");
	}

	float temp1;
	int d1,d2;
	for(int s=0;s<150;s++)
	{
		d1=1+rand()%100;
		d2=100+rand()%110;


		if(d1 != d2)					//shufffling algorithm.....
		{
			for(int t=0;t<count1+1;t++)
			{
				temp1 = arr[d1][t];
				arr[d1][t] = arr[d2][t];
				arr[d2][t] = temp1;
			}
			
		}
	}
	printf("\n Aftter shuffling :................");	//after shulling .......		
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<count1+1;j++)
		{
	
			fscanf(fpt,"%f   ",&arr[i][j]);
			//printf("  %f",arr[i][j]);
		
		}
		//printf("\n\n");
	}
	float trained_set[count][count1+1],tested_set[count][count1+1];
	int tc;   //trained set count.....
	int tesc; //tested set count.....	
	int div;  //tesc=(total/div)
	//tesc=210/4;
	int kv,pv;
	//printf("\nenter the kv and pv :   ");
	//scanf("%d %d",&kv,&pv);
	//printf("\n kv: %d    pv: %d",kv,pv);
	
	//printf("\n enter the number of set R ? :   ");
	//scanf("%d",&div);
	int in=0,in1=0;
	float final_array[10][10];
	int k,p;
			printf("\n\n");
	for(kv=1;kv<=10;kv++)				// for loop for k and p values printing ....
	{
		for(pv=1;pv<=10;pv++)
		{	
			//kv=2;pv=1;
			div=3+rand()%7;
			tesc = count/div;
			tc= count - tesc;
			//printf("\n tested and trained counts  :%d --- %d",tesc,tc);

			int a1,b1,c1,f1,e1,c2;
			float acr[div];

			for(a1=0;a1<div;a1++)				//r- fold cross validation......
			{							//here r = div;
				 f1=0;e1=0;
				 for(b1=0;b1<count;b1++)
				 {
				 	
				 	if(a1*tesc <= b1 && b1 < (a1+1)*tesc)
				 	{
				 		for(c1=0;c1<count1+1;c1++)
				 		{
				 			float value;
				 			value = arr[b1][c1];
				 			tested_set[f1][c1] = value;
				 			//printf("%f ",tested_set[f1][c1]);
				 			
				 		}
				 		f1++;
				 		//printf("\n count :%d \n",f1);
				 	}
				 	
				 	else 
				 	{
				 		//printf("\n entered trained data..............");
				 		for(c1=0;c1<count1+1;c1++)
				 		{
				 			float value1;
				 			value1 = arr[b1][c1];
				 			trained_set[e1][c1] = value1;
				 			//printf("%f ",trained_set[e1][c1]);
				 			
				 		}
				 		e1++;
				 		//printf("\n count :%d \n",e1);
				 		//printf("\n");
				 	}
				 }
			
				float correct =0,total=0;


				for(int q=0;q<f1;q++)
				{
					float array[1][count1+1];
					for(int r=0;r<count1+1;r++)			//setting up the problem into final statement......
					{
						array[0][r] = tested_set[q][r];
						
					}
					int result = Knn_classifier_algo(trained_set,array,kv,pv,e1,count1+1);
					//printf("%d",result);
					int verify = array[0][count1];
					//printf("%d",verify);
					if(result == verify)
					{
						correct+=1;
					}
					total +=1;
				}
				float final = (correct/total)*100;
				acr[a1] = final;
				//printf("\n total lines count is : %d ",count);
				//printf("\n correct :  %f ",correct);
				//printf("\n total :  %f ",total);
				//printf("\n accaracy : %f ",(correct/total)*100);
				 
			}
			//printf("\n result values is ");	
			for(int p=0;p<div;p++)
			{
			
				//printf("\n %f",acr[p]);
			}
			float sum3=0;
			for(int p=0;p<div;p++)
			{
				sum3=sum3+acr[p];
				
				
			}
			float fres;
			fres = sum3/div;
			final_array[in][in1]=fres;			//final 2d array of results....
			printf("%f  ",final_array[in][in1]);			// (k=1,p=1) (k=1,p=2) ............(k=1,p=10)
			in1++;							//  (k=2,p=1)......	......		.....
		}								//.......		.....		.....
										// so on (k=10,p=1)...............(k=10,p=10)	
		printf("\n\n");
		in++;							//final matrix will look as this .....
	}
	float maxi = final_array[0][0];
	for(int u=0;u<=20;u++)
	{
		for(int v=0;v<=10;v++)
		{
			if(u%2==0)
			{
				if(final_array[u][v] > maxi)
				{
					maxi = final_array[u][v];
				}
			}
			//printf("%.2f  ",final_array[u][v]);
		}
		//printf("\n\n");
	}
	printf("\n maximum element :%f",maxi);			
	for(int u1=0;u1<20;u1++)
	{
		for(int v1=0;v1<10;v1++)
		{
			if(u1%2==0)
			{
				if(maxi == final_array[u1][v1] )
				{
					//printf("\n hell0");
					printf("\n k value :%d   p value:%d  \n\n",((u1+2)/2),(v1+1));	
				}
			}			
		}
		//printf("\n\n");
	}			

	//printf("\n final result  is %f",fres);	
	//printf("\n ");		 
	
	
	fclose(fpt);
}

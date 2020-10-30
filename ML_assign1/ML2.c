#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int fc=0;

int Knn_classifier_algo(int trainset[4000][80],int testset[1][80],int kvalue,int p,int trc,int tesc)
{
											// trc =trained count row ;tesc =tested set and trained set column count
	
	float store[trc][2];
	for(int l=0;l<trc;l++)
	{
		float sum=0;
		for(int k=0;k<tesc;k++)
		{
			float md = pow((trainset[l][k] - testset[0][k]),p);			//distance formula applied in c......
			if(md<1)													//....
			{														
				md = md*(-1);
				
			}
			else
			{
				md = md*(1);
			}
			sum = sum + md;											//.......sum of distances
			//printf(" %f  ",sum);
		}
																		//.....end of distance 	
		float res = pow(sum,1./p);										//here the nth root of distance
		//printf(" result :%f  ",res);
		//printf("\n\n");
		store[l][0] = res;
		store[l][1] = trainset[l][tesc];							//storing into array.....
	}	
	//printf("%f,%f,%f,%f,%f,%f,%f,%f",testset[0][0],testset[0][1],testset[0][2],testset[0][3],testset[0][4],testset[0][5],testset[0][6],testset[0][7])2
													//printf("\n before sorted................  ");
	for(int e=0;e<trc;e++)
	{
		
		//printf("\n %f -- class: %f ",store[e][0],store[e][1]);
	}
	
	float swap,swap1;
	for(int a=0;a<(trc-1);a++)
	{
		for(int b=0;b<(trc-1)-a;b++)
		{
			if(store[b][0] > store[b+1][0])
			{
				swap = store[b][0];							//sorting applied for the array............
				store[b][0] = store[b+1][0];
				store[b+1][0] = swap;
				
				swap1 = store[b][1];
				store[b][1] = store[b+1][1];
				store[b+1][1] = swap1;
				
			}
		}
	}
													//printf("\n after sorted................  ");
	fc++;
	printf("\n %d",fc);
	for(int d=0;d<kvalue;d++)
	{
		//printf("\n %f --- class : %f ",store[d][0],store[d][1]);
	}
	int f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,f7=0,f8=0,f9=0,f0=0;
	for(int d=0;d<kvalue;d++)
	{
		//printf("\n %f --- class : %f ",store[d][0],store[d][1]);
		if(store[d][1] == 1.000000 )
		{
			f1 +=1;
		}
		else if (store[d][1] == 2.000000 )				// number of frequencies to find whether which class is that in that.
		{
			f2+=1;
		}
		else if(store[d][1] == 3.000000 )
		{
			f3+=1;
		}
		else if(store[d][1] == 0.000000 )
		{
			f0+=1;
		}
		else if(store[d][1] == 4.000000 )
		{
			f4+=1;
		}
		else if(store[d][1] == 5.000000 )
		{
			f5+=1;
		}
		else if(store[d][1] == 6.000000 )
		{
			f6+=1;
		}
		else if(store[d][1] == 7.000000 )
		{
			f7+=1;
		}
		else if(store[d][1] == 8.000000 )
		{
			f8+=1;
		}
		else if(store[d][1] == 9.000000 )
		{
			f9+=1;
		}
		
	}
												//max number of frequencies .........
	
	int val0=0,val1=1,val2=2,val3=3,val4=4,val5=5,val6=6,val7=7,val8=8,val9=9;
	if (f1>=f2 && f1>=f3 && f1>=f4 && f1>=f5 && f1>=f6 && f1>=f7 && f1>=f8 && f1>=f9 && f1>=f0 )
	{
		return val1;
	}
	if (f2>=f1 && f2>=f3 && f2>=f4 && f2>=f5 && f2>=f6 && f2>=f7 && f2>=f8 && f2>=f9 && f2>=f0 )
	{
		return val2;
	}
	if (f3>=f2 && f3>=f1 && f3>=f4 && f3>=f5 && f3>=f6 && f3>=f7 && f3>=f8 && f3>=f9 && f3>=f0 )
	{
		return val3;
	}
	if (f4>=f2 && f4>=f3 && f4>=f1 && f4>=f5 && f4>=f6 && f4>=f7 && f4>=f8 && f4>=f9 && f4>=f0 )
	{
		return val4;
	}
	if (f5>=f2 && f5>=f3 && f5>=f4 && f5>=f1 && f5>=f6 && f5>=f7 && f5>=f8 && f5>=f9 && f5>=f0 )
	{
		return val5;
	}
	if (f6>=f2 && f6>=f3 && f6>=f4 && f6>=f5 && f6>=f1 && f6>=f7 && f6>=f8 && f6>=f9 && f6>=f0 )
	{
		return val6;
	}
	if (f7>=f2 && f7>=f3 && f7>=f4 && f7>=f5 && f7>=f6 && f7>=f1 && f7>=f8 && f7>=f9 && f7>=f0 )
	{
		return val7;
	}
	if (f8>=f2 && f8>=f3 && f8>=f4 && f8>=f5 && f8>=f6 && f8>=f7 && f8>=f1 && f8>=f9 && f8>=f0 )
	{
		return val8;
	}
	if (f9>=f2 && f9>=f3 && f9>=f4 && f9>=f5 && f9>=f6 && f9>=f7 && f9>=f8 && f9>=f1 && f9>=f0 )
	{
		return val9;
	}
	if (f0>=f2 && f0>=f3 && f0>=f4 && f0>=f5 && f0>=f6 && f0>=f7 && f0>=f8 && f0>=f9 && f0>=f1 )
	{
		return val0;
	}
							//end of finding freq and return the value......
	
}

int main()
{
	/*******************************************PART ONE for testing *******************************************/
	//printf("enter the same ");
	int hash[2000][80];

	//int num1,num2,num3,num4,num5,num6,num7,num8;
	//int arr[6000][800];
	char ch;
	int count = 0;
	FILE *fpt1;
	
	if ((fpt1 = fopen("ML2.txt","r")) == NULL)
	{
		printf("Error! opening File");
	}
	
	while((ch = fgetc(fpt1))!=EOF)
	{
		if(ch=='\n')
		{
			count++;
		}
	}
	printf("row count is : %d ",count);				//row counting.....	
	fclose(fpt1);
	//****************************************************************************//
	
	char ch1;
	int count1 = 0;
	
	if ((fpt1 = fopen("ML2.txt","r")) == NULL)
	{
		printf("Error! opening File");
	}
	
	while((ch1 = fgetc(fpt1))!='\n')
	{
		if(ch1==',')
		{
			count1++;
		}
	}
	printf("column count is : %d ",count1);		//column counting.....
	fclose(fpt1);
	
	
	if ((fpt1 = fopen("ML2.txt","r")) == NULL)
	{
		printf("Error! opening File");
	}
	
	srand((unsigned int)time(NULL));
	
	//printf("\nrandom number is : %d ",d);
	printf("\n before shuffling :....................\n");	
	int c=0;
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<count1+1;j++)
		{
	
			fscanf(fpt1,"%d,",&hash[i][j]);			//file data storing into array.....
			//printf("  %d",hash[i][j]);
		}
		//c++;
		//printf("\n\n");
	}
	//printf("\n  %d\n",hash[4][count1]);			
	//printf("%d",c);
	fclose(fpt1);
	
	int temp1;
	int d1,d2;
	for(int s=0;s<count-100;s++)
	{
		d1=1+rand()%(count/10);
		d2=(count/10)+rand()%count; 


		if(d1 != d2)
		{
			for(int t=0;t<count1+1;t++)			//shuffling is done by randomize........
			{
				temp1 = hash[d1][t];
				hash[d1][t] = hash[d2][t];
				hash[d2][t] = temp1;
			}
			
		}
	}
	printf("\n Aftter shuffling :................");			
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<count1+1;j++)
		{
	
			//fscanf(fpt,"%d   ",&hash[i][j]);
			//printf("  %d",hash[i][j]);
		
		}
		//printf("\n\n");//c++;
	}
	fclose(fpt1);
	/******************************end of part one*********************************/
	/************************************************PART TWO for training set******************************************************************/
	int hash1[4000][80];

	char ch2;
	int count2 = 0;
	
	
	if ((fpt1 = fopen("train.txt","r")) == NULL)
	{
		printf("Error! opening File");
	}
	
	while((ch2 = fgetc(fpt1))!=EOF)
	{
		if(ch2=='\n')
		{
			count2++;
		}
	}
	printf("\nrow count (2) is : %d ",count2);			//row count .......
	fclose(fpt1);
	//****************************************************************************//
	
	char ch3;
	int count4 = 0;
	
	if ((fpt1 = fopen("train.txt","r")) == NULL)
	{
		printf("Error! opening File");
	}
	
	while((ch3 = fgetc(fpt1))!='\n')
	{
		if(ch3==',')
		{
			count4++;
		}
	}
	printf("\ncolumn count(2) is : %d ",count4);			//column count.....
	fclose(fpt1);
	
	
	if ((fpt1 = fopen("train.txt","r")) == NULL)
	{
		printf("Error! opening File");
	}
	
	int c1=0;
	for(int i1=0;i1<count2;i1++)
	{
		for(int j1=0;j1<count4+1;j1++)
		{
	
			fscanf(fpt1,"%d,",&hash1[i1][j1]);			//trained set file storing into array....
			//printf("  %d",hash1[i1][j1]);
		}
		//c1++;
		//printf("\n\n");
	}
	

	/******************************end of part two*********************************/
	int in=0,in1=0;
	int kv,pv;
	float final_array[10];
	printf("\nenter the kv and pv :   ");			//please enter the value for k value and p value...you can get the exact results of given in 														//	internet may be 1 or 2 values of k value may change a bit of 4% to 5 %).....
	scanf("%d %d",&kv,&pv);
	printf("\n kv: %d    pv: %d",kv,pv);
	
	{

		float correct =0,total=0;
			
		//for(kv=1;kv<=10;kv++)
		
		{
			//for(pv=2;pv<=2;pv++)
			//pv=2;//kv=3;  
			{	


				for(int q=0;q<count;q++)
				{
					int array[1][count4+1];
					for(int r=0;r<count4+1;r++)
					{
						array[0][r] = hash[q][r];
						
					}
					int result = Knn_classifier_algo(hash1,array,kv,pv,count2,count4);
					//printf("%d",result);
					int verify = array[0][count4];
					//printf("verify :%d",verify);
					if(result == verify) 
					{
						correct+=1;
					}
					total +=1;
				}
				/*
				printf("\n");
				for(int l=0;l<5;l++)
				{
					for(int q=0;q<count4+1;q++)
					{
						printf("%d  ",hash[l][q]);
					}
					printf("\n");
				}*/

				float final = (correct/total)*100;
				//final_array[in]=final;
				//printf(" \n  %.2f  ",final_array[in]);
				//in1++;
			}	
			
			//printf("\n\n");
			//in++;
				
				//acr[a1] = final;
				printf("\n total lines count is : %d ",count);
				printf("\n correct :  %f ",correct);
				printf("\n total :  %f ",total);
				printf("\n accaracy : %f ",(correct/total)*100);
		}		
	}
		
	fclose(fpt1);
}

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>

int m[50];
//To find the minimum in an array and store and store them in m array
int min(float A[],int p,int K)
{
	
	int i,j,c=0,mi=100000,mii;
	for(j=0;j<K;j++)
	{	
		for(i=0;i<p;i++)
		{
			if(mi>A[i])
			{
				mii=i;
				mi=A[i];
			}
		}
		m[j]=mii;
		A[mii]=1000000;
		mi=1000000;
		
	}
	
}
//This function is to count the no.of each class label adn store them in an array with its corresponding index
int function(int m[30],int D1l[2224],int D2l[2224],int D3l[2224],int K)
{
	int i,count[100];
	for(i=0;i<10;i++)
	{
		count[i]=0;
	}
	for(i=0;i<K;i++)
	{
		if(m[i]>2222)
		{
			m[i]=m[i]-2223;
		
			if(D3l[m[i]]==0)
			{
				count[0]=count[0]+1;
			}
			if(D3l[m[i]]==1)
			{
				count[1]=count[1]+1;
			}
			if(D3l[m[i]]==2)
			{
				count[2]=count[2]+1;
			}
			if(D3l[m[i]]==3)
			{
				count[3]=count[3]+1;
			}
			if(D3l[m[i]]==4)
			{
				count[4]=count[4]+1;
			}
			if(D3l[m[i]]==5)
			{
				count[5]=count[5]+1;
			}
			if(D3l[m[i]]==6)
			{
				count[6]=count[6]+1;
			}
			if(D3l[m[i]]==7)
			{
				count[7]=count[7]+1;
			}
			if(D3l[m[i]]==8)
			{
				count[8]=count[8]+1;
			}
			if(D3l[m[i]]==9)
			{
				count[9]=count[9]+1;
			}
			
		}
		else
		{
			if(D2l[m[i]]==0)
			{
				count[0]=count[0]+1;
			}
			if(D2l[m[i]]==1)
			{
				count[1]=count[1]+1;
			}
			if(D2l[m[i]]==2)
			{
				count[2]=count[2]+1;
			}
			if(D2l[m[i]]==3)
			{
				count[3]=count[3]+1;
			}
			if(D2l[m[i]]==4)
			{
				count[4]=count[4]+1;
			}
			if(D2l[m[i]]==5)
			{
				count[5]=count[5]+1;
			}
			if(D2l[m[i]]==6)
			{
				count[6]=count[6]+1;
			}
			if(D2l[m[i]]==7)
			{
				count[7]=count[7]+1;
			}
			if(D2l[m[i]]==8)
			{
				count[8]=count[8]+1;
			}
			if(D2l[m[i]]==9)
			{
				count[9]=count[9]+1;
			}
		}	
	}
	//get the class label with the maximum count
	int max=0,index;
	for(i=0;i<9;i++)
	{
		if(count[i]>max)
		{
			max=count[i];
			index=i;
		}
	}
return index;
}

int main()
{
    int i,j,k=0,l=0,count=0,u;
   
    int D1[2224][193],D2[2224][193],D3[2224][193],D1_label[2224],D2_label[2224],D3_label[2224];
    FILE* f = fopen("pp_tra.txt", "r");
    //Scan the training set file and store the values in a 2D array and class labels in a 1D array
    while(getc(f) != EOF)
    {
	
        for(i=0;i<6670;i++)
        {
		
		if(i>2223 && i<=4445){
			k++;}
		if(i>4446 && i<=6669){
			l++;}
            for(j=0;j<193;j++)
	    {
		if(i>=0 && i<=2222)
		{
                	if(j == 192){
                	    fscanf(f,"%d ",&D1_label[i]);
		
                	}
                	else{
                	    fscanf(f,"%d ",&D1[i][j]);
                	}
		}
		
		if(i>=2223 && i<=4445)
		{
                	if(j == 192){
			   
                	    fscanf(f,"%d ",&D2_label[k]);
                	}
                	else{
			   
                	    fscanf(f,"%d",&D2[k][j]);

                	}
		}
		if(i>=4446 && i<=6669)
		{
                	if(j == 192){
                	    fscanf(f,"%d ",&D3_label[l]);
                	}
                	else{
                	    fscanf(f,"%d ",&D3[l][j]);
			    
                	}
		}

		
            }
        }
    }

fclose(f);
float dis[100000];
int K,o=0,mini=0,counter=0,c,label;
 float sum=0.0;
float error[5][50];
	//Calculate the euclidian distances and get the k number of minimum distances and check the classification
	//Count those misclassifications to find the error
	//Store the error in a 3*25 matrix.Find the mean of the 25 columns and take the column  number as K value which has minimum error  
	for(K=1;K<=25;K++)
	{
	//printf("%d....................................\n ",K);
		counter=0;
		for(i=0;i<2223;i++)
		{
			o=0;
			for(j=0;j<2223;j++)
			{	
				sum=0.0;
				for(l=0;l<192;l++)
				{
					sum=sum+(D1[i][l]-D2[j][l])*(D1[i][l]-D2[j][l]);
				}
				dis[o]=sqrt(sum);
				o++;
			}
			for(k=0;k<2224;k++)
			{
				sum=0.0;
				for(l=0;l<192;l++)
				{
					sum=sum+(D1[i][l]-D3[k][l])*(D1[i][l]-D3[k][l]);	
				}
				dis[o]=sqrt(sum);
				o++;
			}
			min(dis,o-1,K);
			

				label=function(m,D1_label,D2_label,D3_label,K);
				if(D1_label[i]!=label)
				{
                                          counter++;
						
				}
					
			
		}
		error[0][K]=(counter/2223.0); 
		//printf("%f\n",error[0][K]);
		//printf("counter:%d\n",counter);
	}
	
	/*for(i=0;i<K;i++)
	{
		printf("%f ",error[0][i]);
	}

	printf("\n");*/
	for(i=0;i<25;i++)
	{
		m[i]=0;
	}
//-------------------------------D2 table as validation set--------------------------------------------------------------------
	for(K=1;K<=25;K++)
	{
	//printf("%d....................................\n ",K);
		counter=0;
		for(i=0;i<2223;i++)
		{
			o=0;
			for(j=0;j<2223;j++)
			{	
				sum=0.0;
				for(l=0;l<192;l++)
				{
					sum=sum+(D2[i][l]-D1[j][l])*(D2[i][l]-D1[j][l]);
				}
				dis[o]=sqrt(sum);
				o++;
			}
			for(k=0;k<2224;k++)
			{
				sum=0.0;
				for(l=0;l<192;l++)
				{
					sum=sum+(D2[i][l]-D3[k][l])*(D2[i][l]-D3[k][l]);	
				}
				dis[o]=sqrt(sum);
				o++;
			}
			min(dis,o-1,K);
			//printf("^^^^\n");
			//printf("m:%d\n",m[0]);
				label=function(m,D2_label,D1_label,D3_label,K);
				if(D2_label[i]!=label)
				{
                                          counter++;
						
				}
		}
		error[1][K]=(counter/2223.0); 
		//printf("%f\n",error[1][K]);
		//printf("counter:%d\n",counter);
	}
	
	/*for(i=0;i<K;i++)
	{
		printf("%f ",error[1][i]);
	}

	printf("\n");*/
	for(i=0;i<25;i++)
	{
		m[i]=0;
	}
//-------------------------------------------------------------D3 as validation set----------------------------------------------------------------------------

for(K=1;K<=25;K++)
	{
	//printf("%d....................................\n ",K);
		counter=0;
		for(i=0;i<2224;i++)
		{
			o=0;
			for(j=0;j<2223;j++)
			{	
				sum=0.0;
				for(l=0;l<192;l++)
				{
					sum=sum+(D3[i][l]-D1[j][l])*(D3[i][l]-D1[j][l]);
				}
				dis[o]=sqrt(sum);
				o++;
			}
			for(k=0;k<2223;k++)
			{
				sum=0.0;
				for(l=0;l<192;l++)
				{
					sum=sum+(D3[i][l]-D2[k][l])*(D1[i][l]-D2[k][l]);	
				}
				dis[o]=sqrt(sum);
				o++;
			}
			min(dis,o-1,K);
			label=function(m,D3_label,D1_label,D2_label,K);
				if(D3_label[i]!=label)
				{
                                          counter++;
						
				}
		}
		error[2][K]=(counter/2223.0); 
	//	printf("%f\n",error[2][K]);
	//	printf("counter:%d\n",counter);
	}
	
	/*for(i=0;i<K;i++)
	{
		printf("%f ",error[2][i]);
	}

	printf("\n");*/
	for(i=0;i<25;i++)
	{
		m[i]=0;
	}
float mean[50];
sum=0.0;

	for(j=1;j<=25;j++){
	sum=0.0;
	for(i=0;i<3;i++){
	//printf("%.2f",error[i][j]);
	sum=sum+error[i][j];
	}
//printf("sum=%f \n",sum);
mean[j]=sum/3.0;
}
sum=10000.0;
int z;
for(j=1;j<=25;j++)
{
	if(sum>mean[j])
	{
		sum=mean[j];
		z=j;
	}
}
for(j=1;j<=25;j++)
{
	printf("mean:%f ",mean[j]);
}
printf("\n");
printf("final K=%d\n",z);


int test[3333][192],test_label[3333],countmis=0;
	printf("start\n");
	    //Scan the test set file and store the values in a 2D array and class labels in a 1D array
	FILE* f1 = fopen("pp_tes.txt", "r");
    	while(getc(f1) != EOF)
    	{
		for(i=0;i<3333;i++)
        	{
			for(j=0;j<193;j++)
	    		{
				if(j == 192){
                	    	fscanf(f1,"%d ",&test_label[i]);
			   	}
                		else{
                	    	fscanf(f1,"%d ",&test[i][j]);
                		}
			}
		}	
	}
	fclose(f1);
	printf("end\n");
		//Repeat the same process for test set as above but with a particular K value which is here z
		//Count the misclassifications and count the correctly classified and get the accuracy of the test set 
		int km=0,kp=0;
		for(i=0;i<3333;i++)
		{
			o=0;
			//printf("start=%d\n",i);
			for(k=0;k<6670;k++)
			{
				
				if(k>=0 && k<=2222)
				{
					
					sum=0.0;
					for(l=0;l<192;l++)
					{
						sum=sum+(test[i][l]-D1[k][l])*(test[i][l]-D1[k][l]);
					}
					dis[o]=sqrt(sum);
					o++;
				}
				else if(k>=2223 && k<=4445)
				{
					km=k-2223;
					
					sum=0.0;
					for(l=0;l<192;l++)
					{
					sum=sum+(test[i][l]-D2[km][l])*(test[i][l]-D2[km][l]);
					}
					dis[o]=sqrt(sum);
					o++;	
				}
				else
				{
					kp=k-4446;
					sum=0.0;
					for(l=0;l<192;l++)
					{
						sum=sum+(test[i][l]-D3[kp][l])*(test[i][l]-D3[kp][l]);
					}
					dis[o]=sqrt(sum);
					o++;
				}
			}
		//	printf("end\n");
			min(dis,o-1,z);
			int count[100];
			for(k=0;k<10;k++)
			{
				count[k]=0;
			}
			for(k=0;k<z;k++)
			{
				if(m[k]>=0 && m[k]<=2222)
				{
					if(D1_label[m[k]]==0)
				{
					count[0]=count[0]+1;
				}
				if(D1_label[m[k]]==1)
				{
					count[1]=count[1]+1;
				}
				if(D1_label[m[k]]==2)
				{
					count[2]=count[2]+1;
				}
				if(D1_label[m[k]]==3)
				{
					count[3]=count[3]+1;
				}
				if(D1_label[m[k]]==4)
				{
					count[4]=count[4]+1;
				}
				if(D1_label[m[k]]==5)
				{
					count[5]=count[5]+1;
				}
				if(D1_label[m[k]]==6)
				{
					count[6]=count[6]+1;
				}
				if(D1_label[m[k]]==7)
				{
					count[7]=count[7]+1;
				}
				if(D1_label[m[k]]==8)
				{
					count[8]=count[8]+1;
				}
				if(D1_label[m[k]]==9)
				{
					count[9]=count[9]+1;
				}
				}
				else if(m[k]>=2223 && m[k]<=4445)
				{
				m[k]=m[k]-2223;
				if(D2_label[m[k]]==0)
				{
					count[0]=count[0]+1;
				}
				if(D2_label[m[k]]==1)
				{
					count[1]=count[1]+1;
				}
				if(D2_label[m[k]]==2)
				{
					count[2]=count[2]+1;
				}
				if(D2_label[m[k]]==3)
				{
					count[3]=count[3]+1;
				}
				if(D2_label[m[k]]==4)
				{
					count[4]=count[4]+1;
				}
				if(D2_label[m[k]]==5)
				{
					count[5]=count[5]+1;
				}
				if(D2_label[m[k]]==6)
				{
					count[6]=count[6]+1;
				}
				if(D2_label[m[k]]==7)
				{
					count[7]=count[7]+1;
				}
				if(D2_label[m[k]]==8)
				{
					count[8]=count[8]+1;
				}
				if(D2_label[m[k]]==9)
				{
					count[9]=count[9]+1;
				}
			
				}
				else
				{
					m[k]=m[k]-4446;
			
				if(D3_label[m[k]]==0)
				{
					count[0]=count[0]+1;
				}
				if(D3_label[m[k]]==1)
				{
					count[1]=count[1]+1;
				}
				if(D3_label[m[k]]==2)
				{
					count[2]=count[2]+1;
				}
				if(D3_label[m[k]]==3)
				{
					count[3]=count[3]+1;
				}
				if(D3_label[m[k]]==4)
				{
					count[4]=count[4]+1;
				}
				if(D3_label[m[k]]==5)
				{
					count[5]=count[5]+1;
				}
				if(D3_label[m[k]]==6)
				{
					count[6]=count[6]+1;
				}
				if(D3_label[m[k]]==7)
				{
					count[7]=count[7]+1;
				}
				if(D3_label[m[k]]==8)
				{
					count[8]=count[8]+1;
				}
				if(D3_label[m[k]]==9)
				{
					count[9]=count[9]+1;
				}
				}	
	
	
			}
			int max=0,index;
			for(k=0;k<9;k++)
			{
				if(count[k]>max)
				{
					max=count[k];
					index=k;
				}
			}
			if(index != test_label[i]  )
			{
       				countmis++;
        		}
       			
        	  }
		
		float error1=countmis/3333.0;
		int correctly_classified=3333-countmis;
		float accuracy=((correctly_classified)/3333.0)*100;
		printf("error:%.2f\n",error1);	
		printf("accuracy:%.2f\n",accuracy);
	
	
	
return 0;
}

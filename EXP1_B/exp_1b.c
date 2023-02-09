#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//declaring function for insertion sort based on length
void insertion_sort(int arr[], int len){ 
	int j = 1; 
	for (int i = 1; i < len; i += 1){ 
		while ((arr[j] < arr[j-1]) && j!=0){
			int temp = arr[j]; 
			arr[j] = arr[j-1]; 
			arr[j-1] = temp;
			j -= 1;  
			}
		j = i + 1;
		} 
	
	}
//declaring function for selection sort based on length
void selection_sort(int arr[], int len){ 
	int min = arr[0];
	int m_ind = 0; 
	for (int i = 0; i < len; i +=1){ 
		for (int j = i; j < len; j +=1){ 
			if (arr[j] < min){ 
				min = arr[j];
				m_ind = j; 
				}
			}
		int temp = arr[m_ind]; 
		arr[m_ind] = arr[i]; 
		arr[i] = temp;
		}
	
	}
		

int main(){ 
	//opening file to store input
	FILE *fp = fopen("input.txt", "w");
	 if (fp == NULL)
    {
        printf("Error opening the file");
        return -1;
    }
    
	//inputting 1 lakh random ints to input.txt
	for (int i = 0; i < 100000; i += 1){ 
		fprintf(fp, "%d ", rand()); 
	}
	fclose(fp);
	//opening file to store output
	FILE *fop = fopen("output.txt", "w");
	 if (fop == NULL)
    {
        printf("Error opening the file");
        return -1;
    }
    //outputting code starts
	int b = 1; 
	for (int j = 100; j < 100000; j += 100){ 
		int arrs[j]; 
		FILE *fir = fopen("input.txt", "r"); 
    	if (fir == NULL)
    	{
        printf("Error opening the file");
        return -1;
    	}
		
		for (int k = 0; k < j; k +=1){ 
			fscanf(fir, "%d ", &arrs[k]); 
		}
		double t_selectsort = 0.0; 
		double t_insertsort = 0.0;
		clock_t begin = clock();
 
 		selection_sort(arrs, j); 
    	clock_t end = clock();
    	t_selectsort += (double)(end - begin) / CLOCKS_PER_SEC; 
    	
    	begin = clock();
 		insertion_sort(arrs, j); 
    	end = clock();
 
    	t_insertsort += (double)(end - begin) / CLOCKS_PER_SEC;
    	fprintf(fop, "%d\t%f\t%f\n", b, t_insertsort, t_selectsort);
    	printf("%d\t%f\t%f\n", b, t_insertsort, t_selectsort);
    	b += 1; 
    	fclose(fir);
    	
	}
	fclose(fop);

	
	}
	
		
	

// C program to multiply two square matrices.
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>


// This function multiplies mat1[][] and mat2[][],
// and stores the result in res[][]
void multiply(int** mat1, int** mat2, int** res, int n, int  m, int k)
{
   int i,j,c;

    for (i = 0; i < n; i++)
   {
    for (j = 0; j < k; j++)
      {
           res[i][j] = 0;
	  
            for (c = 0; c < m; c++){

                res[i][j] += mat1[i][c]*mat2[c][j];
	    }
      }


    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < k; j++)
//           printf("%d ", res[i][j]);
//       printf("\n");
//    }
 
}
void matrix_mult(int n, int m, int k)
{
    int i,j;
    int** mat1;
     mat1 = malloc(n * sizeof *mat1);
    for (i=0; i<n; i++)
    {
	mat1[i] = malloc(m * sizeof *mat1[i]);
    }

   for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
           mat1[i][j] = rand()%1000;
    }
 
     int** mat2;
    
      mat2 = malloc(m * sizeof *mat2);
    for (i=0; i<m; i++)
    {
	mat2[i] = malloc(k * sizeof *mat2[i]);
    }
   
   for (i = 0; i < m; i++)
    {
        for (j = 0; j < k; j++)
           mat2[i][j] = rand()%1000;
    }
 
    int** res; // To store result
    res =  malloc(n  * sizeof *res);

   for (i = 0; i < n; i++)
    {
        res[i] = malloc(k * sizeof *res[i]); 
    }
 
    multiply(mat1, mat2, res,n,m,k);
//    printf("first matrix is \n");
//   printf("Result matrix is \n");
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < k; j++)
//           printf("%d ", res[i][j]);
//        printf("\n");
//    }
    
}

int main(int argc, char** argv) {
	struct rusage buf;
	int n,m,k;
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	k = atoi(argv[3]);
	matrix_mult(n,m,k);
	getrusage(RUSAGE_SELF, &buf);
//	printf("Page reclaims:  %ld\n", buf.ru_minflt);
//	printf("Page faults:    %ld\n", buf.ru_majflt); 
//	printf("user time in mircoseconds: %e\n",(double) buf.ru_utime.tv_sec 	 + (double) buf.ru_utime.tv_usec / (double) 1000000); 
//	printf("system time in mircoseconds: %e\n",(double) buf.ru_stime.tv_sec + (double) buf.ru_stime.tv_usec / (double) 1000000); 
// the out put is page reclaims, page faults, tat.	
	printf("%ld,%ld,%e\n",buf.ru_minflt, buf.ru_majflt,
		       	((double) buf.ru_utime.tv_sec + 
			(double) buf.ru_utime.tv_usec / (double) 1000000) +( (double) buf.ru_stime.tv_sec + 
			(double) buf.ru_stime.tv_usec / (double) 1000000));
}

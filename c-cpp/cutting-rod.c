/*
 * Problem : http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


/*
 * Returns maximum between two integers.
 */
int max(int a, int b)
{
    return a > b? a:b;
}



/*
 * Recursive solution to the problem.
 */
int find_max_value_recursive(int *priceArray, int length)
{
    if(length == 1)
    {
        return priceArray[0];
    }
    else
    {
        int maxprice = priceArray[length - 1];
        for(int i = 1; i <= length/2 ; i++)
        {
            maxprice = max(maxprice,
                          (find_max_value_recursive(priceArray, i) +
                           find_max_value_recursive(priceArray, length - i)));
        }

        return maxprice;
    }
}




/*
 * solution using matrix method.
 */
int matrix_solution(int *priceArray, int length)
{
    int *arr = (int *)malloc( (length + 1) * sizeof(int));

    arr[0] = 0;
    for(int i = 1; i <= length; i++)
    {
        int max_val = INT_MIN;
        for(int j = 0; j < i; j++)
        {
            max_val = max(max_val, priceArray[j] +  arr[i - j -1]);
        }
        arr[i] = max_val;
    }


    return arr[length];
}




/*
 *  Driver program.
 */
int main()
{
    int arr[] = {3, 5, 8, 9, 10, 17, 17, 20};
    printf("\nMax value possible is (Recursive) : %d\n",
           find_max_value_recursive(arr, 8));

    printf("\nMax value possible is (Matrix) : %d\n",
           matrix_solution(arr, 8));

    return 0;
}

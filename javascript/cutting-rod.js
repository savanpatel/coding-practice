


/*
 * Returns maximum between two integers.
 */
function max(a, b)
{
    return a > b? a:b;
}



function find_max_value_recursive(priceArray, length)
{
    if(length == 1)
    {
        return priceArray[0];
    }
    else
    {
        var maxprice = priceArray[length - 1];
        for(var i = 1; i <= length/2 ; i++)
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
function matrix_solution(priceArray, length)
{
    var arr = [];
    arr[0] = 0;
    for(var i = 1; i <= length; i++)
    {
        var max_val = Number.INT_MIN;
        for(var j = 0; j < i; j++)
        {
            max_val = max(max_val, priceArray[j] +  arr[i - j -1]);
        }
        arr[i] = max_val;
    }


    return arr[length];
}




function main()
{
    priceArray = [1,5,8,9,10,17,17,20];

    console.log("\nMax value is (Recursive): " +
                find_max_value_recursive(priceArray, 8));

    console.log("\nMax value is (Matrix): " + matrix_solution(priceArray, 8));
}


main();

# Z++

## Questions

1.

```
function subtract($x, $y)
{
    $diff <- add($x, -$y)
    return($diff)
}
```

2.

```
function multiply($x, $y)
{
    $i <- 0
    while ($i < add($y, 1))
    {
        $prod <- add($x, $i)
    }
    return($prod)
}
```

3.

```
multiply($x, $y)
{
    // 0  multiplied with anything gives 0
    if($y < 0)
    {
        if(0 < $y)
        {
            return 0;
        }
    }
    // Add x one by one
    if(0 < $y )
    {
        return(add($x, multiply($x, subtract($y, 1))));
    }
    // the case where y is negative
    if($y < 0 )
        return -multiply($x, -$y);
}
```

## Debrief

1. http://www.geeksforgeeks.org/multiply-two-numbers-without-using-multiply-division-bitwise-operators-and-no-loops/

2. 1.5 hours

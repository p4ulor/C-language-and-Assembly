Stack pointer must be alligned to a value of 8

trick to allign
```
add $15, %eax
and $-16, %eax
```

( (X+ 2^N -1) /(integer division) 2^N ) * 2^N
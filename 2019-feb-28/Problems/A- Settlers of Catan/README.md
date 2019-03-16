## Settlers of Catan

### Solution:

The problem is to minimize x1+x2+x3+x4+x5 given that x1+5x2+10x3+20x4+100x5=n. It is pretty simple to see that we can operate greedily: take as many 100 as we can, then 20, then 10, etc.

The solutions works because each number in the sequence 1,5,10,20,100 is a divisor of the number after it.

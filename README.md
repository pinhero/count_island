# count_island

The world 2-dimensional array represent a file containing a series of equal-length lines that contains either the dot character (.) or the X character.These lines form a rectangle of ‘.’, which contains islands of ‘X’s.A line is a series of ’.’ and ‘X’ characters that are terminated by a ‘\0’.Two characters are considered touching each other if they are:
•contiguous and on the same line
OR
•in the same column and on contiguous lines
An island of ‘X’ is formed by either a single, isolated, ‘X’ or the set of characters touching each other.The function must scan the whole array, line by line, and replace all of the ’X’s from the islands by their number in order of appearance in the array.

The function must do this computation starting at the beginning of the array and processing line by line.There cannot be two different results from the same file.The function return value of the function must be the number of islands found.

**The array contains, at most, 10 islands.**



*****USAGE*****

make

./count_island [path of your map]

*****TEST*****

./count_island file/foo.txt

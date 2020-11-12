# String++
This a c library with a function recopilation for string manipulation

Functions
======
<code>#define strempty(str)</code>
Returns 1 if the string is empty.

<code>#define strew(str,ch)</code>
Returns 1 if the string ends with 'ch'.

<code>#define strsw(str,ch)</code>
Returns 1 if the string starts with 'ch'.

<code>#define strfpos(str,substr)</code>
Returns the position of the first occurrence of a string.

<code>#define strlpos(str,substr)</code>
Returns the position of the first occurrence of a string.

<code>#define strinsl(str,substr)</code>
Inserts a substring to the left of the string.

<code>#define strinsr(str,substr)</code>
Inserts a substring to the right of the string.

<code>#define strrst(str)</code>
Sets 0 in all index.

<code>#define strtolwr(str)</code>
Converts uppercase to lowercase.

<code>#define strtoopp(str)</code>
Converts lowercase to uppercase and uppercase to lowercase respectively.

<code>#define strtoupr(str)</code>
Converts lowercase to uppercase.

<code>#define strtrim(str)</code>
Removes spaces that are to the right and left of the string.

<code>#define strtriml(str)</code>
Removes spaces that are to the left of the string.

<code>#define strtrimr(str)</code>
Removes spaces that are to the right of the string.

<code>#define strrvrs(str)</code>
Reverses the position of the characters in the string.

<code>void strchins(char* str,int x,const char ch )</code>
Inserts a character in a specific point.

<code>void strchinsl(char* str,const char ch)</code>
Inserts a character to the left of the string.

<code>void strchinsr(char* str,const char ch)</code>
Inserts a character to the right of the string.

<code>int strcount(const char *str, const char *word)</code>
Returns the number of times a substring appears.

<code>void strins(char* str,int x,const char* substr)</code>
Inserts a substring in a specific point.

<code>int strposlr(const char *str,const char *substr, int i)</code>
Returns the first position of a substring analyzing it from left to right, starting from the incident 'i'.

<code>int strposrl(char *str,const char *substr, int i)</code>
Returns the first position of a substring analyzing it from right to left, starting from the incident 'i'.

<code>char strrem(char* str, int i)</code>
Removes the character from a string that is in a specific index.

<code>void strrep(char *str,const char *a,const char *b)</code>
Replaces a substring with another substring.

<code>int strsplit(const char *str,const char *sep,const int h,const int w, char arr[h][w])</code>
Separates a string based on a separator and save the result in a matrix. And return the number of substrings that resulted from that separation returns.

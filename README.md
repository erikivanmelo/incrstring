# String++
This a c library with a function recopilation for string manipulation

Functions
======
<code>#define strempty(str)</code>
returns 1 if the string is empty

<code>#define strew(str,ch)</code>
Returns 1 if the end character is the one entered

<code>#define strsw(str,ch)</code>
Returns 1 if the start character is the one entered

<code>#define strrst(str)</code>
Set 0 in all index

<code>#define strtrims(str)</code>
removes the spaces at the start of the string

<code>#define strtrime(str)</code>
removes the spaces at the end of the string

<code>#define strtrim(str)</code>
removes the spaces at the start and end of the string

<code>void strins(char* str,int x,const char* substr)</code>
inserts a substring in a specific point

<code>#define strinss(str,substr)</code>
inserts a substring at the start of the string

<code>#define strinse(str,substr)</code>
inserts a substring at the end of the string


<code>void strchinse(char* str,const char ch)</code>
inserts a character at the end of the string.

<code>void strchinss(char* str,const char ch)</code>
inserts a character at the start of the string.

<code>void strchins(char* str,int x,const char ch)</code>
insert a character in a specific point.


<code>#define strfpos(str,substr)</code>
Returns the position of the first occurrence of a string

<code>#define strlpos(str,substr)</code>
Returns the position of the first occurrence of a string

<code>#define strtoupr(str)</code>
converts lowercase to uppercase

<code>#define strtolwr(str)</code>
converts uppercase to lowercase

<code>#define strtoopp(str)</code>
converts lowercase to uppercase and uppercase to lowercase respectively

<code>#define strrvrs(str)</code>
reverses the position of the characters in the string

<code>char strrem(char* str, int i)</code>
remove the character from a string that is in a specific index


<code>int strposse(const char *str,const char *substr, int i)</code>
returns the first position of a substring analyzing it from start to end, starting from the incident "i"

<code>int strposes(char *str,const char *substr, int i)</code>
returns the first position of a substring analyzing it from end to start, starting from the incident "i"

<code>void strrep(char *str,const char *a,const char *b)</code>
replace a substring with another substring

<code>int strcount(const char *str, const char *word)</code>
returns the number of times a substring appears

<code>int strsplit(const char *str,const char *sep,const int h,const int w, char arr[h][w])</code>
Separate a string based on a separator and save the result in a matrix. And return the number of substrings that resulted from that separation returns.
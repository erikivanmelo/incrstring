#ifndef INCRSTRING_H
#define INCRSTRING_H
#include <stdlib.h>
#include <string.h>

/* Returns 1 if the string is empty. */
#define strempty(str)  (strlen(str)==0)

/* Returns 1 if the string ends with 'ch'. */
#define strew(str,ch) str[strlen(str)-1]==ch

/* Returns 1 if the string starts with 'ch'. */
#define strsw(str,ch) str[0]==ch

/* Returns the position of the first occurrence of a string. */
#define strfpos(str,substr) strposlr(str,substr,0)

/* Returns the position of the last occurrence of a string. */
#define strlpos(str,substr) strposrl(str,substr,strlen(str)-1)

/* Inserts a substring to the left of the string. */
#define strinsl(str,substr) strins(str,0,substr)

/* Inserts a substring to the right of the string. */
#define strinsr(str,substr) strcat(str,substr)

/* Sets 0 in all index. */
#define strrst(str) memset(str,0,strlen(str))

/* Converts uppercase to lowercase. */
#define strtolwr(str) for(size_t ___i = strlen(str);___i--;)if (str[___i]>='A' && str[___i]<='Z')str[___i]+=32

/* Converts lowercase to uppercase and uppercase to lowercase respectively. */
#define strtoopp(str) for(size_t ___i = strlen(str);___i--;)if (str[___i]>='A' && str[___i]<='Z')str[___i]+=32;else if (str[___i]>='a' && str[___i]<='z')str[___i]-=32

/* Converts lowercase to uppercase. */
#define strtoupr(str) for(size_t ___i = strlen(str);___i--;)if (str[___i]>='a' && str[___i]<='z')str[___i]-=32

/* Removes spaces that are to the right and left of the string. */
#define strtrim(str) strtriml(str);strtrimr(str);

/* Removes spaces that are to the left of the string. */
#define strtriml(str) while(str[0]==' ')strrem(str,0)

/* Removes spaces that are to the right of the string. */
#define strtrimr(str) for(size_t ___i = strlen(str)-1;str[___i]==' ';)strrem(str,___i--) 

/* Reverses the position of the characters in the string. */
#define strrvrs(str) ({ \
    size_t ___len = strlen(str); \
    char ___temp;\
    for (size_t ___i = 0; ___i < ___len / 2; ++___i) { \
        ___temp = str[___i]; \
        str[___i] = str[___len - ___i - 1]; \
        str[___len - ___i - 1] = ___temp; \
    } \
})



/* Inserts a substring in a specific point. */
static char strins(char* str, long index,const char* substr){
    if (str == NULL || substr == NULL) return -1; // Error: NULL input
    const size_t str_len = strlen(str);
    const size_t substr_len = strlen(substr);

    if (index >= str_len) return -2; // Error: Not enough space

    // Handle negative indices
    if (index < 0) index = str_len + index;
    if (index < 0 || (size_t)index > str_len) return -3; // Error: Index out of range

    // Move existing characters to make space for the substring
    memmove(str + index + substr_len, str + index, str_len - index + 1);

    // Insert the substring
    memcpy(str + index, substr, substr_len);

    return 0; // Success
}

/* Inserts a character in a specific point. */
static void strchins(char* str,long x,const char ch ){ const char *temp = &ch; strins(str,x,temp) ;}

/* Inserts a character to the left of the string. */
static void strchinsl(char* str,const char ch 	    ){ const char *temp = &ch; strinsl(str,temp)  ;}

/* Inserts a character to the right of the string. */
static void strchinsr(char* str,const char ch 	    ){ const char *temp = &ch; strcat(str,temp)   ;}

/* Returns the first position of a substring analyzing it from left to right, starting from the incident 'i'. */
static long strposlr(const char *str,const char *substr, long i){
	if(strempty(str)) return -1;
	long substr_len = (long)strlen(substr);
	long len 		= (long)strlen(str);

	if ( substr_len > len ) return -2;
	if ( i >= len ) return -3;
	if ( i<0 ) i = len-i;

	char iqual = 0;
	long i2=0;

	if (substr_len == 1)
	{
		while (i < len && str[i]!=substr[0]) i++;
		return (i == len && str[i]!=substr[0] )? -1 : i;
	}else{
		substr_len--;
		len -= substr_len-1;
		do
		{
			if (str[i]==substr[0])
			{
				iqual = 1;
				do{
					if (str[i+i2] != substr[i2]){
						iqual = i2 = 0;
						break;
					}
				}while (i2++ < substr_len);
			}
		}while(i++ < len && iqual == 0);
	}

	return (iqual)? i-1 : -1 ;
}

/* Returns the first position of a substring analyzing it from right to left, starting from the incident 'i'. */
static long strposrl(const char *str,const char *substr, long i){
	const long substr_len = (long)strlen(substr);
	const long len        = (long)strlen(str);

	if ( strempty(str) ) return -1;
	if ( strempty(substr) ) return -2;
	
	if ( substr_len > len ) return -2;

	if (i >= (long)strlen(str)) return -3;

	long i2 = substr_len;

	if ( i<0 ) i = len-i;
	char iqual = 0;


	if (substr_len == 1)
	{
		while (i && str[i]!=substr[0]) i--;
		return ( str[i]!=substr[0] )? -1 : i;
	}else{
		do{
			if (str[i]==substr[i2-1])
			{
				iqual = 1;
				while (i2--){
					if (str[i-((substr_len-1)-i2)] != substr[i2]){
						iqual = 0;
						i2 = substr_len;
						break;
					}
				}
			}
		}while(i-- >= substr_len && !iqual);
		i++;

		return (iqual)? i-(substr_len-1) : -1 ;


	}
}

/* Returns the number of times a substring appears. */
static size_t strcount(const char *str, const char *word){
	long count = 0,i=0;
	const long word_len = (long)strlen(word);
	if ( strempty(str) || strempty(word)) return 0;
	if ( (i = strposlr(str,word,0)) < 0 ) return 0;

	if (word_len == 1){
		i = (long)strlen(str);
		while(i--) if (str[i] == word[0]) count++;
		return count;
	}
	else{
		do count++;	while( (i = strposlr(str,word,i+word_len) ) > -1 );
		return count;
	}
}

/* Removes the character from a string that is in a specific index. */
static char strrem(char* str, long i){
	const long len = (long)strlen(str);
	if (strempty(str)) return -1;
	if (i >= len)return -2;
	if (i < 0 && i*-1 >= len)return -2;
	if (i<0) i = len-i;
	for (; i < len; ++i)
		str[i] = str[i+1];
	str[i]='\0';
	return 1;
}

/* Replaces a substring with another substring. */
static void strrep(char *str,const char *a,const char *b){
	long i2,i;
	const long a_len = i2 = (long)strlen(a);
	const long b_len = 		(long)strlen(b);
	if ((i = strfpos(str,a)) < 0 ) return;

	if (a_len == 1 && b_len == 1)
	{
		i++;
		while (i--)
			if (str[i]==a[0])
				str[i]=b[0];
		return;
	}
	else if (a_len == 1 && b_len == 0)
	{
		i++;
		while (i--)
			if (str[i]==a[0])
				strrem(str,i);
		return;
	}
	else{
		do{
			while (i2--){
				strrem(str,i);
			}
			strins(str,i,b);
			i2 = a_len;
		}while( (i = strfpos(str,a)) > -1 );
	}
}

/* Replaces the first occurrence of the substring with another substring. */
static void strfrep(char *str,const char *a,const char *b){
	//if (str[0] != a[0]) retrn;

	long i2,i;
	const long a_len = i2 = (long) strlen(a);
	const long b_len = (long) strlen(b);
	
	if ((i = strfpos(str,a)) < 0 ) return;

	if (a_len == 1 && b_len == 1)
	{
		str[i]=b[0];
		return;
	}
	else if (a_len == 1 && b_len == 0)
	{
		strrem(str,i);
		return;
	}
	else{
		while (i2--)
			strrem(str,i);
		strins(str,i,b);
	}
}

/* Replaces the last occurrence of the substring with another substring. */
static void strlrep(char *str,const char *a,const char *b){
	long i2,i;
	const long a_len = i2 = (long)strlen(a);
	const long b_len = (long)strlen(b);
	if ((i = strlpos(str,a)) < 0 ) return;

	if (a_len == 1 && b_len == 1)
	{
		str[i]=b[0];
		return;
	}
	else if (a_len == 1 && b_len == 0)
	{
		strrem(str,i);
		return;
	}
	else{
		while (i2--)
			strrem(str,i);

		strins(str,i,b);
		i2 = a_len;
	}
}

/* Separates a string based on a separator and save the result in a matrix. And return the number of substrings that resulted from that separation returns. */
static size_t strsplit(const char *str,const char *sep,const size_t w,char ***arr){
	long i = 0,x = 0;
	long y = 0;
	
	char **aux = (char**)malloc((strcount(str,sep)+1) * sizeof(char*));

	if ( strfpos(str,sep) < 0 ){
		aux[0] = (char*)calloc((strlen(str)+1), sizeof(char) );
		strcpy(aux[0],str);
		*arr = aux;
		return 1;
	}else{
		aux[0] = (char*)calloc((w+1), sizeof(char) );
	}


	long len = strlen(str);
	const int sep_len = strlen(sep);
	if ( sep_len == 1)
	{
		for (; i < len; ++i,++x)
		{

			aux[y][x] = str[i];
			if (str[i]==sep[0]){
				aux[y][x] = '\0';
				++y;
				x=-1;
				aux[y] = (char*)calloc((w+1), sizeof(char) );
			}

		}
	}else{
		long nextSep = strposlr(str,sep,0);
		for (; i < len; ++i,++x)
		{
			aux[y][x] = str[i];
			if (i==nextSep){
				aux[y][x] = '\0';
				++y;
				x=-1;
				i+=sep_len-1;
				nextSep = strposlr(str,sep,i);
				aux[y] = (char*)calloc((w+1), sizeof(char) );
			}
		}
	}
	aux[y][x] = '\0';

	*arr = aux;
	return y+1;
}

#endif

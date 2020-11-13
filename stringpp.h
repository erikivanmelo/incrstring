#ifndef STRINGPP_H
#define STRINGPP_H
#include <stdlib.h>
#include <string.h>


/* Returns 1 if the string is empty. */
#define strempty(str) str==""

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
#define strtolwr(str) for(int ___i = strlen(str);___i--;)if (str[___i]>='A' && str[___i]<='Z')str[___i]+=32

/* Converts lowercase to uppercase and uppercase to lowercase respectively. */
#define strtoopp(str) for(int ___i = strlen(str);___i--;)if (str[___i]>='A' && str[___i]<='Z')str[___i]+=32;else if (str[___i]>='a' && str[___i]<='z')str[___i]-=32

/* Converts lowercase to uppercase. */
#define strtoupr(str) for(int ___i = strlen(str);___i--;)if (str[___i]>='a' && str[___i]<='z')str[___i]-=32

/* Removes spaces that are to the right and left of the string. */
#define strtrim(str) strtriml(str);strtrimr(str);

/* Removes spaces that are to the left of the string. */
#define strtriml(str) while(str[0]==' ')strrem(str,0)

/* Removes spaces that are to the right of the string. */
#define strtrimr(str) for(int ___i = strlen(str)-1;str[___i]==' ';)strrem(str,___i--) 

/* Reverses the position of the characters in the string. */
#define strrvrs(str)({\
	char ___buffer[strlen(str)];\
	memcpy(___buffer, str, strlen(str));\
	for(int ___i = -1, ___j = strlen(str);___j;){\
		___i++;___j--; str[___i] = ___buffer[___j];\
	}\
})



/* Inserts a substring in a specific point. */
void strins(char* str,int x,const char* substr){
	const int substr_len = strlen(substr);
	const int len = strlen(str);

	if (x<0) x = len-x;

	str[len+substr_len] = '\0';
	for (int i = len+substr_len; i > x; --i)
		str[i] = str[i-substr_len];

	for (int j = 0; j < substr_len; ++j)
		str[j+x] = substr[j];
}

/* Inserts a character in a specific point. */
void strchins(char* str,int x,const char ch ){ const char *temp = &ch; strins(str,x,temp) ;}

/* Inserts a character to the left of the string. */
void strchinsl(char* str,const char ch 	    ){ const char *temp = &ch; strinsl(str,temp)  ;}

/* Inserts a character to the right of the string. */
void strchinsr(char* str,const char ch 	    ){ const char *temp = &ch; strcat(str,temp)   ;}

/* Returns the first position of a substring analyzing it from left to right, starting from the incident 'i'. */
int strposlr(const char *str,const char *substr, int i){
	if(strempty(str)) return -1;
	int substr_len = strlen(substr);
	const int len = (strlen(str)-substr_len)+1;

	if ( substr_len > strlen(str) ) return -2;
	if ( i >= strlen(str) ) return -3;
	if ( i<0 ) i = len-i;

	char iqual = 0;
	int i2=0;

	if (substr_len == 1)
	{
		while (i < len && str[i]!=substr[0]) i++;
		return (i == len && str[i]!=substr[0] )? -1 : i;
	}else{
		substr_len--;
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
int strposrl(char *str,const char *substr, int i){
	if ( strempty(str) ) return -1;
	if ( strempty(substr) ) return -2;
	if ( strlen(substr) > strlen(str) ) return -2;

	int i2;
	const int substr_len = i2 = strlen(substr);
	const int len        = strlen(str);
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
					//printf("[%i]%c == [%i]%c\n",i-((substr_len-1)-i2),str[i-((substr_len-1)-i2)],i2,substr[i2] );
					
					if (str[i-((substr_len-1)-i2)] != substr[i2]){
						iqual = 0;
						i2 = substr_len;
						//printf("i = %i\n", i);
						break;
					}
				}
			}
		}while(i-- && !iqual);
		i++;

		return (iqual)? i-(substr_len-1) : -1 ;
	}
}

/* Returns the number of times a substring appears. */
int strcount(const char *str, const char *word){
	int count = 0,i=0;
	const int word_len = strlen(word);
	if ( strempty(str) || strempty(word)) return 0;
	if ( (i = strposlr(str,word,0)) < 0 ) return 0;

	if (word_len == 1){
		i = strlen(str);
		while(i--) if (str[i] == word[0]) count++;
		return count;
	}
	else{
		do count++;	while( (i = strposlr(str,word,i+word_len) ) > -1 );
		return count;
	}
}

/* Removes the character from a string that is in a specific index. */
char strrem(char* str, int i){
	const int len = strlen(str);
	if (strempty(str)) return -1;
	if (i >= len)return -2;
	if (i < 0 && i*-1 >= len)return -2;
	if (i<0) i = len+i;else i--;
	while( i++ < len)
		str[i] = str[i+1];
	str[i]='\0';
}

/* Replaces a substring with another substring. */
void strrep(char *str,const char *a,const char *b){
	int i2,i;
	const int len   = strlen(str);
	const int a_len = i2 = strlen(a);
	const int b_len = strlen(b);
	if ((i = strposrl(str,a,len-1)) < 0 ) return;

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
		}while( (i = strposrl(str,a,i-1)) > -1 );
	}
}


/* Separates a string based on a separator and save the result in a matrix. And return the number of substrings that resulted from that separation returns. */
int strsplit(const char *str,const char *sep,const int h,const int w, char arr[h][w]){
	int i = -1,x = -1,y = 0;
	if ( strposlr(str,sep,0) < 0 ){
		strcpy(arr[0],str);
		return 0;
	}

	int len = strlen(str);
	const int sep_len = strlen(sep);
	if ( sep_len == 1)
	{
		do{
			arr[y][x++] = str[i++];
			if (str[i]==sep[0]){
				arr[y][x++] = '\0';
				y++;
				x=-1;
			}
		}while(i<len);
	}else{
		int nextSep = strposlr(str,sep,0);
		do{
			arr[y][x++] = str[i++];
			if (i==nextSep){
				arr[y][x++] = '\0';
				y++;
				x=-1;
				i+=sep_len-1;
				nextSep = strposlr(str,sep,i);
			}
		}while(i<len);
	}
	arr[y][x++] = '\0';
	return y+1;
}

#endif

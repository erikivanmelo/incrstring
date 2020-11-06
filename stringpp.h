#ifndef STRINGPP_H
#define STRINGPP_H
#include <stdlib.h>
#include <string.h>

/* returns 1 if the string is empty */
#define strempty(str) str==""

/* Returns 1 if the end character is the one entered */
#define strew(str,ch) str[strlen(str)-1]==ch

/* Returns 1 if the start character is the one entered */
#define strsw(str,ch) str[0]==ch

/* Set 0 in all index */
#define strrst(str) memset(str,0,strlen(str))

/* removes the spaces at the start of the string */
#define strtrims(str) while(str[0]==' ')strrem(str,0)

/* removes the spaces at the end of the string */
#define strtrime(str) for(int ___i = strlen(str)-1;str[___i]==' ';)strrem(str,___i--) 

/* removes the spaces at the start and end of the string */
#define strtrim(str) strtrims(str);strtrime(str);

/* inserts a substring at the start of the string */
#define strinss(str,substr) strins(str,0,substr)

/* inserts a substring at the end of the string */
#define strinse(str,substr) strcat(str,substr)

/* Returns the position of the first occurrence of a string */
#define strfpos(str,substr) strposse(str,substr,0)

/* Returns the position of the first occurrence of a string */
#define strlpos(str,substr) strposes(str,substr,strlen(str)-1)

/* converts lowercase to uppercase */
#define strtoupr(str) for(int ___i = strlen(str);___i--;)if (str[___i]>='a' && str[___i]<='z')str[___i]-=32

/* converts uppercase to lowercase */
#define strtolwr(str) for(int ___i = strlen(str);___i--;)if (str[___i]>='A' && str[___i]<='Z')str[___i]+=32

/* converts lowercase to uppercase and uppercase to lowercase respectively */
#define strtoopp(str) for(int ___i = strlen(str);___i--;)if (str[___i]>='A' && str[___i]<='Z')str[___i]+=32;else if (str[___i]>='a' && str[___i]<='z')str[___i]-=32

/* reverses the position of the characters in the string */
#define strrvrs(str)({\
	char ___buffer[strlen(str)];\
	memcpy(___buffer, str, strlen(str));\
	for(int ___i = -1, ___j = strlen(str);___j;){\
		___i++;___j--; str[___i] = ___buffer[___j];\
	}\
})

/* remove the character from a string that is in a specific index */
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

/* insert a substring in a specific point */
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

/* returns the first position of a substring analyzing it from start to end, starting from the incident "i" */
int strposse(const char *str,const char *substr, int i){
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

/* returns the first position of a substring analyzing it from end to start, starting from the incident "i" */
int strposes(char *str,const char *substr, int i){
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
					if (str[i-(substr_len-i2-1)] != substr[i2]){
						iqual = 0;
						i2 = substr_len;
						break;
					}
				}
			}
		}while(i-- && !iqual);
	}

	return (iqual)? (i-substr_len)+1 : -1 ;
}

/* replace a substring with another substring */
void strrep(char *str,const char *a,const char *b){
	int i2,i;
	const int len   = strlen(str);
	const int a_len = i2 = strlen(a);
	const int b_len = strlen(b);
	if ((i = strposes(str,a,len-1)) < 0 ) return;
	i++;

	if (a_len == 1 && b_len == 1)
	{
		while (i--)
			if (str[i]==a[0])
				str[i]=b[0];
		return;
	}
	else if (a_len == 1 && b_len == 0)
	{
		while (i--)
			if (str[i]==a[0])
				strrem(str,i);
		return;
	}
	else{
		do{
			while (i2--)
				strrem(str,i);
			strins(str,i,b);
			i2 = a_len;
		}while( (i = strposes(str,a,i-1)) > -1 );
	}
}


/* returns the number of times a substring appears */
int strcount(const char *str, const char *word){
	int count = 0,i=0;
	const int word_len = strlen(word);
	if ( strempty(str) || strempty(word)) return 0;
	if ( (i = strposse(str,word,0)) < 0 ) return 0;

	if (word_len == 1){
		i = strlen(str);
		while(i--) if (str[i] == word[0]) count++;
		return count;
	}
	else{
		do count++;	while( (i = strposse(str,word,i+word_len) ) > -1 );
		return count;
	}
}

/* Separate a string based on a separator and save the result in a matrix. And return the number of substrings that resulted from that separation returns. */
int strsplit(const char *str,const char *sep,const int h,const int w, char arr[h][w]){
	int i = -1,x = -1,y = 0;
	if ( strposse(str,sep,0) < 0 ){
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
		int nextSep = strposse(str,sep,0);
		do{
			arr[y][x++] = str[i++];
			if (i==nextSep){
				arr[y][x++] = '\0';
				y++;
				x=-1;
				i+=sep_len-1;
				nextSep = strposse(str,sep,i);
			}
		}while(i<len);
	}
	arr[y][x++] = '\0';
	return y+1;
}

#endif
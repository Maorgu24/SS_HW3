#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define TXT 1024
#define WORD 30


int same(char *str2, char *str1, int t, int w){
  if(t!= w){
    return 0;
  }
  int idx_Str2 = 0;
  int idx_Str1 = 0;
  while(idx_Str2<strlen(str2) && idx_Str1<strlen(str1)){
    if(str2[idx_Str2]==' '){
      idx_Str2++;
    }
    else{
      if(str1[idx_Str1] != str2[idx_Str2]){
        return 0;
      }
      idx_Str1++;
      idx_Str2++;
    }
  }
  if(idx_Str1<strlen(str1))
    return 0;
  return 1;
}


int sameText(char* s,char* wo, int t, int w) {
  if(strlen(s)<strlen(wo)){
    return 0;
  }
  for(int i = 0; i < t-1; i++){
    for(int j =0; j < t-i-1; j++){ 
      if(s[j] > s[j+1]){
        char temp = s[j];
        s[j] = s[j+1];
        s[j+1] = temp;
      }
    }
  }
  for(int i = 0; i < w-1; i++){
    for(int j = 0; j < w-i-1; j++){
      if(wo[j] > wo[j+1]){
        char cnt = wo[j];
        wo[j] = wo[j+1];
        wo[j+1] = cnt;
      }
    }
  }
  int idx_S2 = 0;
  int idx_S1 = 0;
  while(idx_S2<strlen(s) && idx_S1<strlen(wo)){
    if(s[idx_S2]==' '){
      idx_S2++;
    }
    else{
      if(wo[idx_S1] != s[idx_S2]){
        return 0;
      }
      idx_S1++;
      idx_S2++;
    }
  }
  if(idx_S2<strlen(s))
    return 0;
  if(idx_S1<strlen(wo))
    return 0;
  return 1;
}

char* cut(char Text[], int len, int i , int j){
  char* Text_cnt=(char*)malloc(TXT + 1);
  int g=0;
  for(int k = i; k <= j; k++){
    Text_cnt[g]=Text[k];
    g++;
  }
  return Text_cnt;
}



int isEqualSum(char s2[],char s1[], int t, int w) {
  int sum_s1= 0;
  for(int i=0; i < w; i++){
    if(s1[i] <= 90 && s1[i] >= 65){
      sum_s1 += s1[i]-'A'+ 1;
    }
    else if(s1[i] <= 122 && s1[i] >= 97){
      sum_s1 += s1[i]-'a'+1;
    }
  }
  int sum_s2=0;
  for(int i=0; i < t; i++) {
    if(s2[i] <= 90 && s2[i] >= 65){
      sum_s2 += s2[i]-'A'+ 1;
    }
    else if (s2[i] <= 122 && s2[i] >= 97){
      sum_s2 += s2[i]-'a'+1;
    }  
  }
  if(sum_s2!=sum_s1)
  {
    return 0;
  }
  return 1;
}

void Gematria(char *Text, char *Word, int lenTEXT, int lenWORD){
  printf("Gematria Sequences: ");   	
  int x=0;
  for (int i = 0; i < lenTEXT; i++){
    for (int j = 0; j < lenTEXT; j++){
      int counter= isEqualSum(cut(Text,lenTEXT, i ,j), Word ,strlen(cut(Text,lenTEXT, i ,j)), lenWORD);
      if (counter==1){ 
        char a[strlen(cut(Text,lenTEXT, i ,j))];
        strcpy(a,cut(Text,lenTEXT, i ,j));
        if(((a[0]<=90 && a[0]>=65) || (a[0]<=122&& a[0]>=97))&& ((a[strlen(a)-1]<=90 && a[strlen(a)-1]>=65) || (a[strlen(a)-1]<=122&& a[strlen(a)-1]>=97))){
          x++;
          if (x>1){
            printf("~");
        }
        for (int i = 0; i <strlen(a); i++)
        {  
          printf("%c",a[i]); 
        }
      }
    }
  }
}
printf("\n");
}


 void AtbashSequences(char *Text, char *Word, int lenTEXT, int lenWORD){
  printf("Atbash Sequences: ");
  for(int i=0; i<lenWORD; i++){
    if (Word[i]>='a'&& Word[i]<='z'){
      char c=Word[i];
      Word[i]= 'z'-c+'a';
      }
      if (Word[i]>='A'&& Word[i]<='Z'){
        char c=Word[i];
        Word[i]= 'Z'-c+'A';
      }  
    }
    char w[lenWORD];
    strcpy(w,Word);
    char temp;
    int end_index=strlen(w)-1;
    for (int i=0 ; i <= end_index/2;++i){
      temp= w[i];
      w[i]= w[end_index-i];
      w[end_index-i]=temp;
    }
    int x=0;
    for (int i = 0; i < lenTEXT; i++){
      for (int j = 0; j < lenTEXT; j++){
        int counter= same(cut(Text,lenTEXT, i ,j), Word ,strlen(cut(Text,lenTEXT, i ,j)), lenWORD);
        int counter_r=same(cut(Text,lenTEXT, i ,j), w ,strlen(cut(Text,lenTEXT, i ,j)), lenWORD);
        if((counter==1)||(counter_r==1)){
          char a[strlen(cut(Text,lenTEXT, i ,j))];
          strcpy(a,cut(Text,lenTEXT, i ,j));
          if((a[0]!=' ')&&(a[strlen(a)-1]!=' ')){
            x++;
            if (x>1){
              printf("~");
            }
            for (int i = 0; i <strlen(a); i++){
              printf("%c",a[i]); 
            }
          }
        }
      }
    }
printf("\n");
}




void AnagramSequences(char *Text, char *Word, int lenTEXT, int lenWORD){
  printf("Anagram Sequences: ");
  int x=0;
  for (int i = 0; i < lenTEXT; i++){
    for (int j = 0; j < lenTEXT; j++){
      int counter= sameText(cut(Text,lenTEXT, i ,j), Word ,strlen(cut(Text,lenTEXT, i ,j)), lenWORD);
      if(counter==1){  
        char a[strlen(cut(Text,lenTEXT, i ,j))];
        strcpy(a,cut(Text,lenTEXT, i ,j));
        if((a[0]!=' ')&&(a[strlen(a)-1]!=' ')){
          x++;
          if(x>1){
            printf("~");  
          }
          for (int i = 0; i <strlen(a); i++){
            printf("%c", a[i]);
          }
        }
      }
    }
  }
}



int main(){
  char Text[TXT];
  char Word[WORD];   
  char Word_c[WORD];
  char Text_c[TXT];
  scanf("%s", Word_c);
  for(int i = 0; i < strlen(Word_c) + 1; i++){
    if(Word_c[i] == '\\'){
      if(Word_c[i+1] == 't' || Word_c[i+1] == 'n'){
        break;
      }
      else{ 
        Word[i] = Word_c[i];
      }
    }
    else{
      Word[i] = Word_c[i];
    }
  }
  scanf("%[^~]s", Text_c);
  for(int i = 0; i < strlen(Text_c) + 1; i++){
    if(Text_c[i] == '~'){
      break;
    }
    else{
      Text[i] = Text_c[i];
    }
    Text[i] = Text_c[i];
  }

  char Word1[WORD];
  char Text1[TXT];
  strcpy(Word1,Word);
  strcpy(Text1,Text);

  Gematria(Text,Word, strlen(Text),strlen(Word));
  AtbashSequences(Text1, Word1, strlen(Text1),strlen(Word1));
  AnagramSequences(Text, Word, strlen(Text),strlen(Word));
  printf("%c", '\n');
 
  return 0;

}



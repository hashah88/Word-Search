// Hey My name is Haley Shah and I have created this program where I first copy the the given data to my new array. Then my program asks the user to enter the word that they want to find. It takes the users word and then checks in every direction. It then tells the users where it found the word and how many times that word appeared in the puzzle. //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void Emptytheunique ( char **unique, int rows, int cols);
int checkLtoR (char ** matrix , int i, int j, char * userwords, int range, char **);
int checkRtoL (char ** matrix , int i, int j, char * userwords, int range, char ** copy);
int checktoptobottom (char ** matrix , int i, int j, char * userwords, int range, char ** copy); 
int checkbottomtotop (char ** matrix , int i, int j, char * userwords, int range, char ** copy);

// Need Functions Signature. 

int main ( int argc , char *argv[]) {

    FILE *userfile = fopen(argv[2],"r");

     
    if (argc < 3) {
        printf("Sorry, there should be three arguments. Make sure to see if you have three.\n");
         exit(1);
         }


if (userfile == NULL) {
        printf("Sorry, could not open the file '%s' \n", argv[2]);
        exit(1);
    }


    int rows = atoi(argv[1]);
    int cols = rows;
    

    // The copied array of the users file.
    char **puzzle;
    puzzle = malloc(sizeof(char*) * rows);
    int a;
    for (a=0;a<rows;a++){
        puzzle[a] = malloc(sizeof(char) * cols);
    }

    //The array with unique characters .
    char **unique;
    unique = malloc(sizeof(char*) * rows);
    for (a = 0; a< rows; a++)
        unique[a] = malloc(sizeof(char) * cols);
    //assign every element the unique character.
    int b;
    for(a=0;a<rows;a++){
        for(b=0;b<cols;b++){
            unique[a][b] = '.';
            }
    }





    char ch;
    for (a=0; a < rows; a++) {
        fscanf(userfile, " %c", &ch);
        puzzle[a][0] = ch;
        for (b=1; b < cols;b++){
            fscanf(userfile, " %c", &ch);
            puzzle[a][b] = ch;
        }
    }


    fclose(userfile);
    printf("The word puzzle is : \n");
    for(a=0;a<rows;a++){
        for(b=0;b<cols;b++){
            printf(" %c ", puzzle[a][b]);}
        printf("\n");
    }



    //Declare all the varaibles. 

    int i;
    int j;


    char word[100];
    printf("Enter a word and if you want to exit, type in 'zzz'\n");
    scanf("%s",word);
   
   
   
   
   
            while (strcmp(word,"zzz") != 0) {
        int totalcount = 0;
        int lefttorightcount = 0;
        int rtolcount = 0;
        int toptobottom = 0;
        int bottomtotop = 0;

       for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                 if(puzzle[i][j] == word[0]){
        
                 lefttorightcount += checkLtoR(puzzle,i,j,word,cols,unique);
                 
                  rtolcount += checkRtoL(puzzle,i,j,word,cols,unique);
                  toptobottom += checktoptobottom(puzzle,i,j,word,cols,unique);
                  bottomtotop += checkbottomtotop(puzzle,i,j,word,cols,unique);

                
        }

            }
        }

        totalcount = lefttorightcount + rtolcount + toptobottom + bottomtotop;
 printf("The word %s was found %d times, as shown below : \n", word, totalcount);
   printf("%d times written left-to-right \n", lefttorightcount);
   printf("%d times written top-to-bottom\n", toptobottom);
   printf("%d times written bottom-to-top\n", bottomtotop);
   printf("%d times written right-to-left\n", rtolcount);
 
 
       //ask uset to enter word.
        
        
        printf("\n");
          
           for (i=0;i<rows;i++) {
             for(j=0;j<cols;j++){
               printf(" %c ", unique[i][j]);
               }
               printf("\n");
               }
        
   printf ("Enter another word or type 'zzz' to exit :\n");
    scanf("%s", word);
    Emptytheunique (unique,rows,cols);
   
   }
    return 0;
}


int checkLtoR (char ** matrix , int i, int j, char * userwords, int range, char ** copy){ 
    int d, c, tempcount;
    int b = strlen(userwords);
    if (j + (b - 1) >= range)
        return 0;
        
    tempcount = d = 0;
    for (c = j; c < j + b; c++){
        if(matrix[i][c] == userwords[d]) {
            tempcount++;
            d++;
        }
    }
    if (tempcount == b) {
        d = 0;
        for (c = j; c < j + b; c++ , d++)
            copy[i][c]= userwords[d];
        return 1;
    }
    
        return 0;
}



int checkRtoL (char ** matrix , int i, int j, char * userwords, int range, char ** copy){ 
    int d, c, tempcount;
    int b = strlen(userwords);
          if (j- b + 1 < 0)
              return 0;
        
    tempcount = d = 0;
    for (c = j; c > j - b; c--){
        if(matrix[i][c] == userwords[d]) {
            tempcount++;
            d++;
        }
    }
    if (tempcount == b) {
        d = 0;
        for (c = j; c >j- b; c-- , d++)
            copy[i][c]= userwords[d];
        return 1;
    }
    
        return 0;
}

//put back the unique character again. 

void Emptytheunique ( char **unique, int rows, int cols){

   int a;
   int b;
    for(a=0;a<rows;a++){
        for(b=0;b<cols;b++){
            unique[a][b] = '.'; }
            }
            return ;
    }


int checktoptobottom (char ** matrix , int i, int j, char * userwords, int range, char ** copy){ 
    int d, c, tempcount;
    int b = strlen(userwords);
    if (i + (b - 1) >= range)
        return 0;
        
    tempcount = d = 0;
    for (c = i; c < i + b; c++){
        if(matrix[c][j] == userwords[d]) {
            tempcount++;
            d++;
        }
    }
    if (tempcount == b) {
        d = 0;
        for (c = i; c < i + b; c++ , d++)
            copy[c][j]= userwords[d];
        return 1;
    }
    
        return 0;
}


int checkbottomtotop (char ** matrix , int i, int j, char * userwords, int range, char ** copy){ 
    int d, c, tempcount;
    int b = strlen(userwords);
          if (i - b + 1 < 0)
              return 0;
        
    tempcount = d = 0;
    for (c = i; c > i - b; c--){
        if(matrix[c][j] == userwords[d]) {
            tempcount++;
            d++;
        }
    }
    if (tempcount == b) {
        d = 0;
        for (c = i; c >i- b; c-- , d++)
            copy[c][j]= userwords[d];
        return 1;
    }
    return 0;
    }

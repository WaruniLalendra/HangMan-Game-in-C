#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/**
 *
 * If you give the same letter twice it won't count and you'll be informed..
 *
 */


int main()
{

    char* words[] = {"hello","world","program","happy"};
    int wordIndex;
    char word[20],guessLetter,showWord[20];
    int noOfLetters,i,countWrong=0,countCorrect=0,j,k,l;
    srand(time(0));

    wordIndex = rand()%4;

    //printf("index of the word: %d\n",wordIndex);
    //printf("%s\n\n",words[wordIndex]);
    strcpy(word,words[wordIndex]);

    //printf("%s\n\n",word);
    noOfLetters = strlen(word);

    //printf("letters in the word : %d\n", noOfLetters);

    printf("you can only give %d wrong answers to guess the letters!!\n\n",noOfLetters);
    for(k=0; k<noOfLetters; k++){
        printf("_ ");
        showWord[k] = '_';
    }

    printf("\n");

    for(;;){


       if(countCorrect == noOfLetters){
            printf("\n----------------------------------------------------\n");
            printf("\nYOU WON!\n\n");
            printf("The correct word is %s",word);
            printf("\n----------------------------------------------------\n");
            break;
       }else if(countWrong == noOfLetters){
            printf("\n----------------------------------------------------\n");
            printf("\nGAME OVER!\n\n");
            printf("The correct word is \'%s\'",word);
            printf("\n----------------------------------------------------\n");
            break;
       }else{
            printf("\n----------------------------------------------------\n");
            printf("\nEnter your guess: ");
            scanf("%c",&guessLetter);
            getchar();


            for(i=0; i<noOfLetters; i++){

                for(l=0; l<noOfLetters; l++){
                    if(guessLetter == showWord[l]){
                        printf("\nYou have already tried this letter!");
                        goto pass;
                    }
                }

                if(guessLetter==word[i] || guessLetter==(word[i]-32) ){
                    printf("\nCORRECT!\n");
                    countCorrect++;
                    showWord[i] = word[i];

                    //if correct letter has been included more than one time add them to countCorrect.
                    for(j=i+1; j<noOfLetters; j++){
                        if(word[i]== word[j]){
                            countCorrect++;
                            showWord[j] = word[i];
                        }
                    }

                    for(k=0; k<noOfLetters; k++){
                        printf("%c ",showWord[k]);
                    }
                    printf("\n");
                    break;
                }
            }
            pass:

            if(i==noOfLetters){
                printf("\nWRONG!\n");
                countWrong++;
            }
       }
    }

    return 0;
}


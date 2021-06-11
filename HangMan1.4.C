#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/**
 *trying to put this in to a loop..
 *
 *
 */


int main()
{
    int again;
    char* words[] = {"hello","world","program","happy"};
    int wordIndex;
    char word[20],guessLetter,showWord[20];
    int noOfLetters,i,countWrong,countCorrect,j,k,l;

    printf("\n\n\n\t\t\tWELCOME TO HANGMAN!!!\n\n\n");

        do{
            countCorrect=0;
            countWrong=0;
            i=0;
            j=0;
            k=0;
            noOfLetters=0;
            guessLetter = 65;

            srand(time(0));
            wordIndex = rand()%4;
            strcpy(word,words[wordIndex]);
            noOfLetters = strlen(word);


            printf("\n\nYou can only give %d wrong answers to guess the letters!!\n\n",noOfLetters);
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
                    scanf(" %c",&guessLetter);
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

            printf("\n----------------------------------------------------\n");
            printf("Do you want to play again?\n\nPress 1 to play again\n\nPress 0 to exit\n");
            scanf("%d",&again);
            printf("\n----------------------------------------------------\n");


        }while(again!=0);


            return 0;
}


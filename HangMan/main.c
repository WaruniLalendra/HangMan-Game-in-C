#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/**
 *One more level added..
 *
 */


int main()
{
    int again;
    char* words[] = {"hello","world","program","happy"};
    char* words2[] = {"hacker","memory","graphic","mobile"};
    int wordIndex,noOfWords=4;
    char word[20],guessLetter,showWord[20];
    int noOfLetters,i,countWrong,countCorrect,j,k,l,level=1;
    static int wordNo=0;

    printf("\n\n\n\t\t\tWELCOME TO HANGMAN!!!\n\n\n");

        next:
            wordNo=0;

        do{
            while(wordNo<noOfWords){
                countCorrect=0;
                countWrong=0;
                i=0;
                j=0;
                k=0;
                noOfLetters=0;
                guessLetter = 65;

                if(level==1){
                    strcpy(word,words[wordNo]);
                }else if(level==2){
                    strcpy(word,words2[wordNo]);
                }else{

                }
                //strcpy(word,words[wordNo]);
                noOfLetters = strlen(word);
                wordNo++;

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

                        if(wordNo==noOfWords){
                           printf("\n\nCONGRATULATIONS!!!! YOU PASS THE LEVEL %d!!!\n\n",level);
                           level++;
                           goto next;
                        }

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
            }

        }while(again!=0);

            return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/**
 * case in sensitive..
 * if the word include one letter more than one time it is enough to mention that letter only once..
 * more user friendly interface..
 */


int main()
{

    char* words[] = {"hello","world","program","happy"};
    int wordIndex;
    char word[20],guessLetter;
    int noOfLetters,i,countWrong=0,countCorrect=0,j;
    srand(time(0));

    wordIndex = rand()%4;

    //printf("index of the word: %d\n",wordIndex);
    //printf("%s\n\n",words[wordIndex]);
    strcpy(word,words[wordIndex]);

    //printf("%s\n\n",word);
    noOfLetters = strlen(word);

    //printf("letters in the word : %d\n", noOfLetters);

    printf("you can only give %d wrong answers to guess the letters!!\n\n",noOfLetters);

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
                if(guessLetter==word[i] || guessLetter==(word[i]-32) ){
                    printf("CORRECT!\n");
                    countCorrect++;

                    //if correct letter has been included more than one time add them to countCorrect.
                    for(j=i+1; j<noOfLetters; j++){
                        if(word[i]== word[j]){
                            countCorrect++;
                        }
                    }
                    break;
                }
            }

            if(i==noOfLetters){
                printf("WRONG!\n");
                countWrong++;
            }
       }
    }

    return 0;
}


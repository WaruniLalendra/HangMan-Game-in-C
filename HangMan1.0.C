#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{

    char* words[] = {"hello","world","program","happy"};
    int wordIndex;
    char word[20],guessLetter;
    int noOfLetters,i,countWrong=0,countCorrect=0;
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
            printf("YOU WON!\n\n");
            printf("The correct word is %s",word);
            break;
       }else if(countWrong == noOfLetters){
            printf("GAME OVER!\n\n");
            printf("The correct word is \"%s\"",word);
            break;
       }else{
            printf("Enter your guess: ");
            scanf(" %c",&guessLetter);

            for(i=0; i<noOfLetters; i++){
                if(guessLetter==word[i]){
                    printf("CORRECT!\n");
                    countCorrect++;
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


#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//Declaration of functions/methods
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(void)
{
    //Prompt user for input,
    string text = get_string("Sample Text: ");

    //Print number of letters in sample text
    int count_letters(string text);
    int l = count_letters(text);
    //printf("%i letters\n", l);

    //Print number words in sample text
    int count_words(string text);
    int w = count_words(text);
    //printf("%i words\n", w);

    //Print number of sentences in sample text
    int count_sentences(string text);
    int s = count_sentences(text);
    //printf("%i sentences\n", s);

    //L = average number of lettsers/100 words
    float L = 100 * ((float) l / (float) w);
    //S = average number of sentences/100 words
    float S = 100 * ((float) s / (float) w);

    // Coleman-Liau Index
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    {
        if (index < 1)
        {
            printf("Before Grade 1\n");
        }
        else if (index > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", index);
        }
    }

}

//returns total number of letters from user input as an integer
int count_letters(string text)
{
    int letters = 0;                        // initialize letters to 0
    for (int l = 0; l <= strlen(text); l++) // iterate through text sample
    {
        if (isalpha(text[l]))               // check if index location is alphabet character
        {
            letters++;                      // increment variable "letters" by +1 if true
        }
    }
    return letters;                         // return value of variable letters

}

//Returns number of words from user input as an integer
int count_words(string text)
{
    int words = 1;                          // initialize words to 1, as every sentence has at least 1 word
    for (int w = 0; w <= strlen(text); w++) // iterate through text sample
    {
        if (text[w] == ' ')                 // check if index location is a space (' ')
        {
            words++;                        // increment vaiable "words" by +1 if true
        }
    }
    return words;                           // return value of vaiable words
}

//Returns number of sentences of user input as an integer
int count_sentences(string text)
{
    int sentences = 0;                      // initialize sentences to 0
    for (int s = 0; s <= strlen(text); s++) // iterate through text sample
    {
        if (text[s] == '.')                 // check if index location is .
        {
            sentences++;                    // increment variable "sentences" by +1 if true
        }

        else if (text[s] == '?')            // check if index location is ?
        {
            sentences++;                    // increment variable "sentences" by +1 if true
        }

        else if (text[s] == '!')            // check if index location is !
        {
            sentences++;                    // increment variable "sentences" by +1 if true
        }

    }
    return sentences;                       // return value of var sentences

}
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define BUFFER_SIZE 4096
#define BUFFER_SIZE 3

typedef struct
{
    unsigned int words;
    unsigned int chars;
    unsigned int lines;
    unsigned int punctuations;
    char longest_word[64];
} Stats;

typedef struct
{
    const char* start;
    size_t length;
    bool in_word;
    char word[64];
} State;

void check_word_length(Stats* stats, State* state)
{
    if ( state->in_word && state->length > strlen(stats->longest_word))
    {
        // One doesn't write trailling `\0` as longest_word
        // was primarly initialized.
        memcpy(stats->longest_word, state->word, state->length);
    }
    state->length = 0;
    state->in_word = false;
}

void process_string(const char* str, Stats* stats, State* state)
{
    const char* c;
    while (*(c = str++) != '\0')
    {
        stats->chars++;
        // Start
        if (isalpha(*c))
        {
            if (!state->in_word)
            {
                state->length = 0;
                stats->words++;
                state->start = c;
                state->in_word = true;
            }
            state->word[state->length++] = *c;
        }
        else
        {
            check_word_length(stats, state);
        }

        if (*c == '\n')
        {
            stats->lines++;
        }
        else if (ispunct(*c))
        {
            stats->punctuations++;
        }
    }
}

void write_stats(Stats stats, FILE* fp)
{
    fprintf(fp, "{\n");
    fprintf(fp, "  \"words\": %d,\n", stats.words);
    fprintf(fp, "  \"lines\": %d,\n", stats.lines);
    fprintf(fp, "  \"chars\": %d,\n", stats.chars);
    fprintf(fp, "  \"ponctuations\": %d,\n", stats.punctuations);
    fprintf(fp, "  \"longest-word\": \"%s\"\n", stats.longest_word);
    fprintf(fp, "}\n");
}

void version(FILE* fp)
{
    fprintf(fp,
            "Version 0.0.1 "
            "Copyright(c) HEIG-VD\n"
            "Yves.Chevallier <yves.chevallier@heig-vd.ch>\n");
}

void help(FILE* fp)
{
    fprintf(fp,
            "usage: ./gallimard [options] [filename]\n\n"
            "This program is similar to wc and displays some statistics \n"
            "about an ASCII file. It reads from [filename] or if missing, \n"
            "directly from STDIN.\n\n"
            "The output format is JSON compliant.\n\n"
            "Options:\n\n"
            "    --version      Displays the program's version\n"
            "    --help         Shows this help dialog\n"
            "    -o<filename>   Write output on <filename>\n\n"
            "Output:\n\n"
            "    - Number of words\n"
            "    - Number of lines\n"
            "    - Number of characters (bytes)\n"
            "    - Longest word in the text file\n");
}

int main(int argc, char* argv[])
{
    char* in_filename = NULL;
    char* out_filename = NULL;

    // Process arguments
    for (int i = 1; i < argc; i++)
    {
        char* arg = argv[i];

        if (strcmp(arg, "--version") == 0)
        {
            version(stdout);
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(arg, "--help") == 0)
        {
            help(stdout);
            exit(EXIT_SUCCESS);
        }
        else if (arg[0] == '-' && arg[1] == 'o')
        {
            arg += 2;
            if (arg[2] == '\0')
            {
                // Attempt to read filename from the next argument
                if (i++ >= argc)
                {
                    fprintf(stderr, "Error: cannot read output filename!");
                    return 3;
                }
                out_filename = &argv[i][0];
            }
            else
            {
                out_filename = arg;
            }
        }
        else
        {
            in_filename = arg;
        }
    }

    // Open input file (from STDIN or from filename)
    FILE* fp = stdin;
    if (in_filename != NULL)
    {
        if ((fp = fopen(in_filename, "r")) == NULL)
        {
            fprintf(stderr, "Error: cannot open '%s'!", in_filename);
            return 2;
        }
    }

    // Compute statistics
    Stats stats = {0};
    stats.lines = 1;
    State state = {0};
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
    {
        process_string(buffer, &stats, &state);
    }
    check_word_length(&stats, &state);

    fclose(fp);

    // Display results on STDOUT or write to filename
    write_stats(stats,
                out_filename != NULL ? fopen(out_filename, "w") : stdout);

    return 0;
}
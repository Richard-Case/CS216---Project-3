/*
	Course:  CS216-003
	Author:  Richard Case
	Project: Lab 12 (as second part of Project 3)
	Purpose: To demonstrate a simple Word Ladder, using four-letter words as examples
			 create a graph from reading the collection of words in an input file each
			 vertex is labeled with a four-letter word. If two words are only different
			 by a single letter, there is an edge between them.
			 Repeatedly ask the user to choose a source vertex(word1), then a destination
			 vertex(word2) (Press enter to quit), and calculate how many steps of the
			 "Word Ladder" from word1 to word2, which is the distance of the shortest path
			 from the source to the destination in the Graph. Thendisplay the
			 "Word Ladder" from word1 to word2, which is the shortest path from the source
			 to the destination in the Graph.
			 It is the second part of Project 3.
*/
#include <fstream>
#include <stack>
#include <algorithm>
#include "Strings.h"
#include "Graph.h"

int main(int numOfArgs, char* argumentsProvided[])
{
	const int REQ_ARGUMENTS = 2;

    if (numOfArgs != REQ_ARGUMENTS)
    {
        std::cout << clearTerminal
			<< alertWarning << alertArgumentCount
		 	<< argumentsProvided[0] << alertArgumentsRequired << REQ_ARGUMENTS - 1
			<< alertTryAgain
			<< std::endl;

        return 1;
    }

    std::ifstream userFile;
    userFile.open(argumentsProvided[1]);

    if (!userFile.good())
    {
        std::cout << clearTerminal
		 	<< alertWarning << alertInvalidFile << argumentsProvided[1] << std::endl;
        return 2;
    }

    // Read data in from the user's file.
    // Each line of the input file must contain one word from the English dictionary.
    std::string word;
    std::vector<std::string> words;

    while (userFile >> word)
    {
        // Convert every word to lower-case letters.
		for (int letterIndex = 0; letterIndex < word.size(); letterIndex++) { word[letterIndex] = tolower(word[letterIndex]); }
        words.push_back(word);
    }

    userFile.close();

    // Build the graph.
    // Each word from input file represents one vertex.
    Graph<std::string> WordGraph;

    // Decide how many letters should be in each word.
    int wordLength = words[0].length();

    // work on each character position
    // replace with possible a, b..,z
    for (int charIndex = 0; charIndex < wordLength; charIndex++)
    {
        // Remove one character in specified position, computing representative
        // words with same representatives are adjacent; so first populate a map...
        std::map<std::string, std::set<std::string> > repBucket;

        for (size_t sizeIndex = 0; sizeIndex < words.size(); sizeIndex++)
        {
            std::string representative = words[sizeIndex];
            representative[charIndex] = '?';
            repBucket[representative].insert(words[sizeIndex]);
        }

        // and then create a Graph by adding edges among words in the same representative bucket
        for (auto index = repBucket.begin(); index != repBucket.end(); index++)
        {
            std::set<std::string> oneBucket = index->second;

            for (auto firstIterator = oneBucket.begin(); firstIterator != oneBucket.end(); firstIterator++)
            {
                for (auto secondIterator = oneBucket.begin(); secondIterator != oneBucket.end(); secondIterator++)
                {
                    if (*firstIterator != *secondIterator) { WordGraph.AddEdge(*firstIterator, *secondIterator); }
                }
            }
        }
    }

    std::string word1, word2;
	bool continueRunning = true;
	std::string userContinueCheck = "";

	do
    {
		std::cout << clearTerminal
        	<< promptIntro1
			<< promptIntro2
			<< std::endl
			<< promptContinue;
		std::getline(std::cin, userContinueCheck);

		std::cout << clearTerminal
			<< promptWord1
			<< promptInput;
	    std::getline(std::cin, word1);

        if (word1 == "")
		{
			continueRunning = false;
			word2 = "";
		}
		else
		{
			std::cout << std::endl
			 	<< promptWord2
				<< promptInput;
			std::getline(std::cin, word2);
		}

		if (word2 == "") { continueRunning = false; }
		else
		{
			// Convert both word1 and word2 to all lower-case letters.
			for (int letterIndex = 0; letterIndex < word1.size(); letterIndex++) { word1[letterIndex] = tolower(word1[letterIndex]); }
			for (int letterIndex = 0; letterIndex < word2.size(); letterIndex++) { word2[letterIndex] = tolower(word2[letterIndex]); }

			std::map<std::string, int> wordDistances;
			std::map<std::string, std::string> go_through;
			int distance = WordGraph.BFS(word1, word2, wordDistances, go_through);

			// Display the ladder distance from word1 to word2
			// Display the shortest path on the word ladder from word1 to word2
			// the ladder distance is defined as the number of edges on the shortest path from one vertex to another
			// the ladder distance of the same vertex to itself is 0
			// if word1 and word2 are the same word, your program should display "Two words should be different."
			// there is no path from word1 to word2 if its ladder distance is -1
			// there is no path from word1 to word2 if its ladder distance is -2, which means either word1 or/and word2 is invalid
			if ( distance == NO_PATH || distance == INVALID_VERTEX)
				{
					std::cout << std::endl
						<< std::endl
						<< alertNoPath1 << word1 << alertNoPath2 << word2 << alertNoPath3
						<< promptContinue;
					std::getline(std::cin, userContinueCheck);
				}
			else if ( distance == 0)
			{
				std::cout << std::endl
					<< std::endl
					<< alertError << alertDuplicateWord
					<< promptContinue;
				std::getline(std::cin, userContinueCheck);
			}
			else
			{
				std::cout << std::endl
					<< std::endl
					<< promptLadderDistance1 << word1 << promptLadderDistance2 << word2 << promptLadderDistance3 << distance << promptLadderDistance4
					<< promptLadder1 << word1 << promptLadder2 << word2 << promptLadder3;

				std::stack<std::string> pathTaken;
				std::string nextVertex = word2;

				// Compile a stack of every word passed through on the path to the final word.
				while (nextVertex != word1)
				{
					nextVertex = go_through[nextVertex];
					pathTaken.push(nextVertex);
				}

				// Print the entire path taken to arrive at the final word.
				while (!pathTaken.empty())
				{
					std::cout << pathTaken.top() << promptArrow;
					pathTaken.pop();
				}

				std::cout << word2 << std::endl
					<< std::endl
					<< promptContinue;
				std::getline(std::cin, userContinueCheck);
			}
		}
	} while (continueRunning);

	std::cout << clearTerminal
	 	<< promptExit
		<< promptContinue;
	std::getline(std::cin, userContinueCheck);
	std::cout << clearTerminal;
	return 0;
}

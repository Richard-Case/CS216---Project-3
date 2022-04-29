#ifndef STRINGS_H
#define STRINGS_H

#include <string>

// ALERTS
const std::string alertError = "ERROR: ";
const std::string alertInvalidFile = " Unable to access file: ";
const std::string alertWarning = "WARNING: ";

const std::string alertArgumentCount = "Incorrect number of arguments provided. \n";
const std::string alertArgumentsRequired = " requires a number of arguments equal to: ";
const std::string alertDuplicateWord = "Second word must be different from first. \n";
const std::string alertNoPath1 = "No path exists from [";
const std::string alertNoPath2 = "] to [";
const std::string alertNoPath3 = "] \n";
const std::string alertTryAgain ="Please try again. \n";

// PROMPTS...
const std::string promptArrow = " ---> ";
const std::string promptContinue = "\nPress ENTER to continue...";
const std::string promptExit = "Exiting program.\n";
const std::string promptInput = "INPUT: ";
const std::string promptIntro1 = "Welcome to CS216 Word Ladder! \nPlease enter two English words. \n";
const std::string promptIntro2 = "This program will provide the list of steps required to change the first into the second, one letter at a time. \n";
const std::string promptLadder1 = "The ladder from [";
const std::string promptLadder2 = "] to [";
const std::string promptLadder3 =  "]: \n";
const std::string promptLadderDistance1 = "The distance from [";
const std::string promptLadderDistance2 = "] to [";
const std::string promptLadderDistance3 = "] is ";
const std::string promptLadderDistance4 = "-step(s). \n";
const std::string promptWord1 = "Please type the FIRST word (or press 'Enter' to quit) \n";
const std::string promptWord2 = "Please type the SECOND word (or press 'Enter' to quit) \n";

// IOStream Utilities...
const std::string clearTerminal = "\033[2J\033[1;1H";	// Clears the LINUX terminal.

#endif

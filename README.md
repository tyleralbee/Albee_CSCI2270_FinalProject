# Albee_CSCI2270_FinalProject
A repository used to store data for Tyler Albee's CSCI 2270 Final Project

PROJECT SUMMARY{
  The project is a pseudo-craiglist with no online capabilities. Outside "items for sale" are generated when the user selects the option to do so. The user has the option to buy items stored in a hash table - after which they are deleted from the hash table. To sell an item the user provides a title for the item and a price - Boulder, CO is hard coded as their location. The user can search a specific item to find its price. Lastly, the user has the option to quit, after which the structs holding the info about the items is destroyed.
}

HOW TO RUN{
  The project doesn't require any command line prompts - the user will be met with a "main menu" interface that will provide all options to explore the functionality of the program.
}

DEPENDENCIES{
  None.
}

SYSTEM REQUIREMENTS{
  This program was built in the Virtual Machine using Linux.
}

GROUP MEMBERS{
  None.
}

CONTRIBUTORS{
  Special shout out to the student grader who helped me out tremendously.
}

OPEN ISSUES/BUGS{
  My integral function, sellItem(), which has functionality my two most important options, has a segmentation fault that I couldn't figure out using the debugger. This segmentation fault could have to do with my definition of hashTable as a vector and my inability to understand how to store my data inside of it. 

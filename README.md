# DragonFighter
This project is a game played between two players, a user and a semi-artificial intelligence computer. To make it interesting, the computer is given a name “Monster” and user is given a name  “hero”. I used three libraries (Pre-processors) to my project:


#include <iostream>  for input output stream
  
#include <cstdlib>  to generate random numbers
  
#include <ctime> to manipulate time information to get randomly random numbers based on time loop
  
By using classes, constructors, arguments, methods, objects, if-else statements, do-while loop, for loop, switch cases and Boolean statements, I was able to complete my first project.
  
The game starts randomly; either the hero starts it or the monster. Both will start with certain health points between 180 and 200. To make this game fun and challenging, health points for both are also randomly chosen. Both fighters have 5 different types of attacks, which are also randomly chosen and each time attacks will carry a different value. Let’s say the hero starts the game, he will be asked to choose one out of five attacks. After choosing one attack, the value of that attack will be reduced from the monster’s health points. If the hero chooses a value not between 1 and 5 then the hero will be prompted to attack again and choose the right attack. After the hero’s attack, it is going to be the monster’s turn to attack the hero. There is one twist, if the value of the attack is lower than 13 then both fighters will be able to defend that attack  without losing any of their health points. Highest attack value could go upto 20 and lowest could be 10. After battling for a while, one fighter will have zero health points, and that fighter will lose the game. The program asks the user if they want to play the game again after losing/winning. 
One fact I would like to share that when I started this project, I had like 600 lines of code but after learning objected oriented programming, I was able to reduce the lines of the code to 200 by adding classes and using objects.

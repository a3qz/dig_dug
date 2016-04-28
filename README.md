# dig_dug
Fundamentals 2 Final Project 
Ryan Michalec and Jess Cioffi

[Time log]( https://docs.google.com/spreadsheets/d/1_oODkY1Xm41ydkTGvraeTkIIeqj-HuKvUVwQ2rqglJA/edit?usp=sharing)

Special Libraries
=================
The SDL, SDL  image, and SDL ttf libraries are required. 

How To Install
==============
Just use gnu Make from the main folder. This will make an executable, and then using ./ you can run it.

Expected Interactions
=====================
You are playing as a blue and white knight, on a quest to retrieve a flower for the princess of the land.
However, this flower is guarded by three mean dragons, that will chase you in order to keep you from taking it.
One touch from any of the dragons will kill you.
If you get to the flower, you can give it the princess, and you win the game.

Controls
========
Hit the spacebar to start the game.  To move your player, you use the arrow keys on the keyboard.  To close the game early, click the X button at the top left of the game window.

Known bugs
==========
1) When walking along the right edge, the sprite may clip outside of the frame.
2) Sometimes on spawn, the player may spawn on top of the flower, causing you to win immediatley.
3) If the characters collides, sometimes their boxes collide with eachother. 

User's Perspective
==================
The user moves a knight across the screen to reach a flower.  If he gets hit by one of the enemies chasing him, he dies and animates his death.  If he gets the flower, the enemies blow up and he wins.  If the user wants to close the game eary, they can hit the X button in the top left corner of the screen.

Programmer's Perspective
========================
We used OOP to implement this game.  By using classes and inheritance, we were able to make it work.  We started off with a board class and a character class, and then from the character class, we made enemies, players, and the flower.
In each, we made functions that were necessary to create the displays we wanted, load media, and create animation.  By having a character class that contained functions that could be used in the specific classes, we were able to focus on what made each sprite a different aspect in our game.  


Initially, we wanted to do a rendition of the classic Atari game Dig Dug, however, we realized how ambitious that was considering we both have minimal experience with SDL, animation, and game design as a whole.  We eventually decided to pull the reins back a little and reevaluate what we could actually implement.  Instead, we were able to turn what we already had into a game where you need to retrieve an item and avoid enemies in order to win.

Verification of Game Functionality
==================================
We played the game ourselves a few times to ensure its functionality.  As we proceeded step by step, we would check and make sure that the game was performing as we wanted so that we could catch bugs early on.  Although we were not able to account for all bugs, we were able to implement a functionl game that is playable.

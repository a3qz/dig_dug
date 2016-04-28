# dig_dug
Fundamentals 2 Final Project 
Ryan Michalec and Jess Cioffi

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
When prompted on the main screen, hit the spacebar to start the game.  To move your player, you use the arrow keys on the keyboard.  To close the game early, click the X button at the top left of the game window.

Known bugs
==========
1) When walking along the right edge, the sprite may clip outside of the frame.
2) Sometimes on spawn, the player may spawn on top of the flower, causing you to win immediatley.
3) If the characters collides, sometimes their boxes collide with eachother. 

User's Perspective
==================

Programmer's Perspective
========================

Verification of Game Functionality
==================================
We played the game ourselves a few times to ensure its functionality.  As we proceeded step by step, we would check and make sure that the game was performing as we wanted so that we could catch bugs early on.

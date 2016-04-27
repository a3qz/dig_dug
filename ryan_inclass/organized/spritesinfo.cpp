// DONT FORGET WE STILL NEED TO Mhe right, going from right to left respectiveliAP OUT THE PLAYER WITH HIS SHOVEL, unless we are just having him run around instead... he's digging so he should be using the shovel, unless you wanna say screw it and leave him just running around.  It's just a matter of mapping it and switching the sprite numbers

//Player walking to the right sprites

gSpriteClips[ 0 ].x = 0;
gSpriteClips[ 0 ].y = 0;
gSpriteClips[ 0 ].w = 38;
gSpriteClips[ 0 ].h = 39;

gSpriteClips[ 1 ].x = 40;
gSpriteClips[ 1 ].y =  0;
gSpriteClips[ 1 ].w = 34;
gSpriteClips[ 1 ].h = 39;

//Player walking to the left sprites

gSpriteClips[ 2 ].x = 543;
gSpriteClips[ 2 ].y =   0;
gSpriteClips[ 2 ].w =  39;
gSpriteClips[ 2 ].h =  39;

gSpriteClips[ 3 ].x = 506;
gSpriteClips[ 3 ].y =   0;
gSpriteClips[ 3 ].w =  34;
gSpriteClips[ 3 ].h =  39;

// Both walking up facing left sprites
gSpriteClips[ 4 ].x =  0;
gSpriteClips[ 4 ].y = 86;
gSpriteClips[ 4 ].w = 39;
gSpriteClips[ 4 ].h = 40;

gSpriteClips[ 5 ].x = 40;
gSpriteClips[ 5 ].y = 86;
gSpriteClips[ 5 ].w = 39;
gSpriteClips[ 5 ].h = 40;

// Both walking up facing right sprites
gSpriteClips[ 6 ].x = 502;
gSpriteClips[ 6 ].y =  91;
gSpriteClips[ 6 ].w =  39;
gSpriteClips[ 6 ].h =  38;

gSpriteClips[ 7 ].x = 543;
gSpriteClips[ 7 ].y =  88;
gSpriteClips[ 7 ].w =  37;
gSpriteClips[ 7 ].h =  39;

// Both walking down facing left sprites
gSpriteClips[ 8 ].x = 544;
gSpriteClips[ 8 ].y =  38;
gSpriteClips[ 8 ].w =  39;
gSpriteClips[ 8 ].h =  38;

gSpriteClips[ 9 ].x = 502;
gSpriteClips[ 9 ].y =  36;
gSpriteClips[ 9 ].w =  39;
gSpriteClips[ 9 ].h =  38;

// Both walking down facing right sprites
gSpriteClips[ 10 ].x =  0;
gSpriteClips[ 10 ].y = 39;
gSpriteClips[ 10 ].w = 39;
gSpriteClips[ 10 ].h = 38;

gSpriteClips[ 11 ].x = 38;
gSpriteClips[ 11 ].y = 38;
gSpriteClips[ 11 ].w = 39;
gSpriteClips[ 11 ].h = 38;

//Pookas facing the right, going from right to left respectively

// First Pooka
gSpriteClips[ 12 ].x =   0;
gSpriteClips[ 12 ].y = 157;
gSpriteClips[ 12 ].w =  35;
gSpriteClips[ 12 ].h =  34;

// Second Pooka
gSpriteClips[ 13 ].x =  37;
gSpriteClips[ 13 ].y = 158;
gSpriteClips[ 13 ].w =  35;
gSpriteClips[ 13 ].h =  34;

// Third Pooka (his eyes) 
gSpriteClips[ 14 ].x =  75;
gSpriteClips[ 14 ].y = 165;
gSpriteClips[ 14 ].w =  35;
gSpriteClips[ 14 ].h =  22;

// Fourth Pooka (blinking eyes)
gSpriteClips[ 15 ].x = 110;
gSpriteClips[ 15 ].y = 165;
gSpriteClips[ 15 ].w =  35;
gSpriteClips[ 15 ].h =  22;

// Fifth Pooka (starting to blow up)
gSpriteClips[ 16 ].x = 146;
gSpriteClips[ 16 ].y = 156;
gSpriteClips[ 16 ].w =  37;
gSpriteClips[ 16 ].h =  41;

// Sixth Pooka
gSpriteClips[ 17 ].x = 187;
gSpriteClips[ 17 ].y = 152;
gSpriteClips[ 17 ].w =  56;
gSpriteClips[ 17 ].h =  45;

// Seventh Pooka
gSpriteClips[ 18 ].x = 243;
gSpriteClips[ 18 ].y = 144;
gSpriteClips[ 18 ].w =  60;
gSpriteClips[ 18 ].h =  54;

// Eighth Pooka
gSpriteClips[ 19 ].x = 306;
gSpriteClips[ 19 ].y = 141;
gSpriteClips[ 19 ].w =  65;// if you get rid off crushed by rock pooka, increase to 66 or 67
gSpriteClips[ 19 ].h =  56;

// Done with first set of Pookas.  Doing his arrows next.  You placed them all too close together so that may cause slight off by 1 errors later on

// Up Arrow
gSpriteClips[ 20 ].x = 448;
gSpriteClips[ 20 ].y = 127;
gSpriteClips[ 20 ].w =  17;
gSpriteClips[ 20 ].h =  81;

// Down Arrow
gSpriteClips[ 21 ].x = 464;
gSpriteClips[ 21 ].y = 127;
gSpriteClips[ 21 ].w =  17;
gSpriteClips[ 21 ].h =  81;

// Pointing to the Left Arrow
gSpriteClips[ 22 ].x = 484;
gSpriteClips[ 22 ].y = 127;
gSpriteClips[ 22 ].w =  81;
gSpriteClips[ 22 ].h =  17;

// Pointing to the Right Arrow
gSpriteClips[ 23 ].x = 484;
gSpriteClips[ 23 ].y = 144;
gSpriteClips[ 23 ].w =  81;
gSpriteClips[ 23 ].h =  17;

// Right Fygar's First Fire
gSpriteClips[ 24 ].x =   1;
gSpriteClips[ 24 ].y = 272;
gSpriteClips[ 24 ].w =  43;
gSpriteClips[ 24 ].h =  37;

// Right Fygar's Second Fire
gSpriteClips[ 25 ].x =  47;
gSpriteClips[ 25 ].y = 265;
gSpriteClips[ 25 ].w =  85;
gSpriteClips[ 25 ].h =  44;

// Right Fygar's Third Fire
gSpriteClips[ 26 ].x = 132;
gSpriteClips[ 26 ].y = 265;
gSpriteClips[ 26 ].w = 126;
gSpriteClips[ 26 ].h =  46;

// Starting Fygar facing the right, going sequentially

// First Fygar
gSpriteClips[ 27 ].x =   0;
gSpriteClips[ 27 ].y = 227;
gSpriteClips[ 27 ].w =  36;
gSpriteClips[ 27 ].h =  37;

// Second Fygar
gSpriteClips[ 28 ].x =  37;
gSpriteClips[ 28 ].y = 227;
gSpriteClips[ 28 ].w =  38;
gSpriteClips[ 28 ].h =  37;

// Third Fygar (Blinking White fire signifier)
gSpriteClips[ 29 ].x =  75;
gSpriteClips[ 29 ].y = 227;
gSpriteClips[ 29 ].w =  38;
gSpriteClips[ 29 ].h =  37;

// Fourth Fygar (his eyes)
gSpriteClips[ 30 ].x = 112;
gSpriteClips[ 30 ].y = 232;
gSpriteClips[ 30 ].w =  40;
gSpriteClips[ 30 ].h =  31;

// Fifth Fygar (his meaner eyes)
gSpriteClips[ 31 ].x = 152;
gSpriteClips[ 31 ].y = 232;
gSpriteClips[ 31 ].w =  40;
gSpriteClips[ 31 ].h =  31;

// Sixth Fygar (starting to blow up)
gSpriteClips[ 32 ].x = 195;
gSpriteClips[ 32 ].y = 227;
gSpriteClips[ 32 ].w =  39;
gSpriteClips[ 32 ].h =  37;

// Seventh Fygar
gSpriteClips[ 33 ].x = 234;
gSpriteClips[ 33 ].y = 259;
gSpriteClips[ 33 ].w =  55;
gSpriteClips[ 33 ].h =  52;

// Eigth Fygar
gSpriteClips[ 34 ].x = 289;
gSpriteClips[ 34 ].y = 207;
gSpriteClips[ 34 ].w =  55;
gSpriteClips[ 34 ].h =  57;

// Ninth Fygar (popped)
gSpriteClips[ 35 ].x = 344;
gSpriteClips[ 35 ].y = 202;
gSpriteClips[ 35 ].w =  65;
gSpriteClips[ 35 ].h =  62;

// Finished Right Facing Fygar.  Starting Left Facing Fygar

// First Fygar
gSpriteClips[ 36 ].x = 268;
gSpriteClips[ 36 ].y = 278;
gSpriteClips[ 36 ].w =  37;
gSpriteClips[ 36 ].h =  37;

// Second Fygar
gSpriteClips[ 37 ].x = 307;
gSpriteClips[ 37 ].y = 278;
gSpriteClips[ 37 ].w =  37;
gSpriteClips[ 37 ].h =  37;

// Third Fygar (Starting to Blow up)
gSpriteClips[ 38 ].x = 353;
gSpriteClips[ 38 ].y = 281;
gSpriteClips[ 38 ].w =  40;
gSpriteClips[ 38 ].h =  37;

// Fourth Fygar
gSpriteClips[ 39 ].x = 397;
gSpriteClips[ 39 ].y = 272;
gSpriteClips[ 39 ].w =  54;
gSpriteClips[ 39 ].h =  52;

// Fifth Fygar
gSpriteClips[ 40 ].x = 460;
gSpriteClips[ 40 ].y = 266;
gSpriteClips[ 40 ].w =  55;
gSpriteClips[ 40 ].h =  57;

// Sixth Fygar (Popped)
gSpriteClips[ 41 ].x = 531;
gSpriteClips[ 41 ].y = 266;
gSpriteClips[ 41 ].w =  64;
gSpriteClips[ 41 ].h =  62;

// Left Fygar's First Fire
gSpriteClips[ 42 ].x = 500;
gSpriteClips[ 42 ].y = 339;
gSpriteClips[ 42 ].w =  43;
gSpriteClips[ 42 ].h =  37;

// Left Fygar's Second Fire
gSpriteClips[ 43 ].x = 412;
gSpriteClips[ 43 ].y = 331;
gSpriteClips[ 43 ].w =  85;
gSpriteClips[ 43 ].h =  44;

// Left Fygar's Third Fire
gSpriteClips[ 44 ].x = 287;
gSpriteClips[ 44 ].y = 334;
gSpriteClips[ 44 ].w = 126;
gSpriteClips[ 44 ].h =  46;

// Flower
gSpriteClips[ 45 ].x =   0;
gSpriteClips[ 45 ].y = 361;
gSpriteClips[ 45 ].w =  33;
gSpriteClips[ 45 ].h =  35;

// Player Dying
gSpriteClips[ 46 ].x =   0;
gSpriteClips[ 46 ].y = 318;
gSpriteClips[ 46 ].w =  41;
gSpriteClips[ 46 ].h =  38;

// Player Dying Second
gSpriteClips[ 47 ].x =  43;
gSpriteClips[ 47 ].y = 313;
gSpriteClips[ 47 ].w =  43;
gSpriteClips[ 47 ].h =  43;

// Player Dying Third
gSpriteClips[ 48 ].x =  88;
gSpriteClips[ 48 ].y = 313;
gSpriteClips[ 48 ].w =  43;
gSpriteClips[ 48 ].h =  43;

// Player Dying Fourth
gSpriteClips[ 49 ].x = 133;
gSpriteClips[ 49 ].y = 318;
gSpriteClips[ 49 ].w =  43;
gSpriteClips[ 49 ].h =  38;

// Poof He's Dead
gSpriteClips[ 50 ].x = 180;
gSpriteClips[ 50 ].y = 320;
gSpriteClips[ 50 ].w =  31;
gSpriteClips[ 50 ].h =  31;

// Player with the Shovel facing right
gSpriteClips[ 51 ].x =  73;
gSpriteClips[ 51 ].y =   0;
gSpriteClips[ 51 ].w =  38;
gSpriteClips[ 51 ].h =  36;

gSpriteClips[ 52 ].x = 113;
gSpriteClips[ 52 ].y =   0;
gSpriteClips[ 52 ].w =  38;
gSpriteClips[ 52 ].h =  36;

// Player with shovel facing down (right)
gSpriteClips[ 53 ].x =  78;
gSpriteClips[ 53 ].y =  38;
gSpriteClips[ 53 ].w =  36;
gSpriteClips[ 53 ].h =  38;

gSpriteClips[ 54 ].x = 118;
gSpriteClips[ 54 ].y =  38;
gSpriteClips[ 54 ].w =  36;
gSpriteClips[ 54 ].h =  38;

// Player with shovel facing up (right)
gSpriteClips[ 55 ].x =  78;
gSpriteClips[ 55 ].y =  88;
gSpriteClips[ 55 ].w =  36;
gSpriteClips[ 55 ].h =  38;

gSpriteClips[ 56 ].x = 118;
gSpriteClips[ 56 ].y =  88;
gSpriteClips[ 56 ].w =  36;
gSpriteClips[ 56 ].h =  38;

// Player with shovel facing left
gSpriteClips[ 57 ].x = 428;
gSpriteClips[ 57 ].y =   0;
gSpriteClips[ 57 ].w =  38;
gSpriteClips[ 57 ].h =  36;

gSpriteClips[ 58 ].x = 468;
gSpriteClips[ 58 ].y =   0;
gSpriteClips[ 58 ].w =  38;
gSpriteClips[ 58 ].h =  36;

// Player with shovel facing down (left)
gSpriteClips[ 59 ].x = 423;
gSpriteClips[ 59 ].y =  38;
gSpriteClips[ 59 ].w =  36;
gSpriteClips[ 59 ].h =  38;

gSpriteClips[ 60 ].x = 463;
gSpriteClips[ 60 ].y =  38;
gSpriteClips[ 60 ].w =  36;
gSpriteClips[ 60 ].h =  36;

// Player with shovel facing up (left)
gSpriteClips[ 61 ].x = 423;
gSpriteClips[ 61 ].y =  88;
gSpriteClips[ 61 ].w =  36;
gSpriteClips[ 61 ].h =  38;

gSpriteClips[ 62 ].x = 463;
gSpriteClips[ 62 ].y =  88;
gSpriteClips[ 62 ].w =  36;
gSpriteClips[ 62 ].h =  38;

##################################
# OpenXcom v0.9+	Modified #
##################################

This is a modification of OpenXcom.

The goal is a more complete less frustrating game with 
the same challenge and feel as the original.

A full list of changes is in the GitHub commits.
A partial list is in TODO_Kmod.txt

A few changes of interest:
    The likelihood that a UFO power source exploded on 'landing'
    increases with the amount of damage the UFO took.

    Damage rolls have an 88% chance of being within 50% - 150% of 
    reported weapon strength. (Originally 50%)

    Unconscious X-COM units are not considered dead for the purpose of 
    losing the mission if they will probably wake up.

    A Chryssalid attack must deal damage to trigger it's special ability.
    Chryssalid special ability will not kill instantly. (Have MediKits)

    New Weapons, Armor, Equipment, Research ...
    A durable non-Elerium powered Interceptor

    Manufacturing rebalance.
    Psi rebalance - (Defense is increased by Energy and Morale)

Not all graphical elements are in the Repo, because they are based on 
Original Game Data. To avoid problems, do not load KmodGraphics or TANK2.


OpenXcom is an open-source clone of the popular
UFO: Enemy Unknown (X-Com: UFO Defense in USA) videogame by
Microprose, licensed under the GPL and written in C++ / SDL.
See more info at the website: http://openxcom.org
And the wiki: http://ufopaedia.org/index.php?title=OpenXcom

Uses modified code from SDL_gfx (LGPL) with permission from author.

1. Installation
================

OpenXcom requires a vanilla copy of the original X-Com resources.
If you have the Steam version, you can find the X-Com game
folder in "Steam\steamapps\common\xcom ufo defense\XCOM".
Do not use modded versions (eg. XcomUtil) as they may cause bugs
and crashes.

When installing manually, copy the X-Com subfolders (GEODATA,
GEOGRAPH, MAPS, ROUTES, SOUND, TERRAIN, UFOGRAPH, UFOINTRO,
UNITS) to OpenXcom's Data folder: <game directory>\data\

The resources can be in a different folder as the OpenXcom data.
You can also specify your own path by passing the command-line
argument "-data <data path>" when running OpenXcom.

1.1. Windows
-------------

OpenXcom will also check the following folders:

- C:\Documents and Settings\<user>\My Documents\OpenXcom\data (Windows 2000/XP)
- C:\Users\<user>\Documents\OpenXcom\data (Windows Vista/7)

It's recommended you copy the resources to the "data" subfolder.
The installer will automatically detect a Steam installation
and copy the resources as necessary.

1.2. Mac OS X
--------------

OpenXcom will also check the following folders:

- <application resources>\data
- ~/Library/Application Support/OpenXcom/data

It's recommended you copy the resources to the application's "data"
resource (right click the application > Show Package Contents >
Contents > Resources > data).

1.3. Linux
-----------

OpenXcom requires the following libraries:

- SDL (libsdl1.2):
http://www.libsdl.org
- SDL_mixer (libsdl-mixer1.2):
http://www.libsdl.org/projects/SDL_mixer/
- TiMidity++ (timidity):
http://timidity.sourceforge.net/
- SDL_gfx (libsdl-gfx1.2), version 2.0.22 or later:
http://www.ferzkopp.net/joomla/content/view/19/14/
- SDL_image (libsdl-image1.2)
http://www.libsdl.org/projects/SDL_image/
- yaml-cpp, version 0.3.0 or older:
http://code.google.com/p/yaml-cpp/

Check your distribution's package manager or the library
website on how to install them.

According to the XDG standard, OpenXcom will also check the
following folders:

- $XDG_DATA_HOME/openxcom/data
- $XDG_DATA_DIRS/openxcom/data

Or if those variables aren't available:

- ~/.local/share/openxcom/data
- /usr/share/openxcom/data
- /usr/local/share/openxcom/data

Choose whichever you prefer.


2. Customization
=================

OpenXcom has a variety of game settings and extras that can be
customized, both in-game and out-game. These options are global
and affect any old or new savegame.

For more details please check the wiki:
http://ufopaedia.org/index.php?title=Customizing_(OpenXcom)

2.1. User Folder
-----------------

OpenXcom creates a User folder with all the user screenshots,
savegames and options in one of the following paths:

- <game directory>\user\
- C:\Documents and Settings\<user>\My Documents\OpenXcom (Windows 2000/XP)
- C:\Users\<user>\Documents\OpenXcom (Windows Vista/7)
- ~/Library/Application Support/OpenXcom (Mac OS X)
- $XDG_DATA_HOME/openxcom (Linux)
- $XDG_CONFIG_HOME/openxcom (Linux)

You can also specify your own path by passing the command-line
argument "-user <user path>" when running OpenXcom.


3. Development
===============

OpenXcom requires the following developer libraries:
- SDL (libsdl1.2):
http://www.libsdl.org
- SDL_mixer (libsdl-mixer1.2):
http://www.libsdl.org/projects/SDL_mixer/
- SDL_gfx (libsdl-gfx1.2), version 2.0.22 or later:
http://www.ferzkopp.net/joomla/content/view/19/14/
- SDL_image (libsdl-image1.2):
http://www.libsdl.org/projects/SDL_image/
- yaml-cpp, version 0.3.0 or older:
http://code.google.com/p/yaml-cpp/

The source code includes files for the following tools:
- Microsoft Visual C++ 2010.
- Microsoft Visual C++ 2008.
- XCode (check the forum).
- Makefile.
- CMake.
- Autotools.

It's also been tested on a variety of other tools on
Windows/Mac/Linux. More detailed compiling instructions
and pre-compiled dependencies are available at:
http://ufopaedia.org/index.php?title=Compiling_(OpenXcom)

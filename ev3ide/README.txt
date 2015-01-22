//README:
---------

//TODO ONLY ONCE - PRIMARY EV3 SETUP
-------------------------------------

//CREATING THE SD-CARD:
-----------------------
1) Take a Micro SD Card and put it into your PC
2) On the root make sure there is a folder called "lib" and a folder called "myapps"
3) Place the file "libstdc++.so.6.0.10" in the "lib" folder
4) Place the file "run_program.rbf" in the "myapps" folder
5) Insert the micro SD-Card into your EV3 brick

HINT: If you choose "File" >> "New project" >> "Basic project..." in the IDE Explorer windowmenu
      all files will be put onto your disk ready to be placed on your Micro SD CARD! You will find them in the directory
	  called "EV3_FILES"

HINT2: Because the new version of "EV3_IDE.exe" has a "File Explorer" embedded into the program, you can also 
	  create the folders on the Micro SD Card directly and download the needed files into the corresponding folders!
	  To see how this is done section "PREPARING THE INTERNAL MEMORY" will help you using the "File Explorer".

//PREPARING THE INTERNAL MEMORY
//-----------------------------

1)	Open the "EV3_IDE.exe" program
2)	Navigate to the "IDE Explorer" window and choose "File" >> "New project" >> "Basic project...". In the window that
    appears type in the desired name for the project. Remember where you locate the project (see step 9 )! 
3)	Create a USB connection ( make sure your EV3 is already connected to the PC ) by clicking on the "Connect button
    with USB Logo" in the Ribbon Menu.
4)	Navigate to the "File Explorer" window
5)	Press on the "Refresh" button in the right hand side of the "File Explorer". This should show the folders and files
    that are on your device, starting at the "../prjs" folder.
6)	Select the "../prjs" folder ( see the blue arrow in front )
7)	Right Click with the mouse, to see the context menu and click "New folder...", in the window that appears type "lib"
    (without quotes )and press "OK"
8)	Right Click with the mouse, to see the context menu and click "New folder...", in the window that appears type "myapps"
    (without quotes )and press "OK"
9)	Navigate to the place on your PC where you created the "Basic project" (see step 2 ). In this folder you will find a
    directory with the name "EV3_FILES". Open it and select the file "libstdc++.so.6.0.10" (see blue arrow). On the right
	hand side of the "File Explorer" make sure you sected the "lib" folder (see blue arrow). Now click the "Download" button.
10)	Navigate to the place on your PC where you created the "Basic project" (see step 2 ). In this folder you will find a
    directory with the name "EV3_FILES". Open it and select the file "run_program_local.rbf " (see blue arrow). On the right
	hand side of the "File Explorer" make sure you sected the "myapps" folder (see blue arrow). Now click the "Download"
	button.


//INSTALLING THE COMPILER
-------------------------
1) Download CodeSourcery Lite:
   https://sourcery.mentor.com/GNUToolchain/package4574/public/arm-none-linux-gnueabi/arm-2009q1-203-arm-none-linux-gnueabi.exe
2) Install arm-2009q1-203-arm-none-linux-gnueabi.exe CodeSourcery Lite crosscompiler 
   for arm-linux to a folder - preferrably short and without spaces in the path, such as
   C:\CSLite
3) Edit your windows PC PATH environment variable and add the paths for CodeSourcery Lite's bin 
   folder to the front of your path. E.G., C:\CSLite\bin; %other path variables%
4) Install the linux_tools.zip file include in the EV3IDE.zip >>> Extract linux_tools.zip to "C:\tools"
5) Update the PC PATH environment variable by adding "C:\tools;" after "C:\CSLite\bin;
6) You may have to reboot your PC for the PATH variable to become active! (If not active, you can't compile)


//CREATING A NEW PROJECT
------------------------

1) Choose "File" >> "New project" >> "Basic project..." in the IDE Explorer windowmenu.
2) Click on the menu button "Compile and run" to compile to program and check for faults,
   download it to the EV3 brick SD-Card root, and start the program!

   HINT: the program will allways be called "program", this to be able to automatically start
         the program!


//UPDATE THE MAKEFILE IN THE SRC FOLDER
---------------------------------------
When you add a new file to your project, you will have to make sure your "MakeFile" is updated.
Let's say we want to add a new file "MyFile.c" and its header file "MyFile.h" this is how to 
do it:

1) First we add the "MyFile.c" - file to the src folder by right clicking on the src folder
   and choosing "Add New File..." or if you allready have a finished file choose "Add existing
   File(s)...".
2) Secondly we add the header file to the "incl" folder, the same way we added the "MyFile.c" file.
3) Now we update the "MakeFile" in the src folder by double clicking on it in the IDE_Explorer.
4) Update the line of text:
            "_DEPS = lms2012.h d_lcd.h MyLib.h"
   TO
			"_DEPS = lms2012.h d_lcd.h MyLib.h MyFile.h"
5) Update the line of text:
			"_OBJ = d_lcd.o MyLib.o program.o"
   TO
			"_OBJ = d_lcd.o MyLib.o program.o MyFile.o"
6) Compile your program again --> Now the compile will take your MyFile.c and MyFile.h - files
   into account!!!

HINT: There are other ways of creating a MakeFile, to automate this process but I am not that good
      in creating MakeFiles, so for now you will have to do it like described above!
	  (help is allways welcome!)


//PROGRAM EXAMPLES:
-------------------
1) http://www.robotnav.com/ev3/


//USING TELNET:
---------------
1) Insert a compatible WIFI dongle in the Lego EV3 USB Host port.
2) Make sure you connect your EV3 to your (home) network. Make sure
   it's the same network your PC is connected to. (See Lego EV3 manual)
3) Write down the IP address of your EV3 (for example: 192.168.0.109)
4) In the menubar click on the "Connect..." button in the Telnet section.
5) Enter the IP address of your EV3 (for example: 192.168.0.109)
6) Click "Save And Close", if everything goes right you should see some
   text appearing in the "Telnet: EV3 output..." window. See below:

///////////////////////////////////Telnet: EV3 Output...//////////////////////////////////////

??????!????
 _____       _     _ ___
|  _  |_ _ _| |___| | __|
|    _| | | . | . | | _|
|__|__|___|___|___|_|_|

Rudolf 2011.01 EV3

login: 

///////////////////////////////////////////////////////////////////////////////////////////////

7) In the Command >> textfield type root and press "Enter" or click on "Send Cmd"
8) If you want to see the directory structure on your EV3 type "ls" in the "Command >>"
   textfield. ( you will see lms2012 )
9) Type "cd lms2012" and press "Enter" to change directory (Hint: "cd.. bring you back one level")
10) Type again "ls" and press "Enter"
11) Type "cd prjs/SD_Card" (navigate to your SD_Card)
12) Type "./program" to start your compiled "hello world" program
13) Notice that the println function in the MyLib.c returns its text to the terminal!!!
    ( So you can use this for some debugging purposes!!! HINT: this will only work if you startup
	  your program by use of a Telnet session not by use of the Lego EV3 menu!!! )
14) As this is a linux system other linux kernel commands are possible, see this webpage for more info:
    http://community.linuxmint.com/tutorial/view/244
15) Don't panic when you don't see your normal EV3 menu anymore just press the "back" button on the
    EV3 and it will reappear!!!



//STARTUP YOUR PROGRAM FROM THE LEGO MENU
------------------------------------------
1) Navigate to the "File browser" menu and open your "SD_Card"
2) Locate the folder "myapps" and open it
3) Locate the file "run_program" open it and startup your program



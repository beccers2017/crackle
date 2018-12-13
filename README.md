# Crackle
This is a password cracking program created as my personal project for CSCI 3010 at CU Boulder.

This program was built on Linux and has only been tested on Linux

Dependencies Required:

OpenSSL

To install, use the commands:
	sudo apt-get install openssl
	sudo apt-get install libss-dev

XAMPP

To run the locally hosted website used in the brute force attack, XAMPP was used.

To get XAMPP set up:

Download the version compatible with your OS from https://www.apachefriends.org/download.html

In its downlaod location, make the run file executable and then run it using the commands:

	chmod +x xampp-linux-x64-7.2.11-0-install.run

	sudo ./xampp-linux-x64-7.2.11-0-install.run

The second command will launch an installer, that will walk you through the process of setting XAMPP up.

Once that is finished, relaunch your terminal and type the command:

	sudo ./manager-linux-x64.run

Turn on Apache web server in the open window, and then go to a browser and load the page http://localhost.com which will display an XAMPP page.

From here go to the top of your file system directory then to /opt/lampp/htdocs/ and move the folder labeled Login-Test into this folder. RW permissions may need to be changed.

Once this folder is placed inside this directory, go back to your browser and type the url:

	http://localhost.com/Login-Test/login.php

to get the website pulled up.

If you get an error stating the localhost isn't connected or running, start the server using the command:
	sudo /opt/lampp/lampp start

To run this program use the command:
	make


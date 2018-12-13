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

Once this folder is placed inside this directory, keep this directory open and go back to your browser and type the url:

	http://localhost/phpmyadmin
	
once on this page look inside the Login-Test folder for the users.sql file and open it up in a text editor. Copy all the text from it and go back to the localhost/phpmyadmin page. Once there, click the New button on the left side of the screen to create a new database. Name the database 'demo' 
and choose the Collation option from the dropdown menu and then hit create. You will see the new database appear on the left part of the screen. Click on the plus sign next to your database name, and then in the dropdown click the new button. This will redirect your page. Click the SQL button in the navigation bar, paste the text in from your users.sql file and hit go to add a table to your database. From here your website should be working when you go to the page:

	http://localhost.com/Login-Test/login.php

Once on this page you will have to create an account to have at least one in the database to test against.

If you get an error stating the localhost isn't connected or running, start the server using the command:
	sudo /opt/lampp/lampp start



To run this program use the command:
	cd src
	make
	./crackle

The dictionary attack is set up with the larger wordlist by default. To run the program with the smaller wordlist at this time, you need to open theUserInterface.cpp file, comment line 252 out, and uncomment line 254. This will switch the file being used from "parsedWordlist.txt" to "smallWordlist.txt".

Sample Hashes for Dictionary Attack:

MD5 digest's:
0d107d09f5bbe40cade3de5c71e9e9b7
2a304a1348456ccd2234cd71a81bd338 
d8578edf8458ce06fbc5bb76a58c5ca4
ec0e2603172c73a8b644bb9456c1ff6e
75cfee476dd66de9bb2e9824db267398
00bfc8c729f5d4d529a412b12c58ddd2
7d9ad0211d6493e8d55a4a75de3f90a1
9ce44f88a25272b6d9cbb430ebbcfcf1
6006cd7b11193da30f24257bda8a2088
5f4dcc3b5aa765d61d8327deb882cf99

SHA1 digest's:
B7A875FC1EA228B9061041B7CEC4BD3C52AB3CE3
4F0AA52D656A3D75867F784B7E9C5D23BF1321C0
B1B3773A05C0ED0176787A4F1574FF0075F7521E
5C6D9EDC3A951CDA763F650235CFC41A3FC23FE8
C60266A8ADAD2F8EE67D793B4FD3FD0FFD73CC61
DF70F9B975B42116EE6C0231A7E6EAD0BBB283AA
891A4AC3F0101A20236B7F3DBE519F0CD38413C4
E4409822BA1D95BEBCEC2DFAF8F8B3D2E7C8291E
5A2FA4DA9967553D347C13A61017F93FACFCC025
5baa61e4c9b93f3f0682250b6cf8331b7ee68fd8

SHA256 digest's:
1c8bfe8f801d79745c4631d09fff36c82aa37fc4
65e84be33532fb784c48129675f9eff3a682b271
b1b1bdb480c61d075300d9bff7d9cb69cf31695e
1532e76dbe9d43d0dea98c331ca5ae8a65c5e8e8
aa97302150fce811425cd84537028a5afbe37e3f
eaa2bded32cc585d3f37c5319abe8890ad28a697
c0a4942143e872cd1ae29fc759e04526de2e909a
43999461d22f67840fcd9b8824293eaa4f18146e
8d01416611a03b7c979d6fdee3b16006da68e29b
5e884898da28047151d0e56f8dc6292773603d0d

SHA512 digest's:
adfb6dd1ab1238afc37acd8ca24c1279f8d46f61
0dd3e512642c97ca3f747f9a76e374fbda73f929
a508d4422e136270c6b877360cc277fb8dc4b23f
5e325d89a5fceb1ba257f50d7e7c1a807ae8b197
922d076069b1df893fc010b7a6d2aa55c7c4c5d1
d193b10e9bc8bddbdb05e163151e37dd926e2d68
33188243e7af2633fb8fec83a3ef0abce3a18b2f
aeeaa03d199ac59dcc4af3467f28fd3323a72688
ce1d7e1262183286b39b02a39450b7421c573410
b109f3bbbc244eb82441917ed06d618b9008dd09
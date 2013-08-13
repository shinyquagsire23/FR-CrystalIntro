FR-CrystalIntro
===============
![Custom Intro](http://i569.photobucket.com/albums/ss135/mtinc2/PFR_zps53387555.png)
![Custom Intro](http://i569.photobucket.com/albums/ss135/mtinc2/PFR_zps46465a44.png)
![Custom Intro](http://i569.photobucket.com/albums/ss135/mtinc2/PFR_zps2ae7f747.png)
![Custom Intro](http://i569.photobucket.com/albums/ss135/mtinc2/PFR_zps4cf0ed63.png)
![Custom Intro](http://i569.photobucket.com/albums/ss135/mtinc2/PFR_zps9d14871c.png)
![Custom Intro](http://i569.photobucket.com/albums/ss135/mtinc2/PFR_zpsaeae8f60.png)
![Custom Intro](http://i569.photobucket.com/albums/ss135/mtinc2/PFR_zps63e03948.png)


This is a custom introductory sequence for the FireRed engine released under GPLv3. This intro happens to recreate the Crystal Intro with the advancements and improved graphics of the GBA.


To compile, first adjust the compile.sh to your appropriate paths and OS (Sorry Windows users, I use Linux). 

Next find appropriate freespace in the ROM (about 0x10000 bytes to be confortable, more if needed). Modify linker.lsc and compile.sh (if using auto-insert JAR) appropriately. 

Finally, place the pointer to the compiled binary (+1) at 0x080EC5D0, and viola! Custom intro.

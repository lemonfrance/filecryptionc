File Encryption Tool

A C program that allows the user to encrypt/decrypt a file using the XOR operation. A password validated by the same program is also used to encrypt/decrypt a file, and after the encryption/decryption process, a new file, named after the original with an additional “new-“ at the front of the filename, will be saved in the same folder as the original file.  
A valid password has a character length ranging from 8-15, a minimum of 1 alphabetical character and a minimum of 1 numerical character. The password length is always displayed, and an invalid password input will generate a message reminding the user of the aforementioned restrictions.

The XOR function has three parameters: three pointers to a character array. Respectively, these are pointers to the input filename, output filename, and encryption/decryption password. The first 5 bytes of the output file store the results of the XOR operation. They are also printed in the form of 2-digit hexadecimals after a successful encryption/decryption.

Before proceeding, you must have (and know) the following:
* A C Compiler (GCC): Run the command “gcc”. If an error about input files is displayed, you have one installed. Otherwise, install GCC Compiler into your computer.
* The files in this repository downloaded in your computer. Put them inside an appropriate folder.
* If your filename/pathname contains a space, you need to enclose the filename/pathname in quotation marks. Otherwise, the commands may not work.

How to COMPILE A2.c in your PC terminal:
1. Open your PC Shell/Terminal, and go to the folder where your C file is by typing in the command, “cd <insertpathname>” (e.g. cd ./Desktop/yourfolderwhereA2dotCis/)
2. Compile the C file by typing in, “gcc A2.c”. A new file named “a.out” will appear in the same folder as A2.c, and this new file will be used to encrypt/decrypt files.

How to ENCRYPT a file in your PC terminal:
1. Type in “./a.out <yourfilename> <your password>“ in the command line. For example, if the file to be encrypted is ‘auckland.jpg’ using the password ‘abcd1234’, then type in, “./A2 auckland.jpg abcd1234”.
2. After a successful encryption, the output file should be saved in the same folder as your input file. The output file should have a filename that is basically the original filename with an additional “new-“ in the first part (e.g. auckland.jpg -> new-auckland.jpg).

The limitation of this program is having a less intuitive decryption method. Decryption is easily done by encrypting the “new-“ file again with the same password, but you will have to change the filename. Regardless, if you compare the original file and the encrypted-then-decrypted file, the terminal will confirm them identical. Two files can be confirmed identical when the command “cmp <insertfilename> <insertotherfilename>” produces no output.

NOTE: This is a university assignment marked, tested and proven to work as described. This was created according to set assignment specifications, so there may be functionalities that are unnecessary or lacking, depending on your expectations.

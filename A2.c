#include <stdio.h>
#include <string.h>

void make_new_name(char *new_name, char *original_name);
int length_of_password(char *password);
int is_alpha(char c);
int is_digit(char c);
int is_valid_password(char *password);
void perform_XOR(char *input_filename, char *output_filename, char *password);
void print_first_five(char *filename);

int main(int argc, char *argv[]) {
	if(argc!=3){
		printf("Correct usage: './a.out filename password'\n");
	}
	else{
		//argv[1] - name of the input file
		char newFileName[20]= "new-";
		char (*newFNptr)[20]=&newFileName;
		char origFileName[15];
		char (*origFNptr)[15]=&origFileName;
		strcpy(origFileName,argv[1]);
		make_new_name(*newFNptr,*origFNptr);
		
  		//argv[2] - password
		char password[15];
		strcpy(password, argv[2]);
		printf("Password length = %d\n", length_of_password(password));
		
		if(is_valid_password(password)==1){
			perform_XOR(origFileName, newFileName, password);
			print_first_five(newFileName);
		}
	}
}

void make_new_name(char *new_name, char *original_name){
	strcat(new_name, original_name);
	printf("New filename = %s\n", new_name);
}
int length_of_password(char *password){
	int pwlen = strlen(password);
	return pwlen;
}
int is_alpha(char c){
	int cDiff_1 = c-65;
	int cDiff_2 = c-97;
	if(cDiff_1>(-1) && cDiff_1<26){
		return 1;
	}
	else if(cDiff_2>(-1) && cDiff_2<26){
		return 1;
	}
	else{
		return 0;
	}
}
int is_digit(char c){
	int cDiff = c-48;
	if(cDiff>(-1) && cDiff<10){
		return 1;
	}
	else{
		return 0;
	}
}
int is_valid_password(char *password){
	int is_valid = 1;
	if(length_of_password(password)<8){
		printf("The password needs to have at least 8 characters.\n");
		is_valid = 0;
	}

	int n=0,m=0,pwlen=length_of_password(password);
	while(n<pwlen){
		if(is_alpha(password[n])==1){
			break;
		}
		else if(is_alpha(password[n])==0 && n==(pwlen-1)){
			printf("The password needs to contain at least 1 alphabetical character.\n");
			is_valid = 0;
		}
		n++;
	}
	while(m<pwlen){
		if(is_digit(password[m])==1){
			break;
		}
		else if(is_digit(password[m])==0 && m==(pwlen-1)){
			printf("The password needs to contain at least 1 digit.\n");
			is_valid = 0;
		}
		m++;
	}
	return is_valid;
}

void perform_XOR(char *input_filename, char *output_filename, char *password){
	FILE *file, *newFile;
	int i, numBytes;
	char block[length_of_password(password)];
	
	//open orig file and create new file
	file = fopen(input_filename,"rb");
  	newFile = fopen(output_filename,"wb");
	
	//read and xor
	do{
		numBytes = fread(block, 1, length_of_password(password), file);
		for (i=0; i<numBytes; i++){
			block[i] = block[i]^password[i];
		}
		//write
		fwrite(block, 1, numBytes, newFile);
	}while(numBytes == length_of_password(password));
	
	//close orig and new file
	fclose(newFile);
  	fclose(file);
}
void print_first_five(char *filename){
	FILE *file;
	int result;
	char block[5];
	
	file = fopen(filename,"rb");
	fread(block, 1, 5, file);
	
	for(int i=0; i<5; i++){
		result=block[i];
		if(i!=4){
			result=block[i] & 0x000000ff;
		}
		printf("%02x\n",result);
	}
	fclose(file);
}

//System Programming
//Assignment 1
//Marcus Toldo
//Sunday, October 8, 2017

#include <fcntl.h>
#include <unistd.h>

//Function Prototypes
int GetPictureWidth(int);
int PowerFunction(int, int);
int GetPictureHeight(int);
int CombinePhotos(int, int, int, int, int, int);

/*                                                                          /
/   Description: Recieves two .ppm photos as input from the command line    /
/                and calculates their resolutions before combining the two  /
/                photos into a new .ppm file with the same resolutions as   /
/                the larger of the two photos, with the smaller photo       /
/                overlayed in the top righthand corner                      /
/                                                                           /
/   Input: Recoeves two .ppm images as input directly from the command line /
/                                                                           /
/   Output: Main funciton returns error code -1 if the first photo inputted /
/           was smaller in resolution than the second photo. Otherwise      /
/           main returns 0 upon merging the two photos                      /
/                                                                          */
 
int main(int argc, char *argv[]) {

	//Opening pictures for read/writing and reading respectively
	int pic1 = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR);
	int pic2 = open(argv[2], O_RDONLY, S_IRUSR | S_IWUSR | S_IXUSR);


	//Declaring variables to hold the width and height of first and second photo respectively
	int p1w = 0;
	int p1h = 0;

	int p2w = 0;
	int p2h = 0;
	
    //Getting the resolutions, width and height, for each picture respectively
	p1w = GetPictureWidth(pic1);
	p1h = GetPictureHeight(pic1);
    
    p2w = GetPictureWidth(pic2);
    p2h = GetPictureHeight(pic2);
    
    
    //Program exits with code -1 if the first picture entered is smaller than the second picture entered
    if (p1w < p2w || p1h < p2h) {
        return -1;
    }
    
    //Resetting lseek
    lseek(pic1, 0, SEEK_SET);
    lseek(pic2, 0, SEEK_SET);
    
    //Combining the two photos
    CombinePhotos(pic1, pic2, p1w, p1h, p2w, p2h);
	
	return 0;

}

/*  										                                /
/  Description: Function used to find the result of exponential operators	/
/  Input: Recieves two int varaibles as input, base and exponent		    /
/  Output: Returns one int varaivle as result, which is the result	        /
/                                                                          */

int PowerFunction(int base, int exponent) {

	//Declaring int variable for the result
	int result = 1;

	//Opening for loop that multiplies the result by the base for the value of the exponent
	for (int i = exponent; i > 0; i--) {
	
		result = result*base;
	}

	return result; 
}


/*										                                        /
/  Description: Function takes in file descriptor to a .ppm photo document      /
/  		and returns the width of the photo				                        /
/  Input: Recieves an int variable that is the file descriptor		            /
/ Output: Returns a int value that corresponds to the width of the photo        /
/                                                                              */

int GetPictureWidth(int picture) {

	//Declaring int variables to be used
	int pictureWidth = 0;

	int counter = 0;
	int running = 1;
	int test = 0;

	//Opening a for loop to find how many digits there are in the resolution value
	for (int i = 3; running == 1; i++) {

		lseek(picture, i, SEEK_SET);

		read(picture, &test, 1);

        //Check to see if the lseek has hit the ASCII space character (represented by 32)
        //If the program finds a space, terminates the loop, otherwise it increments the number of digits
		if (test == 32) {
			running = 0;
		} else {
			counter++;
		}
	} 

	int hold = 0;
	int j = counter;

    //Opening a for loop that calculates the actual dimension of the photo
    //Subtracts 48 from the ASCII digit value (to get decimal value) and mutiplies it by 10^(position) to put it in its proper number coloumn
	for (int i = counter; i > 0; i--) {	
	
		lseek(picture, i+2, SEEK_SET);
	
		read(picture, &hold, 1);

		hold -= 48;	
		hold = hold*PowerFunction(10, counter-j);
		 
		pictureWidth += hold;

		j--;

	} 

	return pictureWidth;
}

/*                                                                          /
/  Description: Function takes in file descriptor to a .ppm photo document  /
/       and returns the height of the photo                                 /
/  Input: Recieves an int variable that is the file descriptor              /
/  Output: Returns a int value that corresponds to the width of the photo   /
/                                                                          */

int GetPictureHeight(int picture) {

	//Declaring int variables to be used
	int pictureHeight = 0;

	int counter = 0;
	int running = 1;
	int test = 0;
    
    int widthDigits = 0;
    
    //Finding the picture width
    for (int i = 3; running == 1; i++) {
        
        lseek(picture, i, SEEK_SET);
        
        read(picture, &test, 1);
        
        //Check to see if the lseek has hit the ASCII space character (represented by 32)
        //If the program finds a space, terminates the loop, otherwise it increments the number of digits
        if (test == 32) {
            running = 0;
        } else {
            widthDigits++;
        }
    }
    
    //Resetting the running variable to true
    running = 1;

	//Opening a for loop to find how many digits there are in the resolution value
	for (int i = 4+widthDigits; running == 1; i++) {
	
		lseek(picture, i, SEEK_SET);
	
		read(picture, &test, 1);
        
        //Check to see if the lseek has hit the ASCII new line character (represented by 10)
        //If the program finds a new line, terminates the loop, otherwise inrement the counter
		if (test == 10) {
			running = 0;
		} else {
			counter++;
		}
	}
    
	int hold = 0;
	int j = counter;

    //Opening a for loop that calculates the actual dimension of the photo
    //Subtracts 48 from the ASCII digit value (to get decimal value) and mutiplies it by 10^(position) to put it in its proper number coloumn
	for (int i = counter; i > 0; i--) {

		lseek(picture, i+3+widthDigits, SEEK_SET);

		read(picture, &hold, 1);
        
		hold -= 48;
		hold = hold*PowerFunction(10, counter-j);

		pictureHeight += hold;
        
		j--;

	}


	return pictureHeight;

}

/*                                                                              /
/   Desctiption: Function recieves the image files and the dimensions of the    /
/                image files. Creates a new image file with the dimensions of   /
/                the larger image file, and copies the larger image before      /
/                overlaying the smaller image in the top righthand corner       /
/   Input: Recieves 6 integer values corresponding to the two images, and each  /
/          images respective width and height                                   /
/   Output: Function returns 0 upon completion, having created and saved the    /
/           new image file while running.                                       /
/                                                                              */
 
int CombinePhotos(int pic1, int pic2, int p1w, int p1h, int p2w, int p2h) {
    
    //Declaring variables
    int returns = 0;
    int line123Len = 0;
    int temp = 0;
    
    //Creating a new .ppm image file
    int newFile = open("combined.ppm", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
    
    
    //Findign the length of the first 3 lines of the first image file rewrite them to the new file
    int i = 0;
    while (returns != 3) {
        
        lseek(pic1, i, SEEK_SET);
        
        read(pic1, &temp, 1);
        
        if (temp == 10) {
            returns++;
            line123Len++;
        } else {
            line123Len++;
        }
        
        i++;
    }
    
    //Opening a loop to write the first 3 lines to the new file
    for (int i = 0; i < line123Len; i++) {
        
        lseek (pic1, i, SEEK_SET);
        
        read(pic1, &temp, 1);
        
        write(newFile, &temp, 1);
        
    }
    
    //Findign the length of the first 3 lines of the second image file to skip them
    returns = 0;
    int secondLine123Len = 0;
    temp = 0;
    
    i = 0;
    while (returns != 3) {
        
        lseek(pic2, i, SEEK_SET);
        
        read(pic2, &temp, 1);
        
        if (temp == 10) {
            returns++;
            secondLine123Len++;
        } else {
            secondLine123Len++;
        }
        
        i++;
    }
    
    //Opening for loop to begin copying each row of the first image file to the new image file
    for (int i = 0; i < p1h*3; i++) {
        
        int rowOffset = i * p1w;
        
        //For loop to copy p1w to new file
        for (int j = 0; j < p1w; j++) {
            
            temp = 0;
            
            lseek(pic1, line123Len+j+rowOffset, SEEK_SET);
            
            //Copying the first picture onto the new file byte by byte
            read(pic1, &temp, 1);
            write(newFile, &temp, 1);
            
        }
    }
    
    //Second part to overlay smaller photo onto larger photo
    //Resetting lseek
    lseek(newFile, secondLine123Len, SEEK_SET);
    
    //Opening for loop to begin copying second photo
    for (int i = 0; i < p2h; i++) {
        
        lseek(newFile, (p1w-p2w)*3, SEEK_CUR);
        
        //Reading and rewriting second photo onto new photo byte by byte
        for (int j = 0; j < p2w*3; j++) {
            read(pic2, &temp, 1);
            write(newFile, &temp, 1);
        }
        
    }
    
    return 0;
}

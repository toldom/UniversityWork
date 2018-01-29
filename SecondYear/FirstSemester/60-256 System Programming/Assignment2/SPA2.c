//System Programming
//Assignment 2
//Marcus Toldo - 104623006
//Sunday, October 29th, 2017

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

const unsigned char RED[3] = {255, 0, 0};
const unsigned char GREEN[3] = {0, 255, 0};
const unsigned char BLUE[3] = {0, 0, 255};
const unsigned char YELLOW[3] = {255, 255, 0};
const unsigned char ORANGE[3] = {255, 156, 0};
const unsigned char CYAN[3] = {0, 255, 255};
const unsigned char MAGENTA[3] = {255, 0, 255};
const unsigned char OCEAN[3] = {43, 101, 236};
const unsigned char VIOLET[3] = {238, 130, 238};

int main(int argc, char *argv[]) {
    
    unsigned char colour1[3];
    unsigned char colour2[3];
    unsigned char colour3[3];
    unsigned char colour4[3];
    unsigned char colour5[3];
    
    //Getting the name for the new picture file from the command line input
    int nameLenght = strlen(argv[1]);
    char fileName[nameLenght];
    memcpy(fileName, argv[1], nameLenght);
    
    //Degining the colour code for the first colour, based on user input
    if ( strcmp(argv[2], "red") == 0) {
        memcpy(colour1, RED,3);
    } else if (strcmp(argv[2], "green") == 0) {
        memcpy(colour1, GREEN,3);
    } else if (strcmp(argv[2], "blue") == 0) {
        memcpy(colour1, BLUE,3);
    } else if (strcmp(argv[2], "yellow") == 0) {
        memcpy(colour1, YELLOW,3);
    } else if (strcmp(argv[2], "orange") == 0) {
        memcpy(colour1, ORANGE,3);
    } else if (strcmp(argv[2], "cyan") == 0) {
        memcpy(colour1, CYAN,3);
    } else if (strcmp(argv[2], "magenta") == 0) {
        memcpy(colour1, MAGENTA,3);
    } else if (strcmp(argv[2], "ocean") == 0) {
        memcpy(colour1, OCEAN,3);
    } else if (strcmp(argv[2], "violet") == 0) {
        memcpy(colour1, VIOLET,3);
    }
    
    //Degining the colour code for the second colour, based on user input
    if ( strcmp(argv[3], "red") == 0) {
        memcpy(colour2, RED,3);
    } else if (strcmp(argv[3], "green") == 0) {
        memcpy(colour2, GREEN,3);
    } else if (strcmp(argv[3], "blue") == 0) {
        memcpy(colour2, BLUE,3);
    } else if (strcmp(argv[3], "yellow") == 0) {
        memcpy(colour2, YELLOW,3);
    } else if (strcmp(argv[3], "orange") == 0) {
        memcpy(colour2, ORANGE,3);
    } else if (strcmp(argv[3], "cyan") == 0) {
        memcpy(colour2, CYAN,3);
    } else if (strcmp(argv[3], "magenta") == 0) {
        memcpy(colour2, MAGENTA,3);
    } else if (strcmp(argv[3], "ocean") == 0) {
        memcpy(colour2, OCEAN,3);
    } else if (strcmp(argv[3], "violet") == 0) {
        memcpy(colour2, VIOLET,3);
    }
    
    //Degining the colour code for the third colour, based on user input
    if ( strcmp(argv[4], "red") == 0) {
        memcpy(colour3, RED,3);
    } else if (strcmp(argv[4], "green") == 0) {
        memcpy(colour3, GREEN,3);
    } else if (strcmp(argv[4], "blue") == 0) {
        memcpy(colour3, BLUE,3);
    } else if (strcmp(argv[4], "yellow") == 0) {
        memcpy(colour3, YELLOW,3);
    } else if (strcmp(argv[4], "orange") == 0) {
        memcpy(colour3, ORANGE,3);
    } else if (strcmp(argv[4], "cyan") == 0) {
        memcpy(colour3, CYAN,3);
    } else if (strcmp(argv[4], "magenta") == 0) {
        memcpy(colour3, MAGENTA,3);
    } else if (strcmp(argv[4], "ocean") == 0) {
        memcpy(colour3, OCEAN,3);
    } else if (strcmp(argv[4], "violet") == 0) {
        memcpy(colour3, VIOLET,3);
    }
    
    //Degining the colour code for the fourth colour, based on user input
    if ( strcmp(argv[5], "red") == 0) {
        memcpy(colour4, RED,3);
    } else if (strcmp(argv[5], "green") == 0) {
        memcpy(colour4, GREEN,3);
    } else if (strcmp(argv[5], "blue") == 0) {
        memcpy(colour4, BLUE,3);
    } else if (strcmp(argv[5], "yellow") == 0) {
        memcpy(colour4, YELLOW,3);
    } else if (strcmp(argv[5], "orange") == 0) {
        memcpy(colour4, ORANGE,3);
    } else if (strcmp(argv[5], "cyan") == 0) {
        memcpy(colour4, CYAN,3);
    } else if (strcmp(argv[5], "magenta") == 0) {
        memcpy(colour4, MAGENTA,3);
    } else if (strcmp(argv[5], "ocean") == 0) {
        memcpy(colour4, OCEAN,3);
    } else if (strcmp(argv[5], "violet") == 0) {
        memcpy(colour4, VIOLET,3);
    }
    
    //Degining the colour code for the fifth colour, based on user input
    if ( strcmp(argv[6], "red") == 0) {
        memcpy(colour5, RED,3);
    } else if (strcmp(argv[6], "green") == 0) {
        memcpy(colour5, GREEN,3);
    } else if (strcmp(argv[6], "blue") == 0) {
        memcpy(colour5, BLUE,3);
    } else if (strcmp(argv[6], "yellow") == 0) {
        memcpy(colour5, YELLOW,3);
    } else if (strcmp(argv[6], "orange") == 0) {
        memcpy(colour5, ORANGE,3);
    } else if (strcmp(argv[6], "cyan") == 0) {
        memcpy(colour5, CYAN,3);
    } else if (strcmp(argv[6], "magenta") == 0) {
        memcpy(colour5, MAGENTA,3);
    } else if (strcmp(argv[6], "ocean") == 0) {
        memcpy(colour5, OCEAN,3);
    } else if (strcmp(argv[6], "violet") == 0) {
        memcpy(colour5, VIOLET,3);
    }
    
    //No more comments past this point
    
	int fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
    
	char firstThreeLines[] = "P6\n1000 1000\n255\n";	
	write(fd, &firstThreeLines, 17);
    
    lseek(fd, 17, SEEK_SET);
    
    if (fork() == 0) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 1000; j++) {
                if (j < 500) {
                    write(fd, &colour2, 3);
                } else {
                    write(fd, &colour3, 3);
                }
            }
            
        }
        
    } else {
        
        sleep(1);
        
        if (fork() == 0) {
            
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 1000; j++) {
                    if (j < 500) {
                        write(fd, &colour2, 3);
                        
                    } else {
                        write(fd, &colour3, 3);
                    }
                }

            }
        } else {
            
            sleep(1);
            
            if (fork() == 0) {
                for (int i = 0; i < 100; i++) {
                    for (int j = 0; j < 1000; j++) {
                        if (j < 500) {
                            if (i > 50 && j > 500 - (i - 50) && j < 500 + (i - 50)) {
                                write(fd, &colour1, 3);
                            } else {
                                write(fd, &colour2, 3);
                            }
                        } else {
                            if (i > 50 && j > 500 - (i - 50) && j < 500 + (i - 50)) {
                                write(fd, &colour1, 3);
                            } else {
                                write(fd, &colour3, 3);
                            }
                        }
                    }
                }
                } else {
                    
                    sleep (1);
                    
                    if (fork() == 0) {
                        for (int i = 0; i < 100; i++) {
                            for (int j = 0; j < 1000; j++) {
                                if (j < 500) {
                                    if (j > 500-50-i && j < 500+50+i) {
                                        write(fd, &colour1, 3);
                                    } else {
                                        write(fd, &colour2, 3);
                                    }
                                } else {
                                    if (j > 450-i && j < 550+i) {
                                        write(fd, &colour1, 3);
                                    } else {
                                        write(fd, &colour3, 3);
                                    }
                                }
                            }

                        }
                    } else {
                        
                        sleep(1);
                        
                        if (fork() == 0) {
                            for (int i = 0; i < 100; i++) {
                                for (int j = 0; j < 1000; j++) {
                                    if (j < 500) {
                                        if (j > 350-i && j < 650+i) {
                                            write(fd, &colour1, 3);
                                        } else {
                                            write(fd, &colour2, 3);
                                        }
                                    } else {
                                        if (j > 350-i && j < 650+i) {
                                            write(fd, &colour1, 3);
                                        } else {
                                            write(fd, &colour3, 3);
                                        }
                                    }
                                }

                            }
                        } else {
                            
                            sleep(1);
                            
                            if (fork() == 0) {
                                for (int i = 0; i < 100; i++) {
                                    for (int j = 0; j < 1000; j++) {
                                        if (j < 500) {
                                            if (j > 250+i && j < 750-i) {
                                                write(fd, &colour1, 3);
                                            } else {
                                                write(fd, &colour4, 3);
                                            }
                                        } else {
                                            if (j > 250+i && j < 750-i) {
                                                write(fd, &colour1, 3);
                                            } else {
                                                write(fd, &colour5, 3);
                                            }
                                        }
                                    }

                                }
                            } else {
                                sleep(1);
                                
                                if (fork() == 0) {
                                    for (int i = 0; i < 100; i++) {
                                        for (int j = 0; j < 1000; j++) {
                                            if (j < 500) {
                                                if (j > 350+i && j < 650-i) {
                                                    write(fd, &colour1, 3);
                                                } else {
                                                    write(fd, &colour4, 3);
                                                }
                                            } else {
                                                if (j > 350+i && j < 650-i) {
                                                    write(fd, &colour1, 3);
                                                } else {
                                                    write(fd, &colour5, 3);
                                                }
                                            }
                                        }

                                    }
                                } else {
                                    
                                    sleep(1);
                                    
                                    if (fork() == 0) {
                                        for (int i = 0; i < 100; i++) {
                                            for (int j = 0; j < 1000; j++) {
                                                if (j < 500) {
                                                    if (i < 50 && j > 500 + (i - 50) && j < 500 - (i - 50)) {
                                                        write(fd, &colour1, 3);
                                                    } else {
                                                        write(fd, &colour4, 3);
                                                    }
                                                } else {
                                                    if (i < 50 && j > 500 + (i - 50) && j < 500 - (i - 50)) {
                                                        write(fd, &colour1, 3);
                                                    } else {
                                                        write(fd, &colour5, 3);
                                                    }
                                                }
                                            }

                                        }
                                    } else {
                                        sleep(1);
                                        
                                        if (fork() == 0) {
                                            for (int i = 0; i < 100; i++) {
                                                for (int j = 0; j < 1000; j++) {
                                                    if (j < 500) {
                                                        write(fd, &colour4, 3);
                                                    } else {
                                                        write(fd, &colour5, 3);
                                                    }
                                                }
                                            }
                                        } else {
                                            sleep(1);
                                            
                                            if (fork() == 0) {
                                                for (int i = 0; i < 100; i++) {
                                                    for (int j = 0; j < 1000; j++) {
                                                        if (j < 500) {
                                                            write(fd, &colour4, 3);
                                                        } else {
                                                            write(fd, &colour5, 3);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    
    return 0;
}

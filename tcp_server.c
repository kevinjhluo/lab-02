/* A simple server in the internet domain using TCP
 * Answer the questions below in your writeup
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    /* 1. What is argc and *argv[]?
     *argc is the number of argument passed, argv[] is a pointer array that points to all of the arguments passed
     */
    int sockfd, newsockfd, portno;
    /* 2. What is a UNIX file descriptor and file descriptor table?
     * a UNIX file descriptor is used to identify an I/O source, a file descriptor table is used to keep track of open files
     */
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
    /* 3. What is a struct? What's the structure of sockaddr_in?
     * A struct compiles data of different types under a single name. sockaddr_in is consists of two integers, one char, and another struct
     */
    
    int n;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 4. What are the input parameters and return value of socket()
     *The input parameter is the address family of the socket, the type of socket, and the protocol number. The socket function returns an interget that indicates the file descriptor.
     */
    
    if (sockfd < 0) 
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");
    /* 5. What are the input parameters of bind() and listen()?
     *The bind function takes a file descriptor of the socket, a pointer to the sockaddr struct and a size of the serv_addr struct. The listen function takes the file descriptor of the socket and the number of maximum number of incoming parameters as its parameter.
     */
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    while(1) {
        /* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        * While (1) loops the following lines of code forever. There is only one char array handling all of the connection, which might lead to data overwriting when multiple connections happen
        */
        
	    char buffer[256];
            newsockfd = accept(sockfd, 
                        (struct sockaddr *) &cli_addr, 
                        &clilen);
	/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         * fork() duplicates a child process that runs at the same time as the parent process, allowing the handling of multiple connections by running the same process.
         */
        
	if (newsockfd < 0) 
             error("ERROR on accept");
	bzero(buffer,256);
        
	n = read(newsockfd,buffer,255);
        if (n < 0) 
            error("ERROR reading from socket");
        printf("Here is the message: %s\n",buffer);
        n = write(newsockfd,"I got your message",18);
        if (n < 0) 
            error("ERROR writing to socket");
        close(newsockfd);
    }
    close(sockfd);
    return 0; 
}
  
/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
 * A system call is a way for the program to requests a service that requries privlege from the operating system.
 */

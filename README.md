# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Kevin Luo
## Lab Question Answers

Answer for Question 1: 
When a 50% loss was added to UDP, half of our data wasn't transmitted because UDP doesn't make an effort to retrieve lost data.

Answer for Question 2:
When the loss is added to TCP. all of the data is still correct transmitted in order to the host, this is because TCP actively sends out signals that ensures all data are correctly received.

Answer for Question 3:
When a loss is added, there is a significant delay to the response, this is due to the time it takes for TCP to track all lost packages and receive them accordingly.

 1. What is argc and *argv[]?
     argc is the number of argument passed, argv[] is a pointer array that points to all of the arguments passed

 2. What is a UNIX file descriptor and file descriptor table?
      a UNIX file descriptor is used to identify an I/O source, a file descriptor table is used to keep track of open files

 3. What is a struct? What's the structure of sockaddr_in?
      A struct compiles data of different types under a single name. sockaddr_in is consists of two integers, one char, and another struct

 4. What are the input parameters and return value of socket()
     The input parameter is the address family of the socket, the type of socket, and the protocol number. The socket function returns an interget that indicates the file descriptor.
    
5. What are the input parameters of bind() and listen()?
   The bind function takes a file descriptor of the socket, a pointer to the sockaddr struct and a size of the serv_addr struct. The listen function takes the file descriptor of the socket and the number of maximum number of incoming parameters as its parameter.
   
 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
     While (1) loops the following lines of code forever. There is only one char array handling all of the connection, which might lead to data overwriting when multiple connections happen

7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
     fork() duplicates a child process that runs at the same time as the parent process, allowing the handling of multiple connections by running the same process.

8. This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
   A system call is a way for the program to requests a service that requries privlege from the operating system.


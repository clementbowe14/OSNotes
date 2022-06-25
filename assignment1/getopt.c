#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    extern char *optarg;
    extern int optind;
    int c, err = 0;
    int nflag = 0, kflag = 0, dflag = 0, vflag = 0, oflag = 0;
    int numProcess = 0, timeInterval = 0, CPUTimes = 0, stdDev = 0;
    char *oname = "Default_File";
    static char usage[] = "Usage: main [-n number of processes][-k time interval a process may arrive][-d mean total CPU time][-v standard deviation][-o output_file_name][input_file_name]\n";

    while ((c = getopt(argc, argv, "n:k:d:v:o:")) != -1)
      switch (c)
      {
        case 'n': // number of processes
		    nflag = 1;
            numProcess = atoi(optarg);
            break;
        case 'k': // the time interval during which processes may arrive
            kflag = 1;
            timeInterval = atoi(optarg);
            break;
        case 'd': // The mean of total CPU times 
            dflag = 1;
            CPUTimes = atoi(optarg);
            break;
        case 'v': // The standard deviation of CPU times 
            vflag = 1;
            stdDev = atoi(optarg);
            break;    
        case 'o': // an output file was chosen
            oflag = 1;
            oname = optarg; // name of the file
            break;
        default: // an error occured
            fprintf(stderr, usage, argv[0]); // print usage statement
            exit(1); // end the program
            break;
	    } // end of switch
    printf("nflag=%d; kflag=%d; dflag=%d; vflag=%d; oflag=%d\n", nflag, kflag, dflag, vflag, oflag);
    printf("numProcess=%d; timeInterval=%d; CPUTimes=%d; stdDev=%d; oname=%s\n", numProcess, timeInterval, CPUTimes, stdDev, oname);

    if (optind >= argc) 
    {
      fprintf(stderr, "Expected argument after options\n");
      exit(EXIT_FAILURE);
    }

    if (optind < argc) // if there is an input file
    {
      for (; optind < argc; optind++)
      {
      }
    } // end of if
    else // if there is no input file there should be a while loop here that listens to user input
    {
    } // end of else
  exit(0);
} // end of program

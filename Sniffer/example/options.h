/*
 * PacMan - Packet Manipulation Library 
 * Copyright © 2008  Jeff Scaparra, Gaurav Yadav, Andrie Tanusetiawan
 *
 * This file is a part of PacMan.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef _CUSTOM_OPTIONS_
#define _CUSTOM_OPTIONS_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>

#define MAX_FILENAME_SIZE   256

class options
{
    private:
        char pcapDev[MAX_FILENAME_SIZE];
        char inputPcapFile[MAX_FILENAME_SIZE];
        char outputPcapFile[MAX_FILENAME_SIZE];
        char filter[MAX_FILENAME_SIZE];
    public:
        bool is_pcapDev;
        bool is_inputPcapFile;
        bool is_outputPcapFile;
        bool is_filter;
		bool is_ls;
        options()
		{
			is_pcapDev = false;
			is_inputPcapFile = false;
			is_outputPcapFile = false;
			is_filter = false;
			is_ls = false;
		}

		bool is_test_proper()
		{
			if(!is_pcapDev)
			{
				printf("\nMissing argument --config\n");
				return 0;
			}
			return 1;
		}

		bool is_main_proper()
		{
		}

		char* get_pcapDev()
		{
			if(is_pcapDev)
				return pcapDev;
			return NULL;
		}

		char* get_inputPcapFile()
		{
			if(inputPcapFile)
				return inputPcapFile;
			return NULL;
		}

		char* get_outputPcapFile()
		{
			if(outputPcapFile)
				return outputPcapFile;
			return NULL;
		}

		char* get_filter()
		{
			if(is_filter)
				return filter;
			return NULL;
		}

		void set_pcapDev(char *optarg)
		{
			strcpy(pcapDev,optarg );
		}

		void set_inputPcapFile(char *optarg)
		{
			strcpy(inputPcapFile, optarg);
		}

		void set_outputPcapFile(char *optarg)
		{
			strcpy(outputPcapFile, optarg);
		}

		void set_filter(char *optarg)
		{
			strcpy(filter, optarg);
		}


		virtual void get_options(int argc, char **argv)
		{
			if(argc==0)
				printf("\nUse \"--help\" for the input arguments");

			int c;
			int option_index = 0;

			static struct option long_options[] = {
				{"help",      0, 0, 'a'},
				{"pcapDev",      1, 0, 'b'},
				{"inputPcapFile",        1, 0, 'c'},
				{"outputPcapFile",      1, 0, 'd'},
				{"filter",   1, 0, 'e'},
				{"ls",   2, 0, 'f'},
				{0, 0, 0, 0}
			};

			while (1)
			{
				c = getopt_long(argc, argv, "abcdef", long_options, &option_index);
				if (c == -1)
					break;

				switch (c)
				{
					case 'a':
						printf("Usage: %s <options>\n\n", argv[0]);
						printf("--help\t\t- print tcpDump options\n");
						printf("--pcapDev\t<pcap device name>\n");
						printf("--filter\t<expression for filtering packets>\n");
						printf("--inputPcapFile\t<pcap file path>\n");
						printf("--outputPcapFile\t\t<ouput pcap file pathListenPort>\n");
						printf("--ls\t\t<to print all the available devices>\n");
						exit(0);
						break;

					case 'b':   
						is_pcapDev = true;
						set_pcapDev(optarg);
						break; 

					case 'c':   
						is_inputPcapFile = true;
						set_inputPcapFile(optarg);
						break;

					case 'd':
						is_outputPcapFile = true;
						set_outputPcapFile(optarg);
						break;

					case 'e':
						is_filter = true;
						set_filter(optarg);
						break;

					case 'f':
						is_ls = true;
						break;

					default:
						break;
				}
			}
		}

		virtual void print_options()
		{
			if(is_pcapDev)
				printf("\npcapDev : %s\n", pcapDev);
			if(is_inputPcapFile)
				printf("inputPcapFile : %s\n", inputPcapFile);
			if(is_outputPcapFile)
				printf("outputPcapFile : %s\n",  outputPcapFile);
			if(is_filter)
				printf("filter: %s\n", filter);
		}
};
#endif

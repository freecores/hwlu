/* Filename: gen_priority_encoder.c */
/* Description: Generates priority_encoder module */
/* Author: Nikos Kavvadias, <nkavv@skiathos.physics.auth.gr> */
/* Date: Friday, 09/04/2004 */

#include <stdio.h>
#include <stdlib.h>   
#include <time.h>                                  

#define PRINT_DEBUG

                       
// FUNCTION PROTOTYPES 
void write_file_priority_encoder(FILE *outfile);
unsigned dectobin(unsigned bin_data, int num_bits);
unsigned ipow(unsigned x, unsigned y);
unsigned log2(unsigned operand);
void print_binary_value(FILE *outfile, int i);
void print_binary_value_fbone(FILE *outfile, int i);


FILE *file_priority_encoder; /* VHDL source for the priority_encoder module of the 
                              * hw_looping unit (priority_encoder.vhd) */

char priority_encoder_file_name[32];
int nlp;
time_t t;


int main(int argc, char **argv) 
{ 
  int i;
  int gen_priority_encoder_file;
  char nlp_s[3];
  
  gen_priority_encoder_file = 0;
      
  if( argc < 3 )
  {
    printf("Usage: gen_priority_encoder <num loops> <output base>\n"); 
    printf("where:\n");                     
    printf("num loops   = give number of supported loops\n");
    printf("output base = output file base name. The generated files will be named:\n");
    printf("              \"<output base>.vhd\" for the module\n");
    //
    printf("\n");
    //
    return -1;
  }
  
  // Acquire number of supported loops
  strcpy(nlp_s,argv[1]);
  nlp = atoi(nlp_s);
                             
  // Filenames for the requested VHDL source files
  sprintf(priority_encoder_file_name,"%s_loops%s%s", argv[2], nlp_s, ".vhd");
  gen_priority_encoder_file = 1;                
    
    
  // DEBUG OUTPUT      
  #ifdef PRINT_DEBUG
    printf("\n");
    //
    printf("nlp = %d\n",nlp);
    printf("priority_encoder_file_name = %s\n", priority_encoder_file_name);
    //
  #endif        
    

  /******************************************************/
  /* Generate VHDL source for the priority_encoder unit */
  /******************************************************/
  if (gen_priority_encoder_file == 1)
  {
    file_priority_encoder = fopen(priority_encoder_file_name,"w");                            
    write_file_priority_encoder(file_priority_encoder);
    fclose(file_priority_encoder);
  }          

  return 0;

}	
		

void write_file_priority_encoder(
                      FILE *outfile     // Name for the output file -- e.g. mbloop_merger.vhd 
                     )
{
  int i;    
  
  // Get current time
  time(&t);            

  /* Generate interface for the VHDL file */
  fprintf(outfile,"----==============================================================----\n");
  fprintf(outfile,"----                                                              ----\n"); 
  fprintf(outfile,"---- Filename: %s                                   ----\n", priority_encoder_file_name);
  fprintf(outfile,"---- Module description: Priority encoder unit. Obtains           ----\n"); 
  fprintf(outfile,"----        increment and reset decisions for the loop indices.   ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- Author: Nikolaos Kavvadias                                   ----\n");
  fprintf(outfile,"----         nkavv@skiathos.physics.auth.gr                       ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- Part of the hwlu OPENCORES project generated automatically   ----\n");
  fprintf(outfile,"---- with the use of the \"gen_priority_encoder\" tool              ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- To Do:                                                       ----\n");
  fprintf(outfile,"----         Considered stable for the time being                 ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- Author: Nikolaos Kavvadias                                   ----\n");
  fprintf(outfile,"----         nkavv@skiathos.physics.auth.gr                       ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"----==============================================================----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- Copyright (C) 2004 Nikolaos Kavvadias                        ----\n");
  fprintf(outfile,"----                    nick-kavi.8m.com                          ----\n");
  fprintf(outfile,"----                    nkavv@skiathos.physics.auth.gr            ----\n");
  fprintf(outfile,"----                    nick_ka_vi@hotmail.com                    ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- This source file may be used and distributed without         ----\n");
  fprintf(outfile,"---- restriction provided that this copyright statement is not    ----\n");
  fprintf(outfile,"---- removed from the file and that any derivative work contains  ----\n");
  fprintf(outfile,"---- the original copyright notice and the associated disclaimer. ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- This source file is free software; you can redistribute it   ----\n");
  fprintf(outfile,"---- and/or modify it under the terms of the GNU Lesser General   ----\n");
  fprintf(outfile,"---- Public License as published by the Free Software Foundation; ----\n");
  fprintf(outfile,"---- either version 2.1 of the License, or (at your option) any   ----\n");
  fprintf(outfile,"---- later version.                                               ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- This source is distributed in the hope that it will be       ----\n");
  fprintf(outfile,"---- useful, but WITHOUT ANY WARRANTY; without even the implied   ----\n");
  fprintf(outfile,"---- warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      ----\n");
  fprintf(outfile,"---- PURPOSE. See the GNU Lesser General Public License for more  ----\n");
  fprintf(outfile,"---- details.                                                     ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- You should have received a copy of the GNU Lesser General    ----\n");
  fprintf(outfile,"---- Public License along with this source; if not, download it   ----\n");
  fprintf(outfile,"---- from <http://www.opencores.org/lgpl.shtml>                   ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"----==============================================================----\n");
  fprintf(outfile,"--\n");                            
  fprintf(outfile,"-- CVS Revision History\n");
  fprintf(outfile,"--\n");   
  fprintf(outfile,"\n");   
  
  /* Code generation for library inclusions */
  fprintf(outfile,"library IEEE;\n");
  fprintf(outfile,"use IEEE.std_logic_1164.all;\n");
  fprintf(outfile,"use IEEE.std_logic_unsigned.all;\n");
  fprintf(outfile,"\n");

  /* Generate entity declaration */
  fprintf(outfile,"entity priority_encoder is\n");					  
  fprintf(outfile,"\tgeneric (\n");					  
  fprintf(outfile,"\t\tNLP : integer := %d\n", nlp);					  					  
  fprintf(outfile,"\t);\n");					  
  fprintf(outfile,"\tport (\n");
  fprintf(outfile,"\t\tflag           : in std_logic_vector(NLP-1 downto 0);\n");
  fprintf(outfile,"\t\ttask_loop%d_end : in std_logic;\n", nlp);
  fprintf(outfile,"\t\tincl           : out std_logic_vector(NLP-1 downto 0);\n");
  fprintf(outfile,"\t\treset_vct      : out std_logic_vector(NLP-1 downto 0);\n");
  fprintf(outfile,"\t\tloops_end      : out std_logic\n");
  fprintf(outfile,"\t);\n");					  
  fprintf(outfile,"end priority_encoder;\n");
  fprintf(outfile,"\n");

  /* Generate architecture declaration */
  fprintf(outfile,"architecture rtl of priority_encoder is\n");					  
  
  /* Add component declarations here if needed */  	
       
  /* Add signal declarations here if needed */  	
  
  /* Continue with the rest of the architecture declaration */				  
  fprintf(outfile,"begin\n");
  fprintf(outfile,"\n");					  					  
  
  fprintf(outfile,"\t-- Fully-nested loop structure with %d loops\n", nlp);
  fprintf(outfile,"\t-- From outer to inner: ");
  //                                               
  i = nlp-1;
  fprintf(outfile,"%d", nlp-1);
  //
  if (nlp>=2)
  {                          
    for (i=nlp-2; i>=0; i--)
      fprintf(outfile,"-> %d",i);
  }   
  //
  fprintf(outfile,"\n");
  
  // Loop counter
  i = nlp-1;
  
  /********************/
  /* GENERATE process */
  /********************/
  
  fprintf(outfile,"\tprocess (flag, task_loop5_end)\n");
  fprintf(outfile,"\tbegin\n");
  fprintf(outfile,"\t\t--\n");
  fprintf(outfile,"\t\t-- if loop%d is terminating:\n", i);
  fprintf(outfile,"\t\t-- reset loops %d-%d to initial index\n", i, 0);
  //
  fprintf(outfile,"\t\tif (flag(%d downto 0) = \"", i);
  print_binary_value_fbone( outfile, ipow(2,i+1)-1 );           
  fprintf(outfile,"\") then\n");
  //
  fprintf(outfile,"\t\t\tincl <= \"");
  print_binary_value( outfile, 0 );           
  fprintf(outfile,"\";\n");
  //                 
  fprintf(outfile,"\t\t\treset_vct <= \"");
  print_binary_value( outfile, ipow(2,i+1)-1 );           
  fprintf(outfile,"\";\n");
  //                 
  fprintf(outfile,"\t\t\tloops_end <= '1';\n");
  
  // Loop on all "elsif" cases: i=2 -> i=nlp                 
  for (i=nlp-2; i>=0; i--)
  {
    fprintf(outfile,"\t\t-- else if loop%d is terminating:\n", i);
    fprintf(outfile,"\t\t-- 1. increment loop%d index\n", i+1);
    fprintf(outfile,"\t\t-- 2. reset loop%d to initial index\n", i);
    //    
    fprintf(outfile,"\t\telsif (flag(%d downto 0) = \"", i);
    print_binary_value_fbone( outfile, ipow(2,i+1)-1 );           
    fprintf(outfile,"\") then\n");
    //
    fprintf(outfile,"\t\t\tincl <= \"");
    print_binary_value( outfile, ipow(2,i+1) );           
    fprintf(outfile,"\";\n");
    //
    fprintf(outfile,"\t\t\treset_vct <= \"");
    print_binary_value( outfile, ipow(2,i+1)-1 );           
    fprintf(outfile,"\";\n");
    //
    fprintf(outfile,"\t\t\tloops_end <= '0';\n");
  }                                       
  
  // Else increment inner loop                 
  fprintf(outfile,"\t\t-- else increment loop%d index\n", i);
  fprintf(outfile,"\t\telse\n");
  //                          
  fprintf(outfile,"\t\t\treset_vct <= \"");
  print_binary_value( outfile, 0 );           
  fprintf(outfile,"\";\n");
  // 
  fprintf(outfile,"\t\t\tloops_end <= '0';\n");                       
  //
  fprintf(outfile,"\t\t\tif (task_loop%d_end = '1') then\n", nlp);
  fprintf(outfile,"\t\t\t\tincl <= \"");
  print_binary_value( outfile, ipow(2,i+1) );           
  fprintf(outfile,"\";\n");                                       
  fprintf(outfile,"\t\t\telse\n");
  fprintf(outfile,"\t\t\t\tincl <= \"");
  print_binary_value( outfile, 0 );           
  fprintf(outfile,"\";\n");     
  fprintf(outfile,"\t\t\tend if;\n");                       
  //                    
  fprintf(outfile,"\t\tend if;\n");                       
  fprintf(outfile,"\tend process;\n");                       
  fprintf(outfile,"\n");					  					  
  //
  fprintf(outfile,"end rtl;\n");                                                  
  
}
     
     
unsigned dectobin(unsigned bin_data, int num_bits)
{
   int count;
   unsigned MASK;
   unsigned result;                                         
   unsigned result_arr[100];    
   
   count = num_bits;
   MASK = 1<<(count-1);
 
   result = 0;

   for (count=num_bits-1; count>-1; count--)
   {
     result_arr[count] = (( bin_data & MASK ) ? 1 : 0 );
     bin_data <<= 1;
   }                
   
   for (count=num_bits-1; count>-1; count--)
     result = ipow(10,count)*result_arr[count] + result;

   return result;
}      


unsigned ipow(unsigned x, unsigned y)
{   
  unsigned i;       
  unsigned result;
  
  result = 1;

  for (i=1; i<=y; i++)
    result = result*x;
    
  return result;
}     
          

/* log2 function for integers: unsigned log2(unsigned operand) */
unsigned log2(unsigned operand)
{
	unsigned temp;
	unsigned log_val;

	temp = operand-1;
	//temp = operand;
	log_val = 0;

	while (temp > 0)
	{
		temp = temp/2;
		log_val = log_val + 1;
	}

	return log_val;
}         

void print_binary_value(FILE *outfile, int i)
{
  // Print integer value
  switch (nlp)
  {                                       
    case 1:
      fprintf(outfile,"%d",dectobin( i, nlp ));
      break;
    case 2:
      fprintf(outfile,"%02d",dectobin( i, nlp ));
      break;
    case 3:
      fprintf(outfile,"%03d",dectobin( i, nlp ));
      break;
    case 4:
      fprintf(outfile,"%04d",dectobin( i, nlp ));
      break;
    case 5:
      fprintf(outfile,"%05d",dectobin( i, nlp ));
      break;
    case 6:
      fprintf(outfile,"%06d",dectobin( i, nlp ));
      break;
    case 7:
      fprintf(outfile,"%07d",dectobin( i, nlp ));
      break;
    case 8:
      fprintf(outfile,"%08d",dectobin( i, nlp ));
      break;
    case 9:                                  
      fprintf(outfile,"%09d",dectobin( i, nlp ));
      break;
    case 10:
      fprintf(outfile,"%10d",dectobin( i, nlp ));
      break;
    case 11:
      fprintf(outfile,"%11d",dectobin( i, nlp ));
      break;
    case 12:
      fprintf(outfile,"%12d",dectobin( i, nlp ));
      break;
    case 13:
      fprintf(outfile,"%13d",dectobin( i, nlp ));
      break;
    case 14:
      fprintf(outfile,"%14d",dectobin( i, nlp ));
      break;
    case 15:
      fprintf(outfile,"%15d",dectobin( i, nlp ));
      break;
    case 16:
      fprintf(outfile,"%16d",dectobin( i, nlp ));
      break;
    default:
      break;
  }
}  

// Print binary value -- First bit is "one".
void print_binary_value_fbone(FILE *outfile, int i)
{
  // Print integer value
  switch ( log2(i) )
  {                                       
    // i = 1
    case 0:
      fprintf(outfile,"%d",dectobin( i, i ));
      break;
    // i = 2:3
    case 1:
      fprintf(outfile,"%d",dectobin( i, log2(i) ));
      break;
    // i = 4:7 
    case 2:
      fprintf(outfile,"%02d",dectobin( i, log2(i) ));
      break;
    // i = 8:15
    case 3:
      fprintf(outfile,"%03d",dectobin( i, log2(i) ));
      break;
    // i = 16:31
    case 4:
      fprintf(outfile,"%04d",dectobin( i, log2(i) ));
      break;
    // i = 32:63
    case 5:
      fprintf(outfile,"%05d",dectobin( i, log2(i) ));
      break;
    default:
      break;
  }
}  
  
  
   
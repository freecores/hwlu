/* Filename: gen_hw_looping.c */
/* Description: Generates top-level module for the hw_looping unit */
/* Author: Nikos Kavvadias, <nkavv@skiathos.physics.auth.gr> */
/* Date: Friday, 09/04/2004 */

#include <stdio.h>
#include <stdlib.h>   
#include <time.h>                                  

#define PRINT_DEBUG

                       
// FUNCTION PROTOTYPES 
void write_file_hw_looping(FILE *outfile);

FILE *file_hw_looping; /* VHDL source for the top-level module of the 
                        * hw_looping unit (hw_looping.vhd) */

char hw_looping_file_name[32];
int nlp;
time_t t;


int main(int argc, char **argv) 
{ 
  int i;
  int gen_hw_looping_file;
  char nlp_s[3];
  
  gen_hw_looping_file = 0;
      
  if( argc < 3 )
  {
    printf("Usage: gen_hw_looping <num loops> <output base>\n"); 
    printf("where:\n");                     
    printf("num loops   = give number of supported loops\n");
    printf("output base = output file base name. The generated files will be named:\n");
    printf("              \"<output base>_top.vhd\" for the top-level module\n");
    //
    printf("\n");
    //
    return -1;
  }
  
  // Acquire number of supported loops
  strcpy(nlp_s,argv[1]);
  nlp = atoi(nlp_s);                 
  
  // Generate hw_looping_file_name 
  // (indicating the number of loops supported)
                             
  // Filenames for the requested VHDL source files
  //strcpy(hw_looping_file_name,argv[2]);
  //strcat(hw_looping_file_name,nlp_s);
  //strcat(hw_looping_file_name,"_top.vhd");
  sprintf(hw_looping_file_name,"%s_loops%s%s", argv[2], nlp_s, "_top.vhd");
  gen_hw_looping_file = 1;
    
  // DEBUG OUTPUT      
  #ifdef PRINT_DEBUG
    printf("\n");
    //
    printf("nlp = %d\n",nlp);
    printf("hw_looping_file_name = %s\n", hw_looping_file_name);
    //
  #endif        
    
                                                      
  /*************************************************************/
  /* Generate VHDL source for the top-level unit of hw_looping */
  /*************************************************************/
  if (gen_hw_looping_file == 1)
  {
    file_hw_looping = fopen(hw_looping_file_name,"w");                            
    write_file_hw_looping(file_hw_looping);
    fclose(file_hw_looping);
  }          

  return 0;

}	
		

void write_file_hw_looping(
                      FILE *outfile     // Name for the output file 
                     )
{
  unsigned i;    
  
  // Get current time
  time(&t);            

  /* Generate interface for the VHDL file */
  fprintf(outfile,"----==============================================================----\n");
  fprintf(outfile,"----                                                              ----\n"); 
  fprintf(outfile,"---- Filename: %s                                  ----\n", hw_looping_file_name);
  fprintf(outfile,"---- Module description: Top-level file for the hw_looping unit.  ----\n");
  fprintf(outfile,"----                     Also implements input and output         ----\n");
  fprintf(outfile,"----                     wrapping operations.                     ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- Author: Nikolaos Kavvadias                                   ----\n");
  fprintf(outfile,"----         nkavv@skiathos.physics.auth.gr                       ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"----                                                              ----\n");
  fprintf(outfile,"---- Part of the hwlu OPENCORES project generated automatically   ----\n");
  fprintf(outfile,"---- with the use of the \"gen_hw_looping\" tool                    ----\n");
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
  fprintf(outfile,"\n");

  /* Generate entity declaration */
  fprintf(outfile,"entity hw_looping is\n");					  
  fprintf(outfile,"\tgeneric (\n");					  
  fprintf(outfile,"\t\tDW  : integer := 8;\n");					  					  
  fprintf(outfile,"\t\tNLP : integer := %d\n", nlp);					  					  
  fprintf(outfile,"\t);\n");					  
  fprintf(outfile,"\tport (\n");
  fprintf(outfile,  "\t\tclk            : in std_logic;\n");
  fprintf(outfile,  "\t\treset          : in std_logic;\n");
  fprintf(outfile,  "\t\ttask_loop%d_end : in std_logic;\n", nlp);
  //
  for (i=1; i<=nlp; i++)
    fprintf(outfile,"\t\tloop%d_count    : in std_logic_vector(DW-1 downto 0);\n", i);
  //					    
  for (i=1; i<=nlp; i++)                   
  {
    fprintf(outfile,"\t\tindex%d         : out std_logic_vector(DW-1 downto 0);\n", i);    
  } 
  //
  fprintf(outfile,  "\t\tloops_end      : out std_logic\n"); 					  
  //
  fprintf(outfile,"\t);\n");					  
  fprintf(outfile,"end hw_looping;\n");
  fprintf(outfile,"\n");

  /* Generate architecture declaration */
  fprintf(outfile,"architecture structural of hw_looping is\n");					  
  
  /* Add component declarations here if needed */  	
  fprintf(outfile,"--\n");
  fprintf(outfile,"-- Component declarations\n");
  fprintf(outfile,"component cmpeq\n");
  fprintf(outfile,"\tgeneric (\n");
  fprintf(outfile,"\t\tDW : integer := 8\n");
  fprintf(outfile,"\t);\n");
  fprintf(outfile,"\tport (\n");
  fprintf(outfile,"\t\ta      : in std_logic_vector(DW-1 downto 0);\n");
  fprintf(outfile,"\t\tb      : in std_logic_vector(DW-1 downto 0);\n");
  fprintf(outfile,"\t\treset  : in std_logic;\n");
  fprintf(outfile,"\t\ta_eq_b : out std_logic\n");
  fprintf(outfile,"\t);\n");
  fprintf(outfile,"end component;\n");
  //
  fprintf(outfile,"--\n");
  fprintf(outfile,"component index_inc\n");
  fprintf(outfile,"\tgeneric (\n");
  fprintf(outfile,"\t\tDW : integer := 8\n");
  fprintf(outfile,"\t);\n");
  fprintf(outfile,"\tport (\n");
  fprintf(outfile,"\t\tclk            : in std_logic;\n");
  fprintf(outfile,"\t\treset          : in std_logic;\n");
  fprintf(outfile,"\t\tinc_en         : in std_logic;\n");
  fprintf(outfile,"\t\tindex_plus_one : out std_logic_vector(DW-1 downto 0);\n");
  fprintf(outfile,"\t\tindex_out      : out std_logic_vector(DW-1 downto 0)\n");
  fprintf(outfile,"\t);\n");
  fprintf(outfile,"end component;\n");
  //                                  
  fprintf(outfile,"--\n");
  fprintf(outfile,"component priority_encoder\n");
  fprintf(outfile,"\tgeneric (\n");
  fprintf(outfile,"\t\tNLP : integer := 5\n");
  fprintf(outfile,"\t);\n");
  fprintf(outfile,"\tport (\n");
  fprintf(outfile,"\t\tflag           : in std_logic_vector(NLP-1 downto 0);\n");
  fprintf(outfile,"\t\ttask_loop%d_end : in std_logic;\n", nlp);
  fprintf(outfile,"\t\tincl           : out std_logic_vector(NLP-1 downto 0);\n");
  fprintf(outfile,"\t\treset_vct      : out std_logic_vector(NLP-1 downto 0);\n");
  fprintf(outfile,"\t\tloops_end      : out std_logic\n");
  fprintf(outfile,"\t);\n");
  fprintf(outfile,"end component;\n");
    
  /* Add signal declarations here if needed */  	
  fprintf(outfile,"--\n");
  fprintf(outfile,"-- Signal declarations\n");
  // flag
  fprintf(outfile,"signal flag                : std_logic_vector(NLP-1 downto 0);\n");
  // incl
  fprintf(outfile,"signal incl                : std_logic_vector(NLP-1 downto 0);\n");
  // temp_loop_count
  fprintf(outfile,"signal temp_loop_count     : std_logic_vector(NLP*DW-1 downto 0);\n");
  // temp_index
  fprintf(outfile,"signal temp_index          : std_logic_vector(NLP*DW-1 downto 0);\n");
  // temp_index_plus_one
  fprintf(outfile,"signal temp_index_plus_one : std_logic_vector(NLP*DW-1 downto 0);\n");
  // temp_vct_penc
  fprintf(outfile,"signal reset_vct_penc      : std_logic_vector(NLP-1 downto 0);\n");
  // temp_index
  fprintf(outfile,"signal reset_vct_ix        : std_logic_vector(NLP-1 downto 0);\n");
  fprintf(outfile,"--\n");
  
  /* Continue with the rest of the architecture declaration */				  
  fprintf(outfile,"begin\n");
  fprintf(outfile,"\n");					  					  
  
  /***************************************/
  /* GENERATE INPUT WRAPPING ASSIGNMENTS */
  /***************************************/
    
  /* Iterate through all loops */
  for (i=1; i<=nlp; i++)
  {
    /* Generate assignment code */
    fprintf(outfile,"\ttemp_loop_count( ((NLP-%d)*DW-1) downto ((NLP-%d)*DW) ) <= loop%d_count;\n", 
            i-1, i, i);
  }                                   
  fprintf(outfile,"\n");					  					  
  
  /***************************************/
  /* GENERATE INTERNAL HW_LOOPING MODULE */
  /***************************************/
  
  // Generate cmpeq modules
  fprintf(outfile,"\tGEN_COMPARATORS: for i in 0 to NLP-1 generate\n");
  fprintf(outfile,"\t\tU_cmp : cmpeq\n");
  fprintf(outfile,"\t\t\tgeneric map (\n");
  fprintf(outfile,"\t\t\t\tDW => DW\n");
  fprintf(outfile,"\t\t\t)\n");
  fprintf(outfile,"\t\t\tport map (\n");
  fprintf(outfile,"\t\t\t\ta => temp_index_plus_one( ((i+1)*DW-1) downto (i*DW) ),\n");
  fprintf(outfile,"\t\t\t\tb => temp_loop_count( ((i+1)*DW-1) downto (i*DW) ),\n");
  fprintf(outfile,"\t\t\t\treset => reset,\n");
  fprintf(outfile,"\t\t\t\ta_eq_b => flag(i)\n");
  fprintf(outfile,"\t\t\t);\n");
  fprintf(outfile,"\tend generate GEN_COMPARATORS;\n");
  fprintf(outfile,"\n");					  					  
  
  // Generate priority encoder                         
  fprintf(outfile,"\tU_priority_enc : priority_encoder\n");
  fprintf(outfile,"\t\tgeneric map (\n");
  fprintf(outfile,"\t\t\tNLP => NLP\n");
  fprintf(outfile,"\t\t)\n");
  fprintf(outfile,"\t\tport map (\n");
  fprintf(outfile,"\t\t\tflag => flag,\n");
  fprintf(outfile,"\t\t\ttask_loop5_end => task_loop5_end,\n");
  fprintf(outfile,"\t\t\tincl => incl,\n");
  fprintf(outfile,"\t\t\treset_vct => reset_vct_penc,\n");
  fprintf(outfile,"\t\t\tloops_end => loops_end\n");
  fprintf(outfile,"\t\t);\n");
  fprintf(outfile,"\n");					  					  
  
  // Generate reset_vct_ix
  fprintf(outfile,"\tGEN_RESET_SEL: for i in 0 to NLP-1 generate\n");
  fprintf(outfile,"\t\treset_vct_ix(i) <= reset_vct_penc(i) or reset;\n");
  fprintf(outfile,"\tend generate GEN_RESET_SEL;\n"); 
  fprintf(outfile,"\n");					  					  
  
  // Generate index_inc modules
  fprintf(outfile,"\tGEN_INC_IX: for i in 0 to NLP-1 generate\n");
  fprintf(outfile,"\t\tU_inc_ix1 : index_inc\n");
  fprintf(outfile,"\t\t\tgeneric map (\n");
  fprintf(outfile,"\t\t\t\tDW => DW\n");
  fprintf(outfile,"\t\t\t)\n");
  fprintf(outfile,"\t\t\tport map (\n");
  fprintf(outfile,"\t\t\t\tclk => clk,\n");
  fprintf(outfile,"\t\t\t\treset => reset_vct_ix(i),\n");
  fprintf(outfile,"\t\t\t\tinc_en => incl(i),\n");
  fprintf(outfile,"\t\t\t\tindex_plus_one => temp_index_plus_one( ((i+1)*DW-1) downto (i*DW) ),\n");
  fprintf(outfile,"\t\t\t\tindex_out => temp_index( ((i+1)*DW-1) downto (i*DW) )\n");
  fprintf(outfile,"\t\t\t);\n");
  fprintf(outfile,"\tend generate GEN_INC_IX;\n"); 
  fprintf(outfile,"\n");					  					  
  
  /****************************************/
  /* GENERATE OUTPUT WRAPPING ASSIGNMENTS */
  /****************************************/
  
  /* Iterate through all loops */
  for (i=1; i<=nlp; i++)
  {
    /* Generate assignment code */
    fprintf(outfile,"\tindex%d <= temp_index( ((NLP-%d)*DW-1) downto ((NLP-%d)*DW) );\n", i, i-1, i);    
  }
  fprintf(outfile,"\n");					  					  
  
  //
  fprintf(outfile,"end structural;\n");                                                  
  
}
      
//Kristopher Valas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXPROGRAMSIZE 100


//Prototypes
int in();
void out();
void showStatus(int, int, int []);

//Instrucion Struct that holes the IR address and Operation Code.
typedef struct {
		int opCode;
		int address;
	} Instruction;


int main (int argc, char * argv[]) {
	
	
	printf("Assembling Program...\n");
	
	//Initialization for tiny computer components.
	int DM[10] = { 0 };  	//Data Memory
	int PC = 0;				//Program Counter
	int MAR;				//Memory Address Register
	int MDR2;				//Memory Data Register	
	int accumulator = NULL;		//Accumulator
	char op = NULL;				//operation
	char addr = NULL;			//address
	
	//variables for program
	int addrNum;
	int i;
	char buff[80];
	
	//instruction types
	Instruction IM[MAXPROGRAMSIZE];   //Instruction Memory
	Instruction MDR;				 //Memory Address Register
	Instruction IR;					//Instruction Register
	
	//Collecting file name from command line 
	if(argv[1] == NULL){
		printf("Please provide a file!\n");
		return 0;
	}
	char *name = malloc(strlen(argv[1]) + 1);
		if (name == NULL){
			printf("Malloc failed!\n");
			return 0;
		}
	strcpy(name, argv[1]);
	
	printf("Program Assembled.\n");
	
	//File handling

	FILE * file;
	file = fopen(name, "r");
	if (file){
		printf("Run.\n");
		showStatus(PC, accumulator, DM);
		while(fgets(buff,sizeof buff, file)){
			
			char *slash_slash = strstr(buff, "//");
			if (slash_slash){
				*slash_slash = '\0';
			}
			for(i=0; i< strlen(buff); i++){	
				if (op == NULL && buff[i] != 32){
					op = buff[i];
				}else{
					if (addr == NULL && buff[i] != 32){
						addr = buff[i];
					}
				}
			}
			
			//Fetch cycle
			IM[PC].opCode = op - '0';		
			IM[PC].address = addr - '0';
			MAR = PC;
			PC = PC + 1;
			MDR = IM[MAR];
			IR = MDR;
			
		
			//Execute cycle
			switch (IR.opCode){
				//In
				case 5:
					accumulator = in();
					showStatus(PC, accumulator, DM);
					break;
				//out
				case 6:
					out(accumulator);
					showStatus(PC, accumulator, DM);
					break;
				//Store
				case 3:
					printf("/**Storing Accumulator**/\n");
					MAR = IR.address;
					MDR2 = accumulator;
					DM[MAR] = MDR2;
					showStatus(PC, accumulator, DM);
					break;
				//Load
				case 1:
					printf("/** Loading memory address: %c into the Accumulator**/\n", addr);
					MAR = IR.address;
					MDR2 = DM[MAR];
					accumulator = MDR2;
					showStatus(PC, accumulator, DM);
					break;
				//Subtract	
				case 4:
					printf("/**Subtracting values in accumulator (%d) from memory addresss %c**/\n", accumulator, addr);
					MAR = IR.address;
					MDR2 = DM[MAR];
					accumulator = accumulator - MDR2;
					showStatus(PC,accumulator, DM);
					break;
				//Add
				case 2:
					printf("/**Adding values in accumulator (%d) and memory address %c**/\n", accumulator, addr);
					MAR = IR.address;
					MDR2 = DM[MAR];
					accumulator = accumulator + MDR2;
					showStatus(PC, accumulator, DM);
					break;
				//Jump
				case 8:
					PC = IR.address;
					break;
				//Skip
				case 9:
					if(accumulator == 0){
						PC = PC + 1;
					}
					break;
					
				//END	
				case 7:
					printf("/**END**/\n\n");
					return 0;
					break;
			}
			
			
			op = NULL;
			addr = NULL;

		}

		fclose(file);
	}
	return 0;
}

void showStatus(int PC, int accumulator, int DM[]){
	int i; 
	
	printf("PC = %d | A = %d | DM = ", PC, accumulator);
	printf("[");
	for (i=0; i< 10; i++){
		printf("%d,", DM[i]);
	}
	printf("]\n");
	printf("\n\n");
}

int in() {
	printf("/**Please Input A Value**/\n");
	int a;
	scanf("%d", &a);
	return a;
}

void out(int accumulator) {
	printf("/**Outputting accumulator to screen**/\n");
	printf("%d\n", accumulator);
	
}


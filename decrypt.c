#include<stdio.h>

int fileRead(FILE *file);
void fileWrite(FILE *rfile,FILE *wfile,int slide);
int leng(char word1[]);
int main(int argc,char *argv[]){
	//arguments take
	char* codes;
	char* input;
	char* output;
	/*char* codes = "ref.txt";
	char *input="ciphertext.txt";
	char *output="o.txt";*/

	char a;
	for (int i = 1; i<argc; i++) {
		if(*(argv[i])=='-')
			switch (*(argv[i]+1)){
				case 'r':
      				codes=argv[++i];
      			break;

    				case 'c':
     					input=argv[++i];
      			break;
    
    				case 'p':
     					output=argv[++i];
      			break;
      		
      		}
			
		
		
	}// get arguments end
		FILE *ref=fopen(codes,"r");
		FILE *reader=fopen(input,"r");
		FILE *reader1=fopen(input,"r");
		FILE *reader2=fopen(input,"r");
		FILE *reader3=fopen(input,"r");
		FILE *writer=fopen(output,"w");
		if(ref==NULL){
			printf("%s is not found. \n",codes);
			if(reader==NULL){
				printf("%s is not found. \n",input);
			}
			
		}
		else if(reader==NULL){
			printf("%s is not found. \n",input);
			
		}
		else{
			char less,morr,les,mor;
		
	
			int x=fileRead(ref);
	
			les=x/1000;
			mor= x-les*1000;
		
		
			x=fileRead(reader);
			
			less=x/1000;
			morr= x-less*1000;
		
			int slide;
			int slide2;
		
			if(les-less>0)slide=les-less;
			else  slide=les-less+26;
		
			
			if(mor-morr>0)slide2=mor-morr;
			else  slide2=mor-morr+26;
		
			if(slide==slide2){
				fileWrite(reader1,fopen(output,"w"),slide);
				printf("Shift is detected as %d.\nDecrypted script is wroten to %s folder. \n",slide,output);
			}
			else{	
				int k=leng(output);
				char newOutput[k+2];
				newOutput[k+2]='\0';
				newOutput[k+1]=output[k-1];
				newOutput[k]=output[k-2];
				newOutput[k-1]=output[k-3];
				newOutput[k-2]=output[k-4];
				newOutput[k-3]='0';
				newOutput[k-4]='_';
				for(int i=0;i<k-4;i++)
					newOutput[i]=output[i];
				
				
				fileWrite(reader2,fopen(newOutput,"w"),slide2);
				printf("Shifts are detected as %d (least used letter) and %d (most used letter).\nDecrypted scripts are wroten to %s",slide2,slide,newOutput);
				newOutput[k-3]='1';
				
				fileWrite(reader3,fopen(newOutput,"w"),slide);
				printf(" and %s. \n",newOutput);
				
			}
		}
}

//read file
int fileRead(FILE *file){
	int alp[26];
	for(int i=0;i<26;i++)
		alp[i]=0;
		
	for(int i=fgetc(file);i>0;){
	
	if(96<i&&i<123)
		alp[i-97]+=1;
	else if(64<i&&i<91)
		alp[i-65]+=1;
	i=fgetc(file);
	
	}
	
	int max=alp[0];
	int min=alp[0];
	char more=97;
	char les=97;
	
	for(int i=1;i<26;i++){
		
		if(max<alp[i]){
			
			
			max=alp[i];
			more=i+97;
			
		}
		if(min>alp[i]){
		
			min=alp[i];
			les=i+97;
		}	
	}
	
	return more+les*1000;
}
// read file end

//write slidely
void fileWrite(FILE *rfile,FILE *wfile,int slide){
		
	for(int i=fgetc(rfile);i>0;){
		
		i=i-97;
		i=(i+slide)%26;
		char x=i+97;
		fputc(x,wfile);
		i=fgetc(rfile);
		}
		fclose(wfile);
}
//end write

//get length of string
int leng(char word1[]){
	for(int i=0;1;i++)
		if(word1[i]=='\0')return i;
	return 0;
}

			
			




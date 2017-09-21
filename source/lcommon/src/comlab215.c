#include "comlab215.h"
#include <sys/stat.h>

FILE* files4[4];
FILE* files8[8];
FILE* files16[16];
FILE* files32[32];
FILE* files_alf[9];
FILE* files_alf_coeff[9];
int j = 0;
int count[4] = {0,0,0,0};
int count_alf = 0;
char inFile[1000];
char inFile2[1000];
char path[1000];
int en_which;
int en_print_alf;

void openFiles(){
	
    int i;
    char name[200];
    char strI[3];

    strncpy(inFile2, inFile + sizeof(char)*21, strlen(inFile)-4-sizeof(char)*21);

    struct stat st = {0};

    strcpy(path,"OUTPUT/");

    strcat(path,inFile2);

    strcat(path,"/");

    if(stat(path, &st) == -1){
        mkdir(path, 0700);
    }

#if EN_ALF
    if(en_print_alf == 1){
        for(i = 0; i < 9; i++){
            memset(name, '\0', sizeof(name));
            strcpy(name,path);
            strcat(name,"alf_");
            sprintf(strI, "%d", i);
            strcat(name,strI);

            //strcat(name, inFile2);

            //printf("%s\n",name);
            files_alf[i] = fopen(name, "w");
            if(files_alf[i] == NULL)
                exit(1);
        }

        for(i = 0; i < 9; i++){
            memset(name, '\0', sizeof(name));
            strcpy(name,path);
            strcat(name,"alf_c");
            sprintf(strI, "%d", i);
            strcat(name,strI);

            //strcat(name, inFile2);

            //printf("%s\n",name);
            files_alf_coeff[i] = fopen(name, "w");
            if(files_alf_coeff[i] == NULL)
                exit(1);
        }
    }
#endif
        
#if EN_BUTTERFLY
    if(en_which == 4){
        for(i = 0; i < 4; i++){
            memset(name, '\0', sizeof(name));
            strcpy(name,path);
            strcat(name,"4_");
            sprintf(strI, "%d", i);
            strcat(name,strI);
            
            //strcat(name, inFile2);

            //printf("%s\n",name);
            files4[i] = fopen(name, "w");
            if(files4[i] == NULL)
                exit(1);
        }
    }

    if(en_which == 8){
        for(i = 0; i < 8; i++){
            memset(name, '\0', sizeof(name));
            strcpy(name,path);
            strcat(name,"8_");
            sprintf(strI, "%d", i);
            strcat(name,strI);
            
            //strcat(name, inFile2);
            
            //printf("%s\n",name);
            files8[i] = fopen(name, "w");
            if(files8[i] == NULL)
                exit(1);
        }
    }
        
    if(en_which == 16){
        for(i = 0; i < 16; i++){
            memset(name, '\0', sizeof(name));
            strcpy(name,path);
            strcat(name,"16_");
            sprintf(strI, "%d", i);
            strcat(name,strI);
            
            //strcat(name, inFile2);
            
            //printf("%s\n",name);
            files16[i] = fopen(name, "w");
            if(files16[i] == NULL)
                exit(1);
        }
    }

    if(en_which == 32){        
        for(i = 0; i < 32; i++){
            memset(name, '\0', sizeof(name));
            strcpy(name,path);
            strcat(name,"32_");
            sprintf(strI, "%d", i);
            strcat(name,strI);
            
            //strcat(name, inFile2);
            
            //printf("%s\n",name);
            files32[i] = fopen(name, "w");
            if(files32[i] == NULL)
                exit(1);
        }
    }
    
#endif
        
        
        
}

void closeFiles(){
    int i;
    
#if EN_ALF
    if(en_print_alf == 1){
        for(i = 0; i < 9; i++){
            fclose(files_alf[i]);
            fclose(files_alf_coeff[i]);
        }
    }
#endif
    
#if EN_BUTTERFLY
    if(en_which == 4){
        for(i = 0; i < 4; i++){
            fclose(files4[i]);
        }
    }
    
    if(en_which == 8){
        for(i = 0; i < 8; i++){
            fclose(files8[i]);
        }
    }
    
    if(en_which == 16){
        for(i = 0; i < 16; i++){
            fclose(files16[i]);
        }
    }
        
    if(en_which == 32){
        for(i = 0; i < 32; i++){
            fclose(files32[i]);
        }
    }
#endif
    
}
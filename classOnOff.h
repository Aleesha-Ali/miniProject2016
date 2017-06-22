void go_to_end_of_line(FILE *);	// Function declaration

void determineClassOnOff(char fname[]){
	int noOfTestCases;
	int caseNo;
	int N;
	int P;
	int timeOfStud;
	int presentStudCount = 0;
	char classStatus[] = "OFF";
	FILE *fptr;

	if ((fptr = fopen(fname,"r")) == NULL){
       printf("Error! opening file\n");
       // Program exits if the file pointer returns NULL.
       exit(1);
    }else{
    	fscanf(fptr, "%d", &noOfTestCases);
    	caseNo = noOfTestCases;
    	while(caseNo > 0){
    		strcpy(classStatus, "OFF");
    		presentStudCount = 0;
    		fscanf(fptr, "%d", &N);
    		fscanf(fptr, "%d", &P);
    		// To ensure that P must be less than equal to N and both must be a positive integer.
    		if(P<0 || N<=0 || P > N){
				printf("***Input data error*** for %d case\n", (noOfTestCases - caseNo) + 1);
		        fclose(fptr);
		        exit(1);
			}else{
				while(N){
					fscanf(fptr, "%d", &timeOfStud);
					if(timeOfStud <=0 ){
						presentStudCount++;
					}

					if(presentStudCount >= P){
						strcpy(classStatus, "ON");
						go_to_end_of_line(fptr);
						break;
					}
				    N--;
				}
				printf("%s \n", classStatus);
			}
    		caseNo--;
    	}
        fclose(fptr);
    }
}

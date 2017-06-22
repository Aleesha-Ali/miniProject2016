int * checkLuckyOrNot(long int number) {
	static int returnArr[3];
	long int temp = number%10;
	returnArr[1] = temp;
	returnArr[2] = 0;
	number =  number/10;
	while(number){
	 	if(temp >= number%10){
	 		if((temp-number%10)>returnArr[2]){
	 			returnArr[2] = temp-number%10;
	 		}
	 		temp = number%10;
	 		number =  number/10;
	 		returnArr[1] = returnArr[1] + temp;
	 	}else{
	 		returnArr[0] = 0;
	 		return returnArr;
	 	}
	}
	returnArr[0] = 1;
	return returnArr;
}

void findLuckyNumber(char fname[]){
	int noOfTestCases;
	int caseNo;
	int Num;
	FILE *fptr;
	int *luckyStatusSumDiff;
	
	if ((fptr = fopen(fname,"r")) == NULL){
       printf("Error! opening file\n");
       // Program exits if the file pointer returns NULL.
       fclose(fptr);
       exit(1);
    }else{
    	fscanf(fptr, "%d", &noOfTestCases);
    	caseNo = noOfTestCases;
    	go_to_end_of_line(fptr);
    	while(caseNo > 0){
    		fscanf(fptr, "%d", &Num);

	    	go_to_end_of_line(fptr);
    		if(Num<=0){
				printf("***Input data error*** for %d case\n", (noOfTestCases - caseNo) + 1);
		        fclose(fptr);
		        exit(1);
			}else{
				luckyStatusSumDiff = checkLuckyOrNot(Num);
				if(!luckyStatusSumDiff[0]){
					printf("NA \n");
		        }else{
					printf("%d, %d \n", *(luckyStatusSumDiff+2), *(luckyStatusSumDiff+1));
				}
			}
    		caseNo--;
    	}
        fclose(fptr);
    }
}

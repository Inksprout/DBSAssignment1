#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char *ID;
    char *caseNumber;
    
    char *time;
    char *day;
    char *month;
    char *year;
    char *updated;
    char *date;

    char *IUCR;
    char *description;
    char *FBICode;
    char *primaryType;
    char *domestic;
    char *arrest;
    
    char *block;
    char *beat;
    char *district;
    char *ward;
    char *community;
    char *xCoordinate;
    char *yCoordinate;
    char *latitude;
    char *longitude;
    char *location;
    char *dateTime;
    
    char buffer[1024];
    char *record;
    int itemCount = 0;

    printf("hello\n");
    
    FILE *csvFile = fopen("test.csv", "r");
    
    if (csvFile == NULL)
    {
        printf("\nFile opening failed.\n");
        return -1 ;
    }


    FILE *outputFile = fopen("mongoDBInsertCommands.txt", "w");
    if(outputFile == NULL){
        printf("\nFile opening failed.\n");
        return -1 ;
    }

    while (fgets(buffer, sizeof(buffer), csvFile) != NULL)
    {
        if (itemCount!=0)
        {
            strtok(buffer, "\n");
            ID = strtok(buffer, ",");
            caseNumber = strtok(NULL, ",");
            dateTime = strtok(NULL, ","); 
            block = strtok(NULL, ","); 
            IUCR = strtok(NULL, ","); 
            primaryType = strtok(NULL, ","); 
            description = strtok(NULL, ","); 
            location = strtok(NULL, ","); 
            arrest = strtok(NULL, ","); 
            domestic = strtok(NULL, ","); 
            beat = strtok(NULL, ","); 
            district = strtok(NULL, ","); 
            ward = strtok(NULL, ","); 
            community = strtok(NULL, ","); 
            FBICode = strtok(NULL, ","); 
            xCoordinate = strtok(NULL, ","); 
            yCoordinate = strtok(NULL, ","); 
            strtok(NULL, ","); 
            updated = strtok(NULL, ","); 
            latitude = strtok(NULL, ","); 
            longitude = strtok(NULL, ","); 
            strtok(NULL, ","); 


           //Splitting the dateTime
            date = strtok(dateTime, " ");
            time = strtok(NULL, ",");
            day = strtok(date, "/");
            month = strtok(NULL, "/");
            year = strtok(NULL, "/");

        fprintf(outputFile,"db.crimes.insert({ID: %s,caseNumber: \"%s\",datetime: {time: \"%s\",day: %s,month: %s,year: %s,updated: \"%s\"},crimeData: {IUCR: \"%s\",description: \"%s\",FBI_code: \"%s\",primaryType: \"%s\",domestic: \"%s\",arrest: \"%s\"},location: {block: \"%s\",beat: %s,district: \"%s\",ward: %s,community: %s,locationDescription: \"%s\", coordinates: {xCoordinate: %s, yCoordinate: %s},geographicCoordinates: {latitude: %s,longitude: %s}} })\n", ID, caseNumber,time,day,month,year,updated,IUCR,description,FBICode,primaryType,domestic,arrest,block,beat,district,ward,community,location,xCoordinate,yCoordinate,latitude,longitude);
       
      }
       itemCount++;
    }  

    fclose(outputFile);
    fclose(csvFile);
    return 0;
}
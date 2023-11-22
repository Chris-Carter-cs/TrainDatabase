#include "Rail.h"

int main(int argc, char *argv[]){
    //Set up call to open.
    sqlite3* database = nullptr;
    char* errorMessage = nullptr;
    int error = 0;
    //Call open
    error = sqlite3_open("test.db", &database);
    //Check for errors
    if(error) {
        printf("Error in opening database: %s\n", sqlite3_errmsg(database));
    }

    printf("Database opened.\n");

    printf("Calling build from scratch... ");

    BuildFromScratch(database);

    printf("Done\n");

    sqlite3_close(database);
}

void BuildFromScratch(sqlite3* _database) {
    char* error;

    const char* sql = 
R"(CREATE TABLE TRAINS(
T_ID        INT PRIMARY KEY NOT NULL,
MODEL       TEXT            NOT NULL,
CAPACITY    INT             NOT NULL,
LINE        INT             NOT NULL
))";

    sqlite3_exec(_database, sql, nullptr, nullptr, &error);
}
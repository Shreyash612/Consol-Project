#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;
int size = 5;

typedef struct Player 
{
    int jerseyNumber;
    char name[30];
    int runs;
    int wickets;
    int matchesPlayed;
} Player;

void add(Player** );
void display(Player* );
void sortedDisplay(Player* );
void searchPlayer(Player* );
void searchByJerseyNumber(Player* , int* );
void searchByName(Player* , int* );
void update(Player* );
void removePlayer(Player* );
void printMenu();
void displayOne(Player* );
void displayTopWicketsTakers(Player* );
void displayTopRunsScorers(Player* );
void displayPlayer(Player* , int );

int main() 
{
    Player* arr = (Player*)malloc(sizeof(Player) * size);
    
    // Hardcoded player data
    Player players[5] = {
        {18, "Virat Kohli", 25229, 5, 508},
        {07, "MS Dhoni", 17266, 10, 538},
        {45, "Rohit Sharma", 25167, 15, 433},
        {93, "Jasprit Bumrah", 393, 150, 114},
        {12, "Yuvraj Singh", 11778, 150, 404}
    };

    //  copies the contents of the players array into the arr array.
    memcpy(arr, players, sizeof(players));
    count = 5; 

int choice;
do
{
    printMenu();
    printf("\nEnter your Option: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            add(&arr);
            break;
        case 2:
            display(arr);
            break;
        case 3:
            sortedDisplay(arr);
            break;
        case 4:
        	searchPlayer(arr);
        	break;
        case 5:
            update(arr);
            break;
        case 6:
            removePlayer(arr);
            break;
        case 7:
            displayOne(arr);
            break;
        case 8:
            displayTopRunsScorers(arr);
            break;
        case 9:
            displayTopWicketsTakers(arr);
            break;
        case 10:
            printf("You have chosen to Exit:\n");
            free(arr);
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
    }
} while (choice != 10);

}

void printMenu() 
{
    printf("\n+----------------------------------+\n");
    printf("|              TABLE OF            |\n");
    printf("|              CONTENT             |\n");
    printf("+----------------------------------+\n");
    printf("| 1. Add a Player                  |\n");
    printf("| 2. Display All Players           |\n");
    printf("| 3. Sort players                  |\n");
    printf("| 4. Search Players                |\n");
    printf("| 5. Update Player Data            |\n");
    printf("| 6. Remove Player                 |\n");
    printf("| 7. Display One player            |\n");
    printf("| 8. Display Top 3 Runs Scorers    |\n");
    printf("| 9. Display Top 3 Wickets Takers  |\n");
    printf("| 10. Exit                         |\n");
    printf("+----------------------------------+\n");
}

void add(Player** arr) 
{
    int n;
    printf("Enter the number of players you want to add: ");
    scanf("%d", &n);

    if ((count + n) > size) 
    {
        size += n; 
        Player* temp = (Player*)realloc(*arr, sizeof(Player) * size);
        *arr = temp; 
    }
		
	for (int i = 0; i < n; i++)
	{
	    printf("-----------------------------------------------------\n");
	    printf("PLAYER %d\n", i + 1);
	    printf("Enter the Jersey Number of player: ");
		scanf("%d", &(*arr)[count].jerseyNumber);
	    fflush(stdin); 
	    printf("Enter the Name of player: ");
	    gets((*arr)[count].name);
	    printf("Enter the number of Runs: ");
	    scanf("%d", &(*arr)[count].runs);
	    fflush(stdin); 
	    printf("Enter the number of Wickets: ");
	    scanf("%d", &(*arr)[count].wickets);
	    fflush(stdin); 
	    printf("Enter the Number of Matches Played: ");
	    scanf("%d", &(*arr)[count].matchesPlayed);
	    count++;
	}
		
}

void display(Player* arr) 
{
		printf("\n+-------------------------+----------------------+----------+----------+---------------------+\n");
		printf("|                                     DISPLAY                                                |\n");
		printf("+-------------------------+----------------------+----------+----------+---------------------+\n");
    	printf("| Jersey Number           | Name                 | Runs     | Wickets  | Matches Played      |\n");
    	printf("+-------------------------+----------------------+----------+----------+---------------------+\n");
    	for (int i = 0; i < count; i++) 
    	{
        	printf("| %-22d  | %-20s | %-8d | %-8d | %-18d  |\n", 
               arr[i].jerseyNumber, arr[i].name, arr[i].runs, arr[i].wickets, arr[i].matchesPlayed);
    	}
    	printf("+-------------------------+----------------------+----------+----------+---------------------+\n");

}

void sortedDisplay(Player* arr) 
{
    int choice;
    Player temp; 
    printf("\n+------------------------------------+\n");
    printf("| How would you like to Sort?        |\n");
    printf("+------------------------------------+\n");
    printf("| 1. Sort By Runs                    |\n");
    printf("| 2. Sort By Wickets                 |\n");
    printf("| 3. Sort By Matches Played          |\n");
    printf("+------------------------------------+\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    getchar(); 
    
    switch (choice)
    {
        case 1:
            for (int i = 0; i < count - 1; i++) 
            {
                for (int j = i + 1; j < count; j++) 
                {
                    if (arr[i].runs < arr[j].runs) 
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            display(arr);
            break;
            
        case 2:
            for (int i = 0; i < count - 1; i++) 
            {
                for (int j = i + 1; j < count; j++) 
                {
                    if (arr[i].wickets < arr[j].wickets) 
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            display(arr);
            break;
        
        case 3:
            for (int i = 0; i < count - 1; i++) 
            {
                for (int j = i + 1; j < count; j++) 
                {
                    if (arr[i].matchesPlayed < arr[j].matchesPlayed) 
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            display(arr);
            break;
    }
}

void searchPlayer(Player* arr)
{
	int searchChoice;
            printf("\n+-------------------------+\n");
            printf("| Search by:              |\n");
            printf("+-------------------------+\n");
            printf("| 1. Jersey Number        |\n");
            printf("| 2. Player Name          |\n");
            printf("+-------------------------+\n");
            printf("\nEnter your choice: ");
            scanf("%d", &searchChoice);
            getchar(); // Clear newline

            if (searchChoice == 1) 
            {
                int index;
                searchByJerseyNumber(arr, &index);
            } 
            else if (searchChoice == 2) 
            {
                int index;
                searchByName(arr, &index);
            } 
            else 
            {
                printf("Invalid choice. Please try again.\n");
            }
            
}

void searchByJerseyNumber(Player* arr, int* index) 
{
    int jerseyNumber;
    printf("Enter the Jersey Number to search: ");
    scanf("%d", &jerseyNumber);
    for (int i = 0; i < count; i++) 
    {
        if (arr[i].jerseyNumber == jerseyNumber) 
        {
            *index = i;
        	printf("\n+-------------------------+----------------------+----------+----------+---------------------+\n");
    		printf("| Jersey Number           | Name                 | Runs     | Wickets  | Matches Played      |\n");
    		printf("+-------------------------+----------------------+----------+----------+---------------------+\n");
        	printf("| %-22d  | %-20s | %-8d | %-8d | %-18d  |\n", 
               arr[i].jerseyNumber, arr[i].name, arr[i].runs, arr[i].wickets, arr[i].matchesPlayed);
    		printf("+-------------------------+----------------------+----------+----------+---------------------+\n");
            return;
        }
    }
    printf("Player not found.\n");
    
}


void searchByName(Player* arr, int* index) 
{
    char name[30];
	printf("Enter the Name to search: ");
	fflush(stdin);
	gets(name);
    for (int i = 0; i < count; i++) 
    {
        if (strcasecmp(arr[i].name, name) == 0) 
        {
            *index = i;
            printf("\n+-------------------------+----------------------+----------+----------+---------------------+\n");
    		printf("| Jersey Number           | Name                 | Runs     | Wickets  | Matches Played      |\n");
    		printf("+-------------------------+----------------------+----------+----------+---------------------+\n");
        	printf("| %-22d  | %-20s | %-8d | %-8d | %-18d  |\n", 
               arr[i].jerseyNumber, arr[i].name, arr[i].runs, arr[i].wickets, arr[i].matchesPlayed);
    		printf("+-------------------------+----------------------+----------+----------+---------------------+\n");
            return;
        }
    }
    printf("Player not found.\n");
    
}

void update(Player* arr) 
{
    int index;
    int searchChoice;
    
    printf("\n+-----------------------------+\n");
    printf("| Search player to update by: |\n");
    printf("+-----------------------------+\n");
    printf("| 1. Jersey Number            |\n");
    printf("| 2. Player Name              |\n");
    printf("+-----------------------------+\n");
    printf("\nEnter your choice: ");
    scanf("%d", &searchChoice);
    getchar();   

    if (searchChoice == 1) 
    {
        searchByJerseyNumber(arr, &index);
    } 
    else if (searchChoice == 2) 
    {
        searchByName(arr, &index);
    } 
    else 
    {
        printf("Invalid choice. Please try again.\n");
        return;
    }

 if (index != -1) 
    {
        int updateChoice;
        printf("\n+-----------------------------------+\n");
        printf("| What would you like to update?    |\n");
        printf("+-----------------------------------+\n");
        printf("| 1. Update Runs                    |\n");
        printf("| 2. Update Wickets                 |\n");
        printf("| 3. Update Matches Played          |\n");
        printf("| 4. Update All                     |\n");
        printf("+-----------------------------------+\n");
        printf("\nEnter your choice: ");
        scanf("%d", &updateChoice);
        getchar(); 

        switch (updateChoice) 
        {
            case 1: 
            {
                printf("Enter the new number of Runs: ");
                scanf("%d", &arr[index].runs);
				displayPlayer( arr,  index);
                printf("Runs updated successfully.\n");
                break;
            }
            case 2: 
            {
                printf("Enter the new number of Wickets: ");
                scanf("%d", &arr[index].wickets);
                displayPlayer( arr,  index);
                printf("Wickets updated successfully.\n");
                break;
            }
            case 3: 
            {
                printf("Enter the new Number of Matches Played: ");
                scanf("%d", &arr[index].matchesPlayed);
                displayPlayer( arr,  index);
                printf("Matches Played updated successfully.\n");
                break;
            }
            case 4: 
            {
                printf("Enter the new number of Runs: ");
                scanf("%d", &arr[index].runs);
                printf("Enter the new number of Wickets: ");
                scanf("%d", &arr[index].wickets);
                printf("Enter the new Number of Matches Played: ");
                scanf("%d", &arr[index].matchesPlayed);
                displayPlayer( arr,  index);
                printf("All fields updated successfully.\n");
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void removePlayer(Player* arr) 
{
    int index;
    int searchChoice;

    printf("\n+----------------------------+\n");
	printf("| Search player to remove by |\n");
    printf("+----------------------------+\n");
    printf("| 1. Jersey Number           |\n");
    printf("| 2. Player Name             |\n");
    printf("+----------------------------+\n");
    printf("\nEnter your choice: ");
    scanf("%d", &searchChoice);
    getchar();   

    if (searchChoice == 1) 
    {
        searchByJerseyNumber(arr, &index);
    } 
    else if (searchChoice == 2) 
    {
        searchByName(arr, &index);
    } 
    else 
    {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    if (index != -1) 
    {
        for (int j = index; j < count - 1; j++) 
        {
            arr[j] = arr[j + 1];
        }
        count--;
        printf("Player removed successfully.\n");
        display(arr);
    }
}

void displayOne(Player* arr) 
{
    int index;
    int choice;

    printf("\n+------------------------+\n");
    printf("|  Display Player By     |\n");
    printf("+------------------------+\n");
    printf("| 1. Jersey Number       |\n");
    printf("| 2. Name                |\n");
    printf("+------------------------+\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    getchar(); 

    if (choice == 1) 
    {
        searchByJerseyNumber(arr, &index);
    } 
    else if (choice == 2) 
    {
        searchByName(arr, &index);
    } 
    else 
    {
        printf("Invalid choice. Please try again.\n");
        return;
    }

}

void displayTopRunsScorers(Player* arr) 
{
    Player temp;
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (arr[i].runs < arr[j].runs) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Top 3 Runs Scorers:\n");
    printf("\n+------+---------------+--------------------+-----------+----------+----------------+\n");
    printf("| Rank | Jersey Number | Name               | Runs      | Wickets  | Matches Played |\n");
    printf("+------+---------------+--------------------+-----------+----------+----------------+\n");
    for (int i = 0; i < 3; i++) 
    {
        printf("| %-4d | %-13d | %-18s | %-9d | %-7d  | %-14d |\n",
               i + 1, arr[i].jerseyNumber, arr[i].name, arr[i].runs, arr[i].wickets, arr[i].matchesPlayed);
    }
    printf("+------+---------------+--------------------+-----------+----------+----------------+\n");
	
}

void displayTopWicketsTakers(Player* arr) 
{
    Player temp;
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (arr[i].wickets < arr[j].wickets) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Top 3 Wickets Takers:\n");
    printf("\n+------+---------------+--------------------+-----------+----------+----------------+\n");
    printf("| Rank | Jersey Number | Name               | Runs      | Wickets  | Matches Played |\n");
    printf("+------+---------------+--------------------+-----------+----------+----------------+\n");
    for (int i = 0; i < 3; i++) 
    {
        printf("| %-4d | %-13d | %-18s | %-9d | %-7d  | %-14d |\n",
               i + 1, arr[i].jerseyNumber, arr[i].name, arr[i].runs, arr[i].wickets, arr[i].matchesPlayed);
    }
    printf("+------+---------------+--------------------+-----------+----------+----------------+\n");
}

void displayPlayer(Player* arr, int index) 
{
    printf("\n+-------------------------+----------------------+----------+----------+---------------------+\n");
    printf("| Jersey Number           | Name                 | Runs     | Wickets  | Matches Played      |\n");
    printf("+-------------------------+----------------------+----------+----------+---------------------+\n");
    printf("| %-22d  | %-20s | %-8d | %-8d | %-18d  |\n", 
           arr[index].jerseyNumber, arr[index].name, arr[index].runs, arr[index].wickets, arr[index].matchesPlayed);
    printf("+-------------------------+----------------------+----------+----------+---------------------+\n");
}




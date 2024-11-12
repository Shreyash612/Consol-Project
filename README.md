
# Cricket Player Management System

# Description
The Cricket Player Management System is a console-based application written in C that helps manage cricket player records. 
This project allows users to add, update, and view details about cricket players, including their jersey number, name, runs scored, wickets taken, and matches played. 
It’s a simple yet effective tool for keeping track of player stats in a local environment.

# Features
- Add Player: Enter a new player’s details, including name, jersey number, runs scored, wickets taken, and matches played.
- View Player: Retrieve a specific player’s stats using their jersey number.
- Update Player: Modify existing records if a player’s stats have changed.
- Delete Player: Remove a player’s details if they are no longer active.
- Display All Players: View a summary of all players in the system, showcasing their stats in an organized format.

# How to Use
1. Adding a Player: Use the menu to navigate to the option for adding a new player. Enter the player’s details as prompted.
2. Viewing Player Stats: Select the view option, enter the jersey number, and the system will display that player’s details.
3. Updating/Deleting Players: Choose the respective menu option and enter the jersey number for quick access.
4. Displaying All Players: Select this option to see a list of all recorded players and their stats.

# Sample Code Snippet
Here’s a quick look at the data structure used to manage player details:
```c
struct Player {
    int jerseyNumber;
    char name[50];
    int runs;
    int wickets;
    int matchesPlayed;
};
```

# Technologies Used
- Programming Language: C
- Environment: Console-based

# Future Enhancements
- Add functionality to calculate batting and bowling averages.
- Include sorting options to display players based on stats (e.g., highest runs).
- Implement file handling for persistent data storage.

# Contributing
Feel free to fork this repository, submit issues, and suggest improvements!


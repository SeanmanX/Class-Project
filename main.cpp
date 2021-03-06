#include "headerfile.h"
#include "stadium.h"
#include "store.h"

//right-click the project and go to "Properties"
//C/C++ Build -> Settings -> Tool Settings -> GCC C++ Compiler -> Miscellaneous -> Other Flags. Put -std=c++0x at the end
int main()
{
	int userChoice;			// IN           - User(s) menu selection
	int mainChoice;			// IN			- User(s) main menu selection
	int adminLogin;			// IN 			- User(s) admin menu selection
	menu userSelection; 	//                INPUT (ENUM TYPE).
	mainMenu mainSelection; //				  INPUT (ENUM TYPE).
	ifstream adminFile;
	adminFile.open("AdminInfo.txt");		//CALC - Opens input file
	string username;
	string password;
	string seanUsername;
	string seanPassword;
	string stevenUsername;
	string stevenPassword;
	bool validLogin;		// CALC - Checks if adminLogin is valid

	srand(time(0));
	//Creates a vector containing the stadium class
	vector<stadium> S;
	//Creates a vector containing all items avaliable to purchase
	vector<item> I;
	//initializes items;
	initializeStore(I);
	//Reads input into the vector
	readInput(S);

	getline(adminFile, stevenUsername);
	getline(adminFile, stevenPassword);
	getline(adminFile, seanUsername);
	getline(adminFile, seanPassword);

	adminFile.close();

	// FUNCTION mainChoice - This function is designed to DISPLAY
	//                           the main menu to the user(s).
		UserChoice(mainChoice, 3, 6);

		// PROCESS
		mainSelection = mainMenu(mainChoice);

		// WHILE LOOP - MAIN BODY LOOP
		while (mainChoice != EXITMAIN)
		{
			// SWITCH STATEMENT -
			switch(mainSelection)
			{
				// CASE EXIT - Exit Case.
				case EXITMAIN:
						  	  break;// END OF CASE EXIT

				// CASE STADIUMNAME
				case STADIUMFINDER:
					// FUNCTION UserMenuChoice - This function is designed to DISPLAY
					//                           the menu to the user(s).
					UserChoice(userChoice, 0, 6);

					// PROCESS
					userSelection = menu(userChoice);

					// WHILE LOOP - MAIN BODY LOOP
					while (userChoice != EXIT)
					{
						// SWITCH STATEMENT -
						switch(userSelection)
						{
							// CASE EXIT - Exit Case.
							case EXIT:
									  	  break;// END OF CASE EXIT

							// CASE STADIUMNAME
							case STADIUMNAME:
							//SORT function to sort the vector by stadium
								OutputMLG(S, 0);
											break; // END OF CASE STADIUMNAME

							// CASE TEAMNAME
							case TEAMNAME:
								//SORT function to sort the vector by teamName
								OutputMLG(S, 1);
											break; // END OF CASE TEAMNAME

							// CASE GRASSTOP
							case GRASSTOP:
								//SORT function to sort the vector by stadium
								OutputMLG(S, 2);
											break; // END OF CASE GRASSTOP

							// CASE LEAGUETYPE
							case LEAGUETYPE:
								OutputMLG(S, 4);
											break; // END OF CASE LEAGUETYPE

							// CASE LEAGUETYPE
							case DATEOFCREATION:
								OutputMLG(S, 3);
											break; // END OF CASE LEAGUETYPE


							// CASE RANDOMSTADIUM
							case RANDOMSTADIUM:
								randomStadium(S);
											break; // END OF CASE RANDOMSTADIUM

							// CASE DEFAULT - Default case.
							default:
										break; // END OF CASE DEFAULT
						}// END OF SWITCH STATEMENT

						// FUNCTION UserChoice - This function is designed to display
						//                       and grab the menu choice from the user(s).
						UserChoice(userChoice, 0, 6);

						// PROCESS
						userSelection = menu(userChoice);

					}
				//SORT function to sort the vector by stadium
								break; // END OF CASE STADIUMNAME

				// CASE TRIPPLANNER
				case TRIPPLANNER:
					// FUNCTION - TripPlanner - Method that helps the user plan their
					//							travels, destination by destination
					tripPlanner(S);
					//SORT function to sort the vector by teamName
								break; // END OF CASE TEAMNAME

				// CASE SOUVENIRSHOP
				case SOUVENIRSHOP:
					storeMenu(I);

								break; // END OF CASE GRASSTOP

				// CASE DISTANCE MEASURE
				case DISTANCEMEASURE:
					StoryTen();
								break; // END OF CASE LEAGUETYPE

				// CASE LEAGUEVISIT
				case LEAGUEVISIT:
					LeagueVisit(S);
								break; // END OF CASE LEAGUETYPE

				// CASE ADMINLOGIN
				case ADMINLOGIN:
					if (validLogin == true)
					{
						cout << "\nYou are already logged in " << username << endl;
					}
					else
					{
						// USER INPUT - Input
						UserChoice(adminLogin, 4, 1);

						// CHECK IF USER WISHED TO PROCEED TO LOGIN
						if(adminLogin == 1)
						{

							while(validLogin == false)
							{
								cin.ignore(1000, '\n');
								cout << "\nEnter Username(Case Sensitive): ";
								getline(cin, username);


								cout << "\nEnter Password(Case Sensitive): ";
								getline(cin, password);


								if((username == seanUsername && password == seanPassword)||
								   (username == stevenUsername && password == stevenPassword))
								{
									cout << "\nWelcome " << username << endl;
									validLogin = true;
									break;
								}
								else
								{
									cout << "\nInvalid Login Information, please try again.\n";
								}
								// USER INPUT - Input
								UserChoice(adminLogin, 4, 1);

							}
						} // END OF IF STATEMENT
						adminMenu(S, I);
					}

					break; // END OF CASE LEAGUETYPE

				// CASE DEFAULT - Default case.
				default:
							break; // END OF CASE DEFAULT
			}// END OF SWITCH STATEMENT

			// FUNCTION mainChoice - This function is designed to DISPLAY
			//                           the main menu to the user(s).
			UserChoice(mainChoice, 3, 6);

			// PROCESS
			mainSelection = mainMenu(mainChoice);
		}
	readInto(S);
	return 0;
}

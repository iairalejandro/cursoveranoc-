#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

void printIntro(const char*);
void createMatrix(char**&, int, int);
void createMatrix(int**&, int, int);
void deleteMatrix(char**&, int);
void deleteMatrix(int**&, int);
void fillTable(char**, int);
void fillTable(int**, int);
void printTable(char**, int);
void printTable(int**, int);
void chooseWordOrientation(std::string&);
void put_Word_On_Table(char**, int**, int, const std::string&);
void askWord(char**, int**, const int, int &, std::string*&);
void menu(char**, int**, int, const char* name, int&, std::string*&);
void ignoreLine();
void addWord(const std::string&, int& , std::string*&);
bool They_Are_All_Letters(const std::string&);
bool checkCollision(int**, char**, const int, const int, int, int, const std::string&);
bool do_You_Wish_To_Continue();
bool searchWord(std::string*&, const std::string&, const int&);

int main()
{
	const int ROWS = 10;
	std::srand(std::time(nullptr));
	char** charMatrix{ nullptr };
	int** intMatrix{ nullptr };
	std::string* words{ nullptr };
	int wordsSize{ 0 };

	createMatrix(charMatrix, ROWS, ROWS);
	fillTable(charMatrix, ROWS);

	createMatrix(intMatrix, ROWS, ROWS);
	fillTable(intMatrix, ROWS);

	menu(charMatrix, intMatrix, ROWS, "Diego Alejandro Hidalgo Machaca", wordsSize, words);
	deleteMatrix(charMatrix, ROWS);
	deleteMatrix(intMatrix, ROWS);
	return 0;
}


//CHAR MATRIX
void menu(char** ptrMatrix, int** intPtrMatrix, int length, const char* name, int &size, std::string*& words)
{
	do
	{
		//printIntro(name);
		printTable(ptrMatrix, length);
		askWord(ptrMatrix, intPtrMatrix, length, size, words);
		std::cout << "\n\n\n";
		printTable(ptrMatrix, length);
		std::cout << "-----------------------------------------\n";
		printTable(intPtrMatrix, length);
		if (!do_You_Wish_To_Continue()) std::cout << "aaa ";
			//break;
		if (searchWord(words, "DIEGO", size)) std::cout << "FUNCA ";
		std::cout << size;
	} while (true);
}

void createMatrix(char**& ptrMatrix, int lenght, int width)
{
	ptrMatrix = new char* [lenght];
	for (int row = 0; row < lenght; row++)
	{
		ptrMatrix[row] = new char[width];
	}
}

void deleteMatrix(char**& ptrMatrix, int lenght)
{
	if (ptrMatrix != nullptr)
	{
		for (int row = 0; row < lenght; row++)
		{
			delete[] ptrMatrix[row];
		}

		delete[] ptrMatrix;
	}

	ptrMatrix = nullptr;
}

void fillTable(char** ptrMatrix, int lenght)
{
	for (int row = 0; row < lenght; row++)
	{
		for (int col = 0; col < lenght; col++)
		{
			int randomNumber{ std::rand() % 2 };

			if (randomNumber == 1) ptrMatrix[row][col] = static_cast<char>((std::rand() % 25) + 65);   //65 - 90 MAYUS				
			else ptrMatrix[row][col] = static_cast<char>((std::rand() % 25) + 97);				  //97 - 122 MIN
		}
	}
}

void printTable(char** ptrMatrix, int length)
{
	for (int row = 0; row < length; row++)
	{
		std::cout << "| ";
		for (int col = 0; col < length; col++)
		{
			std::cout << ptrMatrix[row][col] << " | ";
		}
		std::cout << "\n";
	}
}

void askWord(char** ptrMatrix, int** ptrIntMatrix, const int limite, int &size, std::string*& words)
{
	std::string buffer;
	do
	{
		std::cout << "Ingrese una palabra de \"a-z\" o \"A-Z\", y de tamano maximo 10: ";
		std::cin >> buffer;

		if ((buffer.length() <= 10) && (They_Are_All_Letters(buffer) == true))//Si es correcto
		{
			addWord(buffer, size, words);
			chooseWordOrientation(buffer);
			put_Word_On_Table(ptrMatrix, ptrIntMatrix, limite, buffer);
		}
		else
		{
			std::cout << "Palabra no valida, ingresela de nuevo.\n";
		}
	} while ((buffer.length() > 10) || (They_Are_All_Letters(buffer) == false));
}

void put_Word_On_Table(char** ptrMatrix, int** ptrIntMatrix, const int limite, const std::string& word)
{
	int randomNumber{ std::rand() % 3 }, posROW{ -1 }, posCOL{ -1 }, tries{ 0 };

	switch (randomNumber)
	{
	case 0:
	{
		do
		{
			posCOL = std::rand() % 10;
			posROW = std::rand() % 10;
			tries++;
			if (tries > 200)
			{
				std::cout << "No se puedo colocar la palabra\n";
				break;
			}
		} while ((posCOL + word.length() > 10) ||
			(checkCollision(ptrIntMatrix, ptrMatrix, limite, 1, posROW, posCOL, word)));

		for (int i = 0; (i < word.length()) && (tries <= 200); i++)
		{
			ptrMatrix[posROW][posCOL] = word[i];
			ptrIntMatrix[posROW][posCOL] = 1;
			posCOL++;
		}
		break;
	}
	case 1:
	{
		do
		{
			posCOL = std::rand() % 10;
			posROW = std::rand() % 10;
			tries++;
			if (tries > 200)
			{
				std::cout << "No se puedo colocar la palabra\n";
				break;
			}
		} while ((posROW + word.length() > 10) ||
			(checkCollision(ptrIntMatrix, ptrMatrix, limite, 2, posROW, posCOL, word)));

		for (int i = 0; (i < word.length()) && (tries <= 200); i++)
		{
			ptrMatrix[posROW][posCOL] = word[i];
			ptrIntMatrix[posROW][posCOL] = 1;
			posROW++;
		}
		break;
	}
	case 2:
	{
		do
		{
			posCOL = std::rand() % 10;
			posROW = std::rand() % 10;
			tries++;
			if (tries > 200)
			{
				std::cout << "No se puedo colocar la palabra\n";
				break;
			}
		} while ((posROW + word.length() > 10) || (posCOL + word.length() > 10) ||
			(checkCollision(ptrIntMatrix, ptrMatrix, limite, 2, posROW, posCOL, word)));

		for (int i = 0; (i < word.length()) && (tries <= 200); i++)
		{
			ptrMatrix[posROW][posCOL] = word[i];
			ptrIntMatrix[posROW][posCOL] = 1;
			posROW++;
			posCOL++;
		}
		break;
	}
	}
}

bool They_Are_All_Letters(const std::string& word)
{
	std::string vocabulary{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	for (int index = 0; index < word.length(); index++)
	{
		if (vocabulary.length() < vocabulary.find(word[index]))
		{
			return false;
		}
	}
	return true;
}

bool checkCollision(int** ptrIntMatrix, char** ptrCharMatrix, const int limite, const int direction, int posROW, int posCOL, const std::string& word)
{
	switch (direction)
	{
	case 1:							//HORIZONTAL
	{
		for (int index = 0; index < word.length(); index++)
		{
			if (((ptrIntMatrix[posROW][posCOL + index] == 1) &&					//Si esta ocupada
				(ptrCharMatrix[posROW][posCOL + index] != word[index]))		//Si la letra no coincide
				)
			{

				return true;
			}
		}

		break;
	}
	case 2:							//VERTICAL
	{
		for (int index = 0; index < word.length(); index++)
		{
			if (
				((ptrIntMatrix[posROW + index][posCOL] == 1) &&					//Si esta ocupada
					(ptrIntMatrix[posROW + index][posCOL] != word[index])) 		//Si la letra no coincide
				)
			{
				return true;
			}
		}
		break;
	}
	case 3:							//DIAGONAL
	{
		for (int index = 0; index < word.length(); index++)
		{
			if (
				((ptrIntMatrix[posROW + index][posCOL + index] == 1) &&						//Si esta ocupada
					(ptrIntMatrix[posROW + index][posCOL + index] != word[index])) 			//Si la letra no coincide
				)
			{
				return true;
			}
		}
		break;
	}
	}
	return false;
}

bool do_You_Wish_To_Continue()
{
	char buffer;
	do
	{
		std::cout << "Desea continuar? (S/N): ";
		std::cin >> buffer;
		buffer = std::tolower(buffer);
		switch (buffer)
		{
		case 's':
		{
			return true;
		}
		case 'n':
		{
			return false;
		}
		default:
		{
			std::cout << "Opcion no valida, ingresela de nuevo\n";
		}
		}
	} while (true);
}

void printIntro(const char* name)
{
	std::system("cls");            			// Comando para borrar todo el contenido de la pantalla
	std::cout << "\x1B[H";          		// Codigo para colocar el cursor en el canto superior izquierdo

	std::cout << "\x1B[3;36m";         		// Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"	
	std::cout << "/***************************************************/" << std::endl;
	std::cout << "\x1B[m";             		// Resetear color a valor por defecto
	std::cout << "\x1B[31;5;88mUniversidad Catolica San Pablo \x1B[m" << std::endl;
	std::cout << "\x1B[33;5;88mEscuela Profesional de Ciencia de la Computacion I\x1B[m" << std::endl;
	std::cout << "Curso de C++ Intermedio" << std::endl;
	std::cout << "\x1B[38;5;46m" << name << "\x1B[m" << std::endl;
	std::cout << "Arequipa 2024 - Verano" << std::endl;
	std::cout << "\x1B[3;36m";         		// Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"	
	std::cout << "/***************************************************/" << std::endl;

	std::cout << "\x1B[m";             		// Resetear color a valor por defecto 
	std::cout << "\n";

	return;
}

void chooseWordOrientation(std::string& word)
{
	int randomNumber{ std::rand() % 2 };

	switch (randomNumber)
	{
	case 0:							//NORMAL
	{
		return;
	}
	case 1:							//BACKWARDS
	{
		std::string temp;
		for (int index = word.length() - 1; index >= 0; index--)
		{
			temp += word[index];
		}
		word = temp;
		return;
	}
	}
}

void ignoreLine()
{
	std::cin.clear();
	//std::cin.clear
}
//INT MATRIX
void createMatrix(int**& ptrMatrix, int lenght, int width)
{
	ptrMatrix = new int* [lenght];
	for (int row = 0; row < lenght; row++)
	{
		ptrMatrix[row] = new int[width];
	}
}

void deleteMatrix(int**& ptrMatrix, int lenght)
{
	if (ptrMatrix != nullptr)
	{
		for (int row = 0; row < lenght; row++)
		{
			delete[] ptrMatrix[row];
		}

		delete[] ptrMatrix;
	}

	ptrMatrix = nullptr;
}

void fillTable(int** ptrMatrix, int lenght)
{
	for (int row = 0; row < lenght; row++)
	{
		for (int col = 0; col < lenght; col++)
		{
			ptrMatrix[row][col] = 0;
		}
	}
}

void printTable(int** ptrMatrix, int length)
{
	for (int row = 0; row < length; row++)
	{
		std::cout << "| ";
		for (int col = 0; col < length; col++)
		{
			if (ptrMatrix[row][col] == 1)
				std::cout << "\x1B[3;36m" << ptrMatrix[row][col] << "\x1B[m | "; // Cambia el color de los "1"
			else
				std::cout << ptrMatrix[row][col] << " | ";
		}
		std::cout << "\n";
	}
}

//STRING
void addWord(const std::string& inWord, int &size, std::string *&words)
{
	if (size == 0)
	{
		words = new std::string[1];
		words[0] = inWord;
		size++;
	}
	else
	{
		std::string* temp = new std::string[size];
		for (int index = 0; index < size; index++)
		{
			temp[index] = words[index];
		}

		delete[] words;

		size++;
		words = new std::string[size];
		for (int index = 0; index < size - 1; index++)
		{
			words[index] = temp[index];
		}
		words[size - 1] = inWord;
		delete[] temp;
	}
}

bool searchWord(std::string*& words, const std::string& wordToSearch, const int& size)
{
	std::string subSTR;

	for (int index = wordToSearch.length(); index >= 0; index--)  //ver esto
	{
		subSTR += wordToSearch[index];
	}

	for (int index = 0; index < size; index++)
	{
		if ((words[index] == wordToSearch) || (words[index] == subSTR))
			return true;
	}

	return false;
}

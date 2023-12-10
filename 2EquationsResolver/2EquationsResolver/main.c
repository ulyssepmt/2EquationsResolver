#include <stdio.h>
#include <windows.h>

#define _CRT_SECURE_NO_WARNINGS

void ChangeTextColor(int c) { // méthode pour changer la couleur du texte au moment voulu dans la méthode résolution

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

float CheckUserInput(const char* demandeUser) {
	float terme;
	int validInput;

	do {
		ChangeTextColor(15);
		printf("%s", demandeUser);
		validInput = scanf_s("%f", &terme);

		if (validInput != 1) {
			ChangeTextColor(12);
			printf("[ERREUR] Pas un reel !\n\n");
			while (getchar() != '\n');  // Clear the input buffer
		}
	} while (validInput != 1);

	return terme;
}

void SystemResolution() {

	HWND hwnd = GetConsoleWindow(); // handle de la console
	SetConsoleTitleA("Solveur de systemes d equations"); //évident 
	MoveWindow(hwnd, 0, 0, 700, 400, TRUE); // modification de la taille de la fenêtre 

	ChangeTextColor(11); // couleur du texte qui change selon le paramètre d'entrée choisit

	printf("Comment l utiliser ?\nSaisissez vos coefficients en suivant ce schema : \n\n| ax + by = c\n| a'x + b'y = c'\n\n"); 
	float a = 0, b = 0, c = 0, a2 = 0, b2 = 0, c2 = 0, ta = 0, ta2 = 0, tb = 0, tb2 = 0, tc = 0, tc2 = 0, s1 = 0, s2 = 0, s3 = 0, y = 0, e = 0, x = 0;
nouv_equa:

	ChangeTextColor(15);

	printf("\n----------------------------------1ere equation---------------------------------- \n");

	a = CheckUserInput("Entrez a = ");

	b = CheckUserInput("Entrez b = ");

	c = CheckUserInput("Entrez c = ");

	printf("\n----------------------------------2eme equation---------------------------------- \n");

	a2 = CheckUserInput("Entrez a2 = ");

	b2 = CheckUserInput("Entrez b2 = ");

	c2 = CheckUserInput("Entrez c2 = ");

	ChangeTextColor(10);

	printf("\nSysteme d equation :\n\n"); 
	// Affichage du système d'équation avec qqs conditions : si b ou b2 sont positifs, on affiche un "+" devant le terme
	if (b > 0) { printf("| %f x + %f y = %f\n", a, b, c); 
	}
	else { 
		printf("| %f x %f y = %f\n", a, b, c);
	}


	if (b2 > 0) { 
		printf("| %f x + %f y = %f\n\n", a2, b2, c2); 
	}
	else { printf("| %f x %f y = %f\n\n", a2, b2, c2); 
	}
	//if (c > 0) c* (-1); 
	// combinaisons linéaires simplement : 

	ta = a * a2; tb = b * a2; tc = c * a2;

	ta2 = a2 * a; tb2 = b2 * a; tc2 = c2 * a;

	s1 = ta - ta;

	s2 = tb - tb2;

	s3 = tc - tc2;

	y = s3 / s2;

	e = c - (b * y);

	x = e / a;

	ChangeTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_INTENSITY);

	printf("\nS(x ; y) = ( %f ; %f ", x, y); // Affichage des solutions x y

	goto nouv_equa; 

}

int main() {

	SystemResolution(); 

}

/*conditions:
	if (b > 0)  b * (-1);
	//if (c > 0) c* (-1);
	//if (tb2 < 0) tb2 * (-1);
	//if (tc2 < 0) tc2 * (-1);
*/

/*do {
	ChangeTextColor(15);
	cout << "Entrez a = ";
	if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); } //vide le buffer cin contenant la mauavaise saisie !
	cin >> a;

	if (cin.fail()) {
		ChangeTextColor(12);
		cout << "[ERREUR] Pas un reel !\n\n";
	}

} while ((cin.fail()));*/


/*do { ChangeTextColor(15); cout << "Entrez a = "; if ((cin.fail())) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); } //vide le buffer cin contenant la mauavaise saisie !
	cin >> a;
	if (cin.fail()) { ChangeTextColor(12); cout << "[ERREUR] Pas un reel !\n\n"; }
} while ((cin.fail()));*/
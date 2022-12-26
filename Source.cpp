 //*********************************************************************//
//** Author: Sanjana Vijayakumar Nambiar                             **//
//** Date Created: October 14, 2021                                  **//
//** Assignment 2: Concordance of a Text File                        **//
//** ENGR-UH 1000 Computer Programming for Engineers, NYUAD          **//
//** Problem: Is to develop a program that processes a text file     **//
//** and produces its corresponding concordance file.                **//
//*********************************************************************//

# include <iostream>
# include <cstdlib>
# include <iomanip>//Required for setw()
# include <fstream>//Required for ifstream, ofstream
# include <string>//Required for string

using namespace std;

// Function prototypes.
int Size(string filename, int size);
string Correction(string word);
void Sort(string* arr, int size);
void getFrequency(string* arr, int size, string* unique, int* freq, int& newSize);

int main()
{
	// Program description
	cout << " ******************************************************************************** " << endl;
	cout << "   THIS PROGRAM IS DESIGNED TO PROCESS A TEXTFILE AND PRODUCE ITS CORRESPONDING   " << endl;
	cout << "                             CONCORDANCE TEXT FILE                                " << endl;
	cout << " ******************************************************************************** " << endl;


	// Declare objects.
	string in_filename;
	string out_filename;

	// Prompt for filenames and open files. 
	cout << "Please enter the name of the input file that should be processed\n";
	cin >> in_filename;
	ifstream infile;
	infile.open(in_filename, ios::in);//opening infile 
	if (infile.fail())
	{
		cerr << "The input file could not be opened\n";
		exit(1);
	}

	cout << "Please enter the name of the output file in which the concordance text will be saved\n";
	cin >> out_filename;
	ofstream outfile;
	outfile.open(out_filename, ios::out);//opening outfile
	if (outfile.fail())
	{
		cerr << "The output file could not be opened\n";
		exit(1);
	}

	int i = 0;
	int size;
	// function call to get the size of the array.
	size = Size(in_filename, i);

	// declaring  a pointer for dynamic array memory allocation.
	string* textPtr;
	textPtr = new string[size];

	string word;
	for (int i = 0; i < size; i++)
	{
		infile >> word;// getting word from the text file
		//calling function to remove the special characters and to change uppercase to lowercase
		//Also assigning the corrected word to the array
		textPtr[i] = Correction(word);
	}

	// function call to get the array sorted in alphabetical order.
	Sort(textPtr, size);

	// declaring pointers for dynamic array memory allocation. 
	string* unique_words = new string[size];
	int* frequency = new int[size];

	int newSize;
	// fuction call to get the unique keywords and its frequency.
	getFrequency(textPtr, size, unique_words, frequency, newSize);

	//printing the headings 
	cout << setw(15) << left << "Unique Words" << setw(15) << left << "Frequency" << endl;
	outfile << setw(15) << left << "Unique Words" << setw(15) << left << "Frequency" << endl;

	for (int i = 0; i < newSize; i++)// printing the final result
	{
		cout << setw(15) << left << unique_words[i] << setw(15) << left << frequency[i] << endl;
		outfile << setw(15) << left << unique_words[i] << setw(15) << left << frequency[i] << endl;
	}

	//Program ended description
	cout << endl;
	cout << " ******************************************************************************** " << endl;
	cout << "                 !!The concordance result file has been created!!                 " << endl;
	cout << "                                  !!THANK YOU!!                                   " << endl;
	cout << " ******************************************************************************** " << endl;

	//de-allocating the dynamic memory allocations
	delete[] unique_words;
	delete[] frequency;
	delete[] textPtr;

	// closing the files
	infile.close();
	outfile.close();

	return 0;
}

/*This function opens the file and iterators over each word and
returns the size for the arrays for dynamic memory allocation*/
int Size(string filename, int size)
{
	int i = 0;
	string word;
	ifstream infile;
	infile.open(filename);
	
	//looping in to get the number of the words in the text
	while (infile >> word)
	{
		size++;
	}

	infile.close();
	return (size);
}

/*This function recieves the words from the text and returns
the corrected version of the word s*/
string Correction(string word)
{
	int Wordlen;
	string correct = "";
	char ch;
	Wordlen = word.length();//this function gets the length of the word

	//using ASCII code to correct the word
	for (int i = 0; i < Wordlen; i++)
	{
		ch = word[i];
		if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch + 32;//by this changing the uppercase to lowercase
		}
		if (ch >= 'a' && ch <= 'z')
		{
			//saving the corrected characters in a loop to get the corrected word
			correct += ch;
		}
	}
	return(correct);
}

/*This function sorts the array in alphabetical order using 
the method of selection sorting */
void Sort(string* arr, int size)
{
	int m;
	string temp;

	for (int k = 0; k < size - 1; k++)
	{
		m = k;
		for (int j = k + 1; j < size; j++)
		{
			if (arr[j] < arr[m])
			{
				m = j;
			}
		}
		
		//swaping the words
		temp = arr[m];
		arr[m] = arr[k];
		arr[k] = temp;

	}
}

/*This function takes the advantage of sorted array and gets
the unique words and the frequency of its occurence */
void getFrequency(string* arr, int size, string* unique, int* freq, int& newSize)
{
	string word;
	int j = 0;
	for (int i = 0; i < size;)
	{
		int h = 0;//for getting the frequency
		word = arr[i];
		unique[j] = word;

		//looping till the elements is same in order 
		while (word == arr[i])
		{
			h++;
			i++;
		}
		freq[j] = h;
		j++;
	}
	newSize = j;
}



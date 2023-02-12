#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define MaxRows 500
#define MaxCols 500

class grayImage {

public:
	unsigned short setPixel(unsigned short value, int r, int c) {
		if (r >= Rows || c >= Cols || r < 0 || c < 0)
			return -1;
		Image[r][c] = value;
		return value;
	}

	/*Function for getting a single pixel at rth Row & cth Column*/
	int getPixel(int r, int c) {
		if (r >= Rows || c >= Cols || r < 0 || c < 0)
			return -1;
		return Image[r][c];
	}

	int setRows(int rows) {
		if (rows < 1 || rows > MaxRows)
			return -1;
		Rows = rows;
		return Rows;
	}

	int getRows() {
		return Rows;
	}

	int setCols(int cols) {
		if (cols < 1 || cols > MaxCols)
			return -1;
		Cols = cols;
		return Cols;
	}

	int getCols() {
		return Cols;
	}

	bool saveImage(string File_Name)
	{
		/*
		* Here write the code to save an image in .pgm format
		* The function will return true if the image is saved successfully
		*/
		return false;
	}

	bool loadImage(string File_Name)
	{
		/*
		* Here write the code to load an image which is in .pgm format
		* into the struct member "Image"
		* The function will return true if the image is loaded successfully
		*/
		return false;
	}

	void Negative()
	{
		/*
		* Here write the code to convert the grayscale image into negative form
		* Tip: You need to blacken the pixels at every index
		*/
	}


	void changeBrightness(double amount)
	{
		/*
		* Here write the code to brighten the grayscale image by the provided amount.
		* The range of amount is from -255 till +255
		* Tip: You need to brighten the pixels at every index
		*/
	}

	void medianFilter(int filterSize = 3)
	{
		/*
		* Here write the code to apply the median filter on an image
		* This will reduce the noise in the image
		* Tip:
		* Here filtersize states the size of the matrix grid that will be created upon Image 2D Array i.e 3x3 by default
		* Find median of this array.
		* Then replace neighbouring pixels with the median value.
		*/
	}

	void combineSideBySide(grayImage& Two, int fillValue)
	{
		/*
		* Here write the code to combine the second image aside to the current image
		  Tip: Adding two 2D arrays, increasing the resultant image size
		*/
	}

	void FlipHorizontally()
	{
		/*
		* Here write the code to flip the image horizontally
		  Tip: swapping image pixels
		*/
	}

	void FlipVertically()
	{
		/*
		* Here write the code to flip the image vertically
		  Tip: swapping image pixels
		*/
	}

	/* BONUS TASK */
	void Filter(double Mask[][3], int ro, int co)
	{
		/*
		* Here write the code to apply a filter of user's choice on the image
		  Tip: Use the mask array and enhance each pixel with index of 3x3 mask array
		*/

		int l = 0, r = 0, z = 0, s = 0, x = 0, summ = 0;
		int n = ro / 2;

		cout << endl;
		cout << "Enter the Elements of Mask Filter Array " << endl;
		for (int q = 0; q < ro; q++)
		{
			for (int w = 0; w < co; w++)
				cin >> Mask[q][w];
		}

	}

private:
	unsigned short Image[MaxRows][MaxCols]; //Use this 2D array to store pixels of Image
	int Rows, Cols;	//Total Rows, Columns of image
	char format[10];	//This is the magic number (The first row of pgm image), You can only hardcode this
};

int main()
{
	grayImage GM;
	string outputFile;
	string image1;

	//cout << "Enter name of image 1: " << endl;
	//getline(cin, image1);
	//GM.loadImage(image1);


	system("CLS");
	

	int option = 0;

	while (option != -1)
	{
		cout << "Choose an option:\n" << endl;
		cout << " 1. Combine Two images side by side " << endl;
		cout << " 2. Change Brightness of Image" << endl;
		cout << " 3. Find Negative of an Image " << endl;
		cout << " 4. Flip an image Vertically" << endl;
		cout << " 5. Flip an image Horizontally" << endl;
		cout << " 6. Apply Median Filter (Remove Noise)" << endl;
		cout << " 7. Apply your own Filter (Bonus)" << endl;
		cout << "ENTER -1 TO EXIT" << endl;
		cin >> option;
		cout << endl;

		if (option == 1) //sidebyside
		{
			grayImage GM2;
			string image2;

			cout << "Enter name of image 2: " << endl;
			getline(cin, image2);
			GM.loadImage(image2);

			int fillVal;
			cout << "Enter the gray fill Value: " << endl;
			cin >> fillVal;
			GM.combineSideBySide(GM2, fillVal);
			cout << "Enter the output file name: ";
			cin >> outputFile;
			GM.saveImage(outputFile);
		}

		else if (option == 2) { //brightness
			int amount;
			cout << "Enter the amount for brightness: " << endl;
			cin >> amount;
			cout << endl;
			GM.changeBrightness(amount);
			cout << "Enter the output file name: ";
			cin >> outputFile;
			cout << endl;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		}

		else if (option == 3) { //negative
			GM.Negative();
			cout << "Enter the output file name: ";
			cin >> outputFile;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		}

		else if (option == 4) { //flip v
			GM.FlipVertically();
			cout << "Enter the output file name: ";
			cin >> outputFile;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		}

		else if (option == 5) { //flip h
			GM.FlipHorizontally();
			cout << "Enter the output file name: ";
			cin >> outputFile;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		}

		else if (option == 6) { //median

			int filtersize;
			cout << "Enter filter size: " << endl;
			cin >> filtersize;
			GM.medianFilter(filtersize);
			cout << "Enter the output file name: ";
			cin >> outputFile;
			cout << endl;
			GM.saveImage(outputFile);
			cout << endl;
			cout << "Files Saved successfully in the output folder" << endl;
		}

		else if (option == 7) { //Filter
			double b[3][3];
			int r = 3, c = 3;
			GM.Filter(b, r, c);
			cout << "Enter the output file name: ";
			cin >> outputFile;
			cout << endl;
			GM.saveImage(outputFile);
		}

		else if (option == -1)
			break;
	}

	return 0;
}

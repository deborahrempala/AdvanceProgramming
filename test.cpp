#include <iostream>
#include <fstream>

using namespace std;

void backTrack(int **adjMat, int parent[], int numV);

int main(int argc, char *argv[])
{
    ifstream inFile;
    int **adjMat, numV, numE, i, j, cap;

    if (argc != 2)
    {
	cout << "ERROR: Wrong number of parameters\n";
	cout << "Usage: " << argv[0] << " <input filename>\n";
	return -1;
    }

    inFile.open(argv[1]);
    if (inFile.fail())
    {
	cout << "ERROR: Unable to open input file " << argv[1] << endl;
	return -1;
    }

    inFile >> numV >> numE;
    adjMat = (int **) malloc(sizeof(int *) * numV);
    for (i = 0; i < numV; i++)
    {
	adjMat[i] = (int *) malloc(sizeof(int) * numV);
    }
    for (i = 0; i < numV; i++)
    {
	for (j = 0; j < numV; j++)
	    adjMat[i][j] = 0;
    }
    for (;!inFile.eof();)
    {
	inFile >> i >> j >> cap;
	adjMat[i][j] = cap;
    }
    for (i = 0; i < numV; i++)
    {
	for (j = 0; j < numV; j++)
	    cout << adjMat[i][j] << " ";
	cout << endl;
    }
    

    inFile.close();
    return 0;
}

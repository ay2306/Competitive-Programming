/*
QUESTION: ROTATE A GIVEN MATRIX BY 90 DEGREES
*/

void outputMatrix(int[][100], int);
void rotateMatrix(int [][100], int);
void transposeMatrix(int [100][100], int);
void matrixSwitchRows(int [][100], int);
void outputMatrix(int matrixName[][100], int size){
int i,j;
	for(i = 0; i < size; ++i){
		for(j = 0; j < size; ++j){
			printf("%d\t",matrixName[i][j]);
		}
		printf("\n");
	}
}
void rotateMatrix(int matrixName[][100], int size){
	transposeMatrix(matrixName,size);
	matrixSwitchRows(matrixName,size);
}
void transposeMatrix(int matrixName[100][100], int size){
	int i, j;
	for(i = 0; i < size; ++i){
		for(j = i+1; j < size; ++j){
			matrixName[i][j]=matrixName[i][j]+matrixName[j][i];
			matrixName[j][i]=matrixName[i][j]-matrixName[j][i];
			matrixName[i][j]=matrixName[i][j]-matrixName[j][i];
		}
	}

}
/*
a[0][0] a[0][1] a[0][2] a[0][3]
a[1][0] a[1][1] a[1][2] a[1][3]
a[2][0] a[2][1] a[2][2] a[2][3]
a[3][0] a[3][1] a[3][2] a[3][3]
HERE SWITCHING COLUMNS MAKES SECOND INDEX CONSTANT
*/

void matrixSwitchRows(int matrixName[][100], int size){
	int i = 0;
	int j = size - 1;
	int k = 0;
	while(i < j){
		for(k = 0; k < size; ++k){
			matrixName[k][i] = matrixName[k][i] + matrixName[k][j];
			matrixName[k][j] = matrixName[k][i] - matrixName[k][j];
			matrixName[k][i] = matrixName[k][i] - matrixName[k][j];
		}
		++i;
		--j;
	}
}
int main(){
	int a[][100] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	int N = 4;
	printf("ORIGINAL MATRIX: \n");
	outputMatrix(a,N);
	rotateMatrix(a,N);
	printf("ROTATED MATRIX: \n");
	outputMatrix(a,N);
	return 0;
}

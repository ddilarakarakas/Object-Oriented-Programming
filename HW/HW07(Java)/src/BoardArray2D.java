import java.util.Random;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileWriter;   // Import the FileWriter class
import java.io.IOException;  // Import the IOException class to handle errors
import java.io.FileOutputStream;
import java.io.OutputStream;// Import the IOException class to handle errors

public class BoardArray2D extends AbstractBoard{
	private int[][] gameBoard;
	private int location_x;
	private int location_y;
	public BoardArray2D(){
		super();
		gameBoard = new int[2][2];
        numberBoards++;
	}
	public BoardArray2D(int size1,int size2){
		super(size1,size2);
		gameBoard = new int[size1][size2];
		numberBoards++;
	}
	public int getLocation_x(){
		return location_x;
	}
	public int getLocation_y(){
		return location_y;
	}
	public void print(){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(gameBoard[i][j] == -1)
                	System.out.printf("bb ");
                else{
                    if((gameBoard[i][j] >= 0) && (gameBoard[i][j] <= 9))
                    	System.out.printf("0%d ",gameBoard[i][j]);
                    else
                    	System.out.printf("%d ",gameBoard[i][j]);
                }
                if((j % width) == (width - 1))
                	System.out.printf("\n");
            }
        }
        findLocation();
    }
    public void findLocation(){
        for(int x=0;x<height;x++){
            for(int y=0;y<width;y++){
                if(gameBoard[x][y] == -1){
                    location_x = x;
                    location_y = y;
                }
            }
        }
    }
    public void convertToArray2D(int arr[]){
        int i = 0;
        for(int x=0;x<height;x++){
            for(int y=0;y<width;y++){
                gameBoard[x][y] = arr[i];
                i++;
            }
        }
    }
    public void convertToArray1D(int arr[]){
        int i = 0;
        for(int x=0;x<height;x++){
            for(int y=0;y<width;y++){
                arr[i] = gameBoard[x][y];
                i++;
            }
        }
    }
	public void fillBoard(){
		int i;
        Random rand = new Random();
        int randomNumber = rand.nextInt(height*width);
        int board[] = new int[height*width];
        gameBoard = new int[height][width];
        for(i=0;i<height*width;i++)
            board[i] = -1;
        int control = 0;
        while(control == 0){
            for(i=1;i<height*width;i++){
                randomNumber = rand.nextInt(height*width);
                if(board[randomNumber] == -1)
                    board[randomNumber] = i;
                else
                    i--;
            }
            if(solved(board,height*width) == true){
                control = 1;
            }
            else{
                for(i=0;i<height*width;i++)
                    board[i] = -1;
            }
        }
        convertToArray2D(board);
        findLocation();
	}
	public int rightControl(){
        int control = 0;
        if(location_y % width == width - 1)
            control = 0;
        else{
            if(gameBoard[location_x][location_y+1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    public int leftControl(){
        int control = 0;
        if(location_y == 0)
            control = 0;
        else{
            if(gameBoard[location_x][location_y-1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    public int upControl(){
        int control = 0;
        if(location_x % height == 0)
            control = 0;
        else{
            if(gameBoard[location_x-1][location_y] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    public int downControl(){
        int control = 0;
        if(location_x % width == width - 1)
            control = 0;
        else{
            if(gameBoard[location_x+1][location_y] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    public void move(char choice){
        if(choice == 'R' || choice == 'r'){
            if(rightControl() == 1){
                gameBoard[location_x][location_y] = gameBoard[location_x][location_y+1];
                gameBoard[location_x][location_y+1] = -1;
                numberMoves++;
                lastMove = 'r';
            }
            else
            	System.out.printf("YOU CANNOT THIS MOVE!\n");
        }
        else if(choice == 'L' || choice == 'l'){
            if(leftControl() == 1){
                gameBoard[location_x][location_y] = gameBoard[location_x][location_y-1];
                gameBoard[location_x][location_y-1] = -1;                
                numberMoves++;
                lastMove = 'l';
            }
            else
            	System.out.printf("YOU CANNOT THIS MOVE!\n");
        }
        else if(choice == 'U' || choice == 'u'){
            if(upControl() == 1){
                gameBoard[location_x][location_y] = gameBoard[location_x-1][location_y];
                gameBoard[location_x-1][location_y] = -1;
                numberMoves++;
                lastMove = 'u';
            }
            else
            	System.out.printf("YOU CANNOT THIS MOVE!\n");
        }
        else if(choice == 'D' || choice == 'd'){
            if(downControl() == 1){
                gameBoard[location_x][location_y] = gameBoard[location_x+1][location_y];
                gameBoard[location_x+1][location_y] = -1;
                numberMoves++;
                lastMove = 'd';
            }
            else
            	System.out.printf("YOU CANNOT THIS MOVE!\n");
        }
        else
            System.out.printf("WRONG CHOICE\n");
        findLocation();
    }
    public void reset(){
        int board[] = new int[height*width];
        convertToArray1D(board);
        int temp;
        for(int i=0;i<height*width;i++){
            for(int j=i+1;j<height*width;j++){   //Bubble short
                if(board[i] > board[j]){
                    temp = board[i];
                    board[i] = board[j];
                    board[j] = temp;
                }
            }
        }
        temp = board[0];
        for(int i=0;i<height*width-1;i++)
            board[i] = board[i+1];
        board[height*width-1] = temp;
        convertToArray2D(board);
        findLocation();
    }
    public boolean isSolved(){
        boolean control = false;
        int arr[] = new int[height*width];
        convertToArray1D(arr);
        
        int temp;
        for(int i=0;i<height*width;i++){
            for(int j=i+1;j<height*width;j++){   //Bubble short
                if(arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        temp = arr[0];
        for(int i=0;i<height*width;i++)
            arr[i] = arr[i+1];
        arr[height*width-1] = temp;
        
        int tempBoard[] = new int[height*width];
        convertToArray1D(tempBoard);
        for(int i=0;i<height*width;i++){
            if(tempBoard[i] == arr[i])
                control = true;
            else
                control = false;
        }
        return control;
    }
    public int cell(int x,int y){
    	int temp = 0;
    	if((x*y <= height*width) && (x*y >= 0))
    		temp = gameBoard[x][y];
    	else
    		System.exit(0);
    	return temp;
    }
    public boolean equals(AbstractBoard obje){
		boolean control = true;
		if((obje.getHeight() != height) || (obje.getWidth() != width))
			return false;
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(gameBoard[i][j] == obje.cell(i,j))
				control = true;
			else
				control = false;
			}
		}
		return control;
	}
	public void readFromFile(String answer)throws FileNotFoundException{
		int temp_height = 0;
		int temp_width = 0;
		int numLoc = 0;
		int arrSize = 0;
		int tempBoard[] = new int[10000];
		char arr[] = new char[10000];
		File file = new File(answer);
		Scanner myReader = new Scanner(file);
      	while (myReader.hasNextLine()) {
        	String data = myReader.nextLine();
        	temp_height++;
        	for (int i=0;i <data.length();i++) { 
            	arr[i] = data.charAt(i); 
        	}
        	for(int i=0;i<38;i++){
                    if(arr[i] == '\0')
                        break;
                arrSize++;
            }
            temp_width = convertStringToArray(arr,tempBoard,arrSize,numLoc);
            numLoc += temp_width;
            arrSize = 0;
      	}
      	myReader.close();
      	height = temp_height;
      	width = temp_width;
      	gameBoard = new int[height][width];
      	convertToArray2D(tempBoard);
      	findLocation();
      	lastMove = 's';
	}
	public int convertStringToArray(char arr[], int game[], int size, int numLoc){
        int size2 = 0;
        for(int i=0;i<size;i++){
            if(arr[i] <= '9' && arr[i] >= '0'){
                if(arr[i] == '0'){
                    if(arr[i+1] == '0'){
                        game[numLoc] = arr[i] - 48;
                        numLoc++;
                        i++;
                    }
                    else{
                        game[numLoc] = arr[i+1] - 48;
                        numLoc++;
                        i++;
                    }
                }
                else{
                    int num1 = arr[i] - 48;
                    int num2 = arr[i+1] - 48;
                    game[numLoc] = num1*10 + num2;
                    numLoc++;
                    i++;
                }
            }
            if(arr[i] == 'b'){
                game[numLoc] = -1;
                numLoc++;
                i++;
            }
            if(arr[i] == ' ')
                size2 = size2 + 1;
        }
        size2 = size2 + 1;
        return size2;
    }
    public void writeToFile(String answer)throws IOException{
    	int tempBoard[] = new int[height*width];
    	convertToArray1D(tempBoard);
    	OutputStream os = null;
    	int control = 0;
    	for(int j=0;j<height;j++){
    		String data = "";
			for (int i : tempBoard){
				if(i == -1){
					data += "bb ";
					control++;
				}
				if(i >=0 && i >= 9){
					data += "0";
					data += Integer.toString(i);
					data += " ";
					control++;
				}
				if(i > 9){
					data += Integer.toString(i);
					data += " ";
					control++;
				}
				if((control%width) == 0)
					data += "\n";
			}
    		os = new FileOutputStream(new File(answer));
        	os.write(data.getBytes(),0,data.length());
    	}
    }
    public String toString(){
    	int tempBoard[] = new int[height*width];
    	convertToArray1D(tempBoard);
    	String data = "";
    	int control = 0;
    	for(int j=0;j<1;j++){
			for (int i : tempBoard){
				if(i == -1){
					data += "bb ";
					control++;
				}
				else{
					data += "0";
					data += Integer.toString(i);
					data += " ";
					control++;
				}
				if((control%width) == 0)
					data += "\n";
			}
    	}
    	return String.format("***BoardArray2D***\n%s\nLocation: (%d,%d)\n%s\n%s\n",super.toString(),location_x,location_y,"*Board*",data);
    }
}
import java.util.Random;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileWriter;   // Import the FileWriter class
import java.io.IOException;  // Import the IOException class to handle errors
import java.io.FileOutputStream;
import java.io.OutputStream;

public class BoardArray1D extends AbstractBoard{
	private int[] gameBoard;
	private int location;
	public BoardArray1D(){
		super();
		gameBoard = new int[1];
		location = 0;
		numberBoards++;
	}
	public BoardArray1D(int size1,int size2){
		super(size1,size1);
		gameBoard = new int[size1*size2];
		location = 0;
		numberBoards++;
	}
	public void setSize(int x,int y){
		height = x;
		width = y;
	}
	public int getLocation(){
		return location;
	}
	public void fillBoard(){
		int i;
        Random rand = new Random();
        int randomNumber = rand.nextInt(height*width);
        for(i=0;i<height*width;i++)
            gameBoard[i] = -1;
        int control = 0;
        while(control == 0){
            for(i=1;i<height*width;i++){
                randomNumber = rand.nextInt(height*width);
                if(gameBoard[randomNumber] == -1)
                    gameBoard[randomNumber] = i;
                else
                    i--;
            }
            if(solved(gameBoard,height*width) == true){
                control = 1;
            }
            else{
                for(i=0;i<height*width;i++)
                    gameBoard[i] = -1;
            }
        }
        location = findLocation();
	}
	public void print(){
		int i;
        for(i=0;i<height*width;i++){
            if(gameBoard[i] == -1)
                System.out.printf("bb ");
            else{
                if((gameBoard[i] >= 0) && (gameBoard[i] <= 9))
                	System.out.printf("0%d ",gameBoard[i]);
                else
                    System.out.printf("%d ",gameBoard[i]);
            }
            if((i % width) == (width - 1))
                System.out.printf("\n");
        }
	}
	public int rightControl(){
		int control = 0;
        if((location % width) == (width - 1))
            control = 0;
        else{
            if(gameBoard[location+1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
	}
	public int leftControl(){
        int control = 0;
        if(location % width == 0)
            control = 0;
        else{
            if(gameBoard[location-1] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    public int downControl(){
        int control = 0;
        if(location >= height*width - width && location <= height*width - 1)
            control = 0;
        else{
            if(gameBoard[location+width] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    public int upControl(){
        int control = 0;
        if(location < width)
            control = 0;
        else{
            if(gameBoard[location-width] == 0)
                control = 0;
            else
                control = 1;
        }
        return control;
    }
    public void move(char choice){
        if(choice == 'R' || choice == 'r'){
            if(rightControl() == 1){
                gameBoard[location] = gameBoard[location+1];
                gameBoard[location+1] = -1;
                numberMoves++;
                lastMove = 'r';
            }
            else
                System.out.printf("YOU CANNOT THIS MOVE! \n");
        }
        else if(choice == 'L' || choice == 'l'){
            if(leftControl() == 1){
                gameBoard[location] = gameBoard[location-1];
                gameBoard[location-1] = -1;
                numberMoves++;
                lastMove = 'l';
            }
            else
                System.out.printf("YOU CANNOT THIS MOVE! \n");
        }
        else if(choice == 'U' || choice == 'u'){
            if(upControl() == 1){
                gameBoard[location] = gameBoard[location-width];
                gameBoard[location-width] = -1;
                numberMoves++;
                lastMove = 'u';
            }
            else
                System.out.printf("YOU CANNOT THIS MOVE! \n");
        }
        else if(choice == 'D' || choice == 'd'){
            if(downControl() == 1){
                gameBoard[location] = gameBoard[location+width];
                gameBoard[location+width] = -1;
                numberMoves++;
                lastMove = 'd';
            }
            else
                System.out.printf("YOU CANNOT THIS MOVE! \n");
        }
        else
            System.out.printf("WRONG CHOICE \n");
        location = findLocation();
    }
    public int findLocation(){
        for(int i=0;i<height*width;i++){
            if(gameBoard[i] == -1)
                location = i;
        }
        return location;
    }
    public void reset(){
        int temp;
        for(int i=0;i<height*width;i++){
            for(int j=i+1;j<height*width;j++){   //Bubble short
                if(gameBoard[i] > gameBoard[j]){
                    temp = gameBoard[i];
                    gameBoard[i] = gameBoard[j];
                    gameBoard[j] = temp;
                }
            }
        }
        temp = gameBoard[0];
        for(int i=0;i<height*width-1;i++)
            gameBoard[i] = gameBoard[i+1];
        gameBoard[height*width-1] = temp;
        location = findLocation();
    }
    public boolean isSolved(){
        boolean control = false;
        int arr[] = new int[height*width];
        for(int i=0;i<height*width;i++){
            arr[i] = gameBoard[i];
        }
        
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
        
        for(int i=0;i<height*width;i++){
            if(gameBoard[i] == arr[i])
                control = true;
            else
                control = false;
        }
        return control;
    }
    public int cell(int x,int y){
    	int temp = 0;
    	if((x*y < height*width) && (x*y >= 0))
    		temp = gameBoard[x*y];
    	else
    		System.exit(0);
    	return temp;
    }
	public boolean equals(AbstractBoard obje){
		boolean control = true;
		if((obje.getHeight() != height) || (obje.getWidth() != width))
			return  false;
		for(int i=0;i<height*width;i++)
			if(gameBoard[i] == obje.cell(1,i))
				control = true;
			else
				control = false;
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
      	gameBoard = new int[temp_height*temp_width];
      	height = temp_height;
      	width = temp_width;
      	for(int i=0;i<height*width;i++)
      		gameBoard[i] = tempBoard[i];
      	location = findLocation();
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
    	OutputStream os = null;
    	int control = 0;
    	for(int j=0;j<height;j++){
    		String data = "";
			for (int i : gameBoard){
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
    		os = new FileOutputStream(new File(answer));
        	os.write(data.getBytes(),0,data.length());
    	}
    }
    public String toString(){
    	String data = "";
    	int control = 0;
    	for(int j=0;j<1;j++){
			for (int i : gameBoard){
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
    	return String.format("***BoardArray1D***\n%s\nLocation: %d\n*Boards*\n%s\n",super.toString(),location,data);
    }
}
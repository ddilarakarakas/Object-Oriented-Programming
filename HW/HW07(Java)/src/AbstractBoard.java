import java.io.FileNotFoundException;
import java.io.IOException;

public abstract class AbstractBoard implements Cloneable{
	protected int height;
	protected int width;
	protected char lastMove;
	protected int numberMoves;
	protected static int numberBoards = 0;

	public AbstractBoard(int size1,int size2){
		height = size1;
		width = size2;
		lastMove = 's';
		numberMoves = 0;	}
	public AbstractBoard(){
		height = 0;
		width = 0;
		lastMove = 's';
		numberMoves = 0;
	}
	public int getHeight(){
		return height;
	}
	public int getWidth(){
		return width;
	}
	public char getLastMove(){
		return lastMove;
	}
	public int getNumberMoves(){
		return numberMoves;
	}
	public int getNumberBoards(){
		return numberBoards;
	}
	public void setSize(int size1,int size2){
		height = size1;
		width = size2;
	}
	public String toString(){
		return String.format("Height: %d",height," Width: %d\n",width,
			"Number Of Boards: %d\n",numberBoards,
			"Number Of Moves: %d\n",numberMoves,
			"Last Moves: %c\n",lastMove);
	}
	public int invCount(int board[],int size){
		int count = 0;
        for (int i=0;i<size-1;i++)
            for (int j=i+1;j<size;j++)
                if(board[i]>board[j])
                    count++;
        return count;
	}
	public boolean solved(int board[],int size){
		int count = invCount(board,size);
        return (count % 2 == 0);
	}
	public Object clone()throws CloneNotSupportedException{  
		return super.clone();  
	}
	public abstract void readFromFile(String answer)throws FileNotFoundException;
	public abstract void writeToFile(String answer)throws IOException;
	public abstract void reset();
	public abstract void move(char move);
	public abstract boolean isSolved();
	public abstract int cell(int x,int y);
	public abstract boolean equals(AbstractBoard obje);
}
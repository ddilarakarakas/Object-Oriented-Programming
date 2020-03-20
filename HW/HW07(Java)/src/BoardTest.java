import java.io.FileNotFoundException;
import java.io.IOException;

/**
*@author DilaraKarakas

*/

public class BoardTest{
	public static boolean movesForSolution(AbstractBoard boards[])throws CloneNotSupportedException{
		int numberBoard = boards[0].getNumberBoards();
        boolean control = true;
        AbstractBoard temp = (AbstractBoard)boards[0].clone();
        temp.reset();
        numberBoard--;
        char move = '\0';
        for(int i=numberBoard-2;i>=0;--i){
            if(boards[i].equals(temp) == true){
            	if(i != 0){
                	if(boards[i-1].getLastMove() == 'd')
                    	move = 'u';
                	if(boards[i-1].getLastMove() == 'u')
                    	move = 'd';
                	if(boards[i-1].getLastMove() == 'r')
                    	move = 'l';
                	if(boards[i-1].getLastMove() == 'l')
                    	move = 'r';
                	if(boards[i-1].getLastMove() == 's'){
                    	control = false;
                    	break;
                	}
                	temp.move(move);
            	}  
            }
            else{
                control = false;
                break;
            }
        }
        return control;
	}
	public static void main(String[] args){
		System.out.println("\n\n\n\n**********BoardArray1D Test**********");
		BoardArray1D obje = new BoardArray1D(3,3);
		obje.fillBoard();
		System.out.println("***BOARD***");
		obje.print();
		System.out.println("*RIGHT MOVE TEST*");
		obje.move('r');
		obje.print();
		System.out.println("*DOWN MOVE TEST*");
		obje.move('d');
		obje.print();
		System.out.println("*LEFT MOVE TEST*");
		obje.move('l');
		obje.print();
		System.out.println("*UP MOVE TEST*");
		obje.move('u');
		obje.print();
		System.out.println("*RIGHT MOVE TEST*");
		obje.move('r');
		obje.print();
		System.out.println("*RIGHT MOVE TEST*");
		obje.move('r');
		obje.print();
		System.out.println("*UP MOVE TEST*");
		obje.move('u');
		obje.print();
		System.out.println("*UP MOVE TEST*");
		obje.move('u');
		obje.print();
		System.out.println("*FILE READ TEST*");
		System.out.println("FILE BOARD");
		try{
			obje.readFromFile("d.txt");
		}
		catch (FileNotFoundException e){
      		System.out.println("FILE NOT EXIST!!!");
      		e.printStackTrace();
    	}
    	obje.print();
    	System.out.println("*RESET TEST*");
    	obje.reset();
    	obje.print();
    	System.out.println("*CELL TEST*");
    	obje.print();
    	System.out.printf("0. INDEX: %d\n4. INDEX: %d\n1. INDEX: %d\n5. INDEX: %d\n",obje.cell(0,1),obje.cell(4,1),obje.cell(1,1),obje.cell(5,1));
    	System.out.println("*WRITE FILE TEST*");
    	System.out.println("New file name is test.txt");
    	try{
    		obje.writeToFile("test.txt");
    	}
    	catch(IOException e){
            e.printStackTrace();
    	}
    	System.out.println("*EQUALS TEST*");
    	BoardArray2D testObje = new BoardArray2D(3,4);
    	testObje.fillBoard();
    	System.out.println("Test Boards 1");
    	testObje.print();
    	System.out.println("Test Boards 2");
    	obje.print();
    	if(obje.equals(testObje) == true)
    		System.out.println("EQUALS");
    	else
    		System.out.println("NOT EQUALS");
    	System.out.println("*toString TEST*");
    	System.out.printf("%s\n",obje.toString());
    	System.out.println("\n\n\n\n*************************************");
    	System.out.println("\n\n\n\n**********BoardArray2D Test**********");
		BoardArray1D obje2 = new BoardArray1D(3,3);
		obje2.fillBoard();
		System.out.println("***BOARD***");
		obje2.print();
		System.out.println("*RIGHT MOVE TEST*");
		obje2.move('r');
		obje2.print();
		System.out.println("*DOWN MOVE TEST*");
		obje2.move('d');
		obje2.print();
		System.out.println("*LEFT MOVE TEST*");
		obje2.move('l');
		obje2.print();
		System.out.println("*UP MOVE TEST*");
		obje2.move('u');
		obje2.print();
		System.out.println("*RIGHT MOVE TEST*");
		obje2.move('r');
		obje2.print();
		System.out.println("*RIGHT MOVE TEST*");
		obje2.move('r');
		obje2.print();
		System.out.println("*UP MOVE TEST*");
		obje2.move('u');
		obje2.print();
		System.out.println("*UP MOVE TEST*");
		obje2.move('u');
		obje2.print();
		System.out.println("*WRITE FILE TEST*");
    	System.out.println("New file name is test2.txt");
    	try{
    		obje2.writeToFile("test2.txt");
    	}
    	catch(IOException e){
            e.printStackTrace();
    	}
		System.out.println("*FILE READ TEST*");
		System.out.println("FILE BOARD");
		try{
			obje2.readFromFile("d.txt");
		}
		catch (FileNotFoundException e){
      		System.out.println("FILE NOT EXIST!!!");
      		e.printStackTrace();
    	}
    	obje2.print();
    	System.out.println("*RESET TEST*");
    	obje2.reset();
    	obje2.print();
    	System.out.println("*CELL TEST*");
    	obje2.print();
    	System.out.printf("0. INDEX: %d\n4. INDEX: %d\n1. INDEX: %d\n5. INDEX: %d\n",obje2.cell(0,1),obje2.cell(4,1),obje2.cell(1,1),obje2.cell(5,1));
    	System.out.println("*EQUALS TEST*");
    	BoardArray2D testObje2 = new BoardArray2D(3,4);
    	testObje2.fillBoard();
    	System.out.println("Test Boards 1");
    	testObje2.print();
    	System.out.println("Test Boards 2");
    	obje2.print();
    	if(obje2.equals(testObje2) == true)
    		System.out.println("EQUALS");
    	else
    		System.out.println("NOT EQUALS");
    	System.out.println("*toString TEST*");
    	System.out.printf("%s\n",obje2.toString());
    	System.out.println("\n\n\n\n*************************************");
    	System.out.println("\n\n\n\n**********Global Function Test**********");
    	BoardArray2D boards[] = new BoardArray2D[3]; 
    	BoardArray2D o1 = new BoardArray2D(3,3);
    	try{
    		o1.readFromFile("d.txt");
    	}
    	catch (FileNotFoundException e){
      		System.out.println("FILE NOT EXIST!!!");
      		e.printStackTrace();
    	}
    	boards[0] = o1;
    	o1.move('r');
    	System.out.println("MOVE");
    	o1.print();
    	boards[1] = o1;
    	o1.move('d');
    	System.out.println("MOVE");
    	o1.print();
    	boards[2] = o1;
    	try{
    		System.out.printf("%b\n",movesForSolution(boards));
    	}
    	catch(CloneNotSupportedException e){
    		System.err.printf("ERROR!\n");
    	}
	}
}
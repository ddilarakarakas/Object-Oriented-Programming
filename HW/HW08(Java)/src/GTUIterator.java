import java.lang.reflect.Array;
import java.util.Iterator;

public class GTUIterator<E> {
	private E [] array;
	private int size;
	private int index = 0;
	private int capacity;
	public GTUIterator() throws Exception {
		array = null;
		setSize(0);
	}
	public GTUIterator(E arr[]) throws Exception {
		int count=0;
		if(arr.getClass().getName() == "[Ljava.lang.Integer;") {
			setSize(arr.length);
			array = (E[]) new Integer[arr.length];
			for(int i=0;i<getSize();i++)
				array[i] =  (E) new Integer((Integer)arr[i]);
			while(getArray(count).getClass().getName() == Integer.class.getName()) {
				count++;
				if(count==getSize()) 
					break;
			}
		}
		if(arr.getClass().getName() == "[Ljava.lang.String;"){
			setSize(arr.length);
			array = (E[]) new String[arr.length];
			for(int i=0;i<getSize();i++)
				array[i] =  (E) new String((String)arr[i]);
			while(getArray(count).getClass().getName() == String.class.getName()) {
				count++;
				if(count==getSize()) 
					break;
			}
		}
		if(arr.getClass().getName() == "[Ljava.lang.Double;") {
			setSize(arr.length);
			array = (E[]) new Double[arr.length];
			for(int i=0;i<getSize();i++)
				array[i] =  (E) new Double((Double)arr[i]);
			while(getArray(count).getClass().getName() == Double.class.getName()) {
				count++;
				if(count==getSize()) 
					break;
			}
		}
		setCapacity(getSize()-count);
	}
	public E getArray(int i) {
		return array[i];
	}
	public int getSize() {
		return size;
	}
	public void setSize(int s) throws Exception{
		if(s>0)
			this.size = s;
		else
			new Exception();
	}
	public int getIndex() {
		return index;
	}
	public void setIndex(int index) throws Exception{
		if(index<this.getSize() && index>=0)
			this.index = index;
		else
			new Exception();
	}
	public int getCapacity() {
		return capacity;
	}
	public void setCapacity(int c) throws Exception{
		if(c<=size && c>=0) {
			this.capacity = c;
		}
		else
			new Exception();
	}
	public boolean hasNext() {
		if(getArray(getIndex()+1)!=null)
			return true;
		return false;
	}
	public E next() throws Exception{
		if(hasNext())
			this.setIndex(index+1);
		else 
			new Exception();
		return getArray(index);
	}
	public String toString(){
		return String.format("Current Element = %s", this.getArray(index));
	}	
}
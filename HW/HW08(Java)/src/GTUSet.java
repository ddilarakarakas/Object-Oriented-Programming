public class GTUSet<E> extends GTUContainer{
	private E data[];
	public GTUSet(){
		super();
		data=(E[])new Object[20];
	}
	public GTUSet(int size_){
		super(size_);
		data=(E[])new Object[20];
	}
	public boolean empty(){
		if(this.used_size == 0)
			return true;
		else
			return false;
	}
	public int size(){
		return this.used_size;
	}
	public int max_size(){
		return this.capacity;
	}
	public void insert(Object objec)throws java.lang.IllegalArgumentException{
		if(objec instanceof Integer || objec instanceof String || objec instanceof Double){
			E obje = ((E)objec);
			boolean control = true;
        	for(E temp_iter : data){
            	if(temp_iter == obje){
                	control = false;
            	}
        	}
        	if(control){
            	if(this.size() <= this.max_size()){
                	this.data[used_size] = obje;
            	}
            	if(this.size() > this.max_size()){
                	this.capacity = this.capacity * 2;
                	E temp[] = (E[])new Object[this.capacity];
                	int i = 0;
                	for(E temp_iter : data){
                    	temp[i] = temp_iter;
                    	i++;
                	}
                	this.data = null;
                	this.data = (E[])new Object[this.capacity];
                	this.data = temp;
                	this.data[used_size++] = obje;
            	}
            	this.used_size++;
        	}
		}
		else{
			java.lang.IllegalArgumentException e;
		}
	}
	public void erase(Object objec){
		if((objec instanceof Integer) || (objec instanceof String) || (objec instanceof Double)){
			E obje = ((E)objec);
			boolean control = false;
        	for(int i=0;i<used_size;i++){
            	if(data[i] == obje){
                	for(int k=i;k<used_size;k++){
                		data[k] = data[k+1];
                		control = true;
                	}
            	}
        	}
        	if(control)
            	used_size--;
		}
	}
	public void print()throws NullPointerException{
		for(int i=0;i<used_size;i++)
			System.out.println(data[i]);
	}
	public void clear(){
		used_size = 0;
        capacity = 1;
        E temp[] =(E[])new Object[capacity];
        data = temp;
	}
	public GTUIterator<E> begin()throws Exception{
		GTUIterator<E> iterator =new GTUIterator<E>(data);
		return iterator;
	}
	public boolean contains(Object objec){
		boolean control = false;
		if(objec instanceof Integer || objec instanceof String || objec instanceof Double){
			E obje = ((E)objec);
			for(E iter : data){
				if(obje == iter)
					control = true;
				
			}
		}
		return control;
	}
}
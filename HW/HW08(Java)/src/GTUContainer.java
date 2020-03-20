public abstract class GTUContainer<E>{
	protected int used_size;
	protected int capacity;
	GTUContainer(){
		used_size = 0;
        capacity = 5;
	}
	GTUContainer(int size_){
		used_size = 0;
		capacity = size_;
	}
	public abstract boolean empty();
    public abstract int size();
    public abstract int max_size();
    public abstract void insert(E obje)throws java.lang.IllegalArgumentException;
    public abstract void erase(E obje);
    public abstract void clear();
    public abstract GTUIterator<E> begin()throws Exception;
    public abstract boolean contains(Object o);
}
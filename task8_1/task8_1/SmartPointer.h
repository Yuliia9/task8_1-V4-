/**
*@file		SmartPointer.h
*@brief		File for creating template smart pointer
*/

template  <typename T>
class SmartPointer
{
public:
	//life cycle
	SmartPointer(T* obj);
	~SmartPointer();
	
	T* get(void) const;
	bool isNull(void) const;

private:
	//prohibit
	SmartPointer(SmartPointer&);
	SmartPointer();
	SmartPointer& operator=(SmartPointer&);

	//fields
	T* _obj;	
};


/**
* @brief				Function for getting object to which points smart pointer
* @param	void
* @return	T*			Returns objects to which points smart pointer
*/
template  <typename T>
T* SmartPointer<T>::get(void) const
{
	return _obj;
}


/**
* @brief				Function for checking if pointer points to null object
* @param	void
* @return	bool		Returns true if object is null, otherwise return false
*/
template  <typename T>
bool SmartPointer<T>::isNull(void) const
{
	return (_obj==NULL);
}

/**
* @brief				Destructor for release memory
* @param	void
*/
template  <typename T>
SmartPointer<T>::~SmartPointer()
{
	delete _obj;
}


/**
* @brief				Constructor for initialization pointer with object
* @param	void
*/
template<typename T>
SmartPointer<T>::SmartPointer(T* obj) : _obj(obj)
{
}


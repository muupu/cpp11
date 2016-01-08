#include <vector>

template <typename T> class Blob{
	public:
		typedef T value_type;
		typedef typename std::vector<T>::size_type size_type;

		Blob();
		Blob()(std::initializer_list<T> il);
};
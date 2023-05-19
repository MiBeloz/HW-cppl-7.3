#pragma once

#include <initializer_list>
#include <exception>


namespace my_class {
	template<class T>
	class Vector {
	public:
		Vector() : m_size(0), m_capacity(0), m_array(nullptr) {}
		Vector(const size_t size);
		Vector(const size_t size, const T& val);
		Vector(std::initializer_list<T> list);
		//Vector(const Vector& vector);

		~Vector();

		//Vector& operator=() const;
		//bool operator==() const;

		T& at(const size_t index) const;
		T& operator[](const size_t index);
		const T& operator[](const size_t index) const;
		T& front();
		const T& front() const;
		T& back();
		const T& back() const;

		bool empty() const;
		size_t size() const;
		size_t max_size() const;
		void resize(const size_t new_size);
		size_t capacity() const;
		void shrink_to_fit();

		void clear();
		void push_back(T value);
		//void pop_back();
	
	private:
		size_t m_size;
		size_t m_capacity;
		T* m_array;
	};


	template<class T>
	inline Vector<T>::Vector(const size_t size) {
		if (size > ULONG_MAX) {
			throw std::exception("vector is too long");
		}
		m_size = size;
		m_capacity = m_size / 2 + m_size;
		m_array = new T[m_capacity]{ T() };
	}

	template<class T>
	inline Vector<T>::Vector(const size_t size, const T& val) {
		if (size > ULONG_MAX) {
			throw std::exception("vector is too long");
		}
		m_size = size;
		m_capacity = m_size / 2 + m_size;
		m_array = new T[m_capacity]{ val };
	}

	template<class T>
	inline Vector<T>::Vector(std::initializer_list<T> list) {
		m_size = list.size();
		m_capacity = (m_size / 2 + m_size) + 1;
		m_array = new T[m_capacity]{ T() };

		auto it = list.begin();
		for (size_t i = 0; i < m_size; ++i, ++it) {
			m_array[i] = *it;
		}
	}

	template<class T>
	inline Vector<T>::~Vector() {
		delete[] m_array;
		m_array = nullptr;
	}

	template<class T>
	inline T& Vector<T>::at(const size_t index) const {
		if (index >= m_size) {
			throw std::exception("out of range");
		}
		return m_array[index];
	}

	template<class T>
	inline T& Vector<T>::operator[](const size_t index) {
		return m_array[index];
	}

	template<class T>
	inline const T& Vector<T>::operator[](const size_t index) const {
		return m_array[index];
	}

	template<class T>
	inline T& Vector<T>::front() {
		if (empty()) {
			throw std::exception("front() called on empty vector");
		}
		return m_array[0];
	}

	template<class T>
	inline const T& Vector<T>::front() const {
		if (empty()) {
			throw std::exception("front() called on empty vector");
		}
		return m_array[0];
	}

	template<class T>
	inline T& Vector<T>::back() {
		if (empty()) {
			throw std::exception("back() called on empty vector");
		}
		return m_array[m_size - 1];
	}

	template<class T>
	inline const T& Vector<T>::back() const {
		if (empty()) {
			throw std::exception("back() called on empty vector");
		}
		return m_array[m_size - 1];
	}

	template<class T>
	inline bool Vector<T>::empty() const {
		return m_size == 0;
	}

	template<class T>
	inline size_t Vector<T>::size() const {
		return m_size;
	}

	template<class T>
	inline size_t Vector<T>::max_size() const {
		return ULONG_MAX;
	}

	template<class T>
	inline void Vector<T>::resize(const size_t new_size) {
		if (new_size > ULONG_MAX) {
			throw std::exception("vector is too long");
		}
		m_capacity = new_size;
		T* temp_array = new T[m_capacity];

		size_t j = 0;
		if (m_capacity >= m_size) {
			j = m_size;
		}
		else {
			j = m_capacity;
			m_size = m_capacity;
		}

		for (size_t i = 0; i < j; ++i) {
			temp_array[i] = m_array[i];
		}

		delete[] m_array;
		m_array = temp_array;
	}

	template<class T>
	inline size_t Vector<T>::capacity() const {
		return m_capacity;
	}

	template<class T>
	inline void Vector<T>::shrink_to_fit() {
		if (m_size == m_capacity) {
			return;
		}
		resize(m_size);
	}

	template<class T>
	inline void Vector<T>::clear() {
		for (size_t i = 0; i < m_size; ++i) {
			m_array[i] = T();
		}
		m_size = 0;
	}

	template<class T>
	inline void Vector<T>::push_back(T value) {
		if (m_size == m_capacity) {
			resize((m_size / 2 + m_size) + 2);
		}
		m_array[m_size] = value;
		m_size++;
	}
}

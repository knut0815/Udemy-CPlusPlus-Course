#pragma once

#include <array>

namespace ms {
	template<class T>
	class RingBuffer
	{
	public:
		class Iterator;

		RingBuffer(size_t t_buffer_size) :
			m_buffer_size(t_buffer_size),
			m_elements(new T[m_buffer_size])
		{
		}

		~RingBuffer()
		{
			delete[] m_elements;
		}

		inline size_t size() const { return m_buffer_size; }

		void push_back(const T &t_element)
		{
			// use value then increment
			m_elements[m_position++] = t_element;

			// loop back around to the beginning
			if (m_position == m_buffer_size)
			{
				m_position = 0;
			}
		}

		Iterator begin()
		{
			return{ 0, *this };
		}

		Iterator end()
		{
			return{ m_buffer_size, *this };
		}

		const T& operator[](size_t t_index) const
		{
			return m_elements[t_index];
		}

		T& operator[](size_t t_index) 
		{
			return m_elements[t_index];
		}
	private:
		size_t m_position = 0;
		size_t m_buffer_size;
		T *m_elements;
	};
	
	// Iterator inherits the template parameter T from RingBuffer
	template<class T>
	class RingBuffer<T>::Iterator
	{
	public:
		Iterator(size_t t_position, RingBuffer &t_ring_buffer) :
			m_position(t_position),
			m_ring_buffer(t_ring_buffer)
		{
		}

		// pre-fix operator: increments and returns this
		Iterator& operator++()
		{
			m_position++;
			return *this;
		}

		// post-fix operator: increments this then returns the old Iterator
		Iterator operator++(int)
		{
			Iterator temp = *this;
			++(*this);
			return temp;
		}

		T& operator*()
		{
			return m_ring_buffer[m_position];
		}

		bool operator==(const Iterator &t_other) const
		{
			return m_position == t_other.m_position;
		}

		bool operator!=(const Iterator &t_other) const
		{
			return !(*this == t_other);
		}
	private:
		size_t m_position;
		RingBuffer &m_ring_buffer;
	};
} // namespace ms